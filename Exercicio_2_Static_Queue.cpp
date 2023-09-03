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

    if(fila != nullptr){
        cout << "Fila criada com sucesso!\n" << endl;
    }else{
        cout << "Ops, houve um problema ao criar a fila\n" << endl;
    }

    return fila;
}

void displayMainOptions(void){

    cout << "1.   Criar uma fila\n"
     << "2.   Inserir elemento na fila\n"
     << "3.   Remover elemento da fila\n"
     << "4.   Apagar Fila\n"
     << "5.   Imprimir Fila\n"
     << "0.   Sair" << endl;
}

void insertItem(struct queue* fila){

    if(fila == nullptr){
        cout << "Nao existe nenhuma fila...\n" << endl;
        return;
    }else if(fila->fim >= fila->maxSize){
        cout << "A fila esta cheia...\n";
        return;
    }

    int value = 0;
    cout << "Digite o valor para inserir: " << endl;
    cin >> value;

    fila->vector[fila->fim] = value;
    fila->fim++;
}

void removeFromQueue(struct queue* fila){

    int index = 0;

    if(fila != nullptr){
 
        cout << "Digite o indice para remover: " << endl;
        cin >> index;
        
        if(index < 0 || index > fila->fim - 1){

            cout << "Indice invalido...\n";
            return;
        }

        for(int i = 0; i <= index; i++){

            cout << "Valor a ser removido: " << fila->vector[0] << endl;
            for(int j = 0; j < fila->fim - 1; j++){

                fila->vector[j] = fila->vector[j + 1];
            }
            fila->fim--; 
        }
    }else{

        cout << "Nao existe nenhuma fila...\n" << endl;
    }
}

void printQueue(struct queue* fila){

    if(fila != nullptr){
        for(int i = 0; i < fila->fim; i++){
            
            cout << fila->vector[i] << " ";
        }
        cout << "\n";
    }else{

        cout << "Nao existe fila para imprimir...\n" << endl;
    }
}

void deleteQueue(struct queue** fila) {

    if (*fila != nullptr) {

        free((*fila)->vector);
        free(*fila);
        *fila = nullptr;
        cout << "Fila deletada com sucesso...\n" << endl;
    } else {

        cout << "Nao existe fila para deletar...\n" << endl;
    }
}

int main(void){

    struct queue* fila = nullptr; 
    int option = -1;

    do{
        displayMainOptions();
        cin >> option;

        switch(option){

            case 0: 
                deleteQueue(&fila);
                break;
            case 1: 
                fila = createQueue();
                break;
            case 2:
                insertItem(fila);
                break;
            case 3:
                removeFromQueue(fila);
                break;
            case 4:
                deleteQueue(&fila);
                break;
            case 5:
                printQueue(fila);
                break;
            default:
                cout << "Opcao invalida...\n";
                break;
        }
    }while(option != 0);

    return 0;
}