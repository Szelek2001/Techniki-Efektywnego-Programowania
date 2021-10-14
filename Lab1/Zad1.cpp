//
// Created by Rafał on 14.10.2021.
//

#include "Zad1.h"
#include <iostream>

using namespace std;
void v_alloc_table_add_5(int table_size){
    if(table_size<=0){
        cout<<"invalid number \n";
        return;}
    int *table;
    table = new int[table_size];

    for (int i = 0; i < table_size; ++i) {
        *(table+i) = i+DEFAULT_LENGTH;
    }
    for (int i = 0; i < table_size; ++i) {
        cout<<*(table+i)<<"\n";
    }
    delete[] table;

}
int main() {
    v_alloc_table_add_5(5);

}