#pragma once
#include <string>
#include "Proveedor.h"
#include "Fecha.h"

class Compra {
private:
    int _idCompra;
    int _idProveedor;
    Fecha _fechaCompra;
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
