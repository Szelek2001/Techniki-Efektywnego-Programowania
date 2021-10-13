#include <iostream>
using namespace std;
void v_alloc_table_add_5(int table_size){
    if(table_size<=0){
        cout<<"invalid number";
        return;}
    int *table;
    table = new int[table_size];

    for (int i = 0; i < table_size; ++i) {
        *(table+i) = i+5;
    }
    for (int i = 0; i < table_size; ++i) {
        cout<<*(table+i)<<"\n";
    }
    delete table;

}
int main() {
    v_alloc_table_add_5(5);

}