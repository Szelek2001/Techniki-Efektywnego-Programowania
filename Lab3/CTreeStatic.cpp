#include "CTreeStatic.h"

using namespace std;

// metody CTree

CTreeStatic::~CTreeStatic() {

}

void CTreeStatic::vPrintTree() {
    this->pcGetRoot()->vPrintAllBelow();
}


bool CTreeStatic::bMoveSubtree(CNodeStatic *pcParentNode, CNodeStatic *pcNewChildNode) {
    if (pcParentNode == NULL || pcNewChildNode == NULL) {
        return false;
    }
    if (pcParentNode->pcGetRootFromNode() == pcNewChildNode->pcGetRootFromNode()) {
        return false;
    }

    pcParentNode->getVChildren()->push_back(*pcNewChildNode);
    if(pcNewChildNode->getPcParentNode() !=NULL)
    for (int i = 0; i < pcNewChildNode->getPcParentNode()->iGetChildrenNumber(); i++) {
        if (pcNewChildNode->getPcParentNode()->pcGetChild(i) == pcNewChildNode) {
            pcNewChildNode->getPcParentNode()->vDeleteChild(i);
        }
    }

    pcParentNode->vUpdateParents();


    return true;
}


// metody CNode

vector<CNodeStatic> *CNodeStatic::getVChildren() {
    return &v_children;
}

void CNodeStatic::vUpdateParents() {
    for (int i = 0; i < v_children.size(); i++) {
        v_children.at(i).setPcParentNode(this);
        v_children.at(i).vUpdateParents();
    }
}

void CNodeStatic::setPcParentNode(CNodeStatic *pcParentNode) {
    pc_parent_node = pcParentNode;
}

void CNodeStatic::vDeleteChild(int iChildOffset) {
    this->v_children.erase(v_children.begin() + iChildOffset);
}

CNodeStatic::~CNodeStatic() {

}

void CNodeStatic::vAddNewChild() {
    CNodeStatic newChild;

    newChild.pc_parent_node = this;
    this->v_children.push_back(newChild);
}

CNodeStatic *CNodeStatic::pcGetChild(int iChildOffset) {
    if (iChildOffset < 0 || iChildOffset >= this->iGetChildrenNumber()) {
        return NULL;
    }

    return &(this->v_children[iChildOffset]);
}

CNodeStatic *CNodeStatic::getPcParentNode() const {
    return pc_parent_node;
}

void CNodeStatic::vPrintAllBelow() {
    this->vPrint();
    for (int i = 0; i < this->iGetChildrenNumber(); i++) {
        this->v_children[i].vPrintAllBelow();
    }
}

void CNodeStatic::vPrintUp() {
    this->vPrint();
    if (this->pc_parent_node != NULL) {
        this->pc_parent_node->vPrintUp();
    }
}

CNodeStatic *CNodeStatic::pcGetRootFromNode() {
    if (this->getPcParentNode() == NULL) {
        return this;
    } else {
        return this->getPcParentNode()->pcGetRootFromNode();
    }
}