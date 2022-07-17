#include <stdio.h>

typedef struct {
    char nome[100];
    int idade;

} pessoa;

void changeage(pessoa *ponteiro){
    int change;
    printf("\nDigite a altere: ");
    scanf("%d", &change);

    ponteiro -> idade = change;
}

int main(void){
    pessoa p;
    printf("\nDigite o nome: ");
    scanf("%s", p.nome);
    printf("Digite a idade: ");
    scanf("%d", &p.idade);


    printf("\nNome: %s \nIdade: %d\n", p.nome, p.idade);
    changeage(&p);
    printf("\nNome: %s \nIdade: %d\n", p.nome, p.idade);
}

