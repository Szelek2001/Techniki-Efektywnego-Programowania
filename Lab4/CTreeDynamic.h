//
// Created by Konrad on 14.11.2021.
//

#ifndef TEP_LIST3_CTREEDYNAMIC_H
#define TEP_LIST3_CTREEDYNAMIC_H

#include <vector>
#include <iostream>
#include <queue>

using namespace std;


template<typename T>
class CNodeDynamic {
public:
    CNodeDynamic() { val = T();
        pc_parent_node = NULL; };

    ~CNodeDynamic();

    void vSetValue(T iNewVal) { val = iNewVal; };

    T iGetValue() { return val; }

    void vSetParentNode(CNodeDynamic *parentNode) { this->pc_parent_node = parentNode; };

    int iGetChildrenNumber() { return (v_children.size()); };

    void vAddNewChild();

    void vAddChild(CNodeDynamic *newChild);

    void vDeleteChild(int iChildOffset);

    CNodeDynamic<T> *pcGetChild(int iChildOffset);

    CNodeDynamic<T> *pcGetRoot();

    CNodeDynamic<T> *pcGetParent() { return pc_parent_node; };

    vector<CNodeDynamic<T> *> *vGetChildren() { return &v_children; };

    void vDeleteNodeDown(int val);

    T sum();

    void vPrint() { cout << " " << val; };

    void vPrintAllBelow();

    void vPrintUp();


private:
    vector<CNodeDynamic<T> *> v_children;
    CNodeDynamic<T> *pc_parent_node;
    T val;
};
// END CLASS C_NODE_DYNAMIC

template<typename T>
class CTreeDynamic {
public:
    CTreeDynamic() { pc_root = new CNodeDynamic<T>(); };

    ~CTreeDynamic();

    CNodeDynamic<T> *pcGetRoot() { return (pc_root); }

    void vPrintTree() { pc_root->vPrintAllBelow(); };

    void vPrintTreeInRows();

    void vDeleteNode(int val);

    //CTreeDynamic *cMultiplyTree(CTreeDynamic *tree);
    bool bMoveSubtree(CNodeDynamic<T> *pcParentNode, CNodeDynamic<T> *pcNewChildNode);

    T *sum();

private:
    CNodeDynamic<T> *pc_root;

};

//END CLASS C_TREE_DYNAMIC
template<typename T>
CNodeDynamic<T>::~CNodeDynamic() {
    for (int i = 0; i < this->v_children.size(); i++)
        delete v_children.at(i);
}

template<typename T>
void CNodeDynamic<T>::vAddNewChild() {
    CNodeDynamic *node = new CNodeDynamic();
    node->vSetParentNode(this);
    this->v_children.push_back(node);
}

template<typename T>
CNodeDynamic<T> *CNodeDynamic<T>::pcGetChild(int iChildOffset) {
    if (iChildOffset < 0 || iChildOffset >= this->v_children.size())
        return NULL;
    else
        return this->v_children.at(iChildOffset);
}

template<typename T>
void CNodeDynamic<T>::vPrintAllBelow() {
    this->vPrint();
    for (int i = 0; i < this->v_children.size(); i++)
        this->v_children.at(i)->vPrintAllBelow();
}

template<typename T>
void CNodeDynamic<T>::vPrintUp() {
    this->vPrint();
    if (this->pc_parent_node != NULL)
        this->pc_parent_node->vPrintUp();
}

template<typename T>
CNodeDynamic<T> *CNodeDynamic<T>::pcGetRoot() {
    if (this->pc_parent_node != NULL)
        return this->pc_parent_node->pcGetRoot();
    else
        return this;
}

template<typename T>
void CNodeDynamic<T>::vAddChild(CNodeDynamic<T> *pcNewChild) {
    pcNewChild->pc_parent_node = this;
    this->v_children.push_back(pcNewChild);
}

template<typename T>
void CNodeDynamic<T>::vDeleteChild(int iChildOffset) {
    this->v_children.erase(v_children.begin() + iChildOffset);
}

template<typename T>
void CNodeDynamic<T>::vDeleteNodeDown(int val) {
    for (int i = v_children.size() - 1; i >= 0; i--) {
        v_children[i]->vDeleteNodeDown(val);

        if (v_children[i]->i_val == val) {
            for (int ii = v_children[i]->v_children.size() - 1; ii >= 0; ii--) {
                v_children[i]->v_children[ii]->vSetParentNode(this);
                this->vAddChild(v_children[i]->v_children[ii]);
            }
            this->vDeleteChild(i);
        }
    }
}

template<typename T>
T CNodeDynamic<T>::sum() {
    return NULL;
}

template<>
int CNodeDynamic<int>::sum() {
    int s = val;
    for (int i = 0; i < v_children.size(); i++) {
        s += v_children.at(i)->sum();
    }
    return s;
}

template<>
double CNodeDynamic<double>::sum() {
    double s = val;
    for (int i = 0; i < v_children.size(); i++) {
        s += v_children.at(i)->sum();
    }

    return s;
}

template<typename T>
CTreeDynamic<T>::~CTreeDynamic() {
    delete pc_root;
}

template<typename T>
bool CTreeDynamic<T>::bMoveSubtree(CNodeDynamic<T> *pcParentNode, CNodeDynamic<T> *pcNewChildNode) {
    if (pcNewChildNode == NULL || pcParentNode == NULL)
        return false;
    if (this->pcGetRoot() != pcParentNode->pcGetRoot())
        return false;
    if (pcNewChildNode->pcGetParent() == NULL)
        return false;

    if (pcNewChildNode->pcGetParent() != NULL) {
        for (int i = 0; i < pcNewChildNode->pcGetParent()->iGetChildrenNumber(); i++) {
            if (pcNewChildNode->pcGetParent()->pcGetChild(i) == pcNewChildNode)
                pcNewChildNode->pcGetParent()->vDeleteChild(i);
        }
    }

    pcParentNode->vAddChild(pcNewChildNode);
    return true;
}

template<typename T>
void CTreeDynamic<T>::vPrintTreeInRows() {
    queue < CNodeDynamic<T> * > q;

    int childrenInNextRow = 0, childrenToPrint = 1;

    q.push(this->pc_root);


    while (!q.empty()) {

        CNodeDynamic<T> *act = q.front();
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

    }}

template<typename T>
void CTreeDynamic<T>::vDeleteNode(int val) {
    pc_root->vDeleteNodeDown(val);
}

template<typename T>
T *CTreeDynamic<T>::sum() {
    return NULL;
}

template<>
int *CTreeDynamic<int>::sum() {
    int *s = new int;
    *s = pc_root->sum();
    return s;
}

template<>
double *CTreeDynamic<double>::sum() {
    double *s = new double;
    *s = pc_root->sum();
    return s;
}


#endif //TEP_LIST3_CTREEDYNAMIC_H
