#include "Producto.h"
#include <string>

Producto::Producto() {
    _idProducto = -1;
    _nombre = "N/D";
    _origen = "N/D";
    _idTipo = 0;
    _idCategoria = 0;
    _descripcion = "N/D";
    _stock = 0;
    _status = true;
}

Producto::Producto(int idProducto, std::string nombre, std::string origen, int idTipo, int idCategoria, std::string descripcion, int stock, bool status) {
    _idProducto = idProducto;
    _nombre = nombre;
    _origen = origen;
    _idTipo = idTipo;
    _idCategoria = idCategoria;
    _descripcion = descripcion;
    _stock = stock;
    _status = status;
}

int Producto::getIdProducto() { return _idProducto; }
std::string Producto::getNombre() { return _nombre; }
std::string Producto::getOrigen() { return _origen; }
int Producto::getIdTipo() { return _idTipo; }
int Producto::getIdCategoria() { return _idCategoria; }
std::string Producto::getDescripcion() { return _descripcion; }
int Producto::getStock() { return _stock; }
bool Producto::getStatus() { return _status; }

void Producto::setIdProducto(int idProducto) { _idProducto = idProducto; }
void Producto::setNombre(std::string nombre) { _nombre = nombre; }
void Producto::setOrigen(std::string origen) { _origen = origen; }
void Producto::setIdTipo(int idTipo) { _idTipo = idTipo; }
void Producto::setIdCategoria(int idCategoria) { _idCategoria = idCategoria; }
void Producto::setDescripcion(std::string descripcion) { _descripcion = descripcion; }
void Producto::setStock(int stock) { _stock = stock; }
void Producto::setStatus(bool status) { _status = status; }

std::string Producto::toCSV() {
    return std::to_string(_idProducto) + "," + _nombre + "," + _origen + "," +
           std::to_string(_idTipo) + "," + std::to_string(_idCategoria) + "," +
           _descripcion + "," + std::to_string(_stock) + "," + std::to_string(_status);
}
