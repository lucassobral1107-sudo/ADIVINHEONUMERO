#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void limpar_buffer(void){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}


int ler_inteiro(int *valor){
    if(scanf("%i", valor) != 1){
        limpar_buffer();
        return 0;
    }
    limpar_buffer();
    return 1;
}

void jogar(void){
    int num, palpite = -1, nivel, maximo, limite;
    int tentativas = 0;

    printf("\n=== ADIVINHE O NUMERO ===\n");
    printf("Escolha o nivel de dificuldade:\n");
    printf("1 - Facil   (1 a 5)\n");
    printf("2 - Medio   (1 a 20)\n");
    printf("3 - Dificil (1 a 100)\n");
    printf("Opcao: ");

    if(!ler_inteiro(&nivel)){
        nivel = 0;
    }

    if(nivel == 1){
        maximo = 5;
        limite = 3;
    }else if(nivel == 2){
        maximo = 20;
        limite = 5;
    }else if(nivel == 3){
        maximo = 100;
        limite = 7;
    }else{
        printf("Opcao invalida! Usando nivel facil.\n");
        maximo = 5;
        limite = 3;
    }

    num = (rand() % maximo) + 1;

    printf("\nVoce tem %i tentativas para acertar o numero de 1 a %i.\n", limite, maximo);

    while(tentativas < limite){
        printf("\nTentativa %i de %i - Informe seu palpite: ", tentativas + 1, limite);

        if(!ler_inteiro(&palpite)){
            printf("Entrada invalida! Digite um numero.\n");
            continue; 
        }

        tentativas++;

        if(palpite > num){
            printf("Seu palpite e maior que o numero sorteado.");
        }else if(palpite < num){
            printf("Seu palpite e menor que o numero sorteado.");
        }else{
            printf("Parabens! Voce acertou em %i tentativa(s)!", tentativas);
            break;
        }
    }

    if(palpite != num){
        printf("\n\nSuas tentativas acabaram! Voce perdeu.");
        printf("\nO numero sorteado era: %i", num);
    }
    printf("\n");
}

int main(void){
    int opcao;

    srand(time(NULL));

    do{
        jogar();

        printf("\n=== MENU ===\n");
        printf("1 - Jogar novamente\n");
        printf("2 - Sair\n");
        printf("Opcao: ");

        if(!ler_inteiro(&opcao)){
            opcao = 0;
        }

        while(opcao != 1 && opcao != 2){
            printf("Opcao invalida! Digite 1 ou 2: ");
            if(!ler_inteiro(&opcao)){
                opcao = 0;
            }
        }
    }while(opcao == 1);

    printf("\nObrigado por jogar! Ate a proxima.\n");
    return 0;
}
