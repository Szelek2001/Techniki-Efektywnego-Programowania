

#ifndef TEP_CTABLE_H
#define TEP_CTABLE_H


#include <string>

class CTable {
public:
    CTable();

    CTable(std::__cxx11::basic_string<char> sName, int iTableLen);

    CTable(CTable &pcOthers);

    virtual ~CTable();

    void vSetName(std::string sName);
    static const std::string DEFAULT_NAME;
    static const int DEFAULT_LENGTH = 5;
    static const int DEFAULT_VALUE = -1;

private:
    std::string s_name;
    int i_table_length;
    int *pi_table;

};


#endif //TEP_CTABLE_H
