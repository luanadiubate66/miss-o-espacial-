#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void limpar_linha(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int escolher_planeta(void) {
    int escolha;
    printf("\nEscolha um planeta:\n");
    printf("1. Planeta Azul\n");
    printf("2. Planeta Vermelho\n");
    printf("3. Planeta Roxo\n");

    while (1) {
        printf("Destino (1, 2 ou 3): ");
        if (scanf("%d", &escolha) == 1 && escolha >= 1 && escolha <= 3) {
            limpar_linha();
            return escolha;
        }
        printf("Opcao invalida. Tente novamente.\n");
        limpar_linha();
    }
}

int main(void) {
    const char *nomes[] = {"", "Planeta Azul", "Planeta Vermelho", "Planeta Roxo"};
    const char *mensagens[] = {"", "Voce encontrou cristais de agua!",
                               "Voce encontrou minerais raros!",
                               "Voce encontrou energia espacial!"};
    int pontos = 0, vidas = 3, recursos = 0;
    char nome[80];

    srand((unsigned int)time(NULL));

    printf("==========================================\n");
    printf("             MISSAO ESPACIAL\n");
    printf("==========================================\n");
    printf("Digite o nome do(a) astronauta: ");
    if (fgets(nome, sizeof(nome), stdin) == NULL) {
        strcpy(nome, "Astronauta");
    }
    nome[strcspn(nome, "\n")] = '\0';
    if (strlen(nome) == 0) strcpy(nome, "Astronauta");

    printf("\nBem-vindo(a), %s! Sua missao e explorar 3 planetas\n", nome);
    printf("e coletar pelo menos 2 recursos para salvar a Terra.\n");

    for (int fase = 1; fase <= 3 && vidas > 0; fase++) {
        int planeta, evento;
        printf("\n--- FASE %d DE 3 ---\n", fase);
        planeta = escolher_planeta();
        printf("\nNave chegando ao %s...\n", nomes[planeta]);

        evento = rand() % 3;
        if (evento == 0) {
            printf("%s\n", mensagens[planeta]);
            pontos += 10;
            recursos++;
            printf("+10 pontos! Recurso coletado.\n");
        } else if (evento == 1) {
            printf("Um campo de asteroides bloqueou seu caminho!\n");
            vidas--;
            printf("Voce perdeu uma vida.\n");
        } else {
            printf("Voce encontrou uma estrela de energia!\n");
            pontos += 5;
            printf("+5 pontos bonus!\n");
        }

        printf("Vidas: %d | Pontos: %d | Recursos: %d\n", vidas, pontos, recursos);
    }

    printf("\n==========================================\n");
    printf("             RESULTADO DA MISSAO\n");
    printf("==========================================\n");
    printf("Astronauta: %s\n", nome);
    printf("Pontuacao final: %d\n", pontos);
    printf("Recursos coletados: %d\n", recursos);
    printf("Vidas restantes: %d\n", vidas);

    if (vidas > 0 && recursos >= 2) {
        printf("\nMISSAO CONCLUIDA! Voce ajudou a salvar a Terra!\n");
    } else if (vidas <= 0) {
        printf("\nFIM DE JOGO! Suas vidas acabaram.\n");
    } else {
        printf("\nMISSAO NAO CONCLUIDA. Faltaram recursos para salvar a Terra.\n");
    }
    return 0;
}
