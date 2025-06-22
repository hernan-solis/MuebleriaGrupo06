#pragma once
#include <string>
#include "DetalleCompra.h"

class ControladorDetalleCompra {
private:
    std::string _nombreArchivo;

public:
    ControladorDetalleCompra(std::string nombreArchivo);

    bool Guardar(DetalleCompra detalle);
    bool Guardar(DetalleCompra detalle, int posicion);
    int CantidadRegistros();
    void Leer(int cantidadRegistros, DetalleCompra* vector);
};
