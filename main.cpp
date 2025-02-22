#include <iostream>
#include <limits>
#include "createReportsArray.h"
#include "stationReport.h"
#include "binTreeFuncs.h"
#include "binTreeSearchFuncs.h"
#include "buildMain.h"
#include "printSortedDataFuncs.h"
#include "deleteNodeFunc.h"


int size = 4;
// StationReport report1 = {1, 1, "Grigoriy", "Shustov", "Senior inspector", 32.5, 12.1, 4, getDate(2024, 12, 24), 80000};
// StationReport report2 = {2, 3, "Ivan", "Ivanov", "Junior inspector", 31.2, 9.1, 2, getDate(2024, 12, 21), 72000};
// StationReport report3 = {3, 2, "Petr", "Petrov", "Firefighter", 21, 4, 3, getDate(2024, 12, 12), 77777};
// StationReport report4 = {4, 32, "Magnus", "Carlsen", "Senior inspector", 12, 1.8, 9, getDate(2025, 1, 1), 69321};
// StationReport *sourceReports = {new StationReport[size]{report1, report2, report3, report4}};

int main() {
    StationReport *sourceReports = createReportsArray(size);
    ListNodeLastName *lastNameIndexRoot = nullptr;
    ListNodeThreatsEliminated *threatsEliminatedIndexRoot = nullptr;

    buildIndexByLastName(sourceReports, lastNameIndexRoot, size);
    buildIndexByThreatsEliminated(sourceReports, threatsEliminatedIndexRoot, size);

    while (true) {
        std::cout << "\nChoose task: " << std::endl;
        std::cout << "1. Print sorted data" << std::endl;
        std::cout << "2. Search array record by traversing a binary index tree" << std::endl;
        std::cout << "3. Remove array record by key value" << std::endl;
        std::cout << "4. Print all records" << std::endl;
        std::cout << "5. Exit program" << std::endl;

        std::cout << "Enter task number: ";
        int choice;
        if (!(std::cin >> choice)) {
            std::cout << "Invalid input. Please enter a valid integer.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                printSortedData(lastNameIndexRoot, threatsEliminatedIndexRoot, sourceReports, size);
                break;
            case 2:
                searchDataByKey(lastNameIndexRoot, threatsEliminatedIndexRoot, sourceReports);
                break;
            case 3:
                deleteNodeByKeyValue(sourceReports, lastNameIndexRoot, threatsEliminatedIndexRoot, size);
                break;
            case 4:
                printAllRecords(sourceReports, size);
                break;
            case 5:
                cleanMemmory(sourceReports, lastNameIndexRoot, threatsEliminatedIndexRoot);
                break;
            default:
                std::cout << "Incorrect choice, try again.\n";
                break;
        }
    }
}
