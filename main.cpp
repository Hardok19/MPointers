#include <iostream>
#include <unistd.h>

#include "include/MPointers.h"

#include "ListaDoble.h"



using namespace std;


void pruebaListaDoble() {
    // Crear una lista de enteros
    ListaDoble<int> lista;

    // Crear MPointers
    MPointer<int> valor1 = MPointer<int>::New();
    MPointer<int> valor2 = MPointer<int>::New();
    MPointer<int> valor3 = MPointer<int>::New();

    // Asignar valores
    *valor1 = 10;
    *valor2 = 20;
    *valor3 = 30;

    // Agregar elementos al final de la lista
    lista.agregarAlFinal(valor1);
    lista.agregarAlFinal(valor2);

    // Imprimir lista
    std::cout << "Lista después de agregar al final:" << std::endl;
    lista.imprimir(); // Debería imprimir: 10 20

    // Agregar elementos al principio de la lista
    lista.agregarAlPrincipio(valor3);

    // Imprimir lista
    std::cout << "Lista después de agregar al principio:" << std::endl;
    lista.imprimir(); // Debería imprimir: 30 10 20

    // Eliminar un elemento
    lista.eliminar(valor2);

    // Imprimir lista
    std::cout << "Lista después de eliminar el valor 20:" << std::endl;
    lista.imprimir(); // Debería imprimir: 30 10

    // Limpiar lista al finalizar la prueba
    // Destructor se llamará automáticamente al salir del alcance de la lista
}
int main() {

    MPointerGC::getInstance();
    pruebaListaDoble();






    return 0;
}



