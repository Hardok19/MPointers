//
// Created by harold-madriz on 6/09/24.
//

#include "MPointerGC.h"



bool MPointerGC::status = false;





void MPointerGC::run() {
    while (true) {
        if (!Dlist.empty()) {
            for(int i : Dlist){
                lista.deleteMPtr(i);
            }
            Dlist.clear();
        }
        this_thread::sleep_for(chrono::milliseconds(250));
    }
}

int MPointerGC::getnewid() {
    currentid += 1;
    return  currentid;
}