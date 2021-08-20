#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int maxC = 10;
// Proto
// 1
void inicializarEnMenosUno (int a[]);
int ingresarValores(int a[], int dim);
int sumarContenidoArreglo (int a[], int v);
float promedioArreglo (int suma, int validos);

// 2
int cargarString (char string[30]);
void invertirArreglo (char string[30]);
void mostrarString (char string[30]);

// 3
int arregloADecimal (int a[], int validos);

// 4
int posicionMayor (int A[], int validos);

// 5
void cargarMatriz (int matriz[][maxC], int dimF, int dimC);
int maxPrecipitacion (int matriz[][maxC], int mes, int dimC);
void maxPrecipitacion12Meses (int matriz[][maxC], int dimF, int dimC, int arregloPrecipitaciones[]);
void mostrarMatriz (int matriz[][maxC], int dimF, int dimC);

// 6
int esPalindromo(char a[]);

// 7
void intercambiarVariables(int *numero1, int *numero2);

// 10
void datosArreglo(int A[], int validos, int * valorMaximo, int * valorMinimo, float * promedio);



// Variables / Arreglos
char string[30];
int arr3[4] = {3,2,8,9};




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


    /// 5
    int matriz[12][maxC];

    cargarMatriz(matriz,12,maxC);
    mostrarMatriz(matriz,12,maxC);

    int mesObtener = 0;
    printf("\nDe que mes desea obtener la mayor precipitacion? -> ");
    scanf("%i", &mesObtener);
    int maxima = maxPrecipitacion(matriz,mesObtener,maxC);
    printf("\n FUNCION Maxima precipitacion del mes %i: %i", mesObtener, maxima);

    int arregloPrecipitaciones[12];
    maxPrecipitacion12Meses(matriz,12,maxC, arregloPrecipitaciones);



    return 0;

}

/* 1. Se tiene un arreglo de números enteros positivos. Se desea obtener el promedio de sus valores. */

// a. Función que inicialice las celdas del arreglo void mostrarString (char string[30]) en -1
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

/* 5. Sea una matriz de números enteros, de dimensiones: 12 filas y 31 columnas.
    Contienen las precipitaciones correspondientes a un año entero. Las filas corresponden a los meses y las columnas a los días. Se pide:
    a. Hacer una función para cargar la matriz de forma automática.
    b. Hacer una función que retorne el día de máxima precipitación para un mes determinado.
    c. Hacer una función que cargue en un arreglo de 12 posiciones el resultado de aplicar la fn anterior a cada
    mes de año.
    d. Hacer la función main con el menú correspondiente.
 */

 void cargarMatriz (int matriz[][maxC], int dimF, int dimC)
{
    int random = 0;

    srand(time(NULL));

    for (int f = 0; f < dimF; f++)
    {
        for (int c = 0; c < dimC; c++)
        {
            matriz[f][c] = rand()%999;
        }
    }
}

//b. Hacer una función que retorne el día de máxima precipitación para un mes determinado.
int maxPrecipitacion (int matriz[][maxC], int mes, int dimC)
{
    int mayor = 0;
    int mesObtener = mes - 1;

    for (int f = 0; f < mes; f++) // Recorre filas de 0 a 11 (mes 1 a 12)
    {
        if (mesObtener == f) // Recorre las columnas si mes - 1 = mes ingresado
        {
            for (int c = 0; c < dimC; c++)
            {
                if (matriz[f][c] > mayor)
                {
                    mayor = matriz[f][c];
                }

            }
        }
    }

    return mayor;

}

//c. Hacer una función que cargue en un arreglo de 12 posiciones el resultado de aplicar la fn anterior a cada mes del año.
void maxPrecipitacion12Meses (int matriz[][maxC], int dimF, int dimC, int arregloPrecipitaciones[])
{
    int mes = 1;
    int maximo = 0;
    int posmes = 0;

    for (mes = 1; mes <= dimF; mes++) // Del 1 al 12 (en la fn anterior las columnas se recorren con mes - 1)
    {
        maximo = maxPrecipitacion(matriz, mes, maxC);
        arregloPrecipitaciones[posmes] = maximo;
        printf("\nMaxima precipitacion mes %i: %i", mes, arregloPrecipitaciones[posmes]);
        posmes ++;
    }
}

void mostrarMatriz (int matriz[][maxC], int dimF, int dimC)
{

    int f = 0;
    int c = 0;
    int rand();

    for (f = 0; f < dimF; f++)
    {
        for (c = 0; c < dimC; c++)
        {
            printf(" %i |", matriz[f][c]);
        }
        printf("\n");
    }
}

 /* 6. Dada una cadena de caracteres, hacer una función que determine si dicha cadena es palíndromo o no.
 La función recibe como parámetro la cadena y retorna 1 o 0 según sea la respuesta. */

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

 /* 7. Hacer una función que intercambie el contenido de dos variables. (pasaje de parámetros por referencia) */

 void intercambiarVariables(int *numero1, int *numero2){
	int aux = (*numero1);
	(*numero1) = (*numero2);
	(*numero2) = aux;
}

/* 8. Dados dos arreglos de números enteros ordenados de menor a mayor, hacer una función que los reciba como parámetros y
      retorne un tercer arreglo que contenga los datos de los arreglos anteriores, también ordenados. Se los debe intercalar. */


/* 9. Dados dos arreglos paralelos, uno con apellidos y otro con edades.
      Se debe hacer un programa para encontrar el apellido de la persona de mayor edad. Se debe modularizar. */

/* 10. Hacer una función que reciba como parámetros de entrada un arreglo de enteros y su dimensión, y tres parámetros de salida,
       tres números enteros que representen: valor máximo, valor mínimo y promedio. Se debe usar pasaje de parámetros por referencia. */

void datosArreglo(int A[], int validos, int * valorMaximo, int * valorMinimo, float * promedio){
    *valorMaximo = valorMayor(A, validos);
    *valorMinimo = valorMenor(A, validos);
    int suma = sumarContenidoArreglo(A, validos);
    *promedio = promedioArreglo(suma, validos);
}

int valorMayor (int A[], int validos)
{
    int i = 0;
    int pos = 0;
    int mayor = A[pos];
    i = pos + 1;
    while (i<validos)
    {
        if (mayor < A[i])
        {
            mayor = A[i];
        }
        i++;
    }

    printf("Mayor: %i", mayor);
    return mayor;
}

int valorMenor (int A[], int validos)
{
    int i = 0;
    int pos = 0;
    int menor = A[pos];
    i = pos + 1;

    while (i<validos)
    {
        if (menor > A[i])
        {
            menor = A[i];
        }
        i++;
    }

    printf("Menor: %i", menor);
    return menor;
}

