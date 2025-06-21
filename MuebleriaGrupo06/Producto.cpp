#include "Producto.h"
#include <string>
#include <cstring>

Producto::Producto() {
    _idProducto = 0;
    strcpy(_nombre, "N/D");
    strcpy(_origen, "N/D");
    _idCategoria = 0;
    strcpy(_descripcion, "N/D");
    _stock = 0;
    _status = true;
}

Producto::Producto(int idProducto, std::string nombre, std::string origen, int idCategoria, std::string descripcion, int stock, bool status) {
    _idProducto = idProducto;
    strcpy(_nombre, nombre.c_str());
    strcpy(_origen, origen.c_str());
    _idCategoria = idCategoria;
    strcpy(_descripcion, descripcion.c_str());
    _stock = stock;
    _status = status;
}

int Producto::getIdProducto() { return _idProducto; }
std::string Producto::getNombre() { return _nombre; }
std::string Producto::getOrigen() { return _origen; }
int Producto::getIdCategoria() { return _idCategoria; }
std::string Producto::getDescripcion() { return _descripcion; }
int Producto::getStock() { return _stock; }
bool Producto::getStatus() { return _status; }

void Producto::setIdProducto(int idProducto) { _idProducto = idProducto; }
void Producto::setNombre(std::string nombre) {strcpy(_nombre, nombre.c_str());}
void Producto::setOrigen(std::string origen) {strcpy(_origen, origen.c_str());}
void Producto::setIdCategoria(int idCategoria) { _idCategoria = idCategoria; }
void Producto::setDescripcion(std::string descripcion) {strcpy(_descripcion, descripcion.c_str());}
void Producto::setStock(int stock) { _stock = stock; }
void Producto::setStatus(bool status) { _status = status; }

std::string Producto::toCSV() {
    return std::to_string(_idProducto) + "," + _nombre + "," + _origen + "," +
          std::to_string(_idCategoria) + "," +
           _descripcion + "," + std::to_string(_stock) + "," + std::to_string(_status);
}
