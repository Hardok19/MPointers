#ifndef LISTADOBLE_H
#define LISTADOBLE_H

#include "biblioteca/MPointers.h"

using namespace std;

class Nodo {
public:
    Nodo* prev;
    Nodo* next;
    MPointer<int> valor;

    Nodo(MPointer<int> val): valor(val), prev(nullptr), next(nullptr){}

};
class ListaDoble {
private:
    Nodo* head;
    Nodo* tail;
    int size = 0;


    Nodo* partition(Nodo* low, Nodo* high);

    void quickSort(Nodo *low, Nodo *high);



public:
    ListaDoble(): head(nullptr), tail(nullptr){};


    void BubbleSort();
    void insertionSort();

    void addN(MPointer<int> val) {
        Nodo* newnodo = new Nodo(val);
        if(head == nullptr){
            head = newnodo;
            tail = newnodo;
            size++;
        }
        else {
            newnodo->prev = tail;
            tail->next = newnodo;
            tail = newnodo;
            size++;
        }

    }


    int getvalue(int posicion) {
        Nodo* current = head;
        int i = 1;

        while (current != nullptr) {
            if (i == posicion) {
                return &current->valor;
            }
            i++;
            current = current->next;
        }

        return -1; // Retorna -1 si no se encuentra la posición
    }










    void printlist() {
        Nodo* current = head;
        while(current != nullptr) {
            cout << "MP:" << &current->valor << "   ID:" << current->valor.getid() << endl;
            current = current->next;
        }

    }


    void qsort() {
        quickSort(head, tail);
    }



};



#endif //LISTADOBLE_H
