#include "ControladorProducto.h"


ControladorProducto::ControladorProducto(std::string nombreArchivo) {
    _nombreArchivo = nombreArchivo;
}

bool ControladorProducto::Guardar(Producto producto) {
    int cantidad = CantidadRegistros();
    int maxId = 0;

    if (cantidad > 0) {
        Producto *lista = new Producto[cantidad];
        Leer(cantidad, lista);
        for (int i = 0; i < cantidad; i++) {
            if (lista[i].getIdProducto() > maxId) {
                maxId = lista[i].getIdProducto();
            }
        }
        delete[] lista;
    }

    producto.setIdProducto(maxId + 1);

    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if (pArchivo == NULL) return false;

    bool ok = fwrite(&producto, sizeof(Producto), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

bool ControladorProducto::Guardar(Producto producto, int posicion) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if (pArchivo == NULL) return false;

    fseek(pArchivo, sizeof(Producto) * posicion, SEEK_SET);
    bool ok = fwrite(&producto, sizeof(Producto), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

int ControladorProducto::Buscar(int idProducto) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) return -1;

    Producto producto;
    int i = 0;
    while (fread(&producto, sizeof(Producto), 1, pArchivo)) {
        if (producto.getIdProducto() == idProducto) {
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}

Producto ControladorProducto::BuscarPorNombreProducto(std::string nombre) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) return Producto();

    Producto producto;
    while (fread(&producto, sizeof(Producto), 1, pArchivo)) {
        if (producto.getNombre() == nombre && producto.getStatus()) {
            fclose(pArchivo);
            return producto;
        }
    }
    fclose(pArchivo);
    return Producto();
}

Producto ControladorProducto::Leer(int posicion) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) return Producto();

    Producto producto;
    fseek(pArchivo, sizeof(Producto) * posicion, SEEK_SET);
    fread(&producto, sizeof(Producto), 1, pArchivo);
    fclose(pArchivo);
    return producto;
}

void ControladorProducto::Leer(int cantidadRegistros, Producto *vector) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) return;

    for (int i = 0; i < cantidadRegistros; i++) {
        fread(&vector[i], sizeof(Producto), 1, pArchivo);
    }
    fclose(pArchivo);
}

int ControladorProducto::CantidadRegistros() {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) return 0;

    fseek(pArchivo, 0, SEEK_END);
    int cantidad = ftell(pArchivo) / sizeof(Producto);
    fclose(pArchivo);
    return cantidad;
}

bool ControladorProducto::BorrarTodos() {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "wb");
    if (pArchivo == NULL) return false;
    fclose(pArchivo);
    return true;
}

bool ControladorProducto::Eliminar(int idProducto) {
    int pos = Buscar(idProducto);
    if (pos == -1) return false;

    Producto producto = Leer(pos);
    producto.setStatus(false);
    return Guardar(producto, pos);
}

//  baja física de un producto
bool ControladorProducto::EliminarFisico(int idProducto) {
    int cantidad = CantidadRegistros();
    if (cantidad == 0) return false;

    Producto *lista = new Producto[cantidad];
    Leer(cantidad, lista);

    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "wb");
    if (pArchivo == NULL) {
        delete[] lista;
        return false;
    }

    bool eliminado = false;
    for (int i = 0; i < cantidad; i++) {
        if (lista[i].getIdProducto() != idProducto) {
            fwrite(&lista[i], sizeof(Producto), 1, pArchivo);
        } else {
            eliminado = true;
        }
    }

    fclose(pArchivo);
    delete[] lista;
    return eliminado;
}
