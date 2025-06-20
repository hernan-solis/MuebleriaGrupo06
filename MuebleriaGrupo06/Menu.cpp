#include <iostream>
#include "Menu.h"
#include "MenuProveedores.h"
#include "MenuCompras.h"


using namespace std;

// Fn para limpiar la pantalla
void limpiarPantalla() {
    system("cls");
}
void iniciarMenu(ControladorProveedor &cp, ControladorCompra &cc) {
    int opcionMain;
    do {
        limpiarPantalla();
        cout << "\n=====================================================\n";
        cout << "\n           SISTEMA DE GESTION DE MUEBLERIA           \n";
        cout << "\n                   MENU PRINCIPAL                    \n";
        cout << "\n=====================================================\n";
        cout << "\nSeleccione una opcion:\n";
        cout << "1. Proveedores\n";
        cout << "2. Compras\n";
        cout << "3. Productos\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> opcionMain;
        cin.ignore();

        switch(opcionMain) {
            case 1:
                limpiarPantalla();
                menuProveedores(cp);
                break;
            case 2:
                limpiarPantalla();
                menuCompras(cc);
                break;
            case 3:
                limpiarPantalla();
                cout << "\nMenu Productos - en construccion" << endl;
                cout << "\nPresione Enter para continuar...";
                cin.get();
                break;
            case 0:
                limpiarPantalla();
                cout << "\nGracias por utilizar el sistema. Hasta pronto!" << endl;
                break;
            default:
                cout << "\nOpcion incorrecta, intente nuevamente." << endl;
                cout << "\nPresione Enter para continuar...";
                cin.get();
        }
    } while(opcionMain != 0);
}
