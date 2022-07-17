#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define STRLIMIT 100
typedef struct lista{
    char nome[STRLIMIT];
    char telefone[STRLIMIT];
    char celular[STRLIMIT];
    char email[STRLIMIT];
    struct lista* prox;
}Lista;

int menu(){
    int op = 4;
    printf("=-=-=-=-Menu=-=-=-=-\n");
    printf("\nDigite 1 para inserir um contato; \n");
    printf("\nDigite 2 listar contatos; \n");
    printf("\nDigite 3 para buscar um contato; \n");
    printf("\nDigite 0 para sair; \n");
    printf("\n=-=-=-=-=-=-=-=-=-=-\n");
    while((op < 0) || (op > 3)){
        printf("\nDigite a ação que deseja executar!: ");
        scanf("%d", &op); 
    }
    return op;
}



void busca(Lista* l, char* valor, int tam){
    int i;
    Lista *pont = l;
    for (i = 0; i < tam; i++){
        if (strcmp(l[i].nome, valor)==0){
            printf("\n--Contato Encontrado!--\n");
            printf("\nNome: %s", l[i].nome);
            printf("\nTelefone: %s", l[i].telefone);
            printf("\nCelular: %s", l[i].celular);
            printf("\nEmail: %s", l[i].email);
        }
    } 
}



void imprime(Lista* l, int len){
    int i;
    for (i = 0; i < len; i++){
        printf("Contato %d\n", i+1);
        printf("\nNome: %s", l[i].nome);
        printf("Telefone: %s", l[i].telefone);
        printf("Celular: %s", l[i].celular);
        printf("Email: %s", l[i].email);
        printf("-------------------\n\n");
    }
}

int insere(Lista* l, int pos){
    char clear[100];
    int i = 0;
    fgets(clear, 100, stdin);
    printf("\nDigite o nome: ");
    fgets(l[pos].nome,sizeof(l[pos].nome), stdin);
    printf("Digite o Telefone: ");
    fgets(l[pos].telefone,sizeof(l[pos].telefone), stdin);
    printf("Digite o Celular: ");
    fgets(l[pos].celular,sizeof(l[pos].celular), stdin);
    printf("Digite o Email: ");
    fgets(l[pos].email,sizeof(l[pos].email), stdin);
    i++;
    return i;
}
int main(void){
    int tam = 0, op = 4, c, i;
    char valor[100];
    Lista lista[STRLIMIT];
    while((op < 0) || (op > 3)){
        system("clear");
        op = menu();
        switch (op){
            case 1:
                system("clear");
                tam += insere(lista, tam);
                getchar();
                system("clear");
                op = 4;
                break;
            case 2:
                system("clear");
                imprime(lista, tam);
                c = getchar();
                getchar(); 
                system("clear"); 
                op = 4;
                break;
            case 3:
                system("clear");
                printf("Digite o valor que deseja procurar: \n");
                getchar();
                fgets(valor,100, stdin);
                busca(lista,valor, tam);
                c = getchar();
                op = 4;
                break;
            case 0:
                break;

        }
    }

}
