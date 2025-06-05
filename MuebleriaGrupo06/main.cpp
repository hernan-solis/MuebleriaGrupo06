#include <iostream>
#include "Proveedor.h"
#include "Producto.h"
#include "Compra.h"
#include "Fecha.h"

//using namespace std; habilitar solo si es utilizado


using namespace std;

int main()
{
    //Deberia arrancar con el menú o el objeto menu



    //Pruebas internas
    Proveedor p1;
    cout << "Proveedor standar" << endl;
    cout << p1.toCSV() << endl << endl;

    Compra c1;
    cout << "Compra standar" << endl;
    cout << c1.toCSV() << endl << endl;

    Producto pro1;
    cout << "Producto standar" << endl;
    cout << pro1.toCSV() << endl << endl;

    return 0;
}
