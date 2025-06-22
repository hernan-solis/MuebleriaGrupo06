#include "ControladorDetalleCompra.h"
#include <cstdio>

ControladorDetalleCompra::ControladorDetalleCompra(std::string nombreArchivo) {
    _nombreArchivo = nombreArchivo;
}

bool ControladorDetalleCompra::Guardar(DetalleCompra detalle) {
    FILE* pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if (pArchivo == NULL) return false;

    bool ok = fwrite(&detalle, sizeof(DetalleCompra), 1, pArchivo) == 1;
    fclose(pArchivo);
    return ok;
}

bool ControladorDetalleCompra::Guardar(DetalleCompra detalle, int posicion) {
    FILE* pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if (pArchivo == NULL) return false;

    fseek(pArchivo, sizeof(DetalleCompra) * posicion, SEEK_SET);
    bool ok = fwrite(&detalle, sizeof(DetalleCompra), 1, pArchivo) == 1;
    fclose(pArchivo);
    return ok;
}

int ControladorDetalleCompra::CantidadRegistros() {
    FILE* pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) return 0;

    fseek(pArchivo, 0, SEEK_END);
    int cantidad = ftell(pArchivo) / sizeof(DetalleCompra);
    fclose(pArchivo);
    return cantidad;
}

void ControladorDetalleCompra::Leer(int cantidadRegistros, DetalleCompra* vector) {
    FILE* pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) return;

    for (int i = 0; i < cantidadRegistros; i++) {
        fread(&vector[i], sizeof(DetalleCompra), 1, pArchivo);
    }
    fclose(pArchivo);
}
