#include "Fecha.h"
#include "ControladorProveedor.h"

ControladorProveedor::ControladorProveedor(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}


// "Abre el archivo binario .dat para agregar contenido al final. Si no existe el dat, lo crea. Autoasigna id"
bool ControladorProveedor::Guardar(Proveedor proveedor){

    //busca el id mas grande para luego sumarle 1 al que se va a guardar

    int cantidad = CantidadRegistros();

    int maxId = 0;

    if(cantidad > 0){
        Proveedor *lista = new Proveedor[cantidad];
        Leer(cantidad, lista);

        for(int i = 0; i < cantidad; i++){
            if(lista[i].getIdProveedor() > maxId){
                maxId = lista[i].getIdProveedor();
            }
        }
        delete[] lista;
    }

    // Setea el nuevo ID
    proveedor.setIdProveedor(maxId + 1);


    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if(pArchivo == NULL){
        return false;
    }
    bool ok = fwrite(&proveedor, sizeof(Proveedor), 1, pArchivo); //frite devuelve un entero, 1 o 0 , sera un bool.
    fclose(pArchivo);
    return ok;
}


// Sobrescribe un proveedor ya existente en .dat en la posición indicada.
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


//Se le pasa un ID Proveedor y devuelve la posicion del registro en el .dat
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


//Busca posicion y devuelve Proveedor, si no hay nada devuelve Proveedor vacio standar
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


//DEVUELVE LA CANTIDAD DE REGISTROS QUE TIENE EL .DAT
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


//GUARDA TODOS LOS REGISTROS EN UN ARRAY QUE LE PASEMOS PARA LUEGO TRABAJARLO, ACTIVOS O NO, TODOS
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


// BORRADO FISICO DE TODOS LOS REGISTROS, LIMPIA POR COMPLETO EL .DAT
bool ControladorProveedor::BorrarTodos() {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "wb"); // wb hace que abra el .dat y lo Sobrescribe vacio. Si no existe lo crea.
    if (pArchivo == NULL) {
        return false;
    }
    fclose(pArchivo);
    return true;
}


// ELIMINACION LOGICA DE 1 REGISTRO
bool ControladorProveedor::Eliminar(int idProveedor){
    int posicion = Buscar(idProveedor);
    if(posicion == -1){
        return false;
    }else{
        Proveedor prov = Leer(posicion);
        prov.setStatus(false);
        Guardar(prov,posicion);
        return true;
    }
}
