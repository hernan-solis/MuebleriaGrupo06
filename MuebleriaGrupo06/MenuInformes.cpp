#include <iostream>
#include "MenuInformes.h"
#include "Validador.h"
#include <iomanip>  // <---- esto es necesario para fixed y setprecision - muestra mejor los float


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
        cout << "2. Top 3 Proveedores $ Mes Anio (mm aaaa)\n";
        cout << "3. Top 3 Proveedores $ Anual (aaaa)\n";
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

                // Armo arrays para trabajar
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
                        cout << "ID Prod: " << listaProductos[y].getIdProducto()<< " - " << listaProductos[y].getNombre() << " - Cant: " << listaProductos[y].getStock()<< endl;
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
                cout << "\n           Top 3 Proveedores $ mm aaaa               \n";
                cout << "\n=====================================================\n" << endl << endl;


                // Armo arrays para trabajar

                int cantidadRegistrosDetalle = cdetalle.CantidadRegistros();
                DetalleCompra* listaDetalle = new DetalleCompra[cantidadRegistrosDetalle];
                cdetalle.Leer(cantidadRegistrosDetalle,listaDetalle);

                int cantidadRegistrosCompras = ccomp.CantidadRegistros();
                Compra* listaCompra = new Compra[cantidadRegistrosCompras];
                ccomp.Leer(cantidadRegistrosCompras,listaCompra);

                int cantidadRegistrosProductos = cprod.CantidadRegistros();
                Producto* listaProductos = new Producto[cantidadRegistrosProductos];
                cprod.Leer(cantidadRegistrosProductos,listaProductos);

                int cantidadRegistrosProveedores = cprov.CantidadRegistros();
                Proveedor* listaProveedores = new Proveedor[cantidadRegistrosProveedores];
                cprov.Leer(cantidadRegistrosProveedores,listaProveedores);

                // declaro acumuladores y tambien los inicializo en 0
                float* listaAcumuladores = new float[cantidadRegistrosProveedores];
                for (int i = 0; i < cantidadRegistrosProveedores; i++) {
                listaAcumuladores[i] = 0.0f;
                }


                // ) Pedir fecha
                Fecha fecha;
                int m, a;
                do {
                cout << "Ingrese mes anio a analizar (mm aaaa): ";
                cin >> m >> a;
                cin.ignore();

                if (!Validador::esFechaValidaMA(m,a)) {
                    cout << "Fecha invalida. Intente nuevamente.\n \n";
                }
                } while (!Validador::esFechaValidaMA(m, a));

                // Trabajo los array

                // Recorro las compras
                for(int x = 0; x < cantidadRegistrosCompras ; x++ ){
                    if(listaCompra[x].getStatus() &&
                       listaCompra[x].getFechaCompra().getMes() == m &&
                       listaCompra[x].getFechaCompra().getAnio() == a){

                        //recorro detalle
                        for(int y = 0 ; y < cantidadRegistrosDetalle ; y++){
                            if(listaDetalle[y].getIdCompra() == listaCompra[x].getIdCompra()){
                                //Recorro prov y acumulo
                                for( int z = 0 ; z < cantidadRegistrosProveedores; z++){
                                    if(listaProveedores[z].getIdProveedor() == listaCompra[x].getIdProveedor()){
                                        listaAcumuladores[z] += listaDetalle[y].getCantidad() * listaDetalle[y].getImporteUnitario();
                                    }
                                }
                            }
                        }
                    }
                }

                // Creo array de índices para ordenar sin perder referencia a los proveedores
                int* indices = new int[cantidadRegistrosProveedores];
                for (int i = 0; i < cantidadRegistrosProveedores; i++) {
                    indices[i] = i;
                }

                // Ordenar por gasto (mayor a menor) usando burbujeo simple
                for (int i = 0; i < cantidadRegistrosProveedores - 1; i++) {
                    for (int j = i + 1; j < cantidadRegistrosProveedores; j++) {
                        if (listaAcumuladores[indices[i]] < listaAcumuladores[indices[j]]) {
                            int aux = indices[i];
                            indices[i] = indices[j];
                            indices[j] = aux;
                        }
                    }
                }


                // Muestro el resultado final
                cout << "\n--- TOP 3 PROVEEDORES DEL MES "<< m <<" DEL ANIO "<< a << " ---\n" << endl;
                int mostrados = 0;
                for (int i = 0; i < cantidadRegistrosProveedores && mostrados < 3; i++) {
                    int idx = indices[i];
                    if (listaAcumuladores[idx] > 0 && listaProveedores[idx].getStatus()) {
                        cout << "- " << listaProveedores[idx].getNombre()
                             << " - Total: $ " << fixed << setprecision(2) << listaAcumuladores[idx] << endl;
                        mostrados++;
                    }
                }

                cout << endl << endl;


                delete[]listaDetalle;
                delete[]listaCompra;
                delete[]listaProductos;
                delete[]listaProveedores;
                delete[]listaAcumuladores;
                delete[] indices;

                system("pause");
                }
                break;
            case 3:{

                limpiarPantallaInformes();
                cout << "\n=====================================================\n";
                cout << "\n           Top 3 Proveedores $ aaaa               \n";
                cout << "\n=====================================================\n" << endl << endl;


                // Armo arrays para trabajar

                int cantidadRegistrosDetalle = cdetalle.CantidadRegistros();
                DetalleCompra* listaDetalle = new DetalleCompra[cantidadRegistrosDetalle];
                cdetalle.Leer(cantidadRegistrosDetalle,listaDetalle);

                int cantidadRegistrosCompras = ccomp.CantidadRegistros();
                Compra* listaCompra = new Compra[cantidadRegistrosCompras];
                ccomp.Leer(cantidadRegistrosCompras,listaCompra);

                int cantidadRegistrosProductos = cprod.CantidadRegistros();
                Producto* listaProductos = new Producto[cantidadRegistrosProductos];
                cprod.Leer(cantidadRegistrosProductos,listaProductos);

                int cantidadRegistrosProveedores = cprov.CantidadRegistros();
                Proveedor* listaProveedores = new Proveedor[cantidadRegistrosProveedores];
                cprov.Leer(cantidadRegistrosProveedores,listaProveedores);

                // declaro acumuladores y tambien los inicializo en 0
                float* listaAcumuladores = new float[cantidadRegistrosProveedores];
                for (int i = 0; i < cantidadRegistrosProveedores; i++) {
                listaAcumuladores[i] = 0.0f;
                }


                // ) Pedir fecha
                Fecha fecha;
                int a;
                do {
                cout << "Ingrese anio a analizar (aaaa): ";
                cin >> a;
                cin.ignore();

                if (!Validador::esFechaValidaAnio(a)) {
                    cout << "Fecha invalida. Intente nuevamente.\n \n";
                }
                } while (!Validador::esFechaValidaAnio(a));

                // Trabajo los array

                // Recorro las compras
                for(int x = 0; x < cantidadRegistrosCompras ; x++ ){
                    if(listaCompra[x].getStatus() &&
                       listaCompra[x].getFechaCompra().getAnio() == a){

                        //recorro detalle
                        for(int y = 0 ; y < cantidadRegistrosDetalle ; y++){
                            if(listaDetalle[y].getIdCompra() == listaCompra[x].getIdCompra()){
                                //Recorro prov y acumulo
                                for( int z = 0 ; z < cantidadRegistrosProveedores; z++){
                                    if(listaProveedores[z].getIdProveedor() == listaCompra[x].getIdProveedor()){
                                        listaAcumuladores[z] += listaDetalle[y].getCantidad() * listaDetalle[y].getImporteUnitario();
                                    }
                                }
                            }
                        }
                    }
                }

                // Creo array de índices para ordenar sin perder referencia a los proveedores
                int* indices = new int[cantidadRegistrosProveedores];
                for (int i = 0; i < cantidadRegistrosProveedores; i++) {
                    indices[i] = i;
                }

                // Ordenar por gasto (mayor a menor) usando burbujeo simple
                for (int i = 0; i < cantidadRegistrosProveedores - 1; i++) {
                    for (int j = i + 1; j < cantidadRegistrosProveedores; j++) {
                        if (listaAcumuladores[indices[i]] < listaAcumuladores[indices[j]]) {
                            int aux = indices[i];
                            indices[i] = indices[j];
                            indices[j] = aux;
                        }
                    }
                }


                // Muestro el resultado final
                cout << "\n--- TOP 3 PROVEEDORES DEL ANIO "<< a <<" ---\n" << endl;
                int mostrados = 0;
                for (int i = 0; i < cantidadRegistrosProveedores && mostrados < 3; i++) {
                    int idx = indices[i];
                    if (listaAcumuladores[idx] > 0 && listaProveedores[idx].getStatus()) {
                        cout << "- " << listaProveedores[idx].getNombre()
                             << " - Total: $ " << fixed << setprecision(2) << listaAcumuladores[idx] << endl;
                        mostrados++;
                    }
                }

                cout << endl << endl;


                delete[]listaDetalle;
                delete[]listaCompra;
                delete[]listaProductos;
                delete[]listaProveedores;
                delete[]listaAcumuladores;
                delete[] indices;

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


                int cantidadRegistrosCompras = ccomp.CantidadRegistros();
                Compra* listaCompra = new Compra[cantidadRegistrosCompras];
                ccomp.Leer(cantidadRegistrosCompras,listaCompra);


                int cantidadRegistrosProductos = cprod.CantidadRegistros();
                Producto* listaProductos = new Producto[cantidadRegistrosProductos];
                cprod.Leer(cantidadRegistrosProductos,listaProductos);


                int cantidadRegistrosCategoria = ctrlCategorias.CantidadRegistros();
                CategoriaProducto* listaCategoria = new CategoriaProducto[cantidadRegistrosCategoria];
                ctrlCategorias.Leer(cantidadRegistrosCategoria,listaCategoria);


                int cantidadRegistrosProveedores = cprov.CantidadRegistros();
                Proveedor* listaProveedores = new Proveedor[cantidadRegistrosProveedores];
                cprov.Leer(cantidadRegistrosProveedores,listaProveedores);








                delete[]listaDetalle;
                delete[]listaCompra;
                delete[]listaProductos;
                delete[]listaProveedores;

                */

                system("pause");
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
