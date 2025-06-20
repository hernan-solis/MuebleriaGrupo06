#include <iostream>
#include <iomanip>
#include <string>
#include "MenuCompras.h"
#include "Menu.h"

using namespace std;


void mostrarComprasTabla(Compra* lista, int cantidad) {
    // Definir anchos de columnas
    const int anchoId = 6;
    const int anchoProveedor = 10;
    const int anchoFecha = 15;
    cout << "\n";
    cout << "\n         LISTA DE COMPRAS     \n";
    cout << "\n";

    // Imprimir cabecera
    cout << left;
    cout << string(anchoId + anchoProveedor + anchoFecha + 3, '-') << endl;
    cout << setw(anchoId) << "ID";
    cout << setw(anchoProveedor) << "PROVEEDOR";
    cout << setw(anchoFecha) << "FECHA" << endl;
    cout << string(anchoId + anchoProveedor + anchoFecha + 3, '-') << endl;

    // Imprimir datos
    bool hayActivos = false;
    for (int i = 0; i < cantidad; i++) {
        if (lista[i].getStatus()) {
            Fecha fecha = lista[i].getFechaCompra();
            string fechaStr = to_string(fecha.getDia()) + "/" +
                             to_string(fecha.getMes()) + "/" +
                             to_string(fecha.getAnio());

            cout << setw(anchoId) << i+1;
            cout << setw(anchoProveedor) << lista[i].getIdProveedor();
            cout << setw(anchoFecha) << fechaStr << endl;
            hayActivos = true;
        }
    }

    cout << string(anchoId + anchoProveedor + anchoFecha + 3, '-') << endl;

    if (!hayActivos) {
        cout << "No hay compras activas para mostrar." << endl;
    }
}


//MENU COMPRAS
void menuCompras(ControladorCompra &cc) {
    int opcion;
    do {
        limpiarPantalla();
        cout << "\n=====================================================\n";
        cout << "\n                     MENU COMPRAS                   \n";
        cout << "\n=====================================================\n";
        cout << "1. Cargar compra nueva" << endl;
        cout << "2. Ver todas las compras" << endl;
        cout << "3. Buscar compra por ID" << endl;
        cout << "4. Eliminar compra" << endl;
        cout << "0. Volver al menu principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        switch(opcion) {
            case 1: {
                limpiarPantalla();
                Compra c;
                int idProveedor;
                Fecha fecha;
                bool status = true;

                cout << "Ingrese ID del proveedor: ";
                cin >> idProveedor; cin.ignore();
                c.setIdProveedor(idProveedor);

                int dia, mes, anio;
                cout << "Ingrese fecha de compra (dia mes anio): ";
                cin >> dia >> mes >> anio; cin.ignore();
                fecha.setDia(dia);
                fecha.setMes(mes);
                fecha.setAnio(anio);
                c.setFechaCompra(fecha);

                c.setStatus(status);

                if (cc.Guardar(c)) {
                    cout << "Compra guardada correctamente." << endl;
                } else {
                    cout << "Error al guardar la compra." << endl;
                }
                cout << "\nPresione Enter para continuar...";
                cin.get();
                break;
            }
            case 2: {
                limpiarPantalla();
                int cantidad = cc.CantidadRegistros();
                if (cantidad == 0) {
                    cout << "No hay compras cargadas." << endl;
                } else {
                    Compra* lista = new Compra[cantidad];
                    cc.Leer(cantidad, lista);

                    // Mostrar compras como tabla
                    mostrarComprasTabla(lista, cantidad);

                    delete[] lista;
                }
                cout << "\nPresione Enter para continuar...";
                cin.get();
                break;
            }
            case 3: {
                limpiarPantalla();
                int idBuscar;
                cout << "Ingrese ID compra a buscar: ";
                cin >> idBuscar; cin.ignore();

                int pos = cc.Buscar(idBuscar);
                if (pos != -1) {
                    Compra cBuscado = cc.Leer(pos);
                    cout << "Compra encontrada:" << endl;

                    // Mostrar datos de la compra
                    Fecha fecha = cBuscado.getFechaCompra();
                    cout << "ID: " << idBuscar << endl;
                    cout << "Proveedor: " << cBuscado.getIdProveedor() << endl;
                    cout << "Fecha: " << fecha.getDia() << "/" << fecha.getMes() << "/" << fecha.getAnio() << endl;
                   //  cout << "Total: $" << cBuscado.getTotal() << endl;
                } else {
                    cout << "Compra no encontrada." << endl;
                }
                cout << "\nPresione Enter para continuar...";
                cin.get();
                break;
            }
            case 4: {
                limpiarPantalla();
                int idEliminar;
                cout << "Ingrese ID de la compra a eliminar: ";
                cin >> idEliminar;
                cin.ignore();

                if (cc.Eliminar(idEliminar)) {
                    cout << "Compra eliminada correctamente." << endl;
                } else {
                    cout << "No se pudo eliminar la compra. Verifique que el ID exista." << endl;
                }
                cout << "\nPresione Enter para continuar...";
                cin.get();
                break;
            }
            case 0:
                cout << "Saliendo del menu de compras..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente nuevamente." << endl;
                cout << "\nPresione Enter para continuar...";
                cin.get();
        }
    } while(opcion != 0);
}
