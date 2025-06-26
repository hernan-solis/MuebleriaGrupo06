#pragma once
#include <string>
#include "Proveedor.h"

class ControladorProveedor{
    private:
        std::string _nombreArchivo;

    public:
        ControladorProveedor(std::string nombreArchivo);

        // "Abre el archivo binario .dat para agregar contenido al final. Si no existe el dat, lo crea. Autoasigna id"
        bool Guardar(Proveedor proveedor);


        // Sobrescribe un proveedor ya existente en .dat en la posición indicada.
        bool Guardar(Proveedor proveedor, int posicion);


        //Se le pasa un ID Proveedor y devuelve la posicion del registro en el .dat
        int Buscar(int idProveedor);

        //se le pasa un NOMBRE de proveedor y devuelve yun objeto proveedor
        Proveedor BuscarProveedorPorNombre(std::string nombre);


        //Busca posicion y devuelve Proveedor, si no hay nada devuelve Proveedor vacio standar
        Proveedor Leer(int posicion);


        //DEVUELVE LA CANTIDAD DE REGISTROS QUE TIENE EL .DAT
        int CantidadRegistros();


        //GUARDA TODOS LOS REGISTROS FISICOS EN UN ARRAY QUE LE PASEMOS PARA LUEGO TRABAJARLO, ACTIVOS O NO, TODOS
        void Leer(int cantidadRegistros, Proveedor *vector);


        // BORRADO FISICO DE TODOS LOS REGISTROS, LIMPIA POR COMPLETO EL .DAT
        bool BorrarTodos();


        // ELIMINACION FISICA DE 1 REGISTRO
        bool EliminarFisico(int idProveedor);


        // ELIMINACION LOGICA DE 1 REGISTRO
        bool Eliminar(int idProveedor);

        // ACTUALIZA NOMBRE
        bool ActualizarNombre(int idProveedor, std::string nuevoNombre);

};

