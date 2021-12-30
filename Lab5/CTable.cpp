
#include <iostream>
#include "CTable.h"
using namespace std;

CTable::CTable() {
    s_name=DEFAULT_NAME;
    i_length=DEFAULT_LENGTH;
    table=new int[DEFAULT_LENGTH];

    cout<<"bezp: "<<s_name<<'\n';
}

CTable::CTable(string sName,int iTableLen) {
    if(iTableLen < 0)
        i_length=DEFAULT_LENGTH;
    else
        i_length=iTableLen;

    s_name=sName;
    table=new int[iTableLen];

    cout<<"parametr: "<<s_name<<'\n';
}

CTable::CTable(const CTable &pcOther) {
    copy(pcOther);
    s_name=pcOther.s_name+"_copy";
    cout << "kopiuj: " << s_name << "\n";
}

CTable::CTable(CTable &&cOther) {
    moveSemantic(cOther);
    cout<<"move: "<<s_name<<"\n";

}
void CTable::copy(const CTable &pcOther) {
    i_length=pcOther.i_length;
    table=new int[i_length];
    for(int i=0;i< i_length;i++)
        table[i]=pcOther.table[i];
}

void CTable::moveSemantic(CTable &cOther) {
    table= cOther.table;
    i_length=cOther.i_length;
    s_name=cOther.s_name;

    cOther.table= NULL;
}

CTable::~CTable() {
    if (table != NULL) delete [] table;
    cout<<"usuwam: "<<s_name<<'\n';
}


bool CTable::bSetName(string sName) {
    s_name=sName;
    return true;
}


bool CTable::bSetNewLength(int iTableLen) {
    if(iTableLen<0)
        return false;

    if(i_length < iTableLen){
        int *tempTable=new int[iTableLen];
        for (int i=0;i<i_length;i++)
            tempTable[i]=table[i];

        delete[] table;
        table=tempTable;
    }
    i_length=iTableLen;
    return true;
}

void CTable::vSetValueAt(int iOffset, int iNewVal) {
    if(iOffset < i_length && iOffset >= 0)
        table[iOffset]=iNewVal;
}

void CTable::vPrintTable() {
    cout<<"Tablica "+s_name+":";
    for (int i = 0; i < i_length; ++i)
        cout<<"\t"<<table[i];
    cout<<'\n';
}
//CTable CTable::operator=(const CTable &pcOther){
//    this->bSetNewLength(pcOther.iGetLength());
//    for(int ii = 0; ii < i_length;ii++)
//        table[ii]=pcOther.iGetTable()[ii];
//    return *this;
//}
//
//CTable CTable::operator+(CTable &pcOther) {
//    int i_temp_length=this->i_length+pcOther.i_length;
//    CTable c_res(this->s_name + " + " + pcOther.s_name,i_temp_length);
//
//    for (int i = 0; i < i_temp_length; ++i) {
//        if(i<this->i_length)
//            c_res.table[i]=this->table[i];
//        else
//            c_res.table[i]=pcOther.table[ i - this->i_length];
//    }
//    return c_res;
//}
//
//CTable CTable::operator-(int iDeleteLength) {
//    if(iDeleteLength < 0)
//        return CTable(*this);
//
//    int i_length_after_delete=this->i_length-iDeleteLength;
//    if(i_length_after_delete < 0)
//        i_length_after_delete=0;
//
//    CTable c_res(this->s_name + " - ",i_length_after_delete);
//
//    for (int i = 0; i < i_length_after_delete; ++i) {
//        c_res.table[i]=this->table[i];
//    }
//
//    return c_res;
//}
void CTable::operator=(const CTable &pcOther){
    if (table != NULL) delete table;
    copy(pcOther);
}

void CTable::operator=(CTable &&cOther) {
    if (table != NULL) delete table;
    moveSemantic(cOther);
}

CTable CTable::operator+(CTable &pcOther) {
    int i_temp_length=this->i_length+pcOther.i_length;
    CTable c_res(this->s_name + " + " + pcOther.s_name,i_temp_length);

    for (int i = 0; i < i_temp_length; ++i) {
        if(i<this->i_length)
            c_res.table[i]=this->table[i];
        else
            c_res.table[i]=pcOther.table[ i - this->i_length];
    }
    return move(c_res);
}

CTable CTable::operator-(int iDeleteLength) {
    if(iDeleteLength < 0)
        return CTable(*this);

    int i_length_after_delete=this->i_length-iDeleteLength;
    if(i_length_after_delete < 0)
        i_length_after_delete=0;

    CTable c_res(this->s_name + " - ",i_length_after_delete);

    for (int i = 0; i < i_length_after_delete; ++i) {
        c_res.table[i]=this->table[i];
    }

    return move(c_res);
}



