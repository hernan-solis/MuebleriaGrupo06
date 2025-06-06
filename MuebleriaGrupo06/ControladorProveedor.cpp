#include "Fecha.h"
#include "ControladorProveedor.h"

ControladorProveedor::ControladorProveedor(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}

bool ControladorProveedor::Guardar(Proveedor proveedor){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if(pArchivo == NULL){
        return false;
    }
    bool ok = fwrite(&proveedor, sizeof(Proveedor), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

bool ControladorProveedor::Guardar(Proveedor proveedor, int posicion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if(pArchivo == NULL){
        return false;
    }
    fseek(pArchivo, sizeof(Proveedor) * posicion, SEEK_SET);
    bool ok = fwrite(&proveedor, sizeof(Proveedor), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

int ControladorProveedor::Buscar(int idProveedor){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return -1;
    }
    Proveedor proveedor;
    int i = 0;
    while(fread(&proveedor, sizeof(Proveedor), 1, pArchivo)){
        if(proveedor.getIdProveedor() == idProveedor){
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}

Proveedor ControladorProveedor::Leer(int posicion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return Proveedor();
    }
    Proveedor proveedor;
    fseek(pArchivo, sizeof(Proveedor) * posicion, SEEK_SET);
    fread(&proveedor, sizeof(Proveedor), 1, pArchivo);
    fclose(pArchivo);
    return proveedor;
}

int ControladorProveedor::CantidadRegistros(){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(Proveedor);
    fclose(pArchivo);
    return cantidadRegistros;
}

void ControladorProveedor::Leer(int cantidadRegistros, Proveedor *vector){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++){
        fread(&vector[i], sizeof(Proveedor), 1, pArchivo);
    }
    fclose(pArchivo);
}

