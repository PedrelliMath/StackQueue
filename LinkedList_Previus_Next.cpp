#include <iostream>
#include <stdlib.h>
#include <locale.h>

void printList(struct List *head);

struct List{
	int num;
	struct List *next;
	struct List *previus;
};

struct List *createList(){
	
	int num = 0;
	
	std::cout << "Digite o valor inicial: ";
	std::cin >> num;
	
	struct List *head = (struct List *)malloc(sizeof(struct List));
	head->num = num;
	head->next = NULL;
	head->previus = NULL;
	return head;
}

void insertInit(struct List*& head){
		
	if(head == NULL){
		
		std::cout << "Não existe nenhuma lista...\n";
		return;
	}
	
	int num = 0;

	std::cout << "Digite o valor para inserir no começo: ";
	std::cin >> num;
	
	struct List *newItem = (struct List *)malloc(sizeof(struct List));
	newItem->num = num;
    newItem->next = head;
    newItem->previus = NULL; 

    head->previus = newItem; 
    head = newItem; 
	
	printList(head);	
}

void insertFim(struct List*& head){
		
	if(head == NULL){
		
		std::cout << "Não existe nenhuma lista...\n";
		return;
	}
	
	int num = 0;
	
	std::cout << "Digite o valor para inserir no fim: ";
	std::cin >> num;
	
	struct List *newItem = (struct List *)malloc(sizeof(struct List));
	newItem->num = num;
	
	struct List *current = head;
	
	while(current->next != NULL){
		current = current->next;
	}
	
	current->next = newItem;
	newItem->previus = current;
	newItem->next = NULL;
	
	printList(head);
}

void printList(struct List *head){
	
	if(head == NULL){
		
		std::cout << "Não existe nenhuma lista...\n";
		return;
	}
	
	struct List *current = head;
	
	while(current != NULL){
		
		std::cout << current->num << ", ";
		current = current->next;
	}
}

void printReverse(struct List *head){
	
	if(head == NULL){
		
		std::cout << "Não existe nenhuma lista...\n";
		return;
	}
	
	struct List *current = head;
	
	while(current != NULL && current->next != NULL){
		current = current->next;
	}
	
	while(current != NULL){
		
		std::cout << current->num << ", ";
		current = current->previus;
	}
}

void removeItem(struct List*& head){
	
	int num = 0;
	int quantidade = 0;
	
	cout << "Digite o item para remover: ";
	cin >> num;
	
	while(current != NULL){
		
		if(head->num == num){
		
			struct List *temp = head;
			head = head->next;
			head->previus = NULL;
		
			quantidade++;
			free(temp);
		
		}else{
			
			struct List *current = head;
			
			while(current != NULL & !(current->num)){
				
				
			}
		
		}
	}

}

void apagaLista(struct List*& head){
	
	if(head == NULL){
		
		std::cout << "Não existe nenhuma lista...\n";
		return;
	}
	
	
	while(head != NULL){
		
		struct List *temp = head;
		head = head->next;
		free(temp);
	}
	
}


int main() {
	setlocale(LC_ALL, "Portuguese");
	
	struct List *head = NULL;
	
	int option = -1;
	
	do{
		
		std::cout << "\nEscolha uma das opções abaixo\n";
		std::cout << "1.\tCriar Lista\n"
		<< "2.\tInserir no Inicio\n"
		<< "3.\tInserir no Fim\n" 
		<< "4.\tPrintar Lista\n" 
		<< "5.\tPrintar Reverso\n"
		<< "6.\tApagar Lista\n"
		<< "0.\tSair\n";
		
		std::cin >> option;
		
		switch(option){
			
			case 1:
				if(head != NULL){
					
					std::cout << "A lista ja existe..\n";
				}else{
					
					head = createList();
				}
				
				break;
			
			case 2:
				insertInit(head);
				break;
			
			case 3:
				insertFim(head);
				break;
	
			case 4:
				printList(head);
				break;
			
			case 5:
				printReverse(head);
				break;
				
			case 6:
				apagaLista(head);
				break;
		}
		
	}while(option != 0);
	
	return 0;
}
