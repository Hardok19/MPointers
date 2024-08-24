//
// Created by harold-madriz on 20/08/24.
//

#ifndef MPointer_H
#define MPointer_H


#include <iostream>



using namespace std;

template<typename T>
class MPointer{
private:
    T* ptr;
    MPointer(T*);  // Constructor privado
public:
    static MPointer<T> New();
    string ejemplo();

};


// Constructor privado
template<typename T>
MPointer<T>::MPointer(T* p) : ptr(p) {}


// Método estático para crear un nuevo objeto MPointer
template<typename T>
MPointer<T> MPointer<T>::New() {
    return MPointer<T>(new T());  // Crea un nuevo T y retorna un MPointer
}


template<typename T>
string MPointer<T>::ejemplo() {
    return "HOLAAAAAAA";
}






#endif //MPointer_H
