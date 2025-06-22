#pragma once
#include "CategoriaProducto.h"
#include <string>

class ControladorCategoriaProducto {
private:
    std::string _nombreArchivo;

public:
    ControladorCategoriaProducto(std::string nombreArchivo);

    bool Guardar(CategoriaProducto categoriaproducto);
    bool Guardar(CategoriaProducto categoriaproducto, int posicion);
    int Buscar(int idCategoria);
    CategoriaProducto BuscarPorNombre(std::string nombre);
    CategoriaProducto Leer(int posicion);
    void Leer(int cantidad, CategoriaProducto *vec);
    int CantidadRegistros();
};
