#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Define um valor para STRLIMIT, 100 é o valor;
#define STRLIMIT 100

//Cria uma struct que pode ser usada para criar listas encadeadas com os valores dentro da struct;
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

//Todas as funções utilizadas no código, elas estão logo abaixo do main;
int menu();
int insere();
int imprime();
int busca();
int remover();
int verifica();
void flush_in();

//é onde o código principal será executado;
int main(void) {

    //Chamo a função de verificar;
    verifica();
    //Coloco a como o meu arquivo, em outras palavras, permito com que manipule arquivos;
    FILE *a;

    //Crio a lista encadeada com os dados da struct;
    Lista jobs;

    //a recebe os dados do meu jobs.txt
    a = fopen("jobs.txt", "rb");

    //essa função limpa a tela;
    system("clear");

    printf("É recomendado usar apenas letras minúsculas\nmas use o programa como achar melhor\nPressione Enter para continuar!");
    
    //faço uma pausa no código e limpo os valores digitados;
    flush_in();

    //trago os dados de a (que são do meu arquivo jobs.txt) para a minha lista encadeada "jobs";
    fread(&jobs, sizeof(Lista), 1, a);

    system("clear");

    int op = 5, i, c;

    //esse while serve para ficar repetindo o menu;
    while((op < 0) || (op > 4)){

        //chama a função Menu;
        op = menu();

        //switch para decidir oq fazer com os dados de op;
        switch (op){
            case 1:
                system("clear");

                //chamo a função de inserir;
                insere();

                system("clear");

                //op = 5 para que o menu possa repetir novamente;
                op = 5;
                break;
            case 2:
                system("clear");

                //chamo a função de imprimir;
                imprime();

                system("clear");
                op = 5;
                break;
            case 3:
                system("clear");

                //chamo a função de buscar;
                busca();

                system("clear");
                op = 5;
                break;
            case 4:
                system("clear");

                //chamo a função de remover;
                remover();

                system("clear");
                op = 5;
                break;

            //caso seja digitado 0, o while ira parar de repetir;
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

    //while para ficar repetindo a pergunta;
    while((op < 0) || (op > 4)){
        printf("\nDigite a ação que deseja executar!: ");

        //decidi usar getchar para pegar um caractere para opc por motivos de teste;
        opc = getchar();

        //pega o próximo caractere digitado, aqui foi usado para dar uma pausa na execução (ele pode ser o causador de diversos problemas, mas estamos trabalhando em uma maneira de evitar esses problemas);
        getchar();

        //nesse if eu verifico se opc é um número, caso sim, op recebe o valor, caso não, nada acontece, e a pergunta será repetida novamente;
        //isso foi feito para evitar que o usuário digite caracteres aqui;
        if (isdigit(opc) != 0){
            op = (opc - 48);
        }
    }
    //retorna o valor de op para que possa ser utilizado novamente;
    return op;
}

int insere(){
    int c;
    FILE *a;
    Lista jobs;
    printf("Digite o seu 1º nome: ");

    //insere uma string na lista encadeada jobs;
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

    //da a permissão para "a" adicionar coisas a jobs.txt;
    a = fopen("jobs.txt", "ab");
    //adiciona os dados da lista encadeada jobs a o arquivo jobs.txt (sei que os nomes podem confundir, mas a lista encadeada jobs e o arquivo jobs.txt são coisas diferentes, embora tenham dados parecidos ou iguais);
    fwrite(&jobs, sizeof(Lista), 1, a);

    //eu fecho o arquivo e salvo, para poder utilizalo em outras coisas dentro do código;
    fclose(a);
    printf("Job Inserido!\n");
    c = getchar();
    flush_in();
    system("clear");
}

int imprime(){
    FILE *a;
    Lista jobs;

    //permito que "a" leia o arquivo jobs.txt;
    a = fopen("jobs.txt", "rb");
    //adiciono os dados de jobs.txt a lista encadeada jobs. (sobre os nomes, já foi explicado anteriormente);
    fread(&jobs, sizeof(Lista), 1, a);

    int i, c; 
    i = 0;
    a = fopen("jobs.txt", "rb");

    //enquanto não chegar ao final da lista encadeada jobs;
    while(fread(&jobs, sizeof(Lista), 1, a) == 1){

        i++;

        //imprimir os dados da lista encadeada jobs;
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

    //digito uma palavra que desejo procurar na minha lista encadeada;
    scanf("%s", word);
    system("clear");
    a = fopen("jobs.txt", "rb");

    //enquanto não chegar ao final da lista encadeada jobs;
    while(fread(&jobs, sizeof(Lista), 1, a) == 1){

        //pergunto se word é igual a jobs, caso seja;
        if(strcmp(word, jobs.name) == 0){

            i++;

            //imprimo os dados de jobs;
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

    //crio 2 variáveis que podem manipular arquivos;
    FILE *a, *b;
    Lista jobs;
    char word[STRLIMIT], plur;
    int i = 0, c = 0;
    a = fopen("jobs.txt", "rb");
    fread(&jobs, sizeof(Lista), 1, a);

    //aqui eu crio um arquivo temporário chamado temp.txt;
    b = fopen("temp.txt", "w");
    //permito adicionar coisas ao arquivo temp.txt
    b = fopen("temp.txt", "ab");


    printf("Digite o 1º nome do cliente: ");
    scanf("%s", word);
    a = fopen("jobs.txt", "rb");

    //enquanto não chegar ao final da lista encadeada jobs;
    while(fread(&jobs, sizeof(Lista), 1, a) == 1){

        //se a palavra que desejo procurar for diferente do 1º nome do cliente (jobs.name);
        if(strcmp(word, jobs.name)){
            //eu escrevo os dados de jobs em b, que envia para o arquivo temporário temp.txt;
            fwrite(&jobs, sizeof(Lista), 1, b);
        }

        //caso ele seja igual;
        else{
            system("clear");

            //imprimo os dados de jobs;
            printf("\n--Job encontrado!--\n");
            printf("\nNome: %s %s\n", jobs.name, jobs.surname);
            printf("Contato: %s\n", jobs.cell);
            printf("Email: %s\n", jobs.email);
            printf("Área: %s\n", jobs.job);
            printf("Público Alvo: %s\n", jobs.target);
            printf("Slogan: %s\n\n", jobs.slogan);
            printf("\nDigite 1 para sim;\nDigite 2 para não;\n");

            while((c > 2) || (c < 1)){
                //pergunto para o usuário se ele deseja apagar;
                printf("Deseja apagalo? ");
                scanf("%d", &c);
            }

            //caso a resposta seja 2 (não);
            if (c == 2){

                //passo os dados para o arquivo temp.txt, como já explicado anteriormente;
                fwrite(&jobs, sizeof(Lista), 1, b);

                c = 0;
            }

            //caso a resposta seja 1 (sim);
            else{
                //eu não faço nada;
                i += 1;  
                c = 0;
            }
            
        }
    }

    //aqui eu fecho os arquivos para que eles sejam salvos;
    fclose(a);
    fclose(b);

    //eu apago jobs.txt (ele possui todos os dados de jobs, até mesmo o que decidi apagar);
    remove("jobs.txt");

    //renomeio o arquivo temporário para jobs.txt (assim terei todos os arquivos de jobs, menos oq eu decidi apagar);
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

    //aqui basicamente eu tento abrir o arquivo de jobs, se ele existir;
    if (a = fopen("jobs.txt", "r")) 
    {

        //eu só fecho ele para usar depois;
        fclose(a);
    }

    //caso ele não exista;
    else
    {
        //eu crio ele;
        a = fopen("jobs.txt", "w");
        fclose(a);
    }
}

//Essa função limpa valores digitados em variaveis, retira os \n;
void flush_in(){
    int ch;
    do {
        ch = fgetc(stdin);
    } while (ch != EOF && ch != '\n');
}
