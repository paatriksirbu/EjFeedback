#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct arrayLength{         // Declaramos lo que se nos pide en el enunciado.
    int arrInt[SIZE];       // array de enteros con capacidad para 10 valores.
    int arrSize;            // variable para declarar el numero de elemenos almacenados
    int arrAdd;             // suma de elementos contenidos en el array
    };

typedef struct arrayLength arrayLength_t;
                                            // Ejercicio 2
int initArray(arrayLength_t *miArray){      //Funcion que recibe por parametro un puntero a una estructura del tipo arrayLength_t


    for (int i = 0; i < 10; ++i) {  //Pone valor -1 a todas sus posiciones.
        miArray -> arrInt[i] = -1;
    }

    miArray -> arrSize = 0;     //A los campos arrSize y arrAdd les asigna el valor 0
    miArray -> arrAdd = 0;

    if(miArray == NULL){    //En el caso de que el puntero sea nulo devolvemos un -1 (se produce un error).
        return -1;
    }
    return 0;   //La funcion devuelve 0 si no se produce nignun error.
}

int addElement(arrayLength_t *miArray, int nuevoValor){ //Ejercicio 3
    if(nuevoValor <= 0){    // si el nuevo valor es menor o igual que 0, entonces comprobamos si es positivo o no.
        return -1;  // Si no es positivo devuelve -1.
    }
    if(miArray ->arrSize >= SIZE){  // Comprobamos si hay espacio en el array.
        return -1;  // Si no hay espacio en el array, devuelve -1;
    }

    miArray->arrInt[miArray->arrSize] = nuevoValor; // Accedemos al puntero y se agrega a la posicion siguiente a la ultima.
    miArray-> arrSize++;    // Incrementa el numero de elementos del array
    miArray->arrAdd += nuevoValor;  // actualiza la suma de los elementos del array.

    return 0;   // si se a;ade correctamente al array, devuelve 0.
}

int main() {
     arrayLength_t miArray;

    for (int i = 0; i < SIZE; ++i) {
        miArray.arrInt[i] = i + 1;      //Valores del 1 al 10
    }
    
    miArray.arrSize= SIZE; 
    
    miArray.arrAdd = 0;
    for (int i = 0; i < miArray.arrSize; ++i) {
        miArray.arrAdd += miArray.arrInt[i];
    }

    initArray(&miArray);
    printf("La estructura ha sido inicializada correctamente");

    printf("Los elementos del array son: \n");
    for (int i = 0; i < miArray.arrSize; ++i) {
        printf("%d \n", miArray.arrInt[i]);
    }

    addElement(&miArray,9);
    printf("Al agregar un elemento mas al array, el total de elemenos es de: \n");
    for (int i = 0; i < miArray.arrSize; ++i) {
        printf("%d", miArray.arrInt[i]);
    }

    printf("Numero de elementos almacenados en el array: %d \n", miArray.arrSize);
    printf("Suma de los elementos contenidos en el array: %d \n", miArray.arrAdd);




    return 0;
}
