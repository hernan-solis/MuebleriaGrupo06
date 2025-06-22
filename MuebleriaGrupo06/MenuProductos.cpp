#include <iostream>
#include <iomanip>
#include <string>
#include "MenuProductos.h"
#include "Menu.h"
#include "Validador.h"

using namespace std;


void mostrarProductosTabla(Producto* lista, int cantidad) {
    const int anchoId = 6;
    const int anchoNombre = 20;
    const int anchoOrigen = 15;
    const int anchoTipo = 10;
    const int anchoCategoria = 12;
    const int anchoStock = 8;

    cout << "\n";
    cout << "\n         LISTA DE PRODUCTOS     \n";
    cout << "\n";

    cout << left;
    cout << string(anchoId + anchoNombre + anchoOrigen + anchoTipo + anchoCategoria + anchoStock + 5, '-') << endl;
    cout << setw(anchoId) << "ID";
    cout << setw(anchoNombre) << "NOMBRE";
    cout << setw(anchoOrigen) << "ORIGEN";
    cout << setw(anchoCategoria) << "CATEGORIA";
    cout << setw(anchoStock) << "STOCK" << endl;
    cout << string(anchoId + anchoNombre + anchoOrigen + anchoTipo + anchoCategoria + anchoStock + 5, '-') << endl;

    bool hayActivos = false;
    for (int i = 0; i < cantidad; i++) {
        if (lista[i].getStatus()) {
            cout << setw(anchoId) << lista[i].getIdProducto();
            cout << setw(anchoNombre) << lista[i].getNombre();
            cout << setw(anchoOrigen) << lista[i].getOrigen();
            cout << setw(anchoCategoria) << lista[i].getIdCategoria();
            cout << setw(anchoStock) << lista[i].getStock() << endl;
            hayActivos = true;
        }
    }

    if (!hayActivos) cout << "No hay productos activos para mostrar." << endl;

    cout << string(anchoId + anchoNombre + anchoOrigen + anchoTipo + anchoCategoria + anchoStock + 5, '-') << endl;
}

void menuProductos(ControladorProducto &cprod) {
    int opcion;

    do {
        limpiarPantalla();
        cout << "\n================ MENU PRODUCTOS ================\n";
        cout << "1. Cargar producto nuevo" << endl;
        cout << "2. Ver todos los productos" << endl;
        cout << "3. Buscar producto por ID" << endl;
        cout << "4. Eliminar producto por ID" << endl;
        cout << "5. Buscar producto por nombre" << endl;
        cout << "0. Volver al menu principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1: {
                limpiarPantalla();
                Producto p;
                string aux;
                int auxInt;

                do {
                    limpiarPantalla();
                    cout << "Ingrese nombre: ";
                    getline(cin, aux);

                    if (!Validador::longitudValida(aux,0,50)) {
                        cout << endl << endl;
                        cout << "Nombre muy largo, 50 caracteres maximos...";
                        cout << endl << endl;
                        system("pause");
                        }

                    } while (!Validador::longitudValida(aux,0,50));

                p.setNombre(aux);



                do {
                    limpiarPantalla();
                    cout << "Ingrese origen: ";
                    getline(cin, aux);

                    if (!Validador::longitudValida(aux,0,50)) {
                        cout << endl << endl;
                        cout << "Origen muy largo, 50 caracteres maximos...";
                        cout << endl << endl;
                        system("pause");
                        }

                    } while (!Validador::longitudValida(aux,0,50));

                p.setOrigen(aux);

                // VALIDAR FALTA VALIDAR
                cout << "Categorías disponibles:\n";
                cout << "1. Interior\n";
                cout << "2. Exterior\n";
                cout << "3. Jardín\n";
                cout << "4. Oficina\n";
                cout << "5. Cocina\n";
                cout << "6. Comedor\n";
                cout << "7. Dormitorio\n";
                cout << "8. Baño\n";
                cout << "9. Infantil\n";
                cout << "10. Decoración\n";
                cout << "Ingrese el ID de la categoría: ";
                cin >> auxInt; cin.ignore();
                p.setIdCategoria(auxInt);


                do {
                    limpiarPantalla();
                    cout << "Ingrese descripcion: ";
                    getline(cin, aux);

                    if (!Validador::longitudValida(aux,0,100)) {
                        cout << endl << endl;
                        cout << "Descripcion muy larga, 100 caracteres maximos...";
                        cout << endl << endl;
                        system("pause");
                        }

                    } while (!Validador::longitudValida(aux,0,100));

                p.setDescripcion(aux);


                cout << "Ingrese stock: ";
                cin >> auxInt; cin.ignore(); p.setStock(auxInt);

                p.setStatus(true);

                if (cprod.Guardar(p)) {
                    cout << "Producto guardado correctamente." << endl;
                } else {
                    cout << "Error al guardar el producto." << endl;
                }

                cout << "\nPresione Enter para continuar..."; cin.get();
                break;
            }

            case 2: {
                limpiarPantalla();
                int cantidad = cprod.CantidadRegistros();
                if (cantidad == 0) {
                    cout << "No hay productos cargados." << endl;
                } else {
                    Producto* lista = new Producto[cantidad];
                    cprod.Leer(cantidad, lista);
                    mostrarProductosTabla(lista, cantidad);
                    delete[] lista;
                }
                cout << "\nPresione Enter para continuar..."; cin.get();
                break;
            }

            case 3: {
                limpiarPantalla();
                int idBuscar;
                cout << "Ingrese ID del producto a buscar: ";
                cin >> idBuscar; cin.ignore();
                int pos = cprod.Buscar(idBuscar);
                if (pos != -1) {
                    Producto p = cprod.Leer(pos);
                    cout << "Producto encontrado:\n" << p.toCSV() << endl;
                } else {
                    cout << "Producto no encontrado." << endl;
                }
                cout << "\nPresione Enter para continuar..."; cin.get();
                break;
            }

            case 4: {
                limpiarPantalla();
                int idEliminar;
                cout << "Ingrese ID del producto a eliminar: ";
                cin >> idEliminar; cin.ignore();
                if (cprod.Eliminar(idEliminar)) {
                    cout << "Producto eliminado correctamente." << endl;
                } else {
                    cout << "No se pudo eliminar el producto." << endl;
                }
                cout << "\nPresione Enter para continuar..."; cin.get();
                break;
            }

            case 5: {
                limpiarPantalla();
                string nombreBuscar;
                cout << "Ingrese nombre del producto a buscar: ";
                getline(cin, nombreBuscar);
                Producto p = cprod.BuscarPorNombreProducto(nombreBuscar);
                if (p.getIdProducto() != -1) {
                    cout << "Producto encontrado:\n" << p.toCSV() << endl;
                } else {
                    cout << "Producto no encontrado." << endl;
                }
                cout << "\nPresione Enter para continuar..."; cin.get();
                break;
            }

            case 0:
                cout << "Saliendo del menu de productos..." << endl;
                break;

            default:
                cout << "Opción inválida. Intente nuevamente." << endl;
                cout << "\nPresione Enter para continuar..."; cin.get();
        }
    } while (opcion != 0);
}
