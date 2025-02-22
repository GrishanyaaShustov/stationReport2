#ifndef BUILDMAIN_H
#define BUILDMAIN_H

#include <iostream>
#include "stationReport.h"

void printSortedData(ListNodeLastName *, ListNodeThreatsEliminated *, StationReport *, int);

void searchDataByKey(ListNodeLastName *, ListNodeThreatsEliminated *, StationReport *);

void deleteNodeByKeyValue(StationReport *&sourceReports, ListNodeLastName *&lastNameIndexRoot, ListNodeThreatsEliminated *&threatsEliminatedIndexRoot, int &size);

void printAllRecords(StationReport *, int);

void cleanMemmory(StationReport *, ListNodeLastName *, ListNodeThreatsEliminated *);

#endif //BUILDMAIN_H
