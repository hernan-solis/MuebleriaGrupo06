#include <iostream>
#include <iomanip>
#include <string>
#include "MenuProductos.h"
#include "MenuCategoriaProducto.h"
#include "Menu.h"


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

void menuProductos(ControladorProducto &cprod, ControladorCategoriaProducto &ctrlCategorias) {
    int opcion;

    do {
        limpiarPantalla();
        cout << "\n================ MENU PRODUCTOS ================\n";
        cout << "1. Cargar producto nuevo" << endl;
        cout << "2. Ver todos los productos" << endl;
        cout << "3. Buscar producto por ID" << endl;
        cout << "4. Eliminar producto por ID" << endl;
        cout << "5. Buscar producto por nombre" << endl;
        cout << "6. Gestionar categorias" << endl;
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

                cout << "Ingrese nombre: ";
                getline(cin, aux); p.setNombre(aux);

                cout << "Ingrese origen: ";
                getline(cin, aux); p.setOrigen(aux);



                int cantCat = ctrlCategorias.CantidadRegistros();
                  if (cantCat == 0) {
                    cout << "No hay categorías cargadas. Vamos a crear una ahora.\n";

                    string nuevoNombre;
                    cout << "Ingrese nombre de la nueva categoría: ";
                    getline(cin, nuevoNombre);

                    if (ctrlCategorias.BuscarPorNombre(nuevoNombre).getIdCategoria() != 0) {
                        cout << "Esa categoría ya existe.\n";
                    } else {
                        CategoriaProducto nuevaCat;
                        nuevaCat.setNombre(nuevoNombre);
                        if (ctrlCategorias.Guardar(nuevaCat)) {
                            cout << "Categoría agregada con éxito.\n";
                        } else {
                            cout << "Error al guardar la categoría.\n";
                        }
                    }

                    // Actualizamos categorías
                    cantCat = ctrlCategorias.CantidadRegistros();
                    if (cantCat == 0) {
                        cout << "No se pudo crear una categoría válida. Cancelando carga de producto.\n";
                        cout << "\nPresione Enter para continuar..."; cin.get();
                        return;
                    }
                }


                  CategoriaProducto* categorias = new CategoriaProducto[cantCat];
                  ctrlCategorias.Leer(cantCat, categorias);

                  cout << "Categorías disponibles:\n";
                  for (int i = 0; i < cantCat; i++) {
                      cout << categorias[i].getIdCategoria() << ". " << categorias[i].getNombre() << "\n";
                  }

                  bool valido = false;
                 do {
                  cout << "Ingrese el ID de la categoría (o 0 para agregar una nueva): ";
                  cin >> auxInt;
                  cin.ignore();

                  if (auxInt == 0) {
                      delete[] categorias;
                      string nuevoNombre;
                      cout << "Ingrese nombre de la nueva categoría: ";
                      getline(cin, nuevoNombre);

                      if (ctrlCategorias.BuscarPorNombre(nuevoNombre).getIdCategoria() != 0) {
                          cout << "Esa categoría ya existe.\n";
                      } else {
                          CategoriaProducto nuevaCat;
                          nuevaCat.setNombre(nuevoNombre);
                          if (ctrlCategorias.Guardar(nuevaCat)) {
                              cout << "Categoría agregada con éxito.\n";
                              cantCat = ctrlCategorias.CantidadRegistros();  // actualizar lista
                              categorias = new CategoriaProducto[cantCat];
                              ctrlCategorias.Leer(cantCat, categorias);
                              auxInt = categorias[cantCat - 1].getIdCategoria();  // usar el último ID asignado
                              valido = true;
                          } else {
                              cout << "Error al guardar la categoría.\n";
                          }
                      }
                  } else {
                      for (int i = 0; i < cantCat; i++) {
                          if (categorias[i].getIdCategoria() == auxInt) {
                              valido = true;
                              break;
                          }
                      }
                      if (!valido) {
                          cout << "ID de categoría inválido. Intente de nuevo.\n";
                      }
                  }
              } while (!valido);


                  p.setIdCategoria(auxInt);
                  delete[] categorias;


                cout << "Ingrese descripción: ";
                getline(cin, aux); p.setDescripcion(aux);

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


            case 6:
              limpiarPantalla();
              menuCategorias(ctrlCategorias);
              break;

            case 0:
                cout << "Saliendo del menu de productos..." << endl;
                break;

            default:
                cout << "Opción inválida. Intente nuevamente." << endl;
                cout << "\nPresione Enter para continuar..."; cin.get();
        }
    } while (opcion != 0);
}
