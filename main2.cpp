#include "func/funcoes2.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int v, a, v1, v2;

    printf("Digite o numero de vertices: ");
    scanf("%d", &v);
    
    Grafo* g = criarGrafo(v);

    printf("Digite o numero de arestas: ");
    scanf("%d", &a);

    for(int i = 0; i < a; i++) {
        printf("Aresta %d (origem destino): ", i + 1);
        scanf("%d %d", &v1, &v2);
        adicionarAresta(g, v1, v2);
    }

    imprimirGrafo(g);

    return 0;
}
