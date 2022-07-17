

//--EQUIPE--
//--Antônio Junior--
//--Gabriel Oton--
//--Guilherme Roque--
//--Jonathas Nóbrega--
//--Maria Rita--


#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRLIMIT 100

typedef struct lista {
    char name[STRLIMIT];
    char surname[STRLIMIT];
    char cell[STRLIMIT];
    char email[STRLIMIT];
    char job[STRLIMIT];
    char target[STRLIMIT];
    char slogan[STRLIMIT];

    struct lista *prox;
} Lista;

int menu();
int insere();
int imprime();
int busca();
int remover();
int verifica();
void flush_in();

int main(void) {
    verifica();
    FILE *a;
    Lista jobs;
    a = fopen("jobs.txt", "rb");
    system("clear");
    printf("É recomendado usar apenas letras minúsculas\nmas use o programa como achar melhor\nPressione Enter para continuar!");
    flush_in();
    fread(&jobs, sizeof(Lista), 1, a);
    system("clear");
    int op = 5, i, c;
    while((op < 0) || (op > 4)){
        op = menu();
        switch (op){
            case 1:
                system("clear");
                insere();
                system("clear");
                op = 5;
                break;
            case 2:
                system("clear");
                imprime();
                system("clear");
                op = 5;
                break;
            case 3:
                system("clear");
                busca();
                system("clear");
                op = 5;
                break;
            case 4:
                system("clear");
                remover();
                system("clear");
                op = 5;
                break;
        }
    }
    
}



int menu(){
    int op = 5;
    char opc;
    printf("=-=-=-=-Menu=-=-=-=-\n");
    printf("\nDigite 1 para inserir um trabalho; \n");
    printf("\nDigite 2 listar trabalhos; \n");
    printf("\nDigite 3 para buscar um trabalho; \n");
    printf("\nDigite 4 para concluir um trabalho; \n");
    printf("\nDigite 0 para sair; \n");
    printf("\n=-=-=-=-=-=-=-=-=-=-\n");
    while((op < 0) || (op > 4)){
        printf("\nDigite a ação que deseja executar!: ");
        opc = getchar();
        getchar();
        if (isdigit(opc) != 0){
            op = (opc - 48);
        }
    }
    return op;
}

int insere(){
    int c;
    FILE *a;
    Lista jobs;
    printf("Digite o seu 1º nome: ");
    scanf("%s", jobs.name);
    getchar();
    printf("Digite o seu sobrenome: ");
    scanf("%s", jobs.surname);
    printf("Digita o nº de celular: ");
    scanf("%s", jobs.cell);
    printf("Digite o email: ");
    scanf("%s", jobs.email);
    printf("Digite a sua area: ");
    scanf("%s", jobs.job);
    printf("Digite o público alvo: ");
    scanf("%s", jobs.target);
    printf("Digite o slogan: ");
    scanf("%s", jobs.slogan);
    a = fopen("jobs.txt", "ab");
    fwrite(&jobs, sizeof(Lista), 1, a);
    fclose(a);
    printf("Job Inserido!\n");
    c = getchar();
    flush_in();
    system("clear");
}

int imprime(){
    FILE *a;
    Lista jobs;
    a = fopen("jobs.txt", "rb");
    fread(&jobs, sizeof(Lista), 1, a);
    int i, c; 
    i = 0;
    a = fopen("jobs.txt", "rb");
    while(fread(&jobs, sizeof(Lista), 1, a) == 1){
        i++;
        printf("-----Job %d-----\n", i);
        printf("\nNome: %s %s\n", jobs.name, jobs.surname);
        printf("Contato: %s\n", jobs.cell);
        printf("Email: %s\n", jobs.email);
        printf("Área: %s\n", jobs.job);
        printf("Público Alvo: %s\n", jobs.target);
        printf("Slogan: %s\n\n", jobs.slogan);
    }
    printf("\nPressione Enter para continuar\n");
    getchar();
}

int busca(){
    FILE *a;
    Lista jobs;
    char word[STRLIMIT];
    int i = 0, c;
    a = fopen("jobs.txt", "rb");
    fread(&jobs, sizeof(Lista), 1, a);
    printf("Digite o 1º nome do cliente: ");
    scanf("%s", word);
    system("clear");
    a = fopen("jobs.txt", "rb");
    while(fread(&jobs, sizeof(Lista), 1, a) == 1){
        if(strcmp(word, jobs.name) == 0){
            i++;
            printf("--Job %d--\n", i);
            printf("\nNome: %s %s\n", jobs.name, jobs.surname);
            printf("Contato: %s\n", jobs.cell);
            printf("Email: %s\n", jobs.email);
            printf("Área: %s\n", jobs.job);
            printf("Público Alvo: %s\n", jobs.target);
            printf("Slogan: %s\n\n", jobs.slogan);
        }
    }
    if (i == 0){
        printf("Nenhum contato encontrado!\n");
    }
    printf("\nPressione Enter para continuar\n");
    c = getchar();
    getchar();
}


int remover(){
    FILE *a, *b;
    Lista jobs;
    char word[STRLIMIT], plur;
    int i = 0, c = 0;
    a = fopen("jobs.txt", "rb");
    fread(&jobs, sizeof(Lista), 1, a);
    b = fopen("temp.txt", "w");
    b = fopen("temp.txt", "ab");
    printf("Digite o 1º nome do cliente: ");
    scanf("%s", word);
    a = fopen("jobs.txt", "rb");
    while(fread(&jobs, sizeof(Lista), 1, a) == 1){
        if(strcmp(word, jobs.name)){
            fwrite(&jobs, sizeof(Lista), 1, b);
        }
        else{
            system("clear");
            printf("\n--Job encontrado!--\n");
            printf("\nNome: %s %s\n", jobs.name, jobs.surname);
            printf("Contato: %s\n", jobs.cell);
            printf("Email: %s\n", jobs.email);
            printf("Área: %s\n", jobs.job);
            printf("Público Alvo: %s\n", jobs.target);
            printf("Slogan: %s\n\n", jobs.slogan);
            printf("\nDigite 1 para sim;\nDigite 2 para não;\n");
            while((c > 2) || (c < 1)){
                printf("Deseja apagalo? ");
                scanf("%d", &c);
            }
            if (c == 2){
                fwrite(&jobs, sizeof(Lista), 1, b);
                c = 0;
            }
            else{
                i += 1;  
                c = 0;
            }
            
        }
    }
    fclose(a);
    fclose(b);
    remove("jobs.txt");
    rename("temp.txt", "jobs.txt");
    if (i != 0){
        if (i == 1){
            printf("%d contato chamado %s foi removido dos seus jobs!", i, word);
        }
        else{
            printf("%d contatos chamados %s foram removidos dos seus jobs!", i, word);
        }
    }
    else{
        printf("Não há mais nenhum Job do cliente chamado %s", word);
    }
    c = getchar();
    getchar();
}

int verifica(){
    FILE *a;
    if (a = fopen("jobs.txt", "r")) 
    {
        fclose(a);
    }
    else
    {
        a = fopen("jobs.txt", "w");
        fclose(a);
    }
}

void flush_in(){
    int ch;
    do {
        ch = fgetc(stdin);
    } while (ch != EOF && ch != '\n');
}
