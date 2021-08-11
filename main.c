#include <stdio.h>
#include <stdlib.h>

void inicializarEnMenosUno (int a[]);
int ingresarValores(int a[], int dim);
int sumarContenidoArreglo (int a[], int v);

/*1. Se tiene un arreglo de n�meros enteros positivos. Se desea obtener el promedio de sus valores. Para ello se debe:

d. Hacer una funci�n que cuente la cantidad de valores ingresados.
e. Hacer una funci�n que reciba como par�metro el arreglo ya cargado, calcule y retorne el valor promedio
usando las funciones anteriores (c y d).
f. Hacer la funci�n main correspondiente.*/


int main()
{
    int arreglo[10];

    inicializarEnMenosUno(arreglo);

    int validos = ingresarValores(arreglo, 10);

    int resultado = sumarContenidoArreglo(arreglo, validos);
    printf("La suma dio %i", resultado);

    return 0;

}

// a. Funci�n que inicialice las celdas del arreglo en -1
void inicializarEnMenosUno (int a[])
{
    for(int i = 0; i < 10; i++)
    {
        a[i] = -1;
    }
}

// b. Funci�n que permita al usuario ingresar los valores. No se conoce la cantidad de antemano.
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

// c. Hacer una funci�n que sume el contenido del arreglo y lo retorne.
int sumarContenidoArreglo (int a[], int v)
{
    int suma = 0;

    for (int i = 0; i < v; i++)
    {
        suma = suma + a[i];
    }

    return suma;

}
