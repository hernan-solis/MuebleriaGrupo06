#ifndef MENUPROVEEDORES_H
#define MENUPROVEEDORES_H

#include "ControladorProveedor.h"
#include "Proveedor.h"

// Funci�n para mostrar tabla de proveedores
void mostrarProveedoresTabla(Proveedor* lista, int cantidad);

// Men� de Proveedores
void menuProveedores(ControladorProveedor &cprov);

#endif
