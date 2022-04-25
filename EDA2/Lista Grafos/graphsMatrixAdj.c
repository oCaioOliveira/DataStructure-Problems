#include <stdlib.h>

/// MATRIZ DE ADJACENCIA
typedef struct graph
{
    int quantidadeVertices, quantidadeArestas;
    int **matrizAdjacencia;

} graph;

int **MATRIXInit(int qtdVertices,int valorDeInicializacao)
{
    int **matrix = malloc(qtdVertices*sizeof(int*));

    for(int i = 0; i<qtdVertices; i++)
        matrix[i] = malloc(qtdVertices*sizeof(int));

    for(int i = 0; i<qtdVertices; i++)
        for(int j = 0; j<qtdVertices; j++)
            matrix[i][j] = valorDeInicializacao;

    return matrix;
}

graph *graphInit(int qtdVertices) // inicializacao de grafos representados MATRICIALMENTE
{
    graph *g = malloc(sizeof(graph));
    g->quantidadeVertices = qtdVertices;
    g->quantidadeArestas = 0;
    g->matrizAdjacencia = MATRIXInit(qtdVertices,0);

    return g;
}

/// VETOR DE ARESTAS

typedef struct aresta
{
    int vertice1;
    int vertice2;

} aresta;

aresta inicializaAresta(int v1,int v2)
{
	aresta a;

	a.vertice1 = v1;
	a.vertice2 = v2;

	return a;
}

void insereAresta(graph *g,aresta a)
{
    int v1 = a.vertice1;
    int v2 = a.vertice2;

    if(g->matrizAdjacencia[v1][v2] == 0) g->quantidadeArestas++;

    g->matrizAdjacencia[v1][v2] = 1;
    g->matrizAdjacencia[v2][v1] = 1;

}

void removeAresta(graph *g, aresta a)
{
    int v1 = a.vertice1;
    int v2 = a.vertice2;

    if(g->matrizAdjacencia[v1][v2] == 1) g->quantidadeArestas--;

    g->matrizAdjacencia[v1][v2] = 0;
    g->matrizAdjacencia[v2][v1] = 0;

}

int devolveQuantidadeArestas_E_formaVetorDeArestas(aresta a[],graph *g)
{
    int v1,v2, quantidadeArestas = 0;
    for(v1 = 0; v1 < g->quantidadeVertices; v1++)
		for(v2 = v1+1; v2<g->quantidadeVertices;v2++)
			if(g->matrizAdjacencia[v1][v2] == 1)
				a[quantidadeArestas++] = inicializaAresta(v1,v2);

	return quantidadeArestas;
}
