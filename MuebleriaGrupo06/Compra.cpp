#include <iostream>
#include "Compra.h"
#include "Fecha.h"

Compra::Compra() {
    _idCompra = -1;
    _idProveedor = -1;
    _fechaCompra = Fecha();
    _status = true;
}

Compra::Compra(int idCompra, int idProveedor, Fecha fechaCompra, bool status) {
    _idCompra = idCompra;
    _idProveedor = idProveedor;
    _fechaCompra = fechaCompra;
    _status = status;
}

int Compra::getIdCompra() {
    return _idCompra;
}

int Compra::getIdProveedor() {
    return _idProveedor;
}

Fecha Compra::getFechaCompra() {
    return _fechaCompra;
}

bool Compra::getStatus() {
    return _status;
}

void Compra::setIdCompra(int idCompra) {
    _idCompra = idCompra;
}

void Compra::setIdProveedor(int idProveedor) {
    _idProveedor = idProveedor;
}

void Compra::setFechaCompra(Fecha fechaCompra) {
    _fechaCompra = fechaCompra;
}

void Compra::setStatus(bool status) {
    _status = status;
}

std::string Compra::toCSV() {
    return std::to_string(_idCompra) + "," +
           std::to_string(_idProveedor) + "," +
           _fechaCompra.toString() + "," +
           std::to_string(_status);
}
