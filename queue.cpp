#include <iostream>
#include <stdlib.h>
using namespace std;

struct queue{
    int* vector;
    int fim;
    int maxSize;
};

struct queue* createQueue(void){

    int maxSize = 0;
    cout << "Digite o tamanho da fila: " << endl;
    cin >> maxSize;

    struct queue* fila = (struct queue *) malloc(sizeof(struct queue));
    fila->vector = (int*) malloc(sizeof(int) * maxSize);
    fila->fim = 0;
    fila->maxSize = maxSize;
    return fila;
}

void displayMainOptions(void){
    cout << "1.\tCriar uma fila\n2.\tInserir elemento na fila\n3.\tRemover elemento da fila\n4.\tApagar Fila\n0.\tSair" << endl;
}

void insertItem(struct queue* fila){

    int value = 0;
    cout << "Digite o valor para inserir: " << endl;
    cin >> value;

    fila->vector[fila->fim] = value;
    fila->fim++;
}


int main(void){

    struct queue* fila = nullptr; 
    int option = -1;

    do{

        displayMainOptions();
        cin >> option;

        switch(option){

            case 0: 
                break;
            case 1: 
                fila = createQueue();
                cout << "Fila criada com sucesso!" << endl;
                break;
            case 2:
                insertItem(fila);
                break;
        }
    }while(option != 0);
}