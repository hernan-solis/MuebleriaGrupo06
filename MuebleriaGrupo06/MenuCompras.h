#ifndef MENUCOMPRAS_H
#define MENUCOMPRAS_H

#include "ControladorCompra.h"
#include "Compra.h"

// Funci�n para mostrar tabla de compras
void mostrarComprasTabla(Compra* lista, int cantidad);

// Men� de Compras
void menuCompras(ControladorCompra &cc);

#endif
