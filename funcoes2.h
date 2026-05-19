#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct No {
    int vertice;
    struct No* prox;
} No;

typedef struct {
    int numVertices;
    No* listaAdj[MAX];
} Grafo;

// CORREÇÃO: Retornar o ponteiro 'g' e não '0'
No* criarNo(int v) {
    No* novo = (No*) malloc(sizeof(No));
    novo->vertice = v;
    novo->prox = NULL;
    return novo;
}

Grafo* criarGrafo(int vertices) {
    Grafo* g = (Grafo*) malloc(sizeof(Grafo));
    if (g == NULL) {
        printf("Erro de Memoria \n");
        exit(1);
    }
    g->numVertices = vertices;
    for (int i = 0; i < vertices; i++) {
        g->listaAdj[i] = NULL;
    }
    return g; // Corrigido
}

void adicionarAresta(Grafo* g, int v1, int v2) {
    if (v1 >= g->numVertices || v2 >= g->numVertices) {
        printf("Vertice %d ou %d invalido\n", v1, v2);
        return;
    }
    // Adicionando de v1 para v2
    No* novo = criarNo(v2);
    novo->prox = g->listaAdj[v1];
    g->listaAdj[v1] = novo;

    // Se o grafo for não-direcionado, descomente as linhas abaixo:
    /*
    novo = criarNo(v1);
    novo->prox = g->listaAdj[v2];
    g->listaAdj[v2] = novo;
    */
}

void imprimirGrafo(Grafo* g) {
    printf("\n--- Lista de Adjacencia ---\n");
    for (int i = 0; i < g->numVertices; i++) {
        No* temp = g->listaAdj[i]; // Corrigido operador '='
        printf("[%d]: ", i);
        while (temp != NULL) {
            printf("%d -> ", temp->vertice); // Corrigido printf
            temp = temp->prox; // IMPORTANTE: Avançar para o próximo nó
        }
        printf("NULL\n");
    }
}
