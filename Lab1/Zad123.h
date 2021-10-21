#ifndef TEP_ZAD1_H
#define TEP_ZAD1_H


const int DEFAULT_VALUE = 5;

bool v_alloc_table_add_5(int tablesize);

bool b_alloc_table_2_dim(int ***piTable, int iSizeX, int iSizeY);

bool b_dealloc_table_2_dim(int **piTable, int iSizeX);

#endif //TEP_ZAD1_H
