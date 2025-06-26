#pragma once
#include <string>

class Validador {
  public:

      // Verifica si un string contiene solo números enteros positivos
    static bool esNumero( std::string texto);

    // Verifica si un string contiene solo letras (y espacios)
    static bool esTexto( std::string texto);

    // Verifica si la longitud del texto está entre min y max
    static bool longitudValida( std::string texto, int minimo, int maximo);

    // Valida CuitCuit
    static bool validarCuitCuil( std::string texto);

    // Valida si el año es bisiesto
    static bool esBisiesto(int anio);

    // Valida Fecha Valida
    static bool esFechaValida(int d, int m, int a);

    // Valida Fecha Valida Mes Año
    static bool esFechaValidaMA(int m, int a);

    // Valida Fecha Valida Año
    static bool esFechaValidaAnio(int a);

    // Verifica si un número entero está dentro de un rango [min, max]
    static bool numeroEnRango(int numero, int minimo, int maximo);

  };
