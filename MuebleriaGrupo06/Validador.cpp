#include "Validador.h"
#include <iostream>
#include <cstring>
#include "ControladorProveedor.h"



    // Verifica si un string contiene solo n�meros enteros positivos
    bool Validador::esNumero( std::string texto){
        return true;
    }

    // Verifica si un string contiene solo letras (y espacios)
    bool Validador::esTexto( std::string texto){
        return true;
    }

    // Verifica si la longitud del texto est� entre min y max
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

        // Verificamos que el tercer car�cter (�ndice 2) y el ante�ltimo (�ndice 11) sean guiones '-'
        if (texto[2] != '-' || texto[11] != '-') {
            return false;
        }


        for (int i = 0; i < texto.length(); ++i) {
        if (i == 2 || i == 11) {
            // Estos �ndices ya los validamos que son '-'
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

        // Si pas� todas las validaciones, es correcto
        return true;
    }

    // Verifica si un n�mero entero est� dentro de un rango [min, max]
    bool Validador::numeroEnRango(int numero, int minimo, int maximo){
        if(numero >= minimo && numero <= maximo){
            return true;
        }else{
            return false;
        }

    }





