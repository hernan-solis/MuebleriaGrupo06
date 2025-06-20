#include "Fecha.h"
#include "ControladorCompra.h"

ControladorCompra::ControladorCompra(std::string nombreArchivo){
  _nombreArchivo = nombreArchivo;
}

// Abre el archivo binario .dat para agregar contenido al final. Si no existe el dat lo creará y autoasigna el id:
  bool ControladorCompra::Guardar(Compra compra){
    //busca el id mas grande para luego sumarle 1 al que se va a guardar:
    int cantidad = CantidadRegistros();
    int maxId = 0;

    if(  cantidad > 0 ) {
      Compra *lista = new Compra[cantidad];
      Leer(cantidad, lista);

      for(int i = 0; i < cantidad; i++ ){
          if(lista[i].getIdCompra() > maxId){
            maxId = lista[i].getIdCompra();
          };
      }
      delete[] lista;   // agrego el delete porque dependiendo el sistema operativo puede llegar a quedar bloqueada la memoria q pedí!
    }
    compra.setIdCompra( maxId + 1 ); //setea el nuevo id a la nueva compra!

    FILE *pArchivo = fopen (_nombreArchivo.c_str(), "ab");
    if(pArchivo == NULL){
      return false;
    }
    bool ok = fwrite(&compra, sizeof(Compra), 1, pArchivo) == 1; //fwrite devuelve un entero, 1 o 0 , sera un bool.
    fclose(pArchivo);
    return ok;
  }


// Sobrescribe una Compra ya existente en .dat en la posición indicada.
  bool ControladorCompra::Guardar(Compra compra, int posicion){
   FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
   if(pArchivo == NULL){
    return false;
   }
   fseek(pArchivo, sizeof(Compra)* posicion, SEEK_SET);
   bool ok = fwrite(&compra, sizeof(Compra), 1, pArchivo)== 1;
   fclose(pArchivo);
   return ok;
   }


//Se le pasa un ID Compra y devuelve la posicion del registro en el .dat
  int ControladorCompra::Buscar(int idCompra){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return -1;
    }
    Compra compra;
    int i = 0;
    while(fread(&compra, sizeof(Compra), 1, pArchivo)){
        if(compra.getIdCompra() == idCompra){
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}


//Busca posicion y devuelve Compra, si no hay nada devuelve Compra vacio
  Compra ControladorCompra::Leer(int posicion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return Compra();
    }
    Compra compra;
    fseek(pArchivo, sizeof(Compra) * posicion, SEEK_SET);
    fread(&compra, sizeof(Compra), 1, pArchivo);
    fclose(pArchivo);
    return compra;
}


//Devuelve la cantidad de registros que tiene el .dat
  int ControladorCompra::CantidadRegistros(){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(Compra);
    fclose(pArchivo);
    return cantidadRegistros;
}


//Guarda todos los registros en un array que le pasamos para luego trabajarlo, ya sean activos o no
  void ControladorCompra::Leer(int cantidadRegistros, Compra *vector){

    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++){
        fread(&vector[i], sizeof(Compra), 1, pArchivo);
    }
    fclose(pArchivo);
}

// Borrado de todos los registros
  bool ControladorCompra::BorrarTodos() {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "wb"); // wb hace que abra el .dat y lo Sobrescribe vacio. Si no existe lo crea.
    if (pArchivo == NULL) {
        return false;
    }
    fclose(pArchivo);
    return true;
}

// Soft Delete de un registro
  bool ControladorCompra::Eliminar(int idCompra){
    int posicion = Buscar(idCompra);
    if(posicion == -1){
        return false;
    }else{
        Compra comp = Leer(posicion);
        comp.setStatus(false);
        Guardar(comp,posicion);
        return true;
    }
}
