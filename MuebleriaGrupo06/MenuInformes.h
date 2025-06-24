#ifndef MENU_INFORMES_H
#define MENU_INFORMES_H

#include "ControladorProveedor.h"
#include "ControladorCompra.h"
#include "ControladorProducto.h"
#include "ControladorCategoriaProducto.h"
#include "ControladorDetalleCompra.h"

void limpiarPantallaInformes();

void menuInformes(ControladorProveedor &cprov, ControladorCompra &ccomp, ControladorProducto &cprod, ControladorCategoriaProducto &ctrlCategorias, ControladorDetalleCompra &cdetalle);
#endif
