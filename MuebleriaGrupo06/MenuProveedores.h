#ifndef MENUPROVEEDORES_H
#define MENUPROVEEDORES_H

#include "ControladorProveedor.h"
#include "Proveedor.h"

// Función para mostrar tabla de proveedores
void mostrarProveedoresTabla(Proveedor* lista, int cantidad);

// Menú de Proveedores
void menuProveedores(ControladorProveedor &cprov);

#endif
