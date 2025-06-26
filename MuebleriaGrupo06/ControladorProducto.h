#pragma once
#include <string>
#include "Producto.h"

  class ControladorProducto{
    private:
    std::string _nombreArchivo;

    public:
      ControladorProducto(std::string nombreArchivo);

      bool Guardar(Producto producto);  //debe autoasignar el id

      bool Guardar(Producto producto, int posicion); // en caso de que exista un producto ya existente en .dat en la posicion indicada

      int Buscar(int idProducto);
      Producto BuscarPorNombreProducto (std::string nombre);

      Producto Leer(int posicion);

      int CantidadRegistros();

      void Leer(int CantidadRegistros, Producto *vector);

      bool BorrarTodos();

      bool Eliminar(int idProducto);        // baja lógica
      bool EliminarFisico(int idProducto);  // baja física

        // Funcion para actualizar stock
      bool ActualizarStock(int idProducto, int nuevoStock);
  };
