#ifndef BINTREESEARCHFUNCS_H
#define BINTREESEARCHFUNCS_H
#include "stationReport.h"

ListNodeLastName **searchByLastName(ListNodeLastName *root, std::string lastName, ListNodeLastName *parent);

ListNodeThreatsEliminated **searchByThreatsEliminated(ListNodeThreatsEliminated *root, unsigned int threatsEliminated, ListNodeThreatsEliminated *parent);

#endif //BINTREESEARCHFUNCS_H
