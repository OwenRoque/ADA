#include <iostream>
#include <vector>

using namespace std;

// Función de búsqueda utilizando Divide y Vencerás
bool buscarElemento(vector<vector<int>>& matriz, int x, int inicioFila, int finFila, int inicioColumna, int finColumna) {
    // Verificar los límites de la matriz
    if (inicioFila > finFila || inicioColumna > finColumna) {
        return false;
    }

    // Obtener los índices medios
    int medioFila = inicioFila + (finFila - inicioFila) / 2;
    int medioColumna = inicioColumna + (finColumna - inicioColumna) / 2;
    int elementoMedio = matriz[medioFila][medioColumna];

    // Si el elemento medio es igual a x, lo hemos encontrado
    if (elementoMedio == x) {
        return true;
    }
    // Si el elemento medio es mayor que x, buscamos en las submatrices superiores e izquierdas
    else if (elementoMedio > x) {
        return buscarElemento(matriz, x, inicioFila, medioFila - 1, inicioColumna, finColumna) ||
               buscarElemento(matriz, x, medioFila, finFila, inicioColumna, medioColumna - 1);
    }
    // Si el elemento medio es menor que x, buscamos en las submatrices inferiores y derechas
    else {
        return buscarElemento(matriz, x, medioFila + 1, finFila, inicioColumna, finColumna) ||
               buscarElemento(matriz, x, inicioFila, medioFila, medioColumna + 1, finColumna);
    }
}

// Función de búsqueda inicial para llamar a la función de búsqueda recursiva
bool buscarElemento(vector<vector<int>>& matriz, int x) {
    int n = matriz.size();
    return buscarElemento(matriz, x, 0, n - 1, 0, n - 1);
}

// Ejemplo de uso
int main() {
    vector<vector<int>> matriz = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int elemento = 10;

    if (buscarElemento(matriz, elemento)) {
        cout << "El elemento " << elemento << " se encuentra en la matriz." << endl;
    } else {
        cout << "El elemento " << elemento << " no se encuentra en la matriz." << endl;
    }

    return 0;
}
