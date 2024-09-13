#include "ListaDoble.h"


Nodo* ListaDoble::partition(Nodo* low, Nodo* high) {
    int pivot = (&high->valor);  // Acceso a MPointer
    Nodo* i = low->prev;

    for (Nodo* j = low; j != high; j = j->next) {
        if ((&j->valor) <= pivot) {  // Acceso a MPointer
            i = (i == nullptr) ? low : i->next;
            std::swap(i->valor, j->valor);
        }
    }
    i = (i == nullptr) ? low : i->next;
    std::swap(i->valor, high->valor);
    return i;
}

void ListaDoble::quickSort(Nodo* low, Nodo* high) {
    if (high != nullptr && low != high && low != high->next) {
        Nodo* pi = partition(low, high);
        quickSort(low, pi->prev);
        quickSort(pi->next, high);
    }
}


// Método BubbleSort
void ListaDoble::BubbleSort() {
    if (head == nullptr) return;  // Verificar si la lista está vacía

    bool swapped;
    do {
        swapped = false;
        Nodo* current = head;
        while (current->next != nullptr) {
            // Comparar los valores de los MPointer
            if (*current->valor > *current->next->valor) {
                // Intercambiar los valores
                MPointer<int> temp = current->valor;
                current->valor = current->next->valor;
                current->next->valor = temp;
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
}





void ListaDoble::insertionSort() {
    if (head == nullptr) return;

    Nodo* sorted = head;
    Nodo* current = head->next;

    while (current != nullptr) {
        Nodo* next = current->next;
        MPointer<int> currentValue = current->valor;

        if (&currentValue >= &sorted->valor) {
            sorted = current;
        } else {
            Nodo* temp = sorted;
            while (temp != nullptr && &currentValue < &temp->valor) {
                temp = temp->prev;
            }
            if (current->prev != nullptr) current->prev->next = current->next;
            if (current->next != nullptr) current->next->prev = current->prev;

            if (temp == nullptr) {
                current->next = head;
                head->prev = current;
                head = current;
                current->prev = nullptr;
            } else {
                current->next = temp->next;
                if (temp->next != nullptr) temp->next->prev = current;
                temp->next = current;
                current->prev = temp;
            }
        }
        current = next;
    }
}



