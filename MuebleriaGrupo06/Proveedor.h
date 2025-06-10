#pragma once
#include <string>


class Proveedor{
    private:
        int _idProveedor;
        char _cuitCuil[14];
        char _nombre[51];
        char _telefono[21];
        char _direccion[101];
        bool _status;

    public:
    Proveedor();
    Proveedor(int idProveedor, std::string cuitCuil, std::string nombre, std::string telefono, std::string direccion, bool status);

    int getIdProveedor();
    std::string getCuitCuil();
    std::string getNombre();
    std::string getTelefono();
    std::string getDireccion();
    bool getStatus();


    void setIdProveedor(int idProveedor);
    void setCuitCuil(std::string cuitCuil);
    void setNombre(std::string nombre);
    void setTelefono(std::string telefono);
    void setDireccion(std::string direccion);
    void setStatus(bool status);


    std::string toCSV();


};

