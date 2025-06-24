#include "Menu.h"
#include "ControladorProveedor.h"
#include "ControladorCompra.h"
#include "ControladorProducto.h"
#include "ControladorCategoriaProducto.h"
#include "ControladorDetalleCompra.h"

int main() {


    ControladorProveedor cprov("proveedores.dat");
    ControladorCompra ccomp("compras.dat");
    ControladorProducto cprod("productos.dat");
    ControladorCategoriaProducto ctrlCategorias("categorias.dat");
    ControladorDetalleCompra cdetalle("detallecompras.dat");
    iniciarMenu(cprov, ccomp, cprod, ctrlCategorias, cdetalle); //OJO tiene q respetar el orden y pasar los objetos en el mismo orden en el que fueron declarados en menu.h


    return 0;
}
