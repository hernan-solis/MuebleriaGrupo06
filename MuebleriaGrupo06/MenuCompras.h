#ifndef MENUCOMPRAS_H
#define MENUCOMPRAS_H

#include "ControladorCompra.h"
#include "Compra.h"

// Función para mostrar tabla de compras
void mostrarComprasTabla(Compra* lista, int cantidad);

// Menú de Compras
void menuCompras(ControladorCompra &cc);

#endif
