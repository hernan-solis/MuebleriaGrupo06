#include "DetalleCompra.h"
#include <string>

DetalleCompra::DetalleCompra() {
    _idCompra = -1;
    _idProducto = -1;
    _cantidad = 0;
    _importeUnitario = 0;
}

DetalleCompra::DetalleCompra(int idCompra, int idProducto, int cantidad, float importeUnitario) {
    _idCompra = idCompra;
    _idProducto = idProducto;
    _cantidad = cantidad;
    _importeUnitario = importeUnitario;
}

int DetalleCompra::getIdCompra() { return _idCompra; }
int DetalleCompra::getIdProducto() { return _idProducto; }
int DetalleCompra::getCantidad() { return _cantidad; }
float DetalleCompra::getImporteUnitario() { return _importeUnitario; }

void DetalleCompra::setIdCompra(int idCompra) { _idCompra = idCompra; }
void DetalleCompra::setIdProducto(int idProducto) { _idProducto = idProducto; }
void DetalleCompra::setCantidad(int cantidad) { _cantidad = cantidad; }
void DetalleCompra::setImporteUnitario(float importe) { _importeUnitario = importe; }

std::string DetalleCompra::toCSV() {
    return std::to_string(_idCompra) + "," +
           std::to_string(_idProducto) + "," +
           std::to_string(_cantidad) + "," +
           std::to_string(_importeUnitario);
}
