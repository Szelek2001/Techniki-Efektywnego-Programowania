
#ifndef TEP_5_CMYSMARTPOINTER_H
#define TEP_5_CMYSMARTPOINTER_H


#include <vector>
#include <iostream>

using namespace std;


template<typename T>
class CMySmartPointer;

template<typename T>
class CRefCounter {
public:

    CRefCounter() {
        i_count = 0;

    }

    bool addPointer(CMySmartPointer<T> *cp) {
for (int i = 0; i < list.size(); i++) {
            if (list[i] == cp) {
                return false;


            }
        }
        list.push_back(cp);
        return true;
    }

    bool delatePointer(CMySmartPointer<T> *cp) {
        for (int i = 0; i < list.size(); i++) {
            if (list[i] == cp) {
                list.erase(list.begin() + i);
                return true;
            }
        }return false;

    }

    int iAdd(CMySmartPointer<T> *cp) {
        if (this->addPointer(cp) == true)
            return (++i_count);
    }

    int iDec(CMySmartPointer<T> *cp) {
        if (this->delatePointer(cp) == true)
            return (--i_count);
    };

    int iGet() { return (i_count); }

    void coutvector() {
        for (int i = 0; i < list.size(); i++)
            std::cout << list[i] << "\n";

    }

private:
    vector<CMySmartPointer<T> *> list;
    int i_count;
};

template<typename T>
class CMySmartPointer {
public:
    CMySmartPointer(T *pcPointer);

    CMySmartPointer(const CMySmartPointer &pcOther);

    ~CMySmartPointer();

    T &operator*() { return *pointer; }

    T *operator->() { return pointer; }

    void operator=(const CMySmartPointer &pcOther);

    void coutvector();

    T *getPointer() const;


private:
    void vDeletePointer();

    void vCopyPointer(const CMySmartPointer &pcOther);

    T *pointer;
    CRefCounter<T> *counter;
};

template<typename T>
CMySmartPointer<T>::CMySmartPointer(T *pcPointer) {
    pointer = pcPointer;
    counter = new CRefCounter<T>();
    counter->iAdd(this);
}

template<typename T>
CMySmartPointer<T>::CMySmartPointer(const CMySmartPointer &pcOther) {
    vCopyPointer(pcOther);
}

template<typename T>
CMySmartPointer<T>::~CMySmartPointer() {
    vDeletePointer();
}


template<typename T>
void CMySmartPointer<T>::operator=(const CMySmartPointer &pcOther) {
    vDeletePointer();
    vCopyPointer(pcOther);
}

template<typename T>
void CMySmartPointer<T>::vCopyPointer(const CMySmartPointer &pcOther) {
    pointer = pcOther.pointer;
    counter = pcOther.counter;
    counter->iAdd(this);
}

template<typename T>
void CMySmartPointer<T>::vDeletePointer() {
    if (counter->iDec(this) == 0) {
        delete pointer;
        delete counter;
    }
}



template<typename T>
T *CMySmartPointer<T>::getPointer() const {
    return pointer;
}

template<typename T>
void CMySmartPointer<T>::coutvector() {
    counter->coutvector();

}


#endif //TEP_5_CMYSMARTPOINTER_H
