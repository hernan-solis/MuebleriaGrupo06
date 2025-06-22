#ifndef MENUPRODUCTOS_H_INCLUDED
#define MENUPRODUCTOS_H_INCLUDED

#include "ControladorProducto.h"
#include "Producto.h"
#include "ControladorCategoriaProducto.h"

void mostrarProductoTabla(Producto* lista, int cantidad);

void menuProductos(ControladorProducto &cprod, ControladorCategoriaProducto &ccateg);
#endif // MENUPRODUCTOS_H_INCLUDED
