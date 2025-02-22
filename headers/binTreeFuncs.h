#ifndef BINTREEFUNCS_H
#define BINTREEFUNCS_H
#include "stationReport.h"

ListNodeLastName *insertLastName(ListNodeLastName *node, std::string lastName, int arrayID);

ListNodeThreatsEliminated *insertThreatsEliminated(ListNodeThreatsEliminated *node, unsigned int threatsEliminated,
                                                   int arrayID);

void buildIndexByLastName(StationReport *&reports, ListNodeLastName *&indexRoot, int size);

void buildIndexByThreatsEliminated(StationReport *&reports, ListNodeThreatsEliminated *&indexRoot, int size);

#endif //BINTREEFUNCS_H
