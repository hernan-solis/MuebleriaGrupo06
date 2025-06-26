#include "Validador.h"
#include <iostream>
#include <cstring>
#include "ControladorProveedor.h"



    // Verifica si un string contiene solo números enteros positivos
    bool Validador::esNumero( std::string texto){
        return true;
    }

    // Verifica si un string contiene solo letras (y espacios)
    bool Validador::esTexto( std::string texto){
        return true;
    }

    // Verifica si la longitud del texto está entre min y max
    bool Validador::longitudValida( std::string texto, int minimo, int maximo){
        int longitud = texto.length();
        if(longitud >= minimo && longitud <= maximo){
           return true;
        }else{
            return false;
        }
    }

    bool Validador::validarCuitCuil( std::string texto){
        // Primero verificamos que tenga exactamente 13 caracteres
        if(!longitudValida(texto,13,13)){
            return false;
        }

        // Verificamos que el tercer carácter (índice 2) y el anteúltimo (índice 11) sean guiones '-'
        if (texto[2] != '-' || texto[11] != '-') {
            return false;
        }


        for (int i = 0; i < texto.length(); ++i) {
        if (i == 2 || i == 11) {
            // Estos índices ya los validamos que son '-'
            continue;
        }

        char c = texto[i];

        if (
            c != '0' && c != '1' && c != '2' && c != '3' && c != '4' &&
            c != '5' && c != '6' && c != '7' && c != '8' && c != '9'
            ) {
            return false;
            }
        }

        //Verificamos si ya existe ese cuit en la base de datos
        ControladorProveedor cp1 ("proveedores.dat");

        int cantidad = cp1.CantidadRegistros();

        Proveedor *listaProveedores = new Proveedor[cantidad];

        cp1.Leer(cantidad, listaProveedores);

        for(int x = 0 ; x < cantidad ; x++){
            if(listaProveedores[x].getCuitCuil() == texto && listaProveedores[x].getStatus() == true){
                delete[] listaProveedores;
                return false;
            }

        }

        delete[] listaProveedores;

        // Si pasó todas las validaciones, es correcto
        return true;
    }

    // Verifica si un número entero está dentro de un rango [min, max]
    bool Validador::numeroEnRango(int numero, int minimo, int maximo){
        if(numero >= minimo && numero <= maximo){
            return true;
        }else{
            return false;
        }

    }

    // Valida si el año es bisiesto
    bool Validador::esBisiesto(int anio) {
        return (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
    }

    // Valida Fecha Valida
    bool Validador::esFechaValida(int d, int m, int a) {
        if (a < 1900 || a > 2100) return false;
        if (m < 1 || m > 12) return false;
        if (d < 1) return false;

        int diasPorMes[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

        if (esBisiesto(a)) diasPorMes[1] = 29; // febrero

        return d <= diasPorMes[m - 1];
    }

    // Valida Fecha Valida Mes Año
    bool Validador::esFechaValidaMA(int m, int a) {
        if (a < 1900 || a > 2100) return false;
        if (m < 1 || m > 12) return false;
        return true;
    }

    // Valida Fecha Valida Año
    bool Validador::esFechaValidaAnio(int a) {
        if (a < 1900 || a > 2100) return false;
        return true;
    }



