#include "CTable.h"
#include <iostream>

using namespace std;

int main() {

    CTable c_tab_0, c_tab_1;
//
//    c_tab_0.bSetNewSize(1);
//    c_tab_1.bSetNewSize(4);
//
//    c_tab_0 = c_tab_1;


//    CTable c_tab_0, c_tab_1;
//    c_tab_0.bSetNewSize(6);
//    c_tab_1.bSetNewSize(4);
///* initialize table */
//    c_tab_0 = c_tab_1;
//    c_tab_1.vSetValueAt(2, 123);
//    c_tab_0.vPrint();
//    c_tab_1.vPrint();
//
//
    c_tab_0.bSetNewSize(1);
    c_tab_1.bSetNewSize(4);
    c_tab_0.vSetValueAt(0, 11);
    c_tab_1.vSetValueAt(0, 12);
    c_tab_1.vSetValueAt(1, 13);
    c_tab_1.vSetValueAt(2, 14);
    c_tab_1.vSetValueAt(3, 15);

    c_tab_1 = c_tab_0 + c_tab_1;
    (c_tab_0 + c_tab_1).vPrint();

//    CTable c_tab_0;
//    c_tab_0.bSetNewSize(5);
//    c_tab_0.vSetValueAt(0,1);
//    c_tab_0.vSetValueAt(1,2);
//    c_tab_0.vSetValueAt(2,3);
//    c_tab_0.vSetValueAt(3,4);
//    c_tab_0.vSetValueAt(4,5);
//    c_tab_0.vPrint();
//    c_tab_0++;
//    c_tab_0.vPrint();

}