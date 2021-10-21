
#include "Zad1.h"
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

int main() {
    v_alloc_table_add_5(5);

}