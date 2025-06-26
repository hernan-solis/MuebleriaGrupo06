#include <iostream>
#include "MenuInformes.h"


using namespace std;

// Fn para limpiar la pantalla
void limpiarPantallaInformes() {
    system("cls");
}

void menuInformes(ControladorProveedor &cprov, ControladorCompra &ccomp, ControladorProducto &cprod, ControladorCategoriaProducto &ctrlCategorias, ControladorDetalleCompra &cdetalle) {
    int opcionMain;
    do {
        limpiarPantallaInformes();
        cout << "\n=====================================================\n";
        cout << "\n                   MENU INFORMES                     \n";
        cout << "\n=====================================================\n";
        cout << "\nSeleccione una opcion:\n";
        cout << "1. Stock x Categoria - Totales\n";
        cout << "2. Informe 2\n";
        cout << "3. Informe 3\n";
        cout << "4. Informe 4\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> opcionMain;
        cin.ignore();

        switch(opcionMain) {
            case 1:{

                limpiarPantallaInformes();
                cout << "\n=====================================================\n";
                cout << "\n         Stock x Categoria - Totales                 \n";
                cout << "\n=====================================================\n";

                // RELACIONA 2 TABLAS

                int cantidadRegistrosProductos = cprod.CantidadRegistros();
                Producto* listaProductos = new Producto[cantidadRegistrosProductos];
                cprod.Leer(cantidadRegistrosProductos,listaProductos);

                int cantidadRegistrosCategoria = ctrlCategorias.CantidadRegistros();
                CategoriaProducto* listaCategoria = new CategoriaProducto[cantidadRegistrosCategoria];
                ctrlCategorias.Leer(cantidadRegistrosCategoria,listaCategoria);

                int acumuladorParcial = 0;
                int acumuladorTotal = 0;

                //RECORRE CADA CATEGORIA
                for(int x = 0 ; x < cantidadRegistrosCategoria ; x++){

                cout << "\n=====================================================\n";
                cout << "ID Categ: " << listaCategoria[x].getIdCategoria() << " - " << listaCategoria[x].getNombre();
                cout << "\n=====================================================\n";

                    // RECORRO CADA PRODUCTO
                    for(int y =0 ; y < cantidadRegistrosProductos ; y++){
                       if(listaProductos[y].getStatus() && listaProductos[y].getIdCategoria() == listaCategoria[x].getIdCategoria()){
                        cout << "ID Prod: " << listaProductos[y].getIdProducto()<< " - " << listaProductos[y].getNombre() << "- Cant: " << listaProductos[y].getStock()<< endl;
                        acumuladorParcial += listaProductos[y].getStock();
                       }
                    }

                    cout << endl << endl;
                    cout << "-- SUB TOTAL: " << acumuladorParcial;
                    cout << endl << endl;
                    acumuladorTotal+= acumuladorParcial;
                    acumuladorParcial = 0;


                }
                cout << endl << endl;
                cout << endl << endl << "--------------------------------------------" << endl;
                cout << " -- STOCK TOTAL: " << acumuladorTotal << endl << endl;

                delete[]listaProductos;
                delete[]listaCategoria;

                system("pause");
                }
                break;
            case 2:{


                limpiarPantallaInformes();
                cout << "\n=====================================================\n";
                cout << "\n                    INFORME                          \n";
                cout << "\n=====================================================\n";

                /*

                int cantidadRegistrosDetalle = cdetalle.CantidadRegistros();
                DetalleCompra* listaDetalle = new DetalleCompra[cantidadRegistrosDetalle];
                cdetalle.Leer(cantidadRegistrosDetalle,listaDetalle);
                for(int x = 0 ; x < cantidadRegistrosDetalle ; x++){
                    cout << listaDetalle[x].toCSV() << endl;
                }
                cout << endl;

                int cantidadRegistrosCompras = ccomp.CantidadRegistros();
                Compra* listaCompra = new Compra[cantidadRegistrosCompras];
                ccomp.Leer(cantidadRegistrosCompras,listaCompra);
                for(int x = 0 ; x < cantidadRegistrosCompras ; x++){
                    if(listaCompra[x].getStatus()){
                        cout << listaCompra[x].toCSV() << endl;
                    }
                }
                cout << endl;

                int cantidadRegistrosProductos = cprod.CantidadRegistros();
                Producto* listaProductos = new Producto[cantidadRegistrosProductos];
                cprod.Leer(cantidadRegistrosProductos,listaProductos);
                for(int x = 0 ; x < cantidadRegistrosProductos ; x++){
                    if(listaProductos[x].getStatus()){
                        cout << listaProductos[x].toCSV() << endl;
                    }
                }
                cout << endl;

                int cantidadRegistrosCategoria = ctrlCategorias.CantidadRegistros();
                CategoriaProducto* listaCategoria = new CategoriaProducto[cantidadRegistrosCategoria];
                ctrlCategorias.Leer(cantidadRegistrosCategoria,listaCategoria);
                for(int x = 0 ; x < cantidadRegistrosCategoria ; x++){

                cout << listaCategoria[x].toCSV() << endl;
                }
                cout << endl;

                int cantidadRegistrosProveedores = cprov.CantidadRegistros();
                Proveedor* listaProveedores = new Proveedor[cantidadRegistrosProveedores];
                cprov.Leer(cantidadRegistrosProveedores,listaProveedores);
                for(int x = 0 ; x < cantidadRegistrosProveedores ; x++){
                    if(listaProveedores[x].getStatus()){
                        cout << listaProveedores[x].toCSV() << endl;
                    }
                }
                cout << endl;




                delete[]listaDetalle;
                delete[]listaCompra;
                delete[]listaProductos;
                delete[]listaCategoria;
                delete[]listaProveedores;

            */


                system("pause");
                }
                break;
            case 3:{

                limpiarPantallaInformes();
                cout << "\n=====================================================\n";
                cout << "\n                    INFORME                          \n";
                cout << "\n=====================================================\n";

                /*

                int cantidadRegistrosDetalle = cdetalle.CantidadRegistros();
                DetalleCompra* listaDetalle = new DetalleCompra[cantidadRegistrosDetalle];
                cdetalle.Leer(cantidadRegistrosDetalle,listaDetalle);
                for(int x = 0 ; x < cantidadRegistrosDetalle ; x++){
                    cout << listaDetalle[x].toCSV() << endl;
                }
                cout << endl;

                int cantidadRegistrosCompras = ccomp.CantidadRegistros();
                Compra* listaCompra = new Compra[cantidadRegistrosCompras];
                ccomp.Leer(cantidadRegistrosCompras,listaCompra);
                for(int x = 0 ; x < cantidadRegistrosCompras ; x++){
                    if(listaCompra[x].getStatus()){
                        cout << listaCompra[x].toCSV() << endl;
                    }
                }
                cout << endl;

                int cantidadRegistrosProductos = cprod.CantidadRegistros();
                Producto* listaProductos = new Producto[cantidadRegistrosProductos];
                cprod.Leer(cantidadRegistrosProductos,listaProductos);
                for(int x = 0 ; x < cantidadRegistrosProductos ; x++){
                    if(listaProductos[x].getStatus()){
                        cout << listaProductos[x].toCSV() << endl;
                    }
                }
                cout << endl;

                int cantidadRegistrosCategoria = ctrlCategorias.CantidadRegistros();
                CategoriaProducto* listaCategoria = new CategoriaProducto[cantidadRegistrosCategoria];
                ctrlCategorias.Leer(cantidadRegistrosCategoria,listaCategoria);
                for(int x = 0 ; x < cantidadRegistrosCategoria ; x++){

                cout << listaCategoria[x].toCSV() << endl;
                }
                cout << endl;

                int cantidadRegistrosProveedores = cprov.CantidadRegistros();
                Proveedor* listaProveedores = new Proveedor[cantidadRegistrosProveedores];
                cprov.Leer(cantidadRegistrosProveedores,listaProveedores);
                for(int x = 0 ; x < cantidadRegistrosProveedores ; x++){
                    if(listaProveedores[x].getStatus()){
                        cout << listaProveedores[x].toCSV() << endl;
                    }
                }
                cout << endl;




                delete[]listaDetalle;
                delete[]listaCompra;
                delete[]listaProductos;
                delete[]listaCategoria;
                delete[]listaProveedores;

                */


                system("pause");
                }
                break;
            case 4:{
                limpiarPantallaInformes();
                cout << "\n=====================================================\n";
                cout << "\n                    INFORME                          \n";
                cout << "\n=====================================================\n";

                /*

                int cantidadRegistrosDetalle = cdetalle.CantidadRegistros();
                DetalleCompra* listaDetalle = new DetalleCompra[cantidadRegistrosDetalle];
                cdetalle.Leer(cantidadRegistrosDetalle,listaDetalle);
                for(int x = 0 ; x < cantidadRegistrosDetalle ; x++){
                    cout << listaDetalle[x].toCSV() << endl;
                }
                cout << endl;

                int cantidadRegistrosCompras = ccomp.CantidadRegistros();
                Compra* listaCompra = new Compra[cantidadRegistrosCompras];
                ccomp.Leer(cantidadRegistrosCompras,listaCompra);
                for(int x = 0 ; x < cantidadRegistrosCompras ; x++){
                    if(listaCompra[x].getStatus()){
                        cout << listaCompra[x].toCSV() << endl;
                    }
                }
                cout << endl;

                int cantidadRegistrosProductos = cprod.CantidadRegistros();
                Producto* listaProductos = new Producto[cantidadRegistrosProductos];
                cprod.Leer(cantidadRegistrosProductos,listaProductos);
                for(int x = 0 ; x < cantidadRegistrosProductos ; x++){
                    if(listaProductos[x].getStatus()){
                        cout << listaProductos[x].toCSV() << endl;
                    }
                }
                cout << endl;

                int cantidadRegistrosCategoria = ctrlCategorias.CantidadRegistros();
                CategoriaProducto* listaCategoria = new CategoriaProducto[cantidadRegistrosCategoria];
                ctrlCategorias.Leer(cantidadRegistrosCategoria,listaCategoria);
                for(int x = 0 ; x < cantidadRegistrosCategoria ; x++){

                cout << listaCategoria[x].toCSV() << endl;
                }
                cout << endl;

                int cantidadRegistrosProveedores = cprov.CantidadRegistros();
                Proveedor* listaProveedores = new Proveedor[cantidadRegistrosProveedores];
                cprov.Leer(cantidadRegistrosProveedores,listaProveedores);
                for(int x = 0 ; x < cantidadRegistrosProveedores ; x++){
                    if(listaProveedores[x].getStatus()){
                        cout << listaProveedores[x].toCSV() << endl;
                    }
                }
                cout << endl;




                delete[]listaDetalle;
                delete[]listaCompra;
                delete[]listaProductos;
                delete[]listaCategoria;
                delete[]listaProveedores;

                */


                system("pause");;
                }
                break;
            case 0:{
                limpiarPantallaInformes();
                cout << "\nGracias por utilizar el sistema. Hasta pronto!" << endl;
                }
                break;
            default:{
                cout << "\nOpcion incorrecta, intente nuevamente." << endl;
                cout << "\nPresione Enter para continuar...";
                cin.get();
                }
        }
    } while(opcionMain != 0);
}
