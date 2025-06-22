#include <iostream>
#include <iomanip>
#include <string>
#include "MenuProveedores.h"
#include "Menu.h"
#include "Validador.h"

using namespace std;

// Función para mostrar proveedores en formato tabla
void mostrarProveedoresTabla(Proveedor* lista, int cantidad) {
    // Definir anchos de columnas
    const int anchoId = 6;
    const int anchoCuit = 15;
    const int anchoNombre = 30;
    const int anchoTelefono = 15;
    const int anchoDireccion = 30;

    cout << "\n";
    cout << "\n         LISTA DE PROVEEDORES     \n";
    cout << "\n";


    // Imprimir cabecera
    cout << left;
    cout << string(anchoId + anchoCuit + anchoNombre + anchoTelefono + anchoDireccion + 5, '-') << endl;
    cout << setw(anchoId) << "ID";
    cout << setw(anchoCuit) << "CUIT/CUIL";
    cout << setw(anchoNombre) << "NOMBRE";
    cout << setw(anchoTelefono) << "TELEFONO";
    cout << setw(anchoDireccion) << "DIRECCION" << endl;
    cout << string(anchoId + anchoCuit + anchoNombre + anchoTelefono + anchoDireccion + 5, '-') << endl;

    // Imprimimosr datos
    bool hayActivos = false;
    for (int i = 0; i < cantidad; i++) {
        if (lista[i].getStatus()) {
            cout << setw(anchoId) << i+1;
            cout << setw(anchoCuit) << lista[i].getCuitCuil();
            cout << setw(anchoNombre) << lista[i].getNombre();
            cout << setw(anchoTelefono) << lista[i].getTelefono();
            cout << setw(anchoDireccion) << lista[i].getDireccion() << endl;
            hayActivos = true;
        }
    }

    cout << string(anchoId + anchoCuit + anchoNombre + anchoTelefono + anchoDireccion + 5, '-') << endl;

    if (!hayActivos) {
        cout << "No hay proveedores activos para mostrar." << endl;
    }
}

