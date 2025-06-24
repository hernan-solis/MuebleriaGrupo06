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
        cout << "\n           SISTEMA DE GESTION DE MUEBLERIA           \n";
        cout << "\n                   MENU INFORMES                     \n";
        cout << "\n=====================================================\n";
        cout << "\nSeleccione una opcion:\n";
        cout << "1. Informe 1\n";
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
                cout << "INFORME" << endl;

                cout << "\nMenu informes en construccion!" << endl;


                ControladorDetalleCompra cdetalle("detallecompras.dat");
                int cantidadRegistros = cdetalle.CantidadRegistros();
                DetalleCompra* lista = new DetalleCompra[cantidadRegistros];

                cdetalle.Leer(cantidadRegistros,lista);

                for(int x = 0 ; x < cantidadRegistros ; x++){
                    cout << lista[x].toCSV() << endl;
                }

                system("pause");

                }
                break;
            case 2:{
                limpiarPantallaInformes();
                cout << "INFORME" << endl;
                system("pause");
                }
                break;
            case 3:{
                limpiarPantallaInformes();
                cout << "INFORME" << endl;
                system("pause");
                }
                break;
            case 4:{
                limpiarPantallaInformes();
                cout << "INFORME" << endl;
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
