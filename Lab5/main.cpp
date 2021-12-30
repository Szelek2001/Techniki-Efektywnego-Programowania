#include <iostream>
#include "CMySmartPointer.h"
#include "CTable.h"

void testSmartPointer(){
    CMySmartPointer<int> smartPcInt(new int(5));
    CMySmartPointer<int> smartPcInt2(smartPcInt);
    CMySmartPointer<int> smartPointer(new int(4));
    smartPcInt.coutvector();
    std::cout<<"\n";
    smartPcInt2 = smartPcInt;
    smartPcInt2.coutvector();



}
void testTable(){
    CTable tab1("1",1), tab2("2",2), tab3("3",3);
    tab2=tab1+tab2;
    tab2.vPrintTable();
}

int main() {
    testSmartPointer();
    return 0;
}