// menú de proveedores
void menuProveedores(ControladorProveedor &cprov) {
    int opcionProv;

    do {
        limpiarPantalla();
        cout << "\n=====================================================\n";
        cout << "\n                   MENU PROVEEDORES                  \n";
        cout << "\n=====================================================\n";
        cout << "1. Cargar proveedor nuevo" << endl;
        cout << "2. Ver todos los proveedores" << endl;
        cout << "3. Buscar proveedor por ID" << endl;
        cout << "4. Eliminar proveedor por ID" << endl;
        cout << "5. Buscar proveedor por nombre" << endl;
        cout << "0. Volver al menu principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcionProv;
        cin.ignore();

        switch (opcionProv) {
             case 1: {
                limpiarPantalla();
                Proveedor p;
                string auxStr;

                do {
                    limpiarPantalla();
                    cout << "Ingrese CUIT/CUIL en formato 00-00000000-0: ";
                    getline(cin, auxStr);

                    if (!Validador::validarCuitCuil(auxStr)) {
                        cout << endl << endl;
                        cout << "CUIT/CUIL invalido o ya existente. Intente nuevamente...\n";
                        cout << endl << endl;
                        system("pause");
                        }

                    } while (!Validador::validarCuitCuil(auxStr));

                p.setCuitCuil(auxStr);

                do {
                    limpiarPantalla();
                    cout << "Ingrese nombre: ";
                    getline(cin, auxStr);

                    if (!Validador::longitudValida(auxStr,0,50)) {
                        cout << endl << endl;
                        cout << "Nombre muy largo, 50 caracteres maximos...";
                        cout << endl << endl;
                        system("pause");
                        }

                    } while (!Validador::longitudValida(auxStr,0,50));

                p.setNombre(auxStr);



                do {
                    limpiarPantalla();
                    cout << "Ingrese telefono: ";
                    getline(cin, auxStr);

                    if (!Validador::longitudValida(auxStr,0,20)) {
                        cout << endl << endl;
                        cout << "Telefono muy largo, 20 caracteres maximos...";
                        cout << endl << endl;
                        system("pause");
                        }

                    } while (!Validador::longitudValida(auxStr,0,20));

                p.setTelefono(auxStr);


                do {
                    limpiarPantalla();
                    cout << "Ingrese direccion (calle y numero): ";
                    getline(cin, auxStr);

                    if (!Validador::longitudValida(auxStr,0,100)) {
                        cout << endl << endl;
                        cout << "Direccion muy larga, 100 caracteres maximos...";
                        cout << endl << endl;
                        system("pause");
                        }

                    } while (!Validador::longitudValida(auxStr,0,100));

                p.setDireccion(auxStr);



                p.setStatus(true);




                if (cprov.Guardar(p)) {
                    limpiarPantalla();
                    cout << "Proveedor guardado correctamente." << endl;
                } else {
                    limpiarPantalla();
                    cout << "Error al guardar el proveedor." << endl;
                }
                cout << "\nPresione Enter para continuar...";
                cin.get();
                break;
            }
            case 2: {
                limpiarPantalla();
                int cantidad = cprov.CantidadRegistros();
                if (cantidad == 0) {
                    cout << "No hay proveedores cargados." << endl;
                } else {
                    Proveedor* lista = new Proveedor[cantidad];
                    cprov.Leer(cantidad, lista);

                    // Mostrar solo los proveedores activos en formato tabla
                    mostrarProveedoresTabla(lista, cantidad);

                    delete[] lista;
                }
                cout << "\nPresione Enter para continuar...";
                cin.get();
                break;
            }

            case 3: {
                limpiarPantalla();
                int idBuscar;
                cout << "Ingrese ID proveedor a buscar: ";
                cin >> idBuscar; cin.ignore();

                int pos = cprov.Buscar(idBuscar);
                if (pos != -1) {
                    Proveedor pBuscado = cprov.Leer(pos);
                    cout << "Proveedor encontrado:" << endl;
                    cout << pBuscado.toCSV() << endl;
                } else {
                    cout << "Proveedor no encontrado." << endl;
                }
                cout << "\nPresione Enter para continuar...";
                cin.get();
                break;
            }

            case 4: {
                limpiarPantalla();
                int idEliminar;
                cout << "Ingrese ID del proveedor a eliminar: ";
                cin >> idEliminar;
                cin.ignore();

                if (cprov.Eliminar(idEliminar)) {
                    cout << "Proveedor eliminado)." << endl;
                } else {
                    cout << "No se pudo eliminar el proveedor. Verifique que el ID exista." << endl;
                }
                cout << "\nPresione Enter para continuar...";
                cin.get();
                break;
            }

            case 5: {
                limpiarPantalla();
                string nombreBuscar;
                cout << "Ingrese el nombre del proveedor a buscar: ";
                getline(cin, nombreBuscar);

                Proveedor pBuscado = cprov.BuscarProveedorPorNombre(nombreBuscar);
                if (pBuscado.getIdProveedor() != 0) { // verifica que no sea el vacío
                    cout << "Proveedor encontrado:" << endl;
                    // cout << pBuscado.toCSV() << endl;  //¿¿¿DEVOLVEMOS TODO EL PROVEEDOR O SIMPLEMENTE SU ID Y SU NOMBRE??
                    cout << "Id de Proveedor: ";
                    cout << pBuscado.getIdProveedor()  << endl;
                    cout << "Nombre del proveedor: ";
                    cout << pBuscado.getNombre()  << endl;
                } else {
                    cout << "Proveedor no encontrado." << endl;
                }

                cout << "\nPresione Enter para continuar...";
                cin.get();
                break;
          }

            case 0:
                cout << "Saliendo del menu de proveedores..." << endl;
                break;

            default:
                cout << "Opción inválida. Intente nuevamente." << endl;
                cout << "\nPresione Enter para continuar...";
                cin.get();
        }

    } while (opcionProv != 0);
}
