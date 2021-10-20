#include "Zad2i3.h"


#include <iostream>

using namespace std;

bool b_alloc_table_2_dim(int ***piTable, int iSizeX, int iSizeY) {

    if(iSizeX<=0||iSizeY<=0)
        return false;
    *piTable = new int*[iSizeX];

    for (int i = 0; i < iSizeX; ++i) {
        *(*piTable+i) = new int[iSizeY];

    }

    return true;

}

bool b_dealloc_table_2_dim(int **piTable, int iSizeX) {

    if(iSizeX<=0)
        return false;


    for (int i = 0; i < iSizeX; i++) {
        delete[] *(piTable + i);
    }
    delete[] piTable;
    return true;

}

int main() {

    int **pi_table;
    cout<< b_alloc_table_2_dim(&pi_table, 5, 3);
    cout<< b_dealloc_table_2_dim(pi_table, 5);
    return 0;
}
