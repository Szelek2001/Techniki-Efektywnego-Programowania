#include <iostream>
#include <vector>

using namespace std;


class CNodeStatic {
public:
    CNodeStatic() {
        i_val = 0;
        pc_parent_node = NULL;
    };

    ~CNodeStatic();

    void vSetValue(int iNewVal) { i_val = iNewVal; };

    int iGetChildrenNumber() { return (v_children.size()); };

    void vAddNewChild();

    CNodeStatic *pcGetChild(int iChildOffset);

    void vPrint() { cout << " " << i_val; };

    void vPrintAllBelow();

    void vPrintUp();

    CNodeStatic *pcGetRootFromNode();

    CNodeStatic *getPcParentNode() const;

    void vDeleteChild(int iChildOffset);

    void vUpdateParents();

    void setPcParentNode(CNodeStatic *pcParentNode);

    vector<CNodeStatic> *getVChildren();


private:
    vector<CNodeStatic> v_children;
    CNodeStatic *pc_parent_node;
    int i_val;

};//class  CNodeStatic

class CTreeStatic {
public:
    CTreeStatic() { c_root = CNodeStatic(); };

    ~CTreeStatic();

    CNodeStatic *pcGetRoot() { return (&c_root); };

    void vPrintTree();

    bool bMoveSubtree(CNodeStatic *pcParentNode, CNodeStatic *pcNewChildNode);

private:
    CNodeStatic c_root;
};//class  CTreeStatic
