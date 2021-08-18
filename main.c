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

int esPalindromo(char a[]);

 void intercambiarVariables(int *numero1, int *numero2);

// Variables / Arreglos
char string[30];
int arr3[4] = {3,2,8,9};

/*1. Se tiene un arreglo de n�meros enteros positivos. Se desea obtener el promedio de sus valores. Para ello se debe:

f. Hacer la funci�n main correspondiente.*/


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
    /*cargarString(string);
    invertirArreglo(string);
    mostrarString(string);*/

    // 3
    //arregloADecimal (arr3, 4);

    // 4
    //posicionMayor(arr3, 4);

    //6
    /*int es = esPalindromo(string);
    printf("\n es: %i\n", es);*/

    // 7
    /*int a = 10;
    int b = 20;
    intercambiarVariables(&a,&b);
    printf("%i %i  \n", a, b);*/




    return 0;

}

// a. Funci�n que inicialice las celdas del arreglo void mostrarString (char string[30])en -1
void inicializarEnMenosUno (int a[])
{
    for(int i = 0; i < 10; i++)
    {
        a[i] = -1;
    }
}

// b. Funci�n que permita al usuario ingresar los valores. No se conoce la cantidad de antemano.
// d. Hacer una funci�n que cuente la cantidad de valores ingresados.

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

/* e. Hacer una funci�n que reciba como par�metro el arreglo ya cargado, calcule y retorne el valor promedio
usando las funciones anteriores (c y d). */

float promedioArreglo (int suma, int validos)
{
    float prom = (float) suma / (float) validos;
    return prom;
}

/*2. Invertir el contenido de un arreglo de caracteres. Para ello se debe modularizar de la siguiente forma:
    a. Hacer una funci�n para la carga del arreglo.
    b. Hacer una funci�n para invertir el arreglo.
    c. Hacer una funci�n para mostrar el contenido del arreglo.
    d. Hacer la funci�n main con el men� correspondiente. */

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

/* 3. Hacer una funci�n que reciba como par�metro un arreglo de n�meros enteros de un d�gito y retorne el valor decimal de dicho n�mero.
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

/* 4. Hacer una funci�n que retorne la posici�n del valor m�ximo de un arreglo de n�meros enteros*/

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

/* 5. Sea una matriz de n�meros enteros, de dimensiones: 12 filas y 31 columnas.
    Contienen las precipitaciones correspondientes a un a�o entero. Las filas corresponden a los meses y las columnas a los d�as. Se pide:
    a. Hacer una funci�n para cargar la matriz de forma autom�tica.
    b. Hacer una funci�n que retorne el d�a de m�xima precipitaci�n para un mes determinado.
    c. Hacer una funci�n que cargue en un arreglo de 12 posiciones el resultado de aplicar la fn anterior a cada
    mes de a�o.
    d. Hacer la funci�n main con el men� correspondiente.
 */

 /* 6. Dada una cadena de caracteres, hacer una funci�n que determine si dicha cadena es pal�ndromo o no.
 La funci�n recibe como par�metro la cadena y retorna 1 o 0 seg�n sea la respuesta. */

 int esPalindromo(char a[])
 {
    int longitud = strlen(a);
    int x = longitud-1;
    int i = 0;
    int flag = 1;

    while(i<longitud && flag == 1){
        //printf("Comparando posicion %d (%c) con %d (%c)\n", i, a[i], x, a[x]);
        if(a[i]==a[x]){
            flag=1;
        }else {
            flag=0;
        }
        i++;
        x--;
    }
    return flag;
 }

 /* 7. Hacer una funci�n que intercambie el contenido de dos variables. (pasaje de par�metros por referencia) */

 void intercambiarVariables(int *numero1, int *numero2){
	int aux = (*numero1);
	(*numero1) = (*numero2);
	(*numero2) = aux;
}




