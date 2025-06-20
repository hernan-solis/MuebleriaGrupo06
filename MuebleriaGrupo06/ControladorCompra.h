#pragma once
#include <string>
#include "Compra.h"


class ControladorCompra {
  private:
    std::string _nombreArchivo;

  public:
    ControladorCompra(std::string _nombreArchivo);

    // Abre el archivo binario .dat para agregar contenido al final. Si no existe el archivo .dat lo creará. Y el ID es autoasignado
    bool Guardar(Compra compra);

    // Sobreescribe una compra ya existente en .dat en la posicion indicada.
    bool Guardar (Compra compra, int posicion);

    //Se le pasa un ID Proveedor y devuelve la posicion del registro en el archivo .dat
    int Buscar(int idCompra);

    // Busca la posicion y devuelve la compra, si no hay nada devuelve la Compra vacia
    Compra Leer(int posicion);

    //Devuelve la cantidad de registros que tiene el .dat
    int CantidadRegistros();

    //Guarda todos los registros fisicos en un array que le pasamos para luego trabajarlos, ya sean registros 'activos' o no.
    void Leer(int cantidadRegistros, Compra *vector);

    //Hard delete
    bool BorrarTodos();

    //Hard delete de un solo archivo
    bool EliminarFisico(int idCompra);

    //Soft delete de un solo archivo.
    bool Eliminar(int idCompra);
};
