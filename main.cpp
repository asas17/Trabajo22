#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

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

double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b) {
    LARGE_INTEGER freq;
    QueryPerformanceFrequency(&freq);
    return (double) (a->QuadPart - b->QuadPart) / (double) freq.QuadPart;
}
int busquedabinaria(int vector[], int tamanio, int num)
{
    int izq=0, der=tamanio;
    int central = (izq+der)/2;
    while(izq < der && num!=vector[central])
    {
        if(num>vector[central])
            izq=central+1;
        else if (num < vector[central])
            der=central-1;

        central = (izq+der)/2;
    }
    if(vector[central]==num)
        return central+1;
    else
        return -1; // no lo encontró
}
void nvector(string nombres[], int tamanio) {
    for (int k = 0; k < tamanio; k++) {
        cout << endl << nombres[k];
    }
}
void ordenar2(string vector[], int tamanio) {
    for (int i = 0; i < tamanio; i++) {
        for (int j = i + 1; j < tamanio; j++) {
            if (vector[i].compare(vector[j]) < 0) {
                string aux;
                aux = vector[i];
                vector[i] = vector[j];
                vector[j] = aux;
            }
        }
    }
}
void lala(string ciudad[], int temp[], const int tam)
{
    for (int i = 0; i < tam; i++) {
        for (int j = i + 1; j < tam; j++) {
            if (ciudad[i].compare(ciudad[j]) > 0) {
                string aux;int au;
                aux = ciudad[i];
                ciudad[i] = ciudad[j];
                ciudad[j] = aux;
                au=temp[i];
                temp[i]=temp[j];
                temp[j]=au;
            }
        }
    }
}
void ordenSecuencialnum(int vector[], const int total, string ciudad[]) {
    for (int i = 0; i < total; i++) {
        for (int j = i + 1; j < total; j++) {
            if (vector[i] > vector[j]){
                intercambiar(vector[i], vector[j]);
            string aux;
            aux = ciudad[i];
            ciudad[i] = ciudad[j];
            ciudad[j] = aux;
        }
        }
    }
}
int main() {
    srand(time(NULL));
    LARGE_INTEGER t_ini, t_fin;

    int  b;
    int total=80000;
    int vectorSec[total];
    int vectorBurbuja[total];
    int vectorburbujaMejorado[total];
    int vectorQuickSort[total];
    int vectorShell[total];
    int vectorShellOptimizado[total];
    int vector[10]={10,50,7,78,90,8,77,105,221,45};
    ordenBurbuja(vector,10);
    int x= busquedabinaria(vector, 10, 105);
    cout<<endl<<"Posicion del elemento: "<<x<<endl;

    for (int i=0; i<total; i++){
        int elemento = 1+rand();
        vectorSec[i]=elemento;
        vectorBurbuja[i]=elemento;
        vectorburbujaMejorado[i]=elemento;
        vectorQuickSort[i]=elemento;
        vectorShell[i]=elemento;
        vectorShellOptimizado[i]=elemento;
    }
    const int tam=4;
    string ciudad[tam] = {"Quito", "Guayaquil","Esmeraldas","Cali"};
    int temp[tam]={17, 23, 28, 18};


    cout<<endl<<endl;
    do {
        double secs;
        cout << "Cual metodo de ordenamiento desea usar?" << endl;
        cout << "1. Ordenamiento secuencial" << endl;
        cout << "2. Ordenamiento qsort" << endl;
        cout << "3. Ordenamiento shell" << endl;
        cout << "4. Ordenamiento shell2" << endl;
        cout << "5. Ordenamiento burbuja" << endl;
        cout << "6. Ordenamiento burbuja2" << endl;
        cout << "7. Ordenar de manera alfabetica las ciudades" << endl;
        cout << "8. Ordenar de manera numerica las temperaturas" << endl;
        cout << "9. Salir" << endl;
        cin >> b;
        switch (b) {
            case 1:
                QueryPerformanceCounter(&t_ini);
                ordenSecuencial(vectorSec, total);
                QueryPerformanceCounter(&t_fin);
                cout << "Ordenados secuencial" << endl;

                secs = performancecounter_diff(&t_fin, &t_ini);

                cout<<""<<endl;
                cout << endl << "Tiempo en ordenar el vector: " << endl;
                cout << (secs * 1000.0) << endl;
                break;
            case 2:
                QueryPerformanceCounter(&t_ini);
                OrdenamientoQuicksort(vectorQuickSort, 0, total - 1);
                QueryPerformanceCounter(&t_fin);
                cout << "Ordenados quicksort" << endl;

                secs = performancecounter_diff(&t_fin, &t_ini);

                cout<<""<<endl;
                cout << endl << "Tiempo en ordenar el vector: " << endl;
                cout << (secs * 1000.0) << endl;
                break;
            case 3:
                QueryPerformanceCounter(&t_ini);
                ordenShell(vectorShell, total);
                QueryPerformanceCounter(&t_fin);
                cout << "Ordenados shell" << endl;

                secs = performancecounter_diff(&t_fin, &t_ini);

                cout<<""<<endl;
                cout << endl << "Tiempo en ordenar el vector: " << endl;
                cout << (secs * 1000.0) << endl;
                break;
            case 4:
                QueryPerformanceCounter(&t_ini);
                ordenShell2(vectorShellOptimizado, total);
                QueryPerformanceCounter(&t_fin);
                cout << "Ordenados shell 2" << endl;

                secs = performancecounter_diff(&t_fin, &t_ini);

                cout<<""<<endl;
                cout << endl << "Tiempo en ordenar el vector: " << endl;
                cout << (secs * 1000.0) << endl;
                break;
            case 5:
                QueryPerformanceCounter(&t_ini);
                ordenBurbuja(vectorBurbuja, total);
                QueryPerformanceCounter(&t_fin);
                cout << "Ordenados burbuja" << endl;

                secs = performancecounter_diff(&t_fin, &t_ini);

                cout<<""<<endl;
                cout << endl << "Tiempo en ordenar el vector: " << endl;
                cout << (secs * 1000.0) << endl;
                break;
            case 6:
                QueryPerformanceCounter(&t_ini);
                burbujaMejorado(vectorburbujaMejorado, total);
                QueryPerformanceCounter(&t_fin);
                cout << "Ordenados burbuja 2 " << endl;

                secs = performancecounter_diff(&t_fin, &t_ini);

                cout<<""<<endl;
                cout << endl << "Tiempo en ordenar el vector: " << endl;
                cout << (secs * 1000.0) << endl;
                break;
            case 7:
                lala(ciudad,temp,tam);
                cout<<endl<<endl<<"Se ordenara de manera alfabetica los nombres de las ciudades junto a sus temperaturas (descendente)"<<endl;
                for (int k = 0; k < tam; k++) {
                    cout << endl <<"la ciudad: "<<ciudad[k]<<" y su temperatura: "<<temp[k]<<endl;
                }
                break;
            case 8:
                ordenSecuencialnum(temp,tam,ciudad);
                cout<<endl<<endl<<"Se ordenara de manera numerica las temperaturas junto a sus ciudades (descendente)"<<endl;
                for (int k = 0; k < tam; k++) {
                    cout << endl <<"la ciudad: "<<ciudad[k]<<" y su temperatura: "<<temp[k]<<endl;
                }
                break;
            case 9:
                break;
        }
    } while (b < 9);
    return 0;
}