#ifndef C_NODE_DYN
#define C_NODE_DYN
using namespace std;

#include <iostream>
#include <vector>
#include <queue>

class CTreeDynamic;

class CNodeDynamic {
public:
    CNodeDynamic() {
        i_val = 0;
        pc_parent_node = NULL;
    };

    ~CNodeDynamic();

    void vSetValue(int iNewVal) { i_val = iNewVal; };

    void vSetParent(CNodeDynamic *newParent);

    CNodeDynamic *getParent();

    int getValue();

    int iGetChildrenNumber() { return (v_children.size()); };

    void vAddNewChild();

    void vAddChild(CNodeDynamic *newChild);

    CNodeDynamic *pcGetChild(int iChildOffset);

    void deleteChild(int iChildOffset);

    CNodeDynamic *pcGetRootFromNode();

    void vPrint() { cout << " " << i_val; };

    void vPrintAllBelow();

    void vPrintUp();

private:
    vector<CNodeDynamic *> v_children;
    CNodeDynamic *pc_parent_node;
    int i_val;

};//class  CNodeDynamic

#endif

#ifndef C_TREE_DYN
#define C_TREE_DYN

class CTreeDynamic {
public:
    CTreeDynamic();

    CTreeDynamic(CNodeDynamic *root);

    ~CTreeDynamic();

    CNodeDynamic *pcGetRoot() { return (pc_root); }

    void vPrintTree();

    bool bMoveSubtree(CNodeDynamic *pcParentNode, CNodeDynamic *pcNewChildNode);

    void printTreeInRows();

private:
    CNodeDynamic *pc_root;


};//class  CTreeDynamic

#endif