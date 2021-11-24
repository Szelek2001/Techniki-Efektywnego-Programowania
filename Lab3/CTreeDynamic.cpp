#include "CTreeDynamic.h"

// destruktor wezla
CNodeDynamic::~CNodeDynamic() {
    for (int i = 0; i < this->iGetChildrenNumber(); i++) {
        delete this->v_children[i];
    }
}

// metody wezla

void CNodeDynamic::vSetParent(CNodeDynamic *newParent) {
    this->pc_parent_node = newParent;
}

CNodeDynamic *CNodeDynamic::getParent() {
    return this->pc_parent_node;
}

int CNodeDynamic::getValue() {
    return this->i_val;
}

void CNodeDynamic::vAddNewChild() {
    CNodeDynamic *newChildNode = new CNodeDynamic();
    vAddChild(newChildNode);
}

void CNodeDynamic::vAddChild(CNodeDynamic *newChild) {
    newChild->pc_parent_node = this;
    this->v_children.push_back(newChild);
}

void CNodeDynamic::deleteChild(int iChildOffset) {
    this->v_children.erase(v_children.begin() + iChildOffset);
}

CNodeDynamic *CNodeDynamic::pcGetChild(int iChildOffset) {
    if (iChildOffset < 0 || iChildOffset >= this->iGetChildrenNumber()) {
        return NULL;
    }

    return v_children[iChildOffset];
}

CNodeDynamic *CNodeDynamic::pcGetRootFromNode() {
    if (this->getParent() == NULL) {
        return this;
    } else {
        return this->getParent()->pcGetRootFromNode();
    }
}

void CNodeDynamic::vPrintUp() {
    this->vPrint();
    if (this->pc_parent_node != NULL) {
        this->pc_parent_node->vPrintUp();
    }
}

void CNodeDynamic::vPrintAllBelow() {
    this->vPrint();
    for (int i = 0; i < this->iGetChildrenNumber(); i++) {
        this->v_children[i]->vPrintAllBelow();
    }
}

// konstruktory drzewa
CTreeDynamic::CTreeDynamic() {
    pc_root = new CNodeDynamic();
}

CTreeDynamic::CTreeDynamic(CNodeDynamic *root) {
    pc_root = root;
}

// destruktor drzewa
CTreeDynamic::~CTreeDynamic() {
    delete pc_root;
}

// metody drzewa
void CTreeDynamic::vPrintTree() {
    this->pcGetRoot()->vPrintAllBelow();
}

bool CTreeDynamic::bMoveSubtree(CNodeDynamic *pcParentNode, CNodeDynamic *pcNewChildNode) {
    // sprawdzenie czy wezly nie sa nullem
    if (pcParentNode == NULL || pcNewChildNode == NULL) {
        return false;
    }

    // sprawdzenie czy wezly nie naleza do tego samego drzewa
    if (pcParentNode->pcGetRootFromNode() == pcNewChildNode->pcGetRootFromNode()) {
        return false;
    }
        if(pcNewChildNode->getParent()==NULL)
            return false;

    if (pcNewChildNode->getParent() != NULL)
        for (int i = 0; i < pcNewChildNode->getParent()->iGetChildrenNumber(); i++) {
            if (pcNewChildNode->getParent()->pcGetChild(i) == pcNewChildNode) {
                pcNewChildNode->getParent()->deleteChild(i);
            }
        }


    pcParentNode->vAddChild(pcNewChildNode);
    pcNewChildNode->vSetParent(pcParentNode);

    return true;

}

void CTreeDynamic::printTreeInRows() {
    queue < CNodeDynamic * > q;

    int childrenInNextRow = 0, childrenToPrint = 1;

    q.push(this->pc_root);


    while (!q.empty()) {

        CNodeDynamic *act = q.front();
        q.pop();
        act->vPrint();
        childrenToPrint--;

        for (int i = 0; i < act->iGetChildrenNumber(); i++) {
            q.push(act->pcGetChild(i));
        }

        childrenInNextRow += act->iGetChildrenNumber();
        if (childrenToPrint == 0) {
            cout << "\n";
            childrenToPrint = childrenInNextRow;
            childrenInNextRow = 0;
        }

    }
}