#include "acaoPersonagem.h"
#include <stdio.h>
#include <stdlib.h>

// Implementação da função para ataque fraco
int ataque_fraco() {
    printf("Ataque fraco!\n");
    return rand() % 10 + 1; // Retorna um número aleatório entre 1 e 10
}

// Implementação da função para ataque forte
int ataque_forte() {
    printf("Ataque forte!\n");
    return rand() % 50 + 1; // Retorna um número aleatório entre 1 e 50
}

// Implementação da função para ataque especial
int ataque_especial() {
    printf("Ataque especial!\n");
    return rand() % 100 + 1; // Retorna um número aleatório entre 1 e 100
}

// Implementação da função para curar
int curar() {
    printf("Curando...\n");
    return rand() % 20 + 10; // Retorna um número aleatório entre 10 e 30
}

// Implementação da função para defesa
int defesa() {
    printf("Defendendo...\n");
    return rand() % 20 + 5; // Retorna um número aleatório entre 5 e 25 que será subtraído do próximo dano recebido
}

// Implementação da função para ataque crítico
int ataque_critico() {
    printf("Ataque crítico!\n");
    int chance = rand() % 100;
    if (chance < 20) { // 20% de chance de sucesso
        return rand() % 200 + 50; // Retorna um número aleatório entre 50 e 250
    } else {
        printf("Ataque crítico falhou!\n");
        return 0;
    }
}
