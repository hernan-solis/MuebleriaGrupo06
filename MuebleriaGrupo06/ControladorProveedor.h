#pragma once
#include <string>
#include "Proveedor.h"

class ControladorProveedor{
    private:
        std::string _nombreArchivo;

    public:
        ControladorProveedor(std::string nombreArchivo);
        bool Guardar(Proveedor proveedor);
        bool Guardar(Proveedor proveedor, int posicion);
        int Buscar(int idProveedor);
        Proveedor Leer(int posicion);
        int CantidadRegistros();
        void Leer(int cantidadRegistros, Proveedor *vector);
};

