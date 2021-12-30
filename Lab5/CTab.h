
#ifndef TEP_5_CTAB_H
#define TEP_5_CTAB_H

#define DEF_TAB_SIZE 10
class CTab {
public:
    CTab() { pi_tab = new int[DEF_TAB_SIZE]; i_size = DEF_TAB_SIZE;}
    CTab(const CTab &cOther);
    CTab(CTab &&cOther);
    CTab operator=(const CTab &cOther);
    void operator=(CTab&& other);
    ~CTab();
    bool bSetSize(int iNewSize);
    int iGetSize() { return(i_size); }
private:
    void v_copy(const CTab &cOther);
    void moveSemantic(CTab &pcOther);
    int *pi_tab;
    int i_size;
};


#endif //TEP_5_CTAB_H
