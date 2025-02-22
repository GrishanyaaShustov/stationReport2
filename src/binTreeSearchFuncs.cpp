#include "binTreeSearchFuncs.h"

ListNodeLastName **searchByLastName(ListNodeLastName *root, std::string lastName, ListNodeLastName *parent = nullptr)
{
    auto *rootParentArray = new ListNodeLastName*[2];
    if (!root || root->lastName == lastName) {
        rootParentArray[0] = root;
        rootParentArray[1] = parent;
        return rootParentArray;
    }
    if (lastName < root->lastName) {
        return searchByLastName(root->left, lastName, root);
    } else {
        return searchByLastName(root->right, lastName, root);
    }
}

ListNodeThreatsEliminated **searchByThreatsEliminated(ListNodeThreatsEliminated *root, unsigned int threatsEliminated, ListNodeThreatsEliminated *parent = nullptr) {
    auto *rootParentArray = new ListNodeThreatsEliminated*[2];
    if (!root || root->threatsEliminated == threatsEliminated) {
        rootParentArray[0] = root;
        rootParentArray[1] = parent;
        return rootParentArray;
    }
    if (threatsEliminated > root->threatsEliminated) {
        return searchByThreatsEliminated(root->left, threatsEliminated, root);
    } else {
        return searchByThreatsEliminated(root->right, threatsEliminated, root);
    }
}
