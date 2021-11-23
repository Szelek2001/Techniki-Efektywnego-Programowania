#include "CNodeDynamic.h"

// destruktor wezla
CNodeDynamic::~CNodeDynamic() {
    for (int i = 0; i < this->iGetChildrenNumber(); i++) {
        delete this->v_children[i];
    }
    this->v_children.clear();
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


    if(pcNewChildNode->getParent() != NULL)
        for (int i = 0; i < pcNewChildNode->getParent()->iGetChildrenNumber(); i++) {
        if (pcNewChildNode->getParent()->pcGetChild(i) == pcNewChildNode) {
            pcNewChildNode->getParent()->deleteChild(i);
        }
    }


    pcParentNode->vAddChild(pcNewChildNode);
    pcNewChildNode->vSetParent(pcParentNode);

    return true;

}