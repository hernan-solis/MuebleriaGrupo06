#include <iostream>
#include <string>
#include "Menu.h"
#include "Proveedor.h"

using namespace std;


//MENU PROVEEDORES
// Se accede a cargar un nuevo proveedor, a listar todos los proveedores, a volver al menu principal.

void menuProveedores(ControladorProveedor &cp) {
    int opcionProv;

    do {
        cout << "\n--- MENU PROVEEDORES ---" << endl;
        cout << "1. Cargar proveedor nuevo" << endl;
        cout << "2. Ver todos los proveedores" << endl;
        cout << "3. Buscar proveedor por ID" << endl;
        cout << "4. Eliminar proveedor por ID" << endl;
        cout << "0. Volver al menu principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcionProv;
        cin.ignore();

        switch (opcionProv) {
            case 1: {
                Proveedor p;
                string auxStr;
                int auxId;

                cout << "Ingrese CUIT/CUIL: ";
                getline(cin, auxStr);
                p.setCuitCuil(auxStr);

                cout << "Ingrese nombre: ";
                getline(cin, auxStr);
                p.setNombre(auxStr);

                cout << "Ingrese telefono: ";
                getline(cin, auxStr);
                p.setTelefono(auxStr);

                cout << "Ingrese direccion: ";
                getline(cin, auxStr);
                p.setDireccion(auxStr);

                p.setStatus(true);

                if (cp.Guardar(p)) {
                    cout << "Proveedor guardado correctamente." << endl;
                } else {
                    cout << "Error al guardar el proveedor." << endl;
                }
                break;
            }

            /* case 2: {
                int cantidad = cp.CantidadRegistros();
                if (cantidad == 0) {
                    cout << "No hay proveedores cargados." << endl;
                } else {
                    Proveedor* lista = new Proveedor[cantidad];
                    cp.Leer(cantidad, lista);

                    for (int i = 0; i < cantidad; i++) {
                        cout << lista[i].toCSV() << endl;
                    }

                    delete[] lista;
                }
                break;
            }
            */

            case 2: {
            int cantidad = cp.CantidadRegistros();
            if (cantidad == 0) {
               cout << "No hay proveedores cargados." << endl;
            } else {
                Proveedor* lista = new Proveedor[cantidad];
                cp.Leer(cantidad, lista);

          bool hayActivos = false;
               for (int i = 0; i < cantidad; i++) {
               if (lista[i].getStatus()) {
                cout << lista[i].toCSV() << endl;
                hayActivos = true;
                 }
              }
            if (!hayActivos) {
            cout << "No hay proveedores activos para mostrar." << endl;
            }

           delete[] lista;
          }
          break;
        }

            case 3: {
                int idBuscar;
                cout << "Ingrese ID proveedor a buscar: ";
                cin >> idBuscar; cin.ignore();

                int pos = cp.Buscar(idBuscar);
                if (pos != -1) {
                    Proveedor pBuscado = cp.Leer(pos);
                    cout << "Proveedor encontrado:" << endl;
                    cout << pBuscado.toCSV() << endl;
                } else {
                    cout << "Proveedor no encontrado." << endl;
                }
                break;
            }

            case 4: {
                int idEliminar;
                cout << "Ingrese ID del proveedor a eliminar: ";
                cin >> idEliminar;
                cin.ignore();

                if (cp.Eliminar(idEliminar)) {
                    cout << "Proveedor eliminado)." << endl;
                } else {
                    cout << "No se pudo eliminar el proveedor. Verifique que el ID exista." << endl;
                }
                break;
            }

            case 0:
                cout << "Saliendo del menu de proveedores..." << endl;
                break;

            default:
                cout << "Opción inválida. Intente nuevamente." << endl;
        }

    } while (opcionProv != 0);
    }




// Menú principal!
void iniciarMenu(ControladorProveedor &cp) {
    int opcionMain;
    do {
        cout << "\nBienvenido Administrador\n";
        cout << "Seleccione una opcion:\n";
        cout << "1. Proveedores\n";
        cout << "2. Compras\n";
        cout << "3. Productos\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> opcionMain;
        cin.ignore();

        switch(opcionMain) {
            case 1:
                menuProveedores(cp);
                break;
            case 2:
                cout << "\nMenu Compras - en construccion" << endl;
                break;
            case 3:
                cout << "\nMenu Productos - en construccion" << endl;
                break;
            case 0:
                cout << "\nSaliendo..." << endl;
                break;
            default:
                cout << "\nOpcion incorrecta, intente nuevamente." << endl;
        }

    } while(opcionMain != 0);
}

