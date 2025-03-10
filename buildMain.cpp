#include "buildMain.h"
#include <limits>
#include "binTreeSearchFuncs.h"
#include "printSortedDataFuncs.h"
#include "deleteNodeFunc.h"

void printSortedData(ListNodeLastName *lastNameIndexRoot, ListNodeThreatsEliminated *threatsEliminatedIndexRoot,
                     StationReport *reports, int size) {
    std::cout << "\nChoose sorting key: " << std::endl;
    std::cout << "1. Last name (increasing order)" << std::endl;
    std::cout << "2. Quantity eliminated threats (decreasing order)" << std::endl;
    std::cout << "Your choice: ";

    int choice;

    if (!(std::cin >> choice) || (choice != 1 && choice != 2)) {
        std::cout << "Invalid Input. Returning to main menu." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    printSourceArray(reports, size);
    if (choice == 1) {
        std::cout << "_____Indexes BinTree By Last Name______" << std::endl;
        printSortedByLastName(lastNameIndexRoot);
        std::cout << "_____Sorted By Last Name Data Array______" << std::endl;
        printSortedArrayByLastName(lastNameIndexRoot, reports);
    } else {
        std::cout << "_____Indexes BinTree By Threats Eliminated______" << std::endl;
        printSortedByThreatsEliminated(threatsEliminatedIndexRoot);
        std::cout << "_____Sorted By Last Name Data Array______" << std::endl;
        printSortedArrayByThreatsEliminated(threatsEliminatedIndexRoot, reports);
    }
}

void searchDataByKey(ListNodeLastName *indexByLastName, ListNodeThreatsEliminated *indexByThreatsEliminated,
                     StationReport *sourceReports) {
    ListNodeLastName **searchResultLastName;
    ListNodeThreatsEliminated **searchResultThreatsEliminated;
    std::string lastName;
    int threadsEliminated;

    std::cout << "\nChoose searching key: " << std::endl;
    std::cout << "1. Last name" << std::endl;
    std::cout << "2. Quantity eliminated threats" << std::endl;
    std::cout << "Your choice: ";

    int choice;
    if (!(std::cin >> choice) || (choice != 1 && choice != 2)) {
        std::cout << "Invalid Input. Returning to main menu." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    switch (choice) {
        case 1:
            std::cout << "Enter key - last name: ";
            std::cin >> lastName;
            searchResultLastName = searchByLastName(indexByLastName, lastName, nullptr);
            if (searchResultLastName[0]) {
                std::cout << "\nRecord is found!\n" << std::endl;
                sourceReports[searchResultLastName[0]->arrayID].print();
                delete[] searchResultLastName;
            } else std::cout << "\nRecord is not found =(" << std::endl;
            break;

        case 2:
            std::cout << "Enter key - threats eliminated quantity: ";
            while (!(std::cin >> threadsEliminated) || choice < 0) {
                std::cout << "Invalid Input. Try again." << std::endl;
                std::cout << "Enter key - threats eliminated quantity: ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            searchResultThreatsEliminated = searchByThreatsEliminated(indexByThreatsEliminated, threadsEliminated, nullptr);
            if (searchResultThreatsEliminated[0]) {
                std::cout << "\nRecord is found!\n" << std::endl;
                sourceReports[searchResultThreatsEliminated[0]->arrayID].print();
                delete[] searchResultThreatsEliminated;
            } else std::cout << "\nRecord is not found =(" << std::endl;
            break;
    }
}

void deleteNodeByKeyValue(StationReport *&sourceReports, ListNodeLastName *&lastNameIndexRoot, ListNodeThreatsEliminated *&threatsEliminatedIndexRoot, int &size) {
    std::string lastName;
    unsigned int threatsEliminated;
    ListNodeLastName **searchResultLastName = nullptr;
    ListNodeThreatsEliminated **searchResultThreatsEliminated = nullptr;

    std::cout << "\nChoose deleting key: " << std::endl;
    std::cout << "1. Last name" << std::endl;
    std::cout << "2. Quantity eliminated threats" << std::endl;
    std::cout << "Your choice: ";
    int choice;
    if (!(std::cin >> choice) || (choice != 1 && choice != 2)) {
        std::cout << "Invalid Input. Returning to main menu." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    switch (choice) {
        case 1:
            std::cout << "Enter key - last name: ";
            std::cin >> lastName;
            searchResultLastName = searchByLastName(lastNameIndexRoot, lastName, nullptr);
            if (searchResultLastName[0]) {
                std::cout << "\nRecord is found!\n" << std::endl;
                int searchID = searchResultLastName[0]->arrayID;
                deleteNodeFunc(sourceReports, lastNameIndexRoot, threatsEliminatedIndexRoot, searchID, size);
                lastNameIndexRoot = deleteNodeFromLastNameTree(lastNameIndexRoot, lastName);
                std::cout << "Record deleted!\n" << std::endl;
            } else {
                std::cout << "\nRecord is not found =(\n" << std::endl;
            }
            break;

        case 2:
            std::cout << "Enter key - threats eliminated quantity: ";
            while (!(std::cin >> threatsEliminated) || threatsEliminated < 0) {
                std::cout << "Invalid Input. Try again." << std::endl;
                std::cout << "Enter key - threats eliminated quantity: ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            searchResultThreatsEliminated = searchByThreatsEliminated(threatsEliminatedIndexRoot, threatsEliminated, nullptr);
            if (searchResultThreatsEliminated[0]) {
                std::cout << "Record is found!" << std::endl;
                int searchID = searchResultThreatsEliminated[0]->arrayID;
                deleteNodeFunc(sourceReports, lastNameIndexRoot, threatsEliminatedIndexRoot, searchID, size);
                threatsEliminatedIndexRoot = deleteNodeFromThreatsEliminatedTree(threatsEliminatedIndexRoot, threatsEliminated);
                std::cout << "Record deleted!\n" << std::endl;
            } else {
                std::cout << "Record is not found =(" << std::endl;
            }
            break;

        default:
            break;
    }

    // Освобождаем память для результатов поиска
    if (searchResultLastName) delete[] searchResultLastName;
    if (searchResultThreatsEliminated) delete[] searchResultThreatsEliminated;
}


void printAllRecords(StationReport *reports, int size) {
    std::cout << std::string(80, '-') << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << "\nRecord #" << i + 1 << ": " << std::endl;
        reports[i].print();
        std::cout << std::string(80, '-') << std::endl;
    }
}


void cleanMemmory(StationReport *reports, ListNodeLastName *indexByLastName,
                  ListNodeThreatsEliminated *indexByThreatsEliminated) {
    delete[] reports;
    delete indexByLastName;
    delete indexByThreatsEliminated;
    std::cout << "Exiting program...";
};
