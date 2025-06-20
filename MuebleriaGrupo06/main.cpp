// #include <iostream>
#include "Menu.h"
#include "ControladorProveedor.h"
#include "ControladorCompra.h"

int main() {
    ControladorProveedor cprov("proveedores.dat");
    ControladorCompra ccomp("compras.dat");
    iniciarMenu(cprov, ccomp);
    return 0;
}


/*
int main()
{


    ControladorProveedor cp1("proveedores.dat");


    if(cp1.BorrarTodos()){
        cout << "Todos los registros de Proveedores eliminados" << endl << endl;
        cout << "---------------------------" << endl << endl ;
    }


    //Deberia arrancar con el menú o el objeto menu



    //Pruebas internas
    Proveedor p1;
    cout << "1 Proveedor standar creado:" << endl;
    cout << p1.toCSV() << endl << endl;
    cout << "---------------------------" << endl << endl ;


    Compra c1;
    cout << "1 Compra standar creado:" << endl;
    cout << c1.toCSV() << endl << endl;
    cout << "---------------------------" << endl << endl ;

    Producto pro1;
    cout << "1 Producto standar creado:" << endl;
    cout << pro1.toCSV() << endl << endl;
    cout << "---------------------------" << endl << endl ;



    if(cp1.Guardar(p1)){
        cout << "Se guardo un nuevo proveedor"<< endl << endl;
        cout << "Detalle del proveedor guardado:"<< endl << endl;
        cout << p1.toCSV() << endl << endl;
        cout << "---------------------------" << endl << endl ;
    }

    // Listado de los proveedores cargados en el dat

     int cantidad = cp1.CantidadRegistros();

     Proveedor *listaProveedores = new Proveedor[cantidad];

     cout << "Prueba eliminacion logica" << endl << endl;

     cp1.Eliminar(1);

     cp1.Leer(cantidad,listaProveedores);

     cout << "Listado de registros de Proveedores: " << endl << endl;
     for (int i = 0; i < cantidad; i++) {
        cout <<listaProveedores[i].toCSV() <<endl;

        cout << "---------------------------" <<endl;
    }



     delete[] listaProveedores;





    return 0;
}
*/

