#include <iostream>
#include "include/MPointers.h"



using namespace std;





int main() {
    MPointer<string> myPtr = MPointer<string>::New();
    string a = myPtr.ejemplo();
    cout << a << endl;
    cout << "Hello, World!" << endl;
    return 0;

}


