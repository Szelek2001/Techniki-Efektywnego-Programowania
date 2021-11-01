#include "CTable.h"
#include "Zad123.h"
#include <iostream>

using namespace std;

bool v_alloc_table_add_5(int iTableSize) {
    if (iTableSize <= 0) {
        cout << "invalid number \n";
        return false;
    }
    int *table;
    table = new int[iTableSize];

    for (int i = 0; i < iTableSize; ++i) {
        *(table + i) = i + DEFAULT_VALUE;
    }
    for (int i = 0; i < iTableSize; ++i) {
        cout << *(table + i) << "\n";
    }
    delete[] table;
    return true;
}

bool b_alloc_table_2_dim(int ***piTable, int iSizeX, int iSizeY) {

    if (iSizeX <= 0 || iSizeY <= 0)
        return false;
    *piTable = new int *[iSizeX];

    for (int i = 0; i < iSizeX; ++i) {
        *(*piTable + i) = new int[iSizeY];

    }

    return true;

}

bool b_dealloc_table_2_dim(int **piTable, int iSizeX) {

    if (iSizeX <= 0)
        return false;


    for (int i = 0; i < iSizeX; i++) {
        delete[] *(piTable + i);
    }
    delete[] piTable;
    return true;

}

int main() {

    v_alloc_table_add_5(5);

    int **pi_table;
    cout << b_alloc_table_2_dim(&pi_table, 5, 3);
    cout << b_dealloc_table_2_dim(pi_table, 5);

    CTable *ctable, *ctable2, *ctable3, *ctable4;
    ctable = new CTable();
    ctable2 = new CTable("rafal", 10);
    ctable3 = new CTable(*ctable2);
    ctable4 = (*ctable).pcClone();
    cout << ctable4->getSName() << endl;

    vModTabNoPointer(*ctable2, 50);
    cout << ctable2->getITableLength() << endl;
    vModTabPointer(ctable2, 50);
    cout << ctable2->getITableLength() << endl;

    delete ctable;
    delete ctable2;
    delete ctable3;
    delete ctable4;

    vStaticAllocation();
    vDynamicAllocation();

    return 0;

}