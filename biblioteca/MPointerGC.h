#ifndef MPOINTERGC_H
#define MPOINTERGC_H

#include <iostream>
#include <thread>
#include <list>
#include <chrono>
#include "lLista.h"

using namespace std;

template<typename T>
class MPointerGC {
public:
    list<T*> Dlist;
    lLista<T> lista;

    int elenlista() {
        return lista.getsize();
    }
    int getcuenta() {
        return cuentaMPtr;
    }

    static MPointerGC<T>& getInstance() {

        status = true;
        static MPointerGC instance;
        return instance;
    }

    void printlist() {
        lista.printlist();
    }

    static bool isInitialized() { return status; } // Retorna el estado de MPointerGC

    MPointerGC(const MPointerGC&) = delete; // Elimina el constructor de copia
    void operator=(const MPointerGC&) = delete; // Elimina el operador de asignación

    // Añade un puntero a la lista
    void addPointer(T* ptr, int ide) {
        //cout << "ENTRA A ADDPOINTER" << endl;
        cuentaMPtr += 1;
        lista.addMPtr(ptr, ide);
    }

    // Añade un puntero a la lista de eliminación
    void deletePointer(T* ptr) {
        for (T* i : Dlist) {
            if (i == ptr) {
                return;
            }
        }

        Dlist.push_back(ptr);
    }

    int getnewid() { // Retorna el nuevo id para los MPointers
        currentid += 1;
        return currentid;
    }

    ~MPointerGC() {
        stopGC();  // Solicita detener el recolector
        if (gcThread.joinable()) {
            gcThread.join();  // Termina el hilo
        }
    }


private:

    thread gcThread;
    static bool status;

    int cuentaMPtr = 0;

    int currentid = 0;

    MPointerGC() {
        // Inicia el Garbage Collector en un hilo separado
        gcThread = thread(&MPointerGC::run, this);
        gcThread.detach();
    }

    void stopGC() {
        status = false;  // Señal para detener el recolector de basura
    }

    // Método del hilo
    void run() {
        while (status) {
            if (!Dlist.empty()) { // Si Dlist está vacía no elimina nada
                for (T* i : Dlist) {
                    lista.deleteMPtr(lista.getid(i));
                    //cout << "ELIMINADO " << i << endl;
                    cuentaMPtr -= 1;
                }
                Dlist.clear();
            }
            this_thread::sleep_for(chrono::milliseconds(250));
        }
    }
};

template<typename T>
bool MPointerGC<T>::status = false;

#endif // MPOINTERGC_H



