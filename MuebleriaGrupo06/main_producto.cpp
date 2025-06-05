#include <iostream>
#include "Producto.h"

using namespace std;

int main() {
    Producto p1;
    cout << p1.toCSV() << endl;

    Producto p2(100, "Mesa ratona", "Argentina", 2, 1, "Mesa baja de madera", 10, true);
    cout << p2.toCSV() << endl;

    return 0;
}
