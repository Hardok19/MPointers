//
// Created by harold-madriz on 20/08/24.
//

#ifndef MPointer_H
#define MPointer_H



#include <iostream>
#include "MPointerGC.h"





using namespace std;



template<typename T>
class MPointer{
private:
    int id = 0;
    T* ptr; // Puntero interno al tipo T
    MPointer(T*);

public:
    static MPointer<T> New();



    int getid(); //retorna el id generado por MPointerGC

    ~MPointer(); //

    void senddelete();




    // Sobrecarga del operador * que devuelve una referencia al valor apuntado
    T& operator*() {return *ptr;}
    // Sobrecarga del operador & que devuelve el valor apuntado
    T& operator&() {return *ptr;  }

    // Otros métodos y constructores

    bool operator!=(const MPointer<T>& other) const{
        return ptr != other.ptr;
    }

    bool operator==(const MPointer<T>& other) const{
        return ptr == other.ptr;
    }



    MPointer& operator=(const MPointer& other) {
        if (this != &other) {
            // Elimina el puntero actual
            MPointerGC<T>::getInstance().deletePointer(ptr);


            // Crea una nueva copia profunda del puntero
            ptr = new T(*other.ptr);  // Asegúrate de que T tenga un operador de copia adecuado
            id = other.id;

            MPointerGC<T>::getInstance().addPointer(ptr, id);
        }
        return *this;
    }


    MPointer operator=(const T& value) {
        //cout << "Generado el Mpointer  " "id:" << id << " DM:" << ptr << " Valor: " << *ptr << endl;
        *ptr = value;
        return *this;
    }




    T* getptr() {
        return ptr;
    }

};


// Constructor privado
template<typename T>
MPointer<T>::MPointer(T* p) : ptr(p) {
    id = MPointerGC<T>::getInstance().getnewid();
    //cout << "Generado el Mpointer  " "id:" << id << " DM:" << ptr << " Valor: " << *ptr << endl;
    MPointerGC<T>::getInstance().addPointer(ptr, id);
}


// Metodo estático para crear un nuevo objeto MPointer
template<typename T>
MPointer<T> MPointer<T>::New() {
    if(!MPointerGC<T>::isInitialized()) {
        cout << "Se debe inicializar el Garbage Collector. Usa MPointerGC<T>::getInstance()" << endl;
        return nullptr;
    }
    else {
        return MPointer<T>(new T());  // Crea un nuevo T y retorna un MPointer
    }

}

template<typename T>
MPointer<T>::~MPointer() {
    if (ptr != nullptr) {
        // Marca el puntero para eliminación en lugar de eliminarlo directamente
        MPointerGC<T>::getInstance().deletePointer(ptr);
    }
}



template<typename T>
int MPointer<T>::getid() {  //retorna el id generado por MPointerGC
    return id;
}
template<typename T>
void MPointer<T>::senddelete() {
    if (ptr != nullptr) {
        MPointerGC<T>::getInstance().deletePointer(ptr);

    }
}








#endif //MPointer_H
