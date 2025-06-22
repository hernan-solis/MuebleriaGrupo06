#include <iostream>
#include <iomanip>
#include <string>
#include "MenuCompras.h"
#include "Menu.h"
#include "ControladorProveedor.h"
#include "ControladorProducto.h"
#include "ControladorDetalleCompra.h"
#include "ControladorCategoriaProducto.h"
#include "MenuProveedores.h"
#include "MenuProductos.h"

using namespace std;



void cargarCompraConDetalle(ControladorCompra &ccomp,
                             ControladorProveedor &cprov,
                             ControladorProducto &cprod,
                             ControladorDetalleCompra &cdetalle,
                             ControladorCategoriaProducto &ctrlCategorias){
    using namespace std;

    limpiarPantalla();

    // 1) Elegir proveedor o agregar uno nuevo
    int cantProv = cprov.CantidadRegistros();
    if (cantProv == 0) {
        cout << "No hay proveedores cargados. Debe agregar uno.\n";
        // Llamar función para agregar proveedor (debes tenerla)
        menuProveedores(cprov);
        cantProv = cprov.CantidadRegistros();
        if (cantProv == 0) {
            cout << "No se agregó ningún proveedor. Cancelando carga.\n";
            cout << "Presione Enter para continuar...";
            cin.get();
            return;
        }
    }

    // Mostrar proveedores
    Proveedor* listaProv = new Proveedor[cantProv];
    cprov.Leer(cantProv, listaProv);
    cout << "Proveedores disponibles:\n";
    for (int i = 0; i < cantProv; i++) {
        cout << listaProv[i].getIdProveedor() << ". " << listaProv[i].getNombre() << "\n";
    }

    int idProveedor;
    bool proveedorValido = false;
    do {
        cout << "Ingrese ID del proveedor (o 0 para agregar uno nuevo): ";
        cin >> idProveedor;
        cin.ignore();

        if (idProveedor == 0) {
            menuProveedores(cprov);  // función para agregar proveedor
            cantProv = cprov.CantidadRegistros();
            delete[] listaProv;
            listaProv = new Proveedor[cantProv];
            cprov.Leer(cantProv, listaProv);
            cout << "Proveedores actualizados:\n";
            for (int i = 0; i < cantProv; i++) {
                cout << listaProv[i].getIdProveedor() << ". " << listaProv[i].getNombre() << "\n";
            }
        } else {
            for (int i = 0; i < cantProv; i++) {
                if (listaProv[i].getIdProveedor() == idProveedor) {
                    proveedorValido = true;
                    break;
                }
            }
            if (!proveedorValido) {
                cout << "ID de proveedor inválido. Intente nuevamente.\n";
            }
        }
    } while (!proveedorValido);

    delete[] listaProv;

    // 2) Pedir fecha compra
    Fecha fecha;
    int d, m, a;
    cout << "Ingrese fecha de compra (dia mes anio): ";
    cin >> d >> m >> a;
    cin.ignore();
    fecha.setDia(d);
    fecha.setMes(m);
    fecha.setAnio(a);

    // 3) Crear compra y guardar
    Compra compra;
    compra.setIdProveedor(idProveedor);
    compra.setFechaCompra(fecha);
    compra.setStatus(true);

    if (!ccomp.Guardar(compra)) {
        cout << "Error al guardar la compra.\n";
        cout << "Presione Enter para continuar...";
        cin.get();
        return;
    }

    // Obtener el ID asignado a la compra recién guardada
    int idCompra = 0;
    int cantidadCompras = ccomp.CantidadRegistros();
    if (cantidadCompras > 0) {
        Compra* listaCompras = new Compra[cantidadCompras];
        ccomp.Leer(cantidadCompras, listaCompras);
        idCompra = listaCompras[cantidadCompras -1].getIdCompra();
        delete[] listaCompras;
    }

    // 4) Ahora cargar productos (detalle compra)
    char opcion;
    do {
        int cantProd = cprod.CantidadRegistros();
        if (cantProd == 0) {
            cout << "No hay productos cargados. Debe agregar uno.\n";
            menuProductos(cprod, ctrlCategorias); //FUNCION PARA AGREGAR PRODUCTOS
            cantProd = cprod.CantidadRegistros();
            if (cantProd == 0) {
                cout << "No se agregó ningún producto. Cancelando carga.\n";
                cout << "Presione Enter para continuar...";
                cin.get();
                return;
            }
        }

        Producto* listaProd = new Producto[cantProd];
        cprod.Leer(cantProd, listaProd);
        cout << "Productos disponibles:\n";
        for (int i = 0; i < cantProd; i++) {
            cout << listaProd[i].getIdProducto() << ". " << listaProd[i].getNombre() << "\n";
        }

        int idProducto;
        bool productoValido = false;
        do {
            cout << "Ingrese ID del producto (o 0 para agregar uno nuevo): ";
            cin >> idProducto;
            cin.ignore();

            if (idProducto == 0) {
                void menuProductos(ControladorProducto &cprod, ControladorCategoriaProducto &ctrlCategorias); // función para agregar producto
                cantProd = cprod.CantidadRegistros();
                delete[] listaProd;
                listaProd = new Producto[cantProd];
                cprod.Leer(cantProd, listaProd);
                cout << "Productos actualizados:\n";
                for (int i = 0; i < cantProd; i++) {
                    cout << listaProd[i].getIdProducto() << ". " << listaProd[i].getNombre() << "\n";
                }
            } else {
                for (int i = 0; i < cantProd; i++) {
                    if (listaProd[i].getIdProducto() == idProducto) {
                        productoValido = true;
                        break;
                    }
                }
                if (!productoValido) {
                    cout << "ID de producto inválido. Intente nuevamente.\n";
                }
            }
        } while (!productoValido);

        int cantidad;
        float importe;
        cout << "Ingrese cantidad: ";
        cin >> cantidad;
        cout << "Ingrese importe unitario: ";
        cin >> importe;
        cin.ignore();

        // Crear detalle y guardar
        DetalleCompra detalle(idCompra, idProducto, cantidad, importe);
        if (!cdetalle.Guardar(detalle)) {
            cout << "Error al guardar el detalle de compra.\n";
                } else {
            cout << "Detalle guardado correctamente.\n";

            // !!!!!!!!!!!!!!! ACTUALIZAR STOCK DEL PRODUCTO
            int posProd = cprod.Buscar(idProducto);
            if (posProd != -1) {
                Producto prod = cprod.Leer(posProd);
                int nuevoStock = prod.getStock() + cantidad;
                prod.setStock(nuevoStock);
                cprod.Guardar(prod, posProd);
                cout << "Stock del producto actualizado: " << nuevoStock << endl;
            } else {
                cout << "No se encontró el producto para actualizar el stock." << endl;
            }
        }


        delete[] listaProd;

        cout << "¿Desea agregar otro producto? (s/n): ";
        cin >> opcion;
        cin.ignore();
    } while (opcion == 's' || opcion == 'S'); // agregue las s en mayus y min para q cualquiera de las dos ande :)

    cout << "Compra con detalle cargada exitosamente.\n";
    cout << "Presione Enter para continuar...";
    cin.get();
}


