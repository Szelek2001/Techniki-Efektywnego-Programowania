#ifndef TEP_CTABLE_H
#define TEP_CTABLE_H
#include <string>

using namespace std;


class CTable {
public:
    CTable();

    CTable(string , int );

    CTable(CTable &pcOthers);

     ~CTable();
     static const string DEFAULT_NAME;
    static const int DEFAULT_LENGTH = 5;
    static const int DEFAULT_VALUE = -1;
    bool bSetNewSize(int iTableLen);



    CTable* pcClone() {
        CTable* newCTable;
        newCTable = new CTable(*this);

        return newCTable;
    }
    int *getTable() const;

    void setName(string sName);

    const string &getSName() const;

    int getITableLength() const;
private:
    string s_name;
    int i_table_length;
    int *pi_table;

};
    void vModTabNoPointer(CTable,int);
    void vModTabPointer(CTable*, int );
    void vStaticAllocation();
    void vDynamicAllocation();

#endif //TEP_CTABLE_H
