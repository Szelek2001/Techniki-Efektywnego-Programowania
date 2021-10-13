#include <iostream>

using namespace std;

bool b_alloc_table_2_dim(int ***piTable, int iSizeX, int iSizeY) {

    if(iSizeX<=0||iSizeY<=0)
        return false;
    *piTable = new int*[iSizeX];

    for (int i = 0; i < iSizeX; ++i) {
        (*piTable)[i] = new int[iSizeY];

    }

    return true;

}
int main() {

    int **pi_table;
    b_alloc_table_2_dim(&pi_table, 5, 3);

    return 0;
}
