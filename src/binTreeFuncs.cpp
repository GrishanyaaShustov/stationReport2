#include "binTreeFuncs.h"

ListNodeLastName* insertLastName(ListNodeLastName *node, std::string lastName, int arrayID) {
    if(!node) {
        ListNodeLastName* newNode = new ListNodeLastName{lastName, arrayID, nullptr, nullptr};
        return newNode;
    }
    if(lastName <= node->lastName) {
        node->left = insertLastName(node->left, lastName, arrayID);
    }
    else if(lastName > node->lastName) {
        node->right = insertLastName(node->right, lastName, arrayID);
    }

    return node;

}

ListNodeThreatsEliminated* insertThreatsEliminated(ListNodeThreatsEliminated* node, unsigned int threatsEliminated, int arrayID) {
    if (!node) {
        ListNodeThreatsEliminated* newNode = new ListNodeThreatsEliminated{threatsEliminated, arrayID, nullptr, nullptr};
        return newNode;
    }

    // Для сортировки по убыванию меняем условие вставки
    if (threatsEliminated >= node->threatsEliminated)
        node->left = insertThreatsEliminated(node->left, threatsEliminated, arrayID);
    else
        node->right = insertThreatsEliminated(node->right, threatsEliminated, arrayID);

    return node;
}

void buildIndexByLastName(StationReport *&reports, ListNodeLastName *&indexRoot, int size) {
    for(int i = 0; i < size; i++) {
        indexRoot = insertLastName(indexRoot, reports[i].lastName, i);
    }
}

void buildIndexByThreatsEliminated(StationReport *&reports, ListNodeThreatsEliminated *&indexRoot, int size) {
    for(int i = 0; i < size; i++) {
        indexRoot = insertThreatsEliminated(indexRoot, reports[i].threatsEliminated, i);
    }
}



