#pragma once
#include <string>

inline std::string obtenerNombreCategoria(int id) {
    switch(id) {
        case 1: return "Interior";
        case 2: return "Exterior";
        case 3: return "Jard�n";
        case 4: return "Oficina";
        case 5: return "Cocina";
        case 6: return "Comedor";
        case 7: return "Dormitorio";
        case 8: return "Ba�o";
        case 9: return "Infantil";
        case 10: return "Decoraci�n";
        default: return "Desconocida";
    }
}
