#include <stdio.h>
#include <stdlib.h>

//Definicao do nó da lista encadeada

typedef struct No{
    int value;
    struct No* prox;
}No;

//função para adicionar um novo no na lista
void insertno(No** head, int value){
    No* newno = (No*)malloc(sizeof(No)); // Aloca memória para o novo nó
    newno->value = value; // Atribui o valor ao novo nó
    newno->prox = NULL; // Faz o 'prox' apontar para NULL

    if (*head == NULL) {
        // Se a lista estiver vazia, o novo nó será o primeiro
        *head = newno;
    }
    else {
        // Se a lista não estiver vazia, percorre até o último nó
        No* temp = *head;
        while (temp->prox != NULL) {
            temp = temp->prox;
        }
        // Depois de achar o último nó, faz o 'prox' apontar para o novo nó
        temp->prox = newno;
    }
}
//função para imprimir a lista 
void readlist(No* head){
    if(head == NULL){
        printf("A lista esta vazia!\n");
        return;
    }
    No* temp = head;
    printf("lista de nos: \n");
    while(temp != NULL){
        printf("%d -> ",temp->value); //exibe o valor do nó
        temp = temp->prox; //avança para o proximo nó
    }
    printf("NULL\n");
}   
//função update atuliazar nó
void updateno(No* head, int oldvalue, int newvalue){
    No* temp = head;
    while(temp != NULL){
        if(temp->value==oldvalue){
            temp->value=newvalue; //atualiza o valor do nó  
            printf("o valor %d foi atualizado para %d ! \n",oldvalue,newvalue);
            return;
        }
        temp = temp->prox;
    }
    printf("valor %d nao foi encontrado na lista!\n",oldvalue);
}
//função delete 
void deleteno(No** head, int value){
    if(*head == NULL){
        printf("a lista esta vazia!\n");
        return;
    }
    No* temp = *head;
    No* prev = NULL;
    //Se o nó a ser removido é o primeiro nó
    if(temp != NULL && temp->value==value){
        *head = temp->prox; //atualiza o head para o prox nó
        free(temp);//libera a memoria do no removido
        printf("o valor %d foi removido !\n",value);
        return;
    }
    //caso o nó a ser removido não seja o primeiro
    while(temp != NULL && temp->value != value){
        prev = temp;
        temp = temp->prox;
    }
    //se o valor não for encontrado
    if(temp == NULL){
        printf("o valor %d nao foi encontrado !\n", value);
        return;
    }
    prev->prox = temp->prox; //desconecta o nó a ser removido
    free(temp); //libera a memoria do no removido
    printf("o valor %d foi removido !\n",value);
}

//criação da main 

int main(){
    No* head = NULL; //inicializa a lista vazia
    int choice, value, newvalue, oldvalue;

    while(1){
         printf("\nEscolha uma operacao:\n");
        printf("1. Adicionar (Criar) um valor\n");
        printf("2. Exibir a lista\n");
        printf("3. Atualizar um valor\n");
        printf("4. Remover um valor\n");
        printf("5. Sair\n");
        printf("Opcao: ");
        scanf("%d", &choice);

        if(choice == 1){
            printf("Digite o valor a ser adicionado: \n");
            scanf("%d",&value);
            insertno(&head,value);
        } else if(choice == 2){
            readlist(head);
        } else if(choice == 3){
            printf("Digite o valor que deseja atualizar: \n");
            scanf("%d",&oldvalue);
            printf("Digite o novo valor: \n");
            scanf("%d",&newvalue);
            updateno(head,oldvalue,newvalue);
        } else if(choice == 4){
            printf("Digite o valor que deseja remover: \n");
            scanf("%d",&value);
            deleteno(&head,value);
        } else if(choice == 5){
            break;
        } else{
            printf("Opcao invalida! \n");
        }
    }
        //libera a memoria da lista ao final
        No* temp = head;
        while(temp != NULL){
            No* next = temp->prox;
            free(temp);
            temp = next;
        }
    
    return 0;
}


