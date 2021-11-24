#include "CTreeStatic.h"
#include "CTreeDynamic.h"

void v_static_tree_test() {
    cout << "Operacje na wezle";
    CNodeStatic c_root;


    c_root.vAddNewChild();

    c_root.vAddNewChild();


    c_root.pcGetChild(0)->vSetValue(1);

    c_root.pcGetChild(1)->vSetValue(2);


    c_root.pcGetChild(0)->vAddNewChild();

    c_root.pcGetChild(0)->vAddNewChild();


    c_root.pcGetChild(0)->pcGetChild(0)->vSetValue(11);
    c_root.pcGetChild(0)->pcGetChild(1)->vSetValue(12);


    c_root.pcGetChild(1)->vAddNewChild();

    c_root.pcGetChild(1)->vAddNewChild();


    c_root.pcGetChild(1)->pcGetChild(0)->vSetValue(21);
    c_root.pcGetChild(1)->pcGetChild(1)->vSetValue(22);

    // print below
    c_root.vPrintAllBelow();

    //print up
    cout << "\n\n";
    c_root.pcGetChild(0)->pcGetChild(1)->vPrintUp();
    cout << "\n\n";
    c_root.pcGetChild(1)->pcGetChild(1)->vPrintUp();

    cout << "\nOperacje na drzewie";

    CTreeStatic c_tree;
    c_tree.pcGetRoot()->vSetValue(66);
    c_tree.pcGetRoot()->vAddNewChild();
    c_tree.pcGetRoot()->vAddNewChild();

    c_tree.pcGetRoot()->pcGetChild(0)->vSetValue(77);
    c_tree.pcGetRoot()->pcGetChild(1)->vSetValue(88);

    c_tree.vPrintTree();
    cout << "\n\n";
    c_tree.pcGetRoot()->pcGetChild(0)->vPrintUp();

}//void  v_static_tree_test()

void v_dynamic_tree_test() {
    CTreeDynamic treeDynamic;

    treeDynamic.pcGetRoot()->vSetValue(33);
    treeDynamic.pcGetRoot()->vAddNewChild();
    treeDynamic.pcGetRoot()->vAddNewChild();

    treeDynamic.pcGetRoot()->pcGetChild(0)->vSetValue(44);
    treeDynamic.pcGetRoot()->pcGetChild(1)->vSetValue(55);

    cout << "\nTest metody vPrintTree\n";
    treeDynamic.vPrintTree();

    cout << "\nTest metody vPrintAllBelow:\n";
    treeDynamic.pcGetRoot()->vPrintAllBelow();

}//void v_dynamic_tree_test()

void v_subtree_dynamic_test() {
    CTreeDynamic tree1;

    tree1.pcGetRoot()->vSetValue(0);

    tree1.pcGetRoot()->vAddNewChild();
    tree1.pcGetRoot()->vAddNewChild();
    tree1.pcGetRoot()->vAddNewChild();

    tree1.pcGetRoot()->pcGetChild(0)->vSetValue(1);
    tree1.pcGetRoot()->pcGetChild(1)->vSetValue(2);
    tree1.pcGetRoot()->pcGetChild(2)->vSetValue(3);

    tree1.pcGetRoot()->pcGetChild(2)->vAddNewChild();
    tree1.pcGetRoot()->pcGetChild(2)->pcGetChild(0)->vSetValue(4);

    CTreeDynamic tree2;

    tree2.pcGetRoot()->vSetValue(50);

    tree2.pcGetRoot()->vAddNewChild();
    tree2.pcGetRoot()->vAddNewChild();

    tree2.pcGetRoot()->pcGetChild(0)->vSetValue(54);
    tree2.pcGetRoot()->pcGetChild(1)->vSetValue(55);

    tree2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    tree2.pcGetRoot()->pcGetChild(0)->vAddNewChild();


    tree2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(56);
    tree2.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(57);

    tree2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vAddNewChild();
    tree2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->pcGetChild(0)->vSetValue(58);

    cout << "\nDrzewo 1 przed operacja przenoszenia poddrzewa:\n";
    tree1.vPrintTree();

    cout << "\nDrzewo 1 przed operacja przenoszenia poddrzewa:\n";

    tree1.printTreeInRows();

    cout << "\nDrzewo 2 przed operacja przenoszenia poddrzewa:\n";
    tree2.vPrintTree();
    cout << "\nDrzewo 2 przed operacja przenoszenia poddrzewa:\n";

    tree2.printTreeInRows();

    tree1.bMoveSubtree(tree1.pcGetRoot()->pcGetChild(2), tree2.pcGetRoot()->pcGetChild(0));

    cout << "\nDrzewo 1 po operacji przenoszenia poddrzewa:\n";
    tree1.vPrintTree();

    cout << "\nDrzewo 2 po operacji przenoszenia poddrzewa:\n";
    tree2.vPrintTree();
    cout << "\n Po przepieciu all Up\n";
    tree1.pcGetRoot()->pcGetChild(2)->pcGetChild(1)->vPrintUp();
}

void v_subtree_static_test() {
    CTreeStatic tree1;

    tree1.pcGetRoot()->vSetValue(0);

    tree1.pcGetRoot()->vAddNewChild();
    tree1.pcGetRoot()->vAddNewChild();
    tree1.pcGetRoot()->vAddNewChild();

    tree1.pcGetRoot()->pcGetChild(0)->vSetValue(1);
    tree1.pcGetRoot()->pcGetChild(1)->vSetValue(2);
    tree1.pcGetRoot()->pcGetChild(2)->vSetValue(3);

    tree1.pcGetRoot()->pcGetChild(2)->vAddNewChild();
    tree1.pcGetRoot()->pcGetChild(2)->pcGetChild(0)->vSetValue(4);;

    CTreeStatic tree2;

    tree2.pcGetRoot()->vSetValue(50);

    tree2.pcGetRoot()->vAddNewChild();
    tree2.pcGetRoot()->vAddNewChild();

    tree2.pcGetRoot()->pcGetChild(0)->vSetValue(54);
    tree2.pcGetRoot()->pcGetChild(1)->vSetValue(55);

    tree2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    tree2.pcGetRoot()->pcGetChild(0)->vAddNewChild();

    tree2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(56);
    tree2.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(57);

    tree2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vAddNewChild();
    tree2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->pcGetChild(0)->vSetValue(58);

    cout << "\nDrzewo 1 przed operacja przenoszenia poddrzewa:\n";
    tree1.vPrintTree();

    cout << "\nDrzewo 2 przed operacja przenoszenia poddrzewa:\n";
    tree2.vPrintTree();

    tree1.bMoveSubtree(tree1.pcGetRoot()->pcGetChild(2), tree2.pcGetRoot()->pcGetChild(0));

    cout << "\nDrzewo 1 po operacji przenoszenia poddrzewa:\n";
    tree1.vPrintTree();

    cout << "\nDrzewo 2 po operacji przenoszenia poddrzewa:\n";
    tree2.vPrintTree();

    cout << "\n Po przepieciu all Up\n";
    tree1.pcGetRoot()->pcGetChild(2)->pcGetChild(1)->vPrintUp();
}


int main() {
    // TEST DRZEWA STATYCZNEGO
    //v_static_tree_test();
    // TEST DRZEWA DYNAMICZNEGO
    //v_dynamic_tree_test();
    // TEST PRZENOSZENIA PODDRZEWA DRZEWA DYNAMICZNEGO
    //v_subtree_dynamic_test();
    cout << "\n";
    cout << "\n";
    cout << "\n";
    v_subtree_static_test();
}