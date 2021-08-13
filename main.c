#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Proto
void inicializarEnMenosUno (int a[]);
int ingresarValores(int a[], int dim);
int sumarContenidoArreglo (int a[], int v);
float promedioArreglo (int suma, int validos);

int cargarString (char string[30]);
void invertirArreglo (char string[30]);
void mostrarString (char string[30]);

int arregloADecimal (int a[], int validos);

int posicionMayor (int A[], int validos);


// Variables / Arreglos
char string[30];
int arr3[4] = {3,2,8,9};

/*1. Se tiene un arreglo de números enteros positivos. Se desea obtener el promedio de sus valores. Para ello se debe:

f. Hacer la función main correspondiente.*/


int main()
{
    // 1
    /*
    int arreglo[10];
    inicializarEnMenosUno(arreglo);
    int validos = ingresarValores(arreglo, 10);
    int resultado = sumarContenidoArreglo(arreglo, validos);
    printf("La suma dio %i\n", resultado);
    float promedio = promedioArreglo(resultado, validos);
    printf("El promedio es %.2f\n", promedio);*/

    // 2
/*
    cargarString(string);
    invertirArreglo(string);
    mostrarString(string);*/

    // 3
    //arregloADecimal (arr3, 4);

    // 4
    posicionMayor(arr3, 4);



    return 0;

}

// a. Función que inicialice las celdas del arreglo void mostrarString (char string[30])en -1
void inicializarEnMenosUno (int a[])
{
    for(int i = 0; i < 10; i++)
    {
        a[i] = -1;
    }
}

// b. Función que permita al usuario ingresar los valores. No se conoce la cantidad de antemano.
// d. Hacer una función que cuente la cantidad de valores ingresados.

int ingresarValores(int a[], int dim)
{
    int i = 0;
    char control = 's';

    while(i < dim && control == 's')
    {
        printf("Ingrese un numero\n");
        scanf("%i", &a[i]);
        printf("\nContinuar? ->");
        fflush(stdin);
        scanf("%c", &control);
        i++;
    }

    return i;
}

// c. Hacer una función que sume el contenido del arreglo y lo retorne.
int sumarContenidoArreglo (int a[], int v)
{
    int suma = 0;

    for (int i = 0; i < v; i++)
    {
        suma = suma + a[i];
    }

    return suma;

}

/* e. Hacer una función que reciba como parámetro el arreglo ya cargado, calcule y retorne el valor promedio
usando las funciones anteriores (c y d). */

float promedioArreglo (int suma, int validos)
{
    float prom = (float) suma / (float) validos;
    return prom;
}

/*2. Invertir el contenido de un arreglo de caracteres. Para ello se debe modularizar de la siguiente forma:
    a. Hacer una función para la carga del arreglo.
    b. Hacer una función para invertir el arreglo.
    c. Hacer una función para mostrar el contenido del arreglo.
    d. Hacer la función main con el menú correspondiente. */

int cargarString (char string[30])
{
    printf("Ingrese el string: \n");
    fflush(stdin);
    gets(string);

}

void invertirArreglo (char string[30])
{
    // Para invertir recorremos hasta la mitad del arreglo
    int validos = strlen(string);
    int aux = 0;
    for (int i = 0; i < validos / 2; i++) {

    aux = string[i];
    string[i] = string[validos - i - 1];
    string[validos - i - 1] = aux;

  }
}

void mostrarString (char string[30])
{
    printf("String: %s", string);
}

/* 3. Hacer una función que reciba como parámetro un arreglo de números enteros de un dígito y retorne el valor decimal de dicho número.
      Por ejemplo, un arreglo que tiene cargados los valores 3, 2, 8 y 9, la fn retorna el valor 3289. */

int arregloADecimal (int a[], int validos)
{
    int decimal = 0;
    int multiplicador = 1;
    for (int i = (validos-1); i>-1; i--)
    {
        decimal += a[i] * multiplicador;
        multiplicador *= 10;
    }
    printf("Decimal: %i", decimal);
    return decimal;
}

/* 4. Hacer una función que retorne la posición del valor máximo de un arreglo de números enteros*/

int posicionMayor (int A[], int validos)
{
    int i = 0;
    int pos = 0;
    int mayor = A[pos];
    int posmayor = pos;
    i = pos + 1;
    while (i<validos)
    {
        if (mayor < A[i])
        {
            mayor = A[i];
            posmayor = i;
        }
        i++;
    }

    printf("Posicion mayor: %i", posmayor);
    return posmayor;
}


