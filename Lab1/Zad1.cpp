
#include "Zad1.h"
#include <iostream>

using namespace std;
bool v_alloc_table_add_5(int table_size){
    if(table_size<=0){
        cout<<"invalid number \n";
        return false;}
    int *table;
    table = new int[table_size];

    for (int i = 0; i < table_size; ++i) {
        *(table+i) = i+DEFAULT_VALUE;
    }
    for (int i = 0; i < table_size; ++i) {
        cout<<*(table+i)<<"\n";
    }
    delete[] table;
    return true;
}
int main() {
    v_alloc_table_add_5(-1);

}