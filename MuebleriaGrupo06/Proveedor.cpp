#include "Proveedor.h"
#include <iostream>
#include <cstring>

Proveedor::Proveedor(){
    _idProveedor = 0;
    strcpy(_cuitCuil,"00-00000000-0");
    strcpy(_nombre,"N/D");
    strcpy(_telefono,"N/D");
    strcpy(_direccion,"N/D");
    _status = true;

}

Proveedor::Proveedor(int idProveedor, std::string cuitCuil, std::string nombre, std::string telefono, std::string direccion, bool status){
    _idProveedor = idProveedor;
    strcpy(_cuitCuil,cuitCuil.c_str());
    strcpy(_nombre,nombre.c_str());
    strcpy(_telefono,telefono.c_str());
    strcpy(_direccion,direccion.c_str());
    _status = status;
}

int Proveedor::getIdProveedor(){
    return _idProveedor;
}

std::string Proveedor::getCuitCuil(){
    return std::string(_cuitCuil);
}

std::string Proveedor::getNombre(){
    return std::string(_nombre);
}

std::string Proveedor::getTelefono(){
    return std::string(_telefono);
}

std::string Proveedor::getDireccion(){
    return std::string(_direccion);
}

bool Proveedor::getStatus(){
    return _status;
}

// No precisa validar datos porque lo realizará el controlador

void Proveedor::setIdProveedor(int idProveedor){
    _idProveedor = idProveedor;
}

void Proveedor::setCuitCuil(std::string cuitCuil){
    strcpy(_cuitCuil,cuitCuil.c_str());
}

void Proveedor::setNombre(std::string nombre){
    strcpy(_nombre,nombre.c_str());
}

void Proveedor::setTelefono(std::string telefono){
    strcpy(_telefono,telefono.c_str());
}

void Proveedor::setDireccion(std::string direccion){
    strcpy(_direccion,direccion.c_str());
}

void Proveedor::setStatus(bool status){
    _status = status;
}


std::string Proveedor::toCSV(){

    std::string str = std::to_string(_idProveedor) + "," + _cuitCuil + "," + _nombre + "," + _telefono + "," + _direccion + "," + std::to_string(_status);
    return str;


}





