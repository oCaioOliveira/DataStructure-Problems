#include <stdio.h>
#include <stdlib.h>

/// MATRIZ DE ADJACENCIA
typedef struct graph
{
    int quantidadeVertices, quantidadeArestas;
    int **matrizAdjacencia;
    int **fechoTransitivo;

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

int *verticesJaVisitados;

int *iniciaVetor_verticesJaVisitados(int qtdVertices)
{
    int *vetor = malloc(qtdVertices*sizeof(int));
    for(int i = 0; i<qtdVertices; i++)
        vetor[i] = 0;
    return vetor;
}

void DFS_buscaEmProfundidade_RECURSIVA(graph *g, int v1, int v2)
{
    verticesJaVisitados[v2] = 1;

    for(v1 = 0; v1 < g->quantidadeVertices ; v1++)
        if(g->matrizAdjacencia[v2][v1] != 0)
            if(verticesJaVisitados[v1] == 0)
            {
                DFS_buscaEmProfundidade_RECURSIVA(g, v2, v1);
            }
}

int devolveQuantidadeDeComponentesConexos(graph *g)
{
	int qtdConexos = 0;
	for(int indiceDeVertices = 0; indiceDeVertices < g->quantidadeVertices; indiceDeVertices++)
	{
		if(verticesJaVisitados[indiceDeVertices] == 0)
		{

			DFS_buscaEmProfundidade_RECURSIVA(g,indiceDeVertices, indiceDeVertices);
			qtdConexos++;

		}
	}

	return qtdConexos;
}

void insereAresta(graph *g,int v1, int v2)
{
    if(g->matrizAdjacencia[v1][v2] == 0) g->quantidadeArestas++;

    g->matrizAdjacencia[v1][v2] = 1;
    g->matrizAdjacencia[v2][v1] = 1;

}

int main() {
  int qtdVertices;
  scanf("%d", &qtdVertices);

  verticesJaVisitados = iniciaVetor_verticesJaVisitados(qtdVertices);
  
  graph *graph = graphInit(qtdVertices);

  int vertice1, vertice2;
  while(scanf("%d%d", &vertice1, &vertice2) != EOF) {
    insereAresta(graph, vertice1, vertice2);
  }

  printf("%d\n", devolveQuantidadeDeComponentesConexos(graph));
  
  return 0;
}
