//
// Created by harold-madriz on 20/08/24.
//

#ifndef MPointer_H
#define MPointer_H


#include <iostream>
#include <thread>
#include "MPointerGC.h"





using namespace std;


template <typename T> std::string type_name();
template<typename T>
class MPointer{
private:
    int id = 0;
    T* ptr; // Puntero interno al tipo T
    MPointer(T*);
    void Sendelete(int ide);

public:
    static MPointer<T> New();



    int getid();

    ~MPointer();




    // Sobrecarga del operador * que devuelve una referencia al valor apuntado
    T& operator*() {return *ptr;}
    // Sobrecarga del operador & que devuelve el valor apuntado
    T& operator&() {return *ptr;  }





    // Operador de asignación (copia profunda)
    MPointer& operator=(const MPointer& other) {
        if(this != &other) {
            Sendelete(id);
            delete ptr;
            // Aquí se hace la copia profunda del valor al que apunta el puntero
            ptr = new T(*other.ptr);
            id = other.id;
            MPointerGC::getInstance().addPointer(other.ptr, other.id);
        }
        return *this;
    }



    MPointer& operator=(const T& value) {
        *ptr = value;
        return *this;
    }




};


// Constructor privado
template<typename T>
MPointer<T>::MPointer(T* p) : ptr(p) {
    id = MPointerGC::getInstance().getnewid();
    //cout << "Generado el Mpointer  " "id:" << id << " DM:" << ptr << endl;
    MPointerGC::getInstance().addPointer(ptr, id);
}


// Metodo estático para crear un nuevo objeto MPointer
template<typename T>
MPointer<T> MPointer<T>::New() {
    if(!MPointerGC::isInitialized()) {
        cout << "Se debe inicializar el Garbage Collector. Usa MPointerGC<T>::getInstance()" << endl;
    }
    else {
        return MPointer<T>(new T());  // Crea un nuevo T y retorna un MPointer
    }

}

template<typename T>
MPointer<T>::~MPointer() {
    if (ptr != nullptr) {
        MPointerGC::getInstance().deletePointer(id);
        ptr = nullptr;
    }

}
template<typename T>
void MPointer<T>::Sendelete(int ide){
    MPointerGC::getInstance().deletePointer(ide);
}

template<typename T>
int MPointer<T>::getid() {
    return id;
}








#endif //MPointer_H
