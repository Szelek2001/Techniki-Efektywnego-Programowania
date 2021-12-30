#include <iostream>
#include "CTreeDynamic.h"

void v_dynamic_tree_test() {
    CTreeDynamic<double> treeDynamic;

    treeDynamic.pcGetRoot()->vSetValue(33.3);
    treeDynamic.pcGetRoot()->vAddNewChild();
    treeDynamic.pcGetRoot()->vAddNewChild();

    treeDynamic.pcGetRoot()->pcGetChild(0)->vSetValue(44.4);
    treeDynamic.pcGetRoot()->pcGetChild(1)->vSetValue(55.5);

    cout << "\nTest metody vPrintTree\n";
    treeDynamic.vPrintTree();

    cout << "\nTest metody vPrintAllBelow:\n";
    treeDynamic.pcGetRoot()->pcGetChild(0)->vPrintAllBelow();

}//void v_dynamic_tree_test()

void v_subtree_dynamic_test() {
    CTreeDynamic<int> tree1;

    tree1.pcGetRoot()->vSetValue(0);

    tree1.pcGetRoot()->vAddNewChild();
    tree1.pcGetRoot()->vAddNewChild();
    tree1.pcGetRoot()->vAddNewChild();

    tree1.pcGetRoot()->pcGetChild(0)->vSetValue(1);
    tree1.pcGetRoot()->pcGetChild(1)->vSetValue(2);
    tree1.pcGetRoot()->pcGetChild(2)->vSetValue(3);

    tree1.pcGetRoot()->pcGetChild(2)->vAddNewChild();
    tree1.pcGetRoot()->pcGetChild(2)->pcGetChild(0)->vSetValue(4);

    CTreeDynamic<int> tree2;

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



    cout << "\nDrzewo 2 przed operacja przenoszenia poddrzewa:\n";
    tree2.vPrintTree();
    cout << "\nDrzewo 2 przed operacja przenoszenia poddrzewa:\n";


    tree1.bMoveSubtree(tree1.pcGetRoot()->pcGetChild(2), tree2.pcGetRoot()->pcGetChild(0));

    cout << "\nDrzewo 1 po operacji przenoszenia poddrzewa:\n";
    tree1.vPrintTree();

    cout << "\nDrzewo 2 po operacji przenoszenia poddrzewa:\n";
    tree2.vPrintTree();
    cout << "\n Po przepieciu all Up\n";
    tree1.pcGetRoot()->pcGetChild(2)->pcGetChild(1)->vPrintUp();
}
void testDynSum() {
    CTreeDynamic<int> tree2;
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

    int* sum = tree2.sum();

    cout << *sum;

    CTreeDynamic<string> tree;
    tree.pcGetRoot()->vSetValue("aa");
    tree.pcGetRoot()->vAddNewChild();
    tree.pcGetRoot()->pcGetChild(0)->vSetValue("bb");

    string* ss = tree.sum();


}
int main() {

    //testDynSum();
    //v_dynamic_tree_test();
    string k = "kek";
    string a = "aaaa";
    cout<<(a<k);

    return 0;
}
