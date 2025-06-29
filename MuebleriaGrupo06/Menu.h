#ifndef MENU_H
#define MENU_H

#include "ControladorProveedor.h"
#include "ControladorCompra.h"
#include "ControladorProducto.h"
#include "ControladorCategoriaProducto.h"
#include "ControladorDetalleCompra.h"

void limpiarPantalla();

void iniciarMenu(ControladorProveedor &cprov, ControladorCompra &ccomp, ControladorProducto &cprod, ControladorCategoriaProducto &ctrlCategorias, ControladorDetalleCompra &cdetalle);
#endif
