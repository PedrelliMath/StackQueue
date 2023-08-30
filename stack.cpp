#include <iostream>
using namespace std;

int *createStack(int size){

    int *stack = (int *) new int[size];
    return stack;
}

void displayOptions(void){

    cout << "1.\tInserir na Pilha\n2.\tRemover da Pilha\n3.\tApagar Pilha\n0.\tSair\n" << endl;
}

void stackPush(int * pilha, int& top, int size){

    if(pilha != nullptr){
        
        int value = 0;
        cout << "Digite o valor para inserir: " << endl;
        cin >> value;

        if(top < size - 1){

            top++;
            pilha[top] = value;

            cout << "Sucesso ao inserir o valor na pilha!\n" << endl;
        }else{

            cout << "Pilha esta cheia, nao e possivel inserir...\n" << endl;
        }   
    }else{

        cout << "Nao existe nenhuma pilha!\n" << endl;
    }
}

void stackRemove(int* pilha, int& top) {

    if(pilha != nullptr){
        int index = 0;
        cout << "Digite o indice para remover: " << endl;
        cin >> index;

        if (index < 0 || index > top) {

            cout << "Indice invalido.\n" << endl;
            return;
        }

        while (top >= index) {

            top--;
            cout << "Valor removido: " << pilha[top + 1] << endl;
            pilha[top + 1] = 0;
        }
    }else{

        cout << "Nao existe nenhuma pilha!" << endl;
    }
}

void printStack(int* pilha, int size){

    if(pilha != nullptr){

        for(int i = 0; i < size; i++){
            cout << i << ".\t" << pilha[i] << endl;
        }
    }
}
   

int main(void){

    int size = 0;
   
    cout << "Digite o tamanho da pilha: " << endl;
    cin >> size;

    int* pilha = createStack(size);

    if(pilha != nullptr) cout << "Pilha criada com sucesso!\n";
    else cout << "Falha ao criar a pilha...\n";

    int option = 0;
    int top = - 1;

    do{

        displayOptions();
        cin >> option;

        switch(option){

            case 0:
                break;
            case 1: 
                stackPush(pilha, top, size); 
                break;
            case 2: 
                printStack(pilha, size);
                stackRemove(pilha, top); 
                break;
            case 3: 
                delete[] pilha; 
                pilha = nullptr;
                break;

            default: 
                cout << "Opcao invalida...\n";
                break;
        }
    }while(option != 0);

    delete[] pilha;

    return 0;
}
 
