#ifndef LLISTA_H
#define LLISTA_H

using namespace std;

template<class T> class lLista {
private:
    struct Node {
        int id;
        T* ptr;
        Node* next = nullptr;

        // Constructor para inicializar el nodo con id y puntero.
        Node(int id, T* ptr) : id(id), ptr(ptr), next(nullptr) {}
    };

    Node* head = NULL;
    int size = 0;

public:
    lLista<T>() :size(0) {}
    int getsize() {
        return size;
    }


    void addMPtr(T* ptr, int id) {
        if (size == 0) {
            head = new Node(id, ptr);;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new Node(id, ptr);
        }
        //cout << "Añadido a la lista el MPointer, id: " << id << " DM: " << ptr << endl;
        size++;
    }


    void deleteMPtr(int id) {
        if (size == 0) {
            // La lista está vacía, nada que hacer
            return;
        }

        Node* current = head;
        Node* previous = nullptr;

        // Buscar el nodo con el id especificado
        while (current != nullptr && current->id != id) {
            previous = current;
            current = current->next;
        }

        // Si el nodo no se encontró
        if (current == nullptr) {
            // El id no está en la lista
            return;
        }

        // Si el nodo a eliminar es el primero
        if (previous == nullptr) {
            head = current->next;
        } else {
            previous->next = current->next;
        }
        try {
            delete current->ptr;             // Liberar memoria
            current->ptr = nullptr;          // Establecer puntero a nullptr
            bool a = current->ptr == nullptr;
            //cout << a << endl;
            // Liberar la memoria del nodo
            delete current;
            current = nullptr;
            size--;

        }
        catch (error_code e) {
            cout << e << endl;
        }

    }

    void deletall() {
        while (head != nullptr) {
            deleteMPtr(head->id);
        }
    }

    void changeid(int id, int cambio) {
        Node* current = head;

        // Encuentra el nodo con el id dado
        while (current != nullptr && current->id != id) {
            current = current->next;
        }

        if (current == nullptr) return; // No se encontró el nodo

        current->id = cambio;
    }


    int getid(void* ptr) {
        Node* current = head;

        while (current != nullptr) {
            if (current->ptr == ptr) {
                return current->id;
            }
            current = current->next;
        }

        return -1; // Retorna -1 si no se encuentra la posición
    }

    void printlist() {
        Node* current = head;
        while (current != nullptr) {
            cout << "id: " << current->id << " DM: " << current->ptr <<  endl;
            current = current->next;
        }
    }
    ~lLista()= default;


};


#endif // LLISTA_H

