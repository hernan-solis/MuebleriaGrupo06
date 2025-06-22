#pragma once
#include <string>

class CategoriaProducto {
private:
    int _idCategoria;
    char _nombre[51];

public:
    CategoriaProducto();
    CategoriaProducto(int idCategoria, std::string nombre);

    int getIdCategoria();
    std::string getNombre();

    void setIdCategoria(int idCategoria);
    void setNombre(std::string nombre);
};
