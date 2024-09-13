
#include <gtest/gtest.h>
#include "biblioteca/MPointers.h"
#include "ListaDoble.h"
#include "thread"


TEST(MPointerTest, Collector) {
    // Inicializa el recolector de basura
    MPointerGC<int>::getInstance();
    // Crea un nuevo puntero MPointer
    MPointer<int> myPtr = MPointer<int>::New();
    *myPtr = 10;

    myPtr.senddelete();
    this_thread::sleep_for(chrono::seconds(2));





    EXPECT_EQ(MPointerGC<int>::getInstance().elenlista(), 0);
    EXPECT_EQ(MPointerGC<int>::getInstance().getcuenta(), 0);
}
// Prueba para verificar que se puede crear un MPointer y asignarle un valor
TEST(MPointerTest, asignarvalor) {
    MPointerGC<int>::getInstance();
    MPointer<int> myPtr = MPointer<int>::New();
    *myPtr = 5;
    EXPECT_EQ(*myPtr, 5);
}

// Prueba para verificar la sobrecarga del operador de asignación
TEST(MPointerTest, sobrecargaigualdad) {
    MPointerGC<int>::getInstance();
    MPointer<int> myPtr = MPointer<int>::New();
    MPointer<int> myPtr2 = MPointer<int>::New();
    *myPtr = 5;
    myPtr2 = myPtr;
    EXPECT_EQ(*myPtr2, 5);
}

// Prueba para verificar la sobrecarga del operador & (dirección de memoria)
TEST(MPointerTest, obtenervalor) {
    MPointerGC<int>::getInstance();

    MPointer<int> myPtr = MPointer<int>::New();
    *myPtr = 5;
    int valor = &myPtr;
    EXPECT_EQ(valor, 5);
}




// Pruebas para algoritmos de ordenamiento (QuickSort, BubbleSort, InsertionSort)
TEST(SortingTest, QuickSortTest) {
    MPointerGC<int>::getInstance();
    MPointer<int> ptr1 = MPointer<int>::New();
    MPointer<int> ptr2 = MPointer<int>::New();
    MPointer<int> ptr3 = MPointer<int>::New();
    MPointer<int> ptr4 = MPointer<int>::New();
    MPointer<int> ptr5 = MPointer<int>::New();
    MPointer<int> ptr6 = MPointer<int>::New();
    *ptr1 = 10;
    *ptr2 = 5;
    *ptr3 = 8;
    *ptr4 = 3;
    ptr5 = 30;
    ptr6 = 2;
    ptr3 = ptr5;




    ListaDoble lista;
    lista.addN(ptr1);
    lista.addN(ptr2);
    lista.addN(ptr3);
    lista.addN(ptr4);
    lista.addN(ptr5);
    lista.addN(ptr6);


    lista.qsort();


    EXPECT_EQ(lista.getvalue(1), 2);
    EXPECT_EQ(lista.getvalue(2), 3);
    EXPECT_EQ(lista.getvalue(3), 5);
    EXPECT_EQ(lista.getvalue(4), 10);
    EXPECT_EQ(lista.getvalue(5), 30);
    EXPECT_EQ(lista.getvalue(6), 30);

}

TEST(SortingTest, BubbleSortTest) {
    MPointerGC<int>::getInstance();
    MPointer<int> ptr1 = MPointer<int>::New();
    MPointer<int> ptr2 = MPointer<int>::New();
    MPointer<int> ptr3 = MPointer<int>::New();
    MPointer<int> ptr4 = MPointer<int>::New();
    MPointer<int> ptr5 = MPointer<int>::New();
    MPointer<int> ptr6 = MPointer<int>::New();
    *ptr1 = 10;
    *ptr2 = 5;
    *ptr3 = 8;
    *ptr4 = 3;
    ptr5 = 30;
    ptr6 = 2;
    ptr3 = ptr5;
    int a = &ptr5;


    ListaDoble lista;
    lista.addN(ptr1);
    lista.addN(ptr2);
    lista.addN(ptr3);
    lista.addN(ptr4);
    lista.addN(ptr5);
    lista.addN(ptr6);


    lista.BubbleSort();

    EXPECT_EQ(lista.getvalue(1), 2);
    EXPECT_EQ(lista.getvalue(2), 3);
    EXPECT_EQ(lista.getvalue(3), 5);
    EXPECT_EQ(lista.getvalue(4), 10);
    EXPECT_EQ(lista.getvalue(5), 30);
    EXPECT_EQ(lista.getvalue(6), 30);
    EXPECT_EQ(a, 30);

}

TEST(SortingTest, InsertionSortTest) {
    MPointerGC<int>::getInstance();
    MPointer<int> ptr1 = MPointer<int>::New();
    MPointer<int> ptr2 = MPointer<int>::New();
    MPointer<int> ptr3 = MPointer<int>::New();
    MPointer<int> ptr4 = MPointer<int>::New();
    MPointer<int> ptr5 = MPointer<int>::New();
    MPointer<int> ptr6 = MPointer<int>::New();
    *ptr1 = 10;
    *ptr2 = 5;
    *ptr3 = 8;
    *ptr4 = 3;
    ptr5 = 30;
    ptr6 = 2;
    ptr3 = ptr5;
    int a = &ptr5;


    ListaDoble lista;
    lista.addN(ptr1);
    lista.addN(ptr2);
    lista.addN(ptr3);
    lista.addN(ptr4);
    lista.addN(ptr5);
    lista.addN(ptr6);


    lista.insertionSort();

    EXPECT_EQ(lista.getvalue(1), 2);
    EXPECT_EQ(lista.getvalue(2), 3);
    EXPECT_EQ(lista.getvalue(3), 5);
    EXPECT_EQ(lista.getvalue(4), 10);
    EXPECT_EQ(lista.getvalue(5), 30);
    EXPECT_EQ(lista.getvalue(6), 30);
    EXPECT_EQ(a, 30);

}

TEST(MPointerTest, othervalues) {
    MPointerGC<string>::getInstance();
    MPointer<string> ptr1 = MPointer<string>::New();


    ptr1 = "HOLA:)";

    EXPECT_EQ(&ptr1, "HOLA:)");

}


