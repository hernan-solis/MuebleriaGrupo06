#pragma once
#include <string>

class DetalleCompra {
private:
    int _idCompra;      // ID de la compra a la que pertenece
    int _idProducto;    // Producto comprado
    int _cantidad;
    float _importeUnitario;

public:
    DetalleCompra();
    DetalleCompra(int idCompra, int idProducto, int cantidad, float importeUnitario);

    int getIdCompra();
    int getIdProducto();
    int getCantidad();
    float getImporteUnitario();

    void setIdCompra(int idCompra);
    void setIdProducto(int idProducto);
    void setCantidad(int cantidad);
    void setImporteUnitario(float importe);

    std::string toCSV();
};
