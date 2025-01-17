#include "binTreeSearchFuncs.h"

ListNodeLastName* searchByLastName(ListNodeLastName *root, std::string lastName) {
    if(!root || root->lastName == lastName) {
        return root;
    }
    if(lastName < root->lastName) {
        return searchByLastName(root->left, lastName);
    }
    else {
        return searchByLastName(root->right, lastName);
    }
}

ListNodeThreatsEliminated* searchByThreatsEliminated(ListNodeThreatsEliminated *root, unsigned int threatsEliminated) {
    if(!root || root->threatsEliminated == threatsEliminated) {
        return root;
    }
    if(threatsEliminated > root->threatsEliminated) {
        return searchByThreatsEliminated(root->left, threatsEliminated);
    }
    else {
        return searchByThreatsEliminated(root->right, threatsEliminated);
    }
}


