// #include <iostream>
#include "Menu.h"
#include "ControladorProveedor.h"
#include "ControladorCompra.h"
#include "ControladorProducto.h"
#include "ControladorCategoriaProducto.h"

int main() {
    ControladorProveedor cprov("proveedores.dat");
    ControladorCompra ccomp("compras.dat");
    ControladorProducto cprod("productos.dat");
    ControladorCategoriaProducto
    ctrlCategorias("categorias.dat");

    iniciarMenu(cprov, ccomp, cprod, ctrlCategorias);
    return 0;
}
