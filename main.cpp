#include <iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

void ver(int vec[], int maximo) {
    for (int ar = 0; ar < maximo; ar++) {
        cout << vec[ar] << endl;
    }
}

void aleatorio(int vector[], int tamanio) {
    for (int i = 0; i < tamanio; i++) {
        vector[i] = rand();
    }
}

void intercambiar(int &a, int &b) {
    int aux = a;
    a = b;
    b = aux;
}

void ordenSecuencial(int vector[], int total) {
    for (int i = 0; i < total; i++) {
        for (int j = i + 1; j < total; j++) {
            if (vector[i] > vector[j])
                intercambiar(vector[i], vector[j]);
        }
    }
}

void OrdenamientoQuicksort(int a[], int primerValor, int ultimoValor) {
    int central, i, j, pivote;
    central = (primerValor + ultimoValor) / 2; //Posicion central del arreglo
    pivote = a[central]; //Capturar el valor medio del arreglo
    i = primerValor;
    j = ultimoValor;
    do {
        //Separando en dos partes el arreglo
        while (a[i] < pivote) i++; //Separando los valores menores al pivote
        while (a[j] > pivote) j--; //Separando los valores mayores al pivote
        if (i <= j) {
            int temporal;
            //Intercambio de valores
            temporal = a[i];
            a[i] = a[j];
            a[j] = temporal;
            i++;
            j--;
        }
    } while (i <= j);
    if (primerValor < j)
        OrdenamientoQuicksort(a, primerValor, j);
    if (i < ultimoValor)
        OrdenamientoQuicksort(a, i, ultimoValor);
}

void ordenShell(int a[], int n) {
    int ints, i, aux;
    bool band;
    ints = n;
    while (ints > 1) {
        ints = ints / 2;
        band = true;
        while (band == true) {
            band = false;
            i = 0;
            while ((i + ints) < n) {
                if (a[i] > a[i + ints]) {
                    aux = a[i];
                    a[i] = a[i + ints];
                    a[i + ints] = aux;
                    band = true;
                }
                i++;
            }
        }
    }
}

void ordenShell2(int a[], int n) {//optimizado
    int i, j, inc;
    int temp;
    for (inc = 1; inc < n; inc = inc * 3 + 1);
    while (inc > 0) {
        for (i = inc; i < n; i++) {
            j = i;
            temp = a[i];
            while ((j >= inc) && (a[j - inc] > temp)) {
                a[j] = a[j - inc];
                j = j - inc;
            }
            a[j] = temp;
        }
        inc = inc / 2;
    }
}

void ordenBurbuja(int v[], int n) {
    int i = 0, j = 0;
    int aux;
    for (i = 1; i < n; i++)
        for (j = 0; j < (n - i); j++) {
            if (v[j] > v[j + 1]) {
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
}

void burbujaMejorado(int arreglo[], int tamano) {
    int comparaciones = tamano;
    bool termino = false;
    for (int i = 0; i < (tamano - 1); i++) {
        if (termino)
            break;
        termino = true;
        for (int j = 0; j < comparaciones - 1; j++)
            if (arreglo[j] > arreglo[j + 1]) {
                intercambiar(arreglo[j], arreglo[j + 1]);
                termino = false;
            }
        comparaciones--;
    }
}

int main() {
    srand(time(NULL));
    int a, b;
    cout << "Ingrese la cantidad de numeros a generar" << endl;
    cin >> a;
    int vector[a];
    aleatorio(vector, a);
    cout << "Sin ordenar" << endl;
    ver(vector, a);
    cout << "¿Cual metodo de ordenamiento desea usar?" << endl;
    cout << "1. Ordenamiento secuencial" << endl;
    cout << "2. Ordenamiento qsort" << endl;
    cout << "3. Ordenamiento shell" << endl;
    cout << "4. Ordenamiento shell2" << endl;
    cout << "5. Ordenamiento burbuja" << endl;
    cout << "6. Ordenamiento burbuja2" << endl;
    cin >> b;
    switch (b) {
        case 1:
            ordenSecuencial(vector, a);
            cout << "Ordenados secuencial" << endl;
            ver(vector, a);
            break;
        case 2:
            OrdenamientoQuicksort(vector, 0, a - 1);
            cout << "Ordenados quicksort" << endl;
            ver(vector, a);
            break;
        case 3:
            ordenShell(vector, a);
            cout << "Ordenados shell" << endl;
            ver(vector, a);
            break;
        case 4:
            ordenShell2(vector, a);
            cout << "Ordenados shell 2" << endl;
            ver(vector, a);
            break;
        case 5:
            ordenBurbuja(vector, a);
            cout << "Ordenados burbuja" << endl;
            ver(vector, a);
            break;
        case 6:
            burbujaMejorado(vector, a);
            cout << "Ordenados burbuja 2 " << endl;
            ver(vector, a);
            break;
    }
    return 0;
}