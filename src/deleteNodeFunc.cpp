#include "deleteNodeFunc.h"

#include "binTreeFuncs.h"

// Нахождение минимального значения в дереве
ListNodeLastName* findMin(ListNodeLastName *root) {
    while (root && root->left != nullptr) {
        root = root->left;
    }
    return root;
}

ListNodeThreatsEliminated* findMinThreatsEliminated(ListNodeThreatsEliminated *root) {
    while (root && root->left != nullptr) {
        root = root->left;
    }
    return root;
}

// Удаление узла из дерева LastName
ListNodeLastName* deleteNodeFromLastNameTree(ListNodeLastName *root, const std::string &lastName) {
    if (root == nullptr) return root;

    if (lastName < root->lastName) {
        root->left = deleteNodeFromLastNameTree(root->left, lastName);
    } else if (lastName > root->lastName) {
        root->right = deleteNodeFromLastNameTree(root->right, lastName);
    } else {
        // Найден узел для удаления
        if (root->left == nullptr) {
            ListNodeLastName *temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            ListNodeLastName *temp = root->left;
            delete root;
            return temp;
        }

        // Узел имеет два потомка
        ListNodeLastName *minRight = findMin(root->right);
        root->lastName = minRight->lastName;
        root->arrayID = minRight->arrayID;
        root->right = deleteNodeFromLastNameTree(root->right, minRight->lastName);
    }
    return root;
}

ListNodeThreatsEliminated* deleteNodeFromThreatsEliminatedTree(ListNodeThreatsEliminated *root, unsigned int threatsEliminated) {
    if (root == nullptr) return root;

    if (threatsEliminated < root->threatsEliminated) {
        root->left = deleteNodeFromThreatsEliminatedTree(root->left, threatsEliminated);
    } else if (threatsEliminated > root->threatsEliminated) {
        root->right = deleteNodeFromThreatsEliminatedTree(root->right, threatsEliminated);
    } else {
        if (root->left == nullptr) {
            ListNodeThreatsEliminated *temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            ListNodeThreatsEliminated *temp = root->left;
            delete root;
            return temp;
        }

        ListNodeThreatsEliminated *minRight = findMinThreatsEliminated(root->right);
        root->threatsEliminated = minRight->threatsEliminated;
        root->arrayID = minRight->arrayID;
        root->right = deleteNodeFromThreatsEliminatedTree(root->right, minRight->threatsEliminated);
    }
    return root;
}

void deleteTree(ListNodeLastName *root) {
    if (!root) return; // Базовый случай: если дерево пустое, ничего не делаем
    deleteTree(root->left); // Рекурсивно удаляем левое поддерево
    deleteTree(root->right); // Рекурсивно удаляем правое поддерево
    delete root; // Удаляем текущий узел
}

void deleteTree(ListNodeThreatsEliminated *root) {
    if (!root) return; // Базовый случай: если дерево пустое, ничего не делаем
    deleteTree(root->left); // Рекурсивно удаляем левое поддерево
    deleteTree(root->right); // Рекурсивно удаляем правое поддерево
    delete root; // Удаляем текущий узел
}

void deleteNodeFunc(StationReport *&sourceReports, ListNodeLastName *&lastNameIndexRoot, ListNodeThreatsEliminated *&threatsEliminatedIndexRoot, int reportId, int &size) {
    // Создаем новый массив отчетов без удаляемого элемента
    StationReport *newReports = new StationReport[size - 1];
    for (int i = 0; i < reportId; i++) {
        newReports[i] = sourceReports[i];
    }
    for (int i = reportId + 1; i < size; i++) {
        newReports[i - 1] = sourceReports[i];
        newReports[i - 1].reportIndex -= 1; // Обновляем индекс
    }

    // Удаляем старый массив отчетов
    delete[] sourceReports;

    // Обновляем указатель на новый массив
    sourceReports = newReports;

    // Уменьшаем размер массива
    --size;

    // Пересоздаем индексы
    deleteTree(lastNameIndexRoot); // Удаляем старое дерево LastName
    deleteTree(threatsEliminatedIndexRoot); // Удаляем старое дерево ThreatsEliminated

    // Сбрасываем указатели на корни деревьев
    lastNameIndexRoot = nullptr;
    threatsEliminatedIndexRoot = nullptr;

    // Построение новых индексных деревьев
    buildIndexByLastName(sourceReports, lastNameIndexRoot, size);
    buildIndexByThreatsEliminated(sourceReports, threatsEliminatedIndexRoot, size);
}