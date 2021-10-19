#include "CTable.h"
#include <iostream>
using namespace std;

const string CTable::DEFAULT_NAME= "default";

CTable::CTable() {
    s_name = DEFAULT_NAME;
    i_table_length = DEFAULT_LENGTH;
    pi_table = new int[i_table_length];
    cout << "bezp: " << s_name << "\n";
}

CTable::CTable(string sName, int iTableLen) {
    s_name= sName;
    i_table_length = iTableLen;
    pi_table = new int[i_table_length];
    cout << "parametr: " << s_name << endl;

}
CTable::CTable(CTable &pcOther) {
    i_table_length = pcOther.i_table_length;
    pi_table = new int[i_table_length];
    s_name = pcOther.s_name + "_copy";
    cout << "kopiuj: " << s_name << endl;

    for (int i = 0; i < i_table_length; ++i)
        pi_table[i] = pcOther.getTable()[i];

}
CTable::~CTable() {
    cout << "usuwam: " << s_name << "\n";
    delete[] pi_table;
}

void CTable::setName(string sName)
{
    s_name = sName;
}


bool CTable::bSetNewSize(int iTableLen){
    if (i_table_length <= 0) return false;

    if(i_table_length < iTableLen)
        { int *tempTable = new int[iTableLen];
            for (int i = 0; i < i_table_length ;  ++i) {
               tempTable[i] = pi_table[i];
            }

        }
    i_table_length = iTableLen;
    return true;
}


int* CTable::getTable() const
{
    return pi_table;
}
void modTabPointer(CTable* cTab, int newSize) {
    cTab->bSetNewSize(newSize);
}

void modTabNoPointer(CTable cTab, int newSize) {
    cTab.bSetNewSize(newSize);
}