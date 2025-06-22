#ifndef MENUCOMPRAS_H
#define MENUCOMPRAS_H

#include "ControladorCompra.h"
#include "ControladorDetalleCompra.h"
#include "ControladorProveedor.h"
#include "ControladorProducto.h"
#include "ControladorCategoriaProducto.h"
#include "Compra.h"

// Funci�n para mostrar tabla de compras
void mostrarComprasTabla(Compra* lista, int cantidad);

// Men� de Compras con todos los controladores necesarios
void menuCompras(ControladorCompra &ccomp, ControladorDetalleCompra &cdetalle, ControladorProveedor &cprov, ControladorProducto &cprod, ControladorCategoriaProducto &ctrlCategoria);

#endif
