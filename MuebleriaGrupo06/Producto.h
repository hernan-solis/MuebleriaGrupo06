#pragma once
#include <string>

class Producto {
  private:
      int _idProducto;
      char _nombre[51];
      char _origen[51];
      int _idCategoria;
      char _descripcion[101];
      int _stock;
      bool _status;

  public:
      Producto();
      Producto(int idProducto, std::string nombre, std::string origen,
               int idCategoria, std::string descripcion, int stock, bool status);

      int getIdProducto();
      std::string getNombre();
      std::string getOrigen();
      int getIdCategoria();
      std::string getDescripcion();
      int getStock();
      bool getStatus();

      void setIdProducto(int idProducto);
      void setNombre(std::string nombre);
      void setOrigen(std::string origen);
      void setIdCategoria(int idCategoria);
      void setDescripcion(std::string descripcion);
      void setStock(int stock);
      void setStatus(bool status);

      std::string toCSV();
  };
