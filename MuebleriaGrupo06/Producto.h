#pragma once
#include <string>

class Producto {
private:
    int _idProducto;
    std::string _nombre;
    std::string _origen;
    int _idTipo;
    int _idCategoria;
    std::string _descripcion;
    int _stock;
    bool _status;

public:
    Producto();
    Producto(int idProducto, std::string nombre, std::string origen, int idTipo,
             int idCategoria, std::string descripcion, int stock, bool status);

    int getIdProducto();
    std::string getNombre();
    std::string getOrigen();
    int getIdTipo();
    int getIdCategoria();
    std::string getDescripcion();
    int getStock();
    bool getStatus();

    void setIdProducto(int idProducto);
    void setNombre(std::string nombre);
    void setOrigen(std::string origen);
    void setIdTipo(int idTipo);
    void setIdCategoria(int idCategoria);
    void setDescripcion(std::string descripcion);
    void setStock(int stock);
    void setStatus(bool status);

    std::string toCSV();
};
