#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "acaoPersonagem.h"

void limpa_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int main() {
    srand(time(NULL)); // Inicializa a semente para geração de números aleatórios

    int vida_jogador = 100;
    int vida_inimigo = 100;
    int defesa_jogador = 0;
    int defesa_inimigo = 0;

    while (vida_jogador > 0 && vida_inimigo > 0) {

        // Turno do jogador
        printf("\n --> Turno do Jogador:\n");

        int opcao;

        printf("\nEscolha o que seu personagem deve fazer:\n");
        printf("1. Ataque fraco\n");
        printf("2. Ataque forte\n");
        printf("3. Ataque especial\n");
        printf("4. Curar\n");
        printf("5. Defesa\n");
        printf("6. Ataque crítico\n");

        scanf("%d", &opcao);

        int dano_causado = 0;
        int cura_recebida = 0;

        switch (opcao) {
            case 1:
                dano_causado = ataque_fraco();
                break;
            case 2:
                dano_causado = ataque_forte();
                break;
            case 3:
                dano_causado = ataque_especial();
                break;
            case 4:
                cura_recebida = curar();
                vida_jogador += cura_recebida;
                if (vida_jogador > 100) vida_jogador = 100; // Limita a vida do jogador a 100
                printf("\nCura recebida: %d\n", cura_recebida);
                printf("Vida do jogador: %d\n", vida_jogador);
                break;
            case 5:
                defesa_jogador = defesa();
                printf("\nDefesa aumentada: %d\n", defesa_jogador);
                break;
            case 6:
                dano_causado = ataque_critico();
                break;
            default:
                printf("\nMovimento inválido! Tente novamente.\n");
                limpa_buffer();
                continue;
        }

        vida_inimigo -= dano_causado;

        printf("\nDano causado ao inimigo: %d\n", dano_causado);
        printf("Vida do inimigo: %d\n", vida_inimigo);

        // Turno do inimigo
        if (vida_inimigo > 0) {
            printf("\n --> Turno do Inimigo:\n");

            int acao_inimigo = rand() % 5 + 1; // Aleatoriamente escolhe entre ataque fraco, ataque forte, ataque especial, curar e defesa

            if (acao_inimigo == 1)
                dano_causado = ataque_fraco();
            else if (acao_inimigo == 2)
                dano_causado = ataque_forte();
            else if (acao_inimigo == 3)
                dano_causado = ataque_especial();
            else if (acao_inimigo == 4) {
                cura_recebida = curar();
                vida_inimigo += cura_recebida;
                if (vida_inimigo > 100) vida_inimigo = 100; // Limita a vida do inimigo a 100
                printf("\nInimigo se curou: %d\n", cura_recebida);
                printf("Vida do inimigo: %d\n", vida_inimigo);
                dano_causado = 0;
            } else if (acao_inimigo == 5) {
                defesa_inimigo = defesa();
                printf("\nDefesa do inimigo aumentada: %d\n", defesa_inimigo);
                dano_causado = 0;
            }

            dano_causado -= defesa_jogador;
            if (dano_causado < 0) dano_causado = 0;
            vida_jogador -= dano_causado;
            defesa_jogador = 0; // Reseta a defesa após o ataque
            printf("\nDano causado ao jogador: %d\n", dano_causado);
            printf("Vida do jogador: %d\n", vida_jogador);
        }

        if (vida_jogador > 0 && vida_inimigo > 0) {
            printf("\nPressione qualquer tecla para o próximo turno...");
            limpa_buffer(); // Limpa o buffer antes de esperar por uma tecla
            getchar(); // Espera por uma tecla
            system("cls");
        }
    }

    if (vida_jogador <= 0)
        printf("O jogador foi derrotado!\n");
    else
        printf("O inimigo foi derrotado! Parabéns!\n");

    return 0;
}
