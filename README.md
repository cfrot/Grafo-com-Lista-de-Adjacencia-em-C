# Implementação de Grafo com Lista de Adjacência em C

## Introdução

Este projeto apresenta uma implementação de grafos utilizando lista de adjacência na linguagem C.

O objetivo principal é demonstrar uma das formas mais utilizadas para representar grafos computacionalmente, utilizando estruturas encadeadas e ponteiros.

A lista de adjacência é uma abordagem muito eficiente para grafos esparsos, consumindo menos memória quando comparada à matriz de adjacência.

---

# O que é um grafo?

Um grafo é uma estrutura matemática utilizada para representar conexões entre elementos.

Ele é composto por:

- **Vértices (nós)** → representam os elementos
- **Arestas** → representam as conexões entre os vértices

---

## Exemplo de grafo

```txt
0 ---- 1
|    /
|   /
2
```

Nesse exemplo:
- `0`, `1` e `2` são vértices
- As linhas representam as conexões entre eles

---

# Objetivo do projeto

O projeto tem como objetivo:

✅ Criar grafos dinamicamente  
✅ Adicionar conexões entre vértices  
✅ Representar grafos utilizando listas encadeadas  
✅ Exibir a estrutura do grafo  
✅ Praticar manipulação de ponteiros e memória em C  

---

# O que é lista de adjacência?

A lista de adjacência é uma estrutura onde cada vértice possui uma lista contendo seus vizinhos conectados.

Diferente da matriz de adjacência, ela armazena apenas as conexões existentes.

---

# Exemplo visual

## Grafo

```txt
0 ---- 1
|
|
2
```

---

## Representação em lista de adjacência

```txt
[0] -> 1 -> 2 -> NULL
[1] -> 0 -> NULL
[2] -> 0 -> NULL
```

Cada linha representa:
- Um vértice
- Os vértices conectados a ele

---

# Estrutura do projeto

O projeto foi dividido em estruturas e funções responsáveis pela manipulação do grafo.

---

# Estrutura do nó

```c
typedef struct No {
    int vertice;
    struct No* prox;
} No;
```

---

## Explicação

| Campo | Função |
|---|---|
| `vertice` | Armazena o vértice conectado |
| `prox` | Ponteiro para o próximo nó |

---

# Estrutura do grafo

```c
typedef struct {
    int numVertices;
    No* listaAdj[MAX];
} Grafo;
```

---

## Explicação

| Campo | Função |
|---|---|
| `numVertices` | Quantidade de vértices |
| `listaAdj` | Vetor contendo listas encadeadas |

---

# Funções implementadas

---

# Criar nó

```c
No* criarNo(int v)
```

Responsável por:

- Criar um novo nó dinamicamente
- Armazenar o vértice
- Inicializar o ponteiro como `NULL`

---

## Funcionamento

```c
No* novo = (No*) malloc(sizeof(No));
```

Aloca memória dinamicamente para o nó.

---

# Criar grafo

```c
Grafo* criarGrafo(int vertices)
```

Responsável por:

- Criar o grafo dinamicamente
- Inicializar todas as listas como vazias

---

## Inicialização

```c
for (int i = 0; i < vertices; i++) {
    g->listaAdj[i] = NULL;
}
```

Inicialmente nenhum vértice possui conexões.

---

# Adicionar aresta

```c
void adicionarAresta(Grafo* g, int v1, int v2)
```

Responsável por conectar dois vértices.

---

## Funcionamento

O algoritmo:

1. Cria um novo nó
2. Insere o vértice na lista do vértice origem

---

## Inserção

```c
novo->prox = g->listaAdj[v1];
g->listaAdj[v1] = novo;
```

O novo nó é inserido no início da lista.

---

# Grafo direcionado

Na implementação atual:

```txt
v1 → v2
```

A conexão ocorre apenas em uma direção.

---

# Grafo não direcionado

O código possui um trecho comentado que permite transformar o grafo em não direcionado.

```c
novo = criarNo(v1);
novo->prox = g->listaAdj[v2];
g->listaAdj[v2] = novo;
```

Nesse caso:

```txt
v1 ↔ v2
```

---

# Imprimir grafo

```c
void imprimirGrafo(Grafo* g)
```

Responsável por exibir todas as listas de adjacência.

---

# Exemplo de execução

## Entrada

```txt
Digite o numero de vertices: 4
Digite o numero de arestas: 4

Aresta 1:
0 1

Aresta 2:
0 2

Aresta 3:
1 3

Aresta 4:
2 3
```

---

## Saída

```txt
--- Lista de Adjacencia ---

[0]: 2 -> 1 -> NULL
[1]: 3 -> NULL
[2]: 3 -> NULL
[3]: NULL
```

---

# Fluxo do programa

O programa executa as seguintes etapas:

1. Lê a quantidade de vértices
2. Cria o grafo dinamicamente
3. Lê as arestas informadas pelo usuário
4. Adiciona as conexões nas listas
5. Exibe a lista de adjacência

---

# Conceitos utilizados

Durante o desenvolvimento deste projeto foram utilizados conceitos importantes como:

- Grafos
- Lista de adjacência
- Listas encadeadas
- Ponteiros
- Alocação dinâmica de memória
- Estruturas (`struct`)
- Manipulação de memória
- Modularização em C
- Funções
- Laços de repetição

---

# Validação de vértices

O projeto verifica se os vértices informados são válidos.

```c
if (v1 >= g->numVertices || v2 >= g->numVertices)
```

Isso evita acessos inválidos à memória.

---

# Complexidade

## Inserção de arestas

```txt
O(1)
```

A inserção ocorre diretamente no início da lista.

---

## Impressão do grafo

```txt
O(V + E)
```

Onde:

- `V` = quantidade de vértices
- `E` = quantidade de arestas

---

# ✅ Vantagens da lista de adjacência

- Menor consumo de memória
- Ideal para grafos esparsos
- Estrutura mais eficiente em muitos cenários

---

# ❌ Desvantagens

- Verificar conexão entre vértices pode ser mais lento
- Implementação mais complexa que matriz de adjacência

---

# Aplicações reais

Grafos utilizando listas de adjacência são utilizados em:

- 🌐 Redes sociais
- 📡 Redes de computadores
- 🛰️ Sistemas de navegação
- 🎮 Inteligência artificial em jogos
- 🗺️ Sistemas de mapas
- 🚦 Sistemas de trânsito
- 🔗 Sistemas de recomendação

---

# Tecnologias utilizadas

- Linguagem C
- Estruturas de Dados
- Algoritmos

---

# Como executar o projeto

## Compilar o projeto

```bash
gcc main.c -o grafo
```

---

## Executar

### Linux/macOS

```bash
./grafo
```

### Windows

```bash
grafo.exe
```

---

# Estrutura do projeto

```txt
projeto/
│
├── main.c
├── funcoes2.h
```

---

# Objetivo acadêmico

Este projeto foi desenvolvido com fins acadêmicos para estudo de grafos, listas de adjacência, listas encadeadas e manipulação de memória na linguagem C.

---

# 👨‍💻 Autor

Desenvolvido por Daniel Pacheco.
