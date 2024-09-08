#include "lLista.h"
#include <iostream>

using namespace std;

void lLista::addMPtr(void* ptr, int id) {
    Node* newNode = new Node(id, ptr);
    cout << "Añadido a la lista el MPointer, id: " << id << " DM: " << ptr << endl;

    if (size == 0) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
    size++;
}

void lLista::deleteMPtr(int id) {
    Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr) {
        if (current->id == id) {
            Node* nodeToDelete = current;

            // Si el nodo a eliminar es el primer nodo
            if (prev == nullptr) {
                head = current->next;
            } else {
                prev->next = current->next;  // Saltar el nodo a eliminar
            }

            current = current->next;  // Avanzar al siguiente nodo
            nodeToDelete = nullptr;
            printlist();
            size--;  // Reducir el tamaño de la lista

        } else {
            prev = current;
            current = current->next;
        }
    }
}


void lLista::changeid(int id, int cambio) {
    Node* current = head;

    // Encuentra el nodo con el id dado
    while (current != nullptr && current->id != id) {
        current = current->next;
    }

    if (current == nullptr) return; // No se encontró el nodo

    current->id = cambio;
}


int lLista::getid(int posicion) {
    Node* current = head;
    int i = 0;

    while (current != nullptr) {
        if (i == posicion) {
            return current->id;
        }
        i++;
        current = current->next;
    }

    return -1; // Retorna -1 si no se encuentra la posición
}

void lLista::printlist() {
    Node* current = head;
    while (current != nullptr) {
        current = current->next;
    }
}

// Destructor para liberar la memoria de todos los nodos
lLista::~lLista() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}





