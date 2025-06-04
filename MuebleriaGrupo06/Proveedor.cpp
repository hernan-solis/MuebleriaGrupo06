#include "Proveedor.h"
#include <iostream>

Proveedor::Proveedor(){
    _idProveedor = -1;
    _cuitCuil = "N/D";
    _nombre = "N/D";
    _telefono = "N/D";
    _direccion = "N/D";
    _status = true;

}

Proveedor::Proveedor(int idProveedor, std::string cuitCuil, std::string nombre, std::string telefono, std::string direccion, bool status){
    _idProveedor = idProveedor;
    _cuitCuil = cuitCuil;
    _nombre = nombre;
    _telefono = telefono;
    _direccion = direccion;
    _status = status;
}

int Proveedor::getIdProveedor(){
    return _idProveedor;
}

std::string Proveedor::getCuitCuil(){
    return _cuitCuil;
}

std::string Proveedor::getNombre(){
    return _nombre;
}

std::string Proveedor::getTelefono(){
    return _telefono;
}

std::string Proveedor::getDireccion(){
    return _direccion;
}

bool Proveedor::getStatus(){
    return _status;
}

// No precisa validar datos porque lo realizará el controlador

void Proveedor::setIdProveedor(int idProveedor){
    _idProveedor = idProveedor;
}

void Proveedor::setCuitCuil(std::string cuitCuil){
    _cuitCuil = cuitCuil;
}

void Proveedor::setNombre(std::string nombre){
    _nombre = nombre;
}

void Proveedor::setTelefono(std::string telefono){
    _telefono = telefono;
}

void Proveedor::setDireccion(std::string direccion){
    _direccion = direccion;
}

void Proveedor::setStatus(bool status){
    _status = status;
}


std::string Proveedor::toCSV(){

    std::string str = std::to_string(_idProveedor) + "," + _cuitCuil + "," + _nombre + "," + _telefono + "," + _direccion + "," + std::to_string(_status);
    return str;


}





