//
// Created by harold-madriz on 8/09/24.
//

#ifndef LISTADOBLE_H
#define LISTADOBLE_H

#include "include/MPointers.h"


template <typename T>
class Nodo {
public:
    MPointer<T> dato; // Almacena MPointer<T>, donde T puede ser cualquier tipo
    Nodo* prev;
    Nodo* next;

    Nodo(MPointer<T> valor) : dato(valor), prev(nullptr), next(nullptr) {}
};




template <typename T>
class ListaDoble {
private:
    Nodo<T>* head;  // Apunta al primer nodo de la lista
    Nodo<T>* tail;    // Apunta al último nodo de la lista

public:
    ListaDoble() : head(nullptr), tail(nullptr) {}

    ~ListaDoble() {
        // Destruir la lista y liberar memoria
        Nodo<T>* actual = head;
        while (actual != nullptr) {
            Nodo<T>* siguiente = actual->next;
            delete actual;
            actual = siguiente;
        }
    }

    // Agregar un nuevo nodo al final de la lista
    void agregarAlFinal(MPointer<T> valor) {
        Nodo<T>* nuevoNodo = new Nodo<T>(valor);
        if (tail == nullptr) { // Lista vacía
            head = tail = nuevoNodo;
        } else {
            tail->next = nuevoNodo;
            nuevoNodo->prev = tail;
            tail = nuevoNodo;
        }
    }

    // Agregar un nuevo nodo al principio de la lista
    void agregarAlPrincipio(MPointer<T> valor) {
        Nodo<T>* nuevoNodo = new Nodo<T>(valor);
        if (head == nullptr) { // Lista vacía
            head = tail = nuevoNodo;
        } else {
            head->prev = nuevoNodo;
            nuevoNodo->next = head;
            head = nuevoNodo;
        }
    }

    // Eliminar un nodo con un valor específico
    void eliminar(MPointer<T> valor) {
        Nodo<T>* actual = head;
        while (actual != nullptr) {
            if (*actual->dato == *valor) { // Comparar los valores almacenados en MPointer
                if (actual->prev != nullptr) {
                    actual->prev->next = actual->next;
                } else { // El nodo = head
                    head = actual->next;
                }
                if (actual->next != nullptr) {
                    actual->next->prev = actual->prev;
                } else { // El nodo es la tail
                    tail = actual->prev;
                }
                delete actual;
                return;
            }
            actual = actual->next;
        }
    }

    // Imprimir los valores de la lista (para propósitos de depuración)
    void imprimir() const {
        Nodo<T>* actual = head;
        while (actual != nullptr) {
            std::cout << *actual->dato << " " << actual->dato.getid() << endl;
            actual = actual->next;
        }
        std::cout << std::endl;
    }


};




#endif //LISTADOBLE_H
