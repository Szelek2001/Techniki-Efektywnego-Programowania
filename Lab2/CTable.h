#ifndef TEP_CTABLE_H
#define TEP_CTABLE_H

#include <string>

using namespace std;


class CTable {
public:
    void operator=(CTable &pcOther);

    CTable operator+(CTable &pcOther);

    CTable();

    CTable(string s_name, int i_table_length);

    CTable(const CTable &pcOthers);

    ~CTable();

    static const string DEFAULT_NAME;
    static const int DEFAULT_LENGTH = 5;

    bool bSetNewSize(int iTableLen);


    CTable *pcClone() {
        CTable *newCTable;
        newCTable = new CTable(*this);

        return newCTable;
    }

    int *getTable() const;

    void setName(string sName);

    const string &getSName() const;

    int getITableLength() const;

    void vPrint();

    void vSetValueAt(int iOffset, int iNewVal);

private:
    string s_name;
    int i_table_length;
    int *pi_table;


};

void vModTabNoPointer(CTable cTab, int inewSize);

void vModTabPointer(CTable *cTab, int);

void vStaticAllocation();

void vDynamicAllocation();

#endif //TEP_CTABLE_H