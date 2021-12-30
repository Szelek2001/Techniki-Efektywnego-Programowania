

#ifndef TEP_5_CTABLE_H
#define TEP_5_CTABLE_H

#include <string>
#include <iostream>

using namespace std;

const string DEFAULT_NAME="default_name";
const int DEFAULT_LENGTH=5;

class CTable{
private:
    string s_name;
    int i_length;
    int *table;

    void moveSemantic(CTable &pcOther);
    void copy(const CTable &pcOther);


public:
    CTable();
    CTable(string sName, int iTableLen);
    CTable(const CTable &pcOther);
    CTable(CTable &&cOther);
    ~CTable();

    string sGetName() {return s_name;}
    bool bSetName(string sName);

    int iGetLength() const { return i_length;}
    bool bSetNewLength(int iTableLen);
    void vSetValueAt(int iOffset,int iNewVal);
    void vPrintTable();
    int *iGetTable() { return table;}

    CTable *pcClone(){ return new CTable(*this);};

    void operator=(const CTable &pcOther);
    void operator=(CTable &&cOther);
    CTable operator+(CTable &pcOther);
    CTable operator-(int iDeleteLength);


};


#endif //TEP_5_CTABLE_H
