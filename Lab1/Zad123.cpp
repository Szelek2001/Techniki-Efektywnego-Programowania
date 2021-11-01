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

    CTable c_tab_0, c_tab_1;
    c_tab_0.bSetNewSize(6);
    c_tab_1.bSetNewSize(4);
    c_tab_0 = c_tab_1;

    return 0;

}