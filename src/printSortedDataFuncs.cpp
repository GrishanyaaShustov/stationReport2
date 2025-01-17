#include <iostream>
#include <stationReport.h>

void printSortedByLastName(ListNodeLastName* root) {
    if(root!=nullptr) {
        printSortedByLastName(root->left);
        std::cout << "Last name: " << root->lastName << "(index: " << root->arrayID << ")" <<std::endl;
        printSortedByLastName(root->right);
    }
}

void printSortedByThreatsEliminated(ListNodeThreatsEliminated *root) {
    if(root!=nullptr) {
        printSortedByThreatsEliminated(root->left);
        std::cout << "Threats eliminated: " << root->threatsEliminated << "(index: " << root->arrayID << ")" <<std::endl;
        printSortedByThreatsEliminated(root->right);
    }
}

void printSortedArrayByLastName(ListNodeLastName* root, StationReport* reports) {
    if (root != nullptr) {
        // Обходим левое поддерево
        printSortedArrayByLastName(root->left, reports);

        // Выводим данные текущего узла
        int idx = root->arrayID;
        std::cout << reports[idx].reportIndex << ", "
                  << reports[idx].stationNumber << ", "
                  << reports[idx].firstName << ", "
                  << reports[idx].lastName << ", "
                  << reports[idx].rank << ", "
                  << reports[idx].airTemperature << ", "
                  << reports[idx].windSpeed << ", "
                  << reports[idx].threatsEliminated << ", "
                  << (reports[idx].reportDate.tm_year + 1900) << "-"
                  << (reports[idx].reportDate.tm_mon + 1) << "-"
                  << reports[idx].reportDate.tm_mday << ", "
                  << reports[idx].reportTimeSeconds << std::endl;

        // Обходим правое поддерево
        printSortedArrayByLastName(root->right, reports);
    }
}

void printSortedArrayByThreatsEliminated(ListNodeThreatsEliminated* root, StationReport* reports) {
    if (root != nullptr) {
        // Обходим правое поддерево (меньшие значения)
        printSortedArrayByThreatsEliminated(root->left, reports);

        // Выводим данные текущего узла
        int idx = root->arrayID;
        std::cout << reports[idx].reportIndex << ", "
                  << reports[idx].stationNumber << ", "
                  << reports[idx].firstName << ", "
                  << reports[idx].lastName << ", "
                  << reports[idx].rank << ", "
                  << reports[idx].airTemperature << ", "
                  << reports[idx].windSpeed << ", "
                  << reports[idx].threatsEliminated << ", "
                  << (reports[idx].reportDate.tm_year + 1900) << "-"
                  << (reports[idx].reportDate.tm_mon + 1) << "-"
                  << reports[idx].reportDate.tm_mday << ", "
                  << reports[idx].reportTimeSeconds << std::endl;

        // Обходим левое поддерево (большие значения)
        printSortedArrayByThreatsEliminated(root->right, reports);
    }
}

void printSourceArray(StationReport* reports, int size) {
    std::cout << "\n" << std::endl;
    std::cout << "_____Source Data______" << std::endl;
    for(int idx = 0; idx < size; idx ++) {
        std::cout << reports[idx].reportIndex << ", "
                  << reports[idx].stationNumber << ", "
                  << reports[idx].firstName << ", "
                  << reports[idx].lastName << ", "
                  << reports[idx].rank << ", "
                  << reports[idx].airTemperature << ", "
                  << reports[idx].windSpeed << ", "
                  << reports[idx].threatsEliminated << ", "
                  << (reports[idx].reportDate.tm_year + 1900) << "-"
                  << (reports[idx].reportDate.tm_mon + 1) << "-"
                  << reports[idx].reportDate.tm_mday << ", "
                  << reports[idx].reportTimeSeconds << std::endl;
    }
}