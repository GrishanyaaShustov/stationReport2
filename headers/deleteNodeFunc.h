#ifndef DELETENODEFUNC_H
#define DELETENODEFUNC_H

#include "stationReport.h"

ListNodeLastName* findMin(ListNodeLastName *root);

ListNodeThreatsEliminated* findMinThreatsEliminated(ListNodeThreatsEliminated *root);

ListNodeLastName* deleteNodeFromLastNameTree(ListNodeLastName *root, const std::string &lastName);

ListNodeThreatsEliminated* deleteNodeFromThreatsEliminatedTree(ListNodeThreatsEliminated *root, unsigned int threatsEliminated);

void deleteTree(ListNodeLastName *root);

void deleteTree(ListNodeThreatsEliminated *root);

void deleteNodeFunc(StationReport *&sourceReports, ListNodeLastName *&lastNameIndexRoot, ListNodeThreatsEliminated *&threatsEliminatedIndexRoot, int reportId, int &size);

#endif //DELETENODEFUNC_H
