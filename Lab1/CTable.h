

#ifndef TEP_CTABLE_H
#define TEP_CTABLE_H
#include <string>

using namespace std;


class CTable {
public:
    CTable();

    CTable(std::__cxx11::basic_string<char> sName, int iTableLen);

    CTable(CTable &pcOthers);

     ~CTable();

    void vSetName(string sName);
    static const string DEFAULT_NAME;
    static const int DEFAULT_LENGTH = 5;
    static const int DEFAULT_VALUE = -1;

private:
    std::string s_name;
    int i_table_length;
    int *pi_table;

};


#endif //TEP_CTABLE_H
