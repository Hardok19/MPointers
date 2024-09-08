#ifndef LLISTA_H
#define LLISTA_H

struct Node {
    int id;
    void* ptr;
    Node* next = nullptr;

    // Constructor para inicializar el nodo con id y puntero.
    Node(int id, void* ptr) : id(id), ptr(ptr), next(nullptr) {}
};

class lLista {
private:
    Node* head;
    int size = 0;

public:
    lLista() : head(nullptr), size(0) {}

    // Destructor para liberar la memoria de todos los nodos.
    ~lLista();

    void addMPtr(void* ptr, int id);
    void deleteMPtr(int id);
    void changeid(int id, int cambio);
    int getid(int posicion);

    void printlist();
};

#endif // LLISTA_H

