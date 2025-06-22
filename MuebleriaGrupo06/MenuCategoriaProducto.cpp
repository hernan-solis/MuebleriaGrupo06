#include <iostream>
#include "ControladorCategoriaProducto.h"

void mostrarCategorias(ControladorCategoriaProducto& ctrl) {
    int cant = ctrl.CantidadRegistros();
    if (cant == 0) {
        std::cout << "No hay categorias cargadas.\n";
        return;
    }
    CategoriaProducto* lista = new CategoriaProducto[cant];
    ctrl.Leer(cant, lista);

    std::cout << "ID\tNombre\n";
    for (int i = 0; i < cant; i++) {
        std::cout << lista[i].getIdCategoria() << "\t" << lista[i].getNombre() << "\n";
    }
    delete[] lista;
}

void agregarCategoria(ControladorCategoriaProducto& ctrl) {
    std::string nombre;
    std::cout << "Ingrese nombre de la nueva categoria: ";
    std::getline(std::cin, nombre);

    // Validar si ya existe esa categoría
    if (ctrl.BuscarPorNombre(nombre).getIdCategoria() != 0) {
        std::cout << "La categoria ya existe.\n";
        return;
    }

    CategoriaProducto nuevaCategoria;
    nuevaCategoria.setNombre(nombre);

    if (ctrl.Guardar(nuevaCategoria)) {
        std::cout << "Categoria agregada con exito.\n";
    } else {
        std::cout << "Error al guardar la categoria.\n";
    }
}

void menuCategorias(ControladorCategoriaProducto& ctrl) {
    int opcion = 0;
    do {
        std::cout << "\n-- Menu Categorias Producto --\n";
        std::cout << "1. Mostrar categorias\n";
        std::cout << "2. Agregar categoria\n";
        std::cout << "0. Volver al menu principal\n";
        std::cout << "Ingrese opcion: ";
        std::cin >> opcion;
        std::cin.ignore();

        switch (opcion) {
            case 1:
                mostrarCategorias(ctrl);
                break;
            case 2:
                agregarCategoria(ctrl);
                break;
            case 0:
                break;
            default:
                std::cout << "Opcion invalida.\n";
        }
    } while (opcion != 0);
}
