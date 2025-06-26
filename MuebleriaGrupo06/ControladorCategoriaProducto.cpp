#include "ControladorCategoriaProducto.h"
#include <cstdio>
#include <cstring>

ControladorCategoriaProducto::ControladorCategoriaProducto(std::string nombreArchivo) {
    _nombreArchivo = nombreArchivo;
}

bool ControladorCategoriaProducto::Guardar(CategoriaProducto categoria) {
    int cantidad = CantidadRegistros();
    int maxId = 0;

    if (cantidad > 0) {
        CategoriaProducto* lista = new CategoriaProducto[cantidad];
        Leer(cantidad, lista);
        for (int i = 0; i < cantidad; i++) {
            if (lista[i].getIdCategoria() > maxId) {
                maxId = lista[i].getIdCategoria();
            }
        }
        delete[] lista;
    }

    categoria.setIdCategoria(maxId + 1);

    FILE* pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if (pArchivo == NULL) return false;

    bool ok = fwrite(&categoria, sizeof(CategoriaProducto), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

bool ControladorCategoriaProducto::Guardar(CategoriaProducto categoria, int posicion) {
    FILE* pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if (pArchivo == NULL) return false;

    fseek(pArchivo, sizeof(CategoriaProducto) * posicion, SEEK_SET);
    bool ok = fwrite(&categoria, sizeof(CategoriaProducto), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

int ControladorCategoriaProducto::Buscar(int idCategoria) {
    FILE* pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) return -1;

    CategoriaProducto cat;
    int i = 0;
    while (fread(&cat, sizeof(CategoriaProducto), 1, pArchivo)) {
        if (cat.getIdCategoria() == idCategoria) {
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}

CategoriaProducto ControladorCategoriaProducto::BuscarPorNombre(std::string nombre) {
    FILE* pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) return CategoriaProducto();

    CategoriaProducto cat;
    while (fread(&cat, sizeof(CategoriaProducto), 1, pArchivo)) {
        if (cat.getNombre() == nombre) {
            fclose(pArchivo);
            return cat;
        }
    }
    fclose(pArchivo);
    return CategoriaProducto(); // Retorna "vacío"
}

CategoriaProducto ControladorCategoriaProducto::Leer(int posicion) {
    FILE* pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) return CategoriaProducto();

    CategoriaProducto cat;
    fseek(pArchivo, sizeof(CategoriaProducto) * posicion, SEEK_SET);
    fread(&cat, sizeof(CategoriaProducto), 1, pArchivo);
    fclose(pArchivo);
    return cat;
}

void ControladorCategoriaProducto::Leer(int cantidad, CategoriaProducto* vec) {
    FILE* pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) return;

    for (int i = 0; i < cantidad; i++) {
        fread(&vec[i], sizeof(CategoriaProducto), 1, pArchivo);
    }
    fclose(pArchivo);
}

int ControladorCategoriaProducto::CantidadRegistros() {
    FILE* pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) return 0;

    fseek(pArchivo, 0, SEEK_END);
    int cantidad = ftell(pArchivo) / sizeof(CategoriaProducto);
    fclose(pArchivo);
    return cantidad;
}


bool ControladorCategoriaProducto::ActualizarNombre(int idCategoria, std::string nuevoNombre) {
    int pos = Buscar(idCategoria);
    if (pos == -1) return false;

    CategoriaProducto cat = Leer(pos);
    cat.setNombre(nuevoNombre);

    return Guardar(cat, pos);
}
