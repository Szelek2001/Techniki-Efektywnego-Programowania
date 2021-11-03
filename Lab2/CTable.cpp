#include <iostream>
#include "CTable.h"


using namespace std;

const string CTable::DEFAULT_NAME = "default";

CTable::CTable() {
    s_name = DEFAULT_NAME;
    i_table_length = DEFAULT_LENGTH;
    pi_table = new int[i_table_length];
    cout << "bezp: " << s_name << "\n";
}

CTable::CTable(string sName, int iTableLen) {
    if (iTableLen < 0)
        iTableLen = DEFAULT_LENGTH;
    s_name = sName;
    i_table_length = iTableLen;
    pi_table = new int[i_table_length];
    cout << "parametr: " << s_name << endl;

}

CTable::CTable(const CTable &pcOther) {
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

void CTable::setName(string sName) {
    s_name = sName;
}

const string &CTable::getSName() const {
    return s_name;
}

bool CTable::bSetNewSize(int iTableLen) {
    if (iTableLen <= 0) return false;

    if (i_table_length < iTableLen) {
        int *tempTable = new int[iTableLen];
        for (int i = 0; i < i_table_length; ++i) {
            tempTable[i] = pi_table[i];
        }
        delete[] pi_table;
        pi_table = tempTable;
    }
    i_table_length = iTableLen;

    return true;
}

int CTable::getITableLength() const {
    return i_table_length;
}


int *CTable::getTable() const {
    return pi_table;
}


void vModTabPointer(CTable *cTab, int inewSize) {
    cTab->bSetNewSize(inewSize);
}

void vModTabNoPointer(CTable cTab, int inewSize) {
    cTab.bSetNewSize(inewSize);
}

void vStaticAllocation() {
    CTable cTableStatic("romb", 10);
    cTableStatic.bSetNewSize(20);

}

void vDynamicAllocation() {
    CTable *cTableDynamic = new CTable();
    delete cTableDynamic;
}

void CTable::vPrint() {
    cout << "\n";
    for (int i = 0; i < i_table_length; i++) {
        cout << pi_table[i];
        cout << " ";
    }
}

void CTable::vSetValueAt(int iOffset, int iNewVal) {
    // Sprawdzenie prawidłowości parametru
    if (iOffset < 0) {
        cout << "\nWartosc parametru iOffset nieprawidlowa.\n";
    } else {
        pi_table[iOffset] = iNewVal;
    }
};;

CTable CTable::operator+(CTable &other) {
    CTable newTable(this->s_name + " + " + other.s_name, this->i_table_length + other.i_table_length);

    for (int i = 0; i < this->i_table_length; i++) {
        newTable.vSetValueAt(i, this->pi_table[i]);
    }

    for (int i = this->i_table_length; i < newTable.i_table_length; i++) {
        newTable.vSetValueAt(i, other.pi_table[i - this->i_table_length]);
    }

    return newTable;
}

//void CTable::operator=(CTable &pcOther) {
//    bSetNewSize(pcOther.getITableLength());
//    for (int i = 0; i < i_table_length; ++i) {
//        pi_table[i] = pcOther.getTable()[i];
//    }
//}

void CTable::operator=(CTable &pcOther) {
    pi_table = pcOther.pi_table;
    i_table_length = pcOther.i_table_length;
}

int main() {

//    CTable c_tab_0, c_tab_1;
//    c_tab_0.bSetNewSize(1);
//    c_tab_1.bSetNewSize(4);
//
//    c_tab_0 = c_tab_1;


    CTable c_tab_0, c_tab_1;
    c_tab_0.bSetNewSize(6);
    c_tab_1.bSetNewSize(4);
/* initialize table */
    c_tab_0 = c_tab_1;
    c_tab_1.vSetValueAt(2, 123);
    c_tab_0.vPrint();
    c_tab_1.vPrint();


//    c_tab_0.vSetValueAt(0, 11);
//    c_tab_1.vSetValueAt(0, 12);
//    c_tab_1.vSetValueAt(1, 13);
//    c_tab_1.vSetValueAt(2, 14);
//    c_tab_1.vSetValueAt(3, 15);
//
//
//    (c_tab_0 + c_tab_1).vPrint();


}