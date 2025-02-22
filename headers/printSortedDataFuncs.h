#ifndef PRINTSORTEDDATAFUNCS_H
#define PRINTSORTEDDATAFUNCS_H

#include <stationReport.h>
#include <binTreeFuncs.h>

void printSortedByLastName(ListNodeLastName *root);

void printSortedByThreatsEliminated(ListNodeThreatsEliminated *root);

void printSortedArrayByLastName(ListNodeLastName *root, StationReport *reports);

void printSortedArrayByThreatsEliminated(ListNodeThreatsEliminated *root, StationReport *reports);

void printSourceArray(StationReport *reports, int size);


#endif //PRINTSORTEDDATAFUNCS_H
