#include "CategoriaProducto.h"
#include <cstring>

CategoriaProducto::CategoriaProducto() {
    _idCategoria = 0;
    strcpy(_nombre, "N/D");

}

CategoriaProducto::CategoriaProducto(int idCategoria, std::string nombre) {
    _idCategoria = idCategoria;
    strcpy(_nombre, nombre.c_str());
}

int CategoriaProducto::getIdCategoria() { return _idCategoria; }
std::string CategoriaProducto::getNombre() { return _nombre; }

void CategoriaProducto::setIdCategoria(int idCategoria) { _idCategoria = idCategoria; }
void CategoriaProducto::setNombre(std::string nombre) { strcpy(_nombre, nombre.c_str()); }
