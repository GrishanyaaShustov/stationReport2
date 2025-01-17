#ifndef BINTREESEARCHFUNCS_H
#define BINTREESEARCHFUNCS_H
#include "stationReport.h"

ListNodeLastName* searchByLastName(ListNodeLastName* root, std::string lastName);
ListNodeThreatsEliminated* searchByThreatsEliminated(ListNodeThreatsEliminated* root, unsigned int threatsEliminated);

#endif //BINTREESEARCHFUNCS_H