void mostrarCompraConDetalle(Compra &compra,
                            ControladorProveedor &cprov,
                            ControladorDetalleCompra &cdetalle,
                            ControladorProducto &cprod) {

    // Mostrar datos básicos
    cout << "ID Compra: " << compra.getIdCompra() << endl;

    // Buscar proveedor para mostrar nombre
    int idProv = compra.getIdProveedor();
    int posProv = cprov.Buscar(idProv);
    if (posProv != -1) {
        Proveedor prov = cprov.Leer(posProv);
        cout << "Proveedor: " << prov.getNombre() << endl;
    } else {
        cout << "Proveedor: (No encontrado)" << endl;
    }

    // Fecha
    Fecha fecha = compra.getFechaCompra();
    cout << "Fecha: " << fecha.getDia() << "/" << fecha.getMes() << "/" << fecha.getAnio() << endl;

    // Mostrar detalle
    int cantDetalles = cdetalle.CantidadRegistros();

    // Leer todos los detalles
    DetalleCompra *detalles = new DetalleCompra[cantDetalles];
    cdetalle.Leer(cantDetalles, detalles);

    cout << "\nDetalle de la compra:\n";
    cout << "Producto  Cantidad  Importe Unitario  Subtotal\n";

    float totalCompra = 0;

    for (int i = 0; i < cantDetalles; i++) {
        if (detalles[i].getIdCompra() == compra.getIdCompra()) {
            // Obtener producto para mostrar nombre
            int idProd = detalles[i].getIdProducto();
            int posProd = cprod.Buscar(idProd);
            string nombreProd = "(No encontrado)";
            if (posProd != -1) {
                Producto prod = cprod.Leer(posProd);
                nombreProd = prod.getNombre();
            }

            int cantidad = detalles[i].getCantidad();
            float importeUnitario = detalles[i].getImporteUnitario();
            float subtotal = cantidad * importeUnitario;
            totalCompra += subtotal;

            cout <<  nombreProd << "        " << cantidad << "          " << importeUnitario << "            " << subtotal << endl;
        }
    }



    cout << "\nTotal compra: $" << totalCompra << endl;

    delete[] detalles;
}


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
void menuCompras(ControladorCompra &ccomp,
                 ControladorDetalleCompra &cdetalle,
                 ControladorProveedor &cprov,
                 ControladorProducto &cprod,
                 ControladorCategoriaProducto &ctrlCategorias){
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
                cargarCompraConDetalle(ccomp, cprov, cprod, cdetalle, ctrlCategorias);
                break;
            }
            case 2: {
                limpiarPantalla();
                int cantidad = ccomp.CantidadRegistros();
                if (cantidad == 0) {
                    cout << "No hay compras cargadas." << endl;
                } else {
                    Compra* lista = new Compra[cantidad];
                    ccomp.Leer(cantidad, lista);

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

                int pos = ccomp.Buscar(idBuscar);
               if (pos != -1) {
                    Compra cBuscado = ccomp.Leer(pos);
                    mostrarCompraConDetalle(cBuscado, cprov, cdetalle, cprod);
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

                if (ccomp.Eliminar(idEliminar)) {
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






