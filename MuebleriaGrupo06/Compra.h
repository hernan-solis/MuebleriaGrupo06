#pragma once
#include <string>

class Compra {
private:
    int _idCompra;
    int _idProveedor;
    Fecha _fechaCompra; // no olvidar la clase y controlador de FECHA :)
    bool _status;

public:
    Compra();
    Compra(int idCompra, int idProveedor, Fecha fechaCompra, bool status);

    int getIdCompra();
    int getIdProveedor();
    Fecha getFechaCompra();
    bool getStatus();

    void setIdCompra(int idCompra);
    void setIdProveedor(int idProveedor);
    void setFechaCompra(Fecha fechaCompra);
    void setStatus(bool status);

    std::string toCSV();
};
