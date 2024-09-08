//
// Created by harold-madriz on 6/09/24.
//

#ifndef MPOINTERGC_H
#define MPOINTERGC_H


#include <iostream>
#include <thread>
#include <list>
#include <typeinfo>
#include "lLista.h"

using namespace std;

class MPointerGC {
public:



    static MPointerGC& getInstance() {
        status = true;
        static MPointerGC instance;
        return instance;
    }


    static bool isInitialized() {return status;}




    MPointerGC(const MPointerGC&) = delete;
    void operator=(const MPointerGC&) = delete;


    //añade a la lista un ptr
    void addPointer(void* ptr, int ide) {lista.addMPtr(ptr, ide);}
    //añade a la delete list un ptr a eliminar
    void deletePointer(int ide) {Dlist.push_front(ide);}

    int getnewid();






private:
    lLista lista;

    thread gcThread;

    static bool status;

    int currentid = 0;


    list<int> Dlist;



    MPointerGC() {
        // Inicia el Garbage Collector en un hilo separado
        thread gcThread(&MPointerGC::run, this);
        gcThread.detach();
    }



    ~MPointerGC() {
        lista.printlist();
    }


    //hilo
    void run();





};



#endif //MPOINTERGC_H
