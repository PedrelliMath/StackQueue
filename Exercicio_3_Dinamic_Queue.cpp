#include <iostream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

struct Queue{
    int password;
    bool priority;
    bool(*setPriority)(void);
    struct Queue *next;
};

bool setPriority(void){
    int priority = 0;

    while(1){

        cout << "Esta senha tem prioridade?\n1.\tSim\n0.\tNao\n";
        cin >> priority;

        if(priority != 0 && priority != 1){

            cout << "Opcao invalida... Digite novamente." << endl;
        }else break;
    }

    return priority == 1; 
}


void getNewPassword(struct Queue*& head, int& password) {

    system("cls");

    struct Queue* newPassword = (struct Queue*)malloc(sizeof(struct Queue));
    newPassword->password = password++;
    newPassword->setPriority = &setPriority;
    newPassword->priority = newPassword->setPriority();
    newPassword->next = nullptr;

    if (head == nullptr) {
        head = newPassword;
    } else {
        struct Queue* current = head;

        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = newPassword;
    }

    cout << password - 1 << " adicionado a fila de senhas!\n" << endl;
}

void callPassword(struct Queue*& head){

    system("cls");

    if(head == nullptr){

        cout << "Nao existe nenhuma senha na fila...\n" << endl;
        return;
    }

    if(head->priority){

        cout << "Encontrado senha com prioridade...\n"
        << "A senha: " << head->password << " foi chamada\n" << endl;

        struct Queue* temp = head;
        head = head->next;

        free(temp);
        return;

    }else{
        
        struct Queue* current = head;
        struct Queue* previous = nullptr;

        while(current != nullptr && !current->priority){
            previous = current;
            current = current->next;
        }

        if (current != nullptr) {

            if (previous != nullptr) {

                previous->next = current->next;
            }else{

                head = current->next;
            }

            cout << "Encontrado senha com prioridade...\n"
            << "A senha: " << current->password << " foi chamada\n" << endl;

            free(current);

        }else {

            cout << "Nao foi encontrado senha com prioridade...\n"
            << "A senha: " << head->password << " foi chamada\n" << endl;

            struct Queue* temp = head;
            head = head->next;
            free (temp);
        }
    }
}

void printDetails(struct Queue *head){

    system("cls");

    if(head != nullptr){

        struct Queue *current = head;

        while(current != nullptr){
            
            cout << "Senha: " << setw(4) << setfill('0') << current->password << " Prioridade: "
            << (current->priority ? "Sim" : "Nao") << endl;

            current = current->next;
        }

    }else{
        cout << "Nao existe fila para imprimir...\n" << endl;
    }
}

void printQueue(struct Queue *head){

    system("cls");

    if(head != nullptr){

        struct Queue *current = head;

        while(current != nullptr){
            cout << setw(4) << setfill('0') << current->password << " ";
            current = current->next;
        }

        cout << "\n" << endl;

    }else{
        cout << "Nao existe fila para imprimir...\n" << endl;
    }
}

void deleteQueue(struct Queue*& head, int& password){

    system("cls");

    if(head != nullptr){

        while (head != nullptr) {
            struct Queue* temp = head;
            head = head->next;
            free(temp);
        }

        password = 1;
        cout << "As senhas foram excluidas da fila!\n" << endl;

    }else{

        cout << "Nao foi encontrado nenhuma senha na fila...\n" << endl;
    }
}


void displayMainOptions(void){

    cout << "1.   Solicitar Senha\n"
     << "2.   Chamar Senha\n"
     << "3.   Imprimir Fila\n"
     << "4.   Imprimir Detalhes\n"
     << "5.   Apagar Fila\n"
     << "0.   Sair" << endl;
}

int main(void){

    int passwordCount = 1;
    struct Queue* queue = nullptr; 
    int option = -1;

    do{
        displayMainOptions();
        cin >> option;

        switch(option){

            case 0: 
                deleteQueue(queue, passwordCount);
                break;
            case 1: 
                getNewPassword(queue, passwordCount);
                break;
            case 2:
                callPassword(queue);
                break;
            case 3:
                printQueue(queue);
                break;
            case 4:
                printDetails(queue);
                break;
            case 5:
                deleteQueue(queue, passwordCount);
                break;
            default:
                cout << "Opcao invalida...\n";
                break;
        }
    }while(option != 0);

    return 0;
}