#pragma once
#include <string>

inline std::string obtenerNombreCategoria(int id) {
    switch(id) {
        case 1: return "Interior";
        case 2: return "Exterior";
        case 3: return "Jardín";
        case 4: return "Oficina";
        case 5: return "Cocina";
        case 6: return "Comedor";
        case 7: return "Dormitorio";
        case 8: return "Baño";
        case 9: return "Infantil";
        case 10: return "Decoración";
        default: return "Desconocida";
    }
}
