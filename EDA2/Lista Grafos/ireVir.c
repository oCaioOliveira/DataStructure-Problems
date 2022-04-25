#include <stdio.h>
#include <stdlib.h>

typedef struct graph
{
    int quantidadeVertices, quantidadeArestas;
    int **matrizAdjacencia;
    int **fechoTransitivo;

} graph;

int **MATRIXInit(int qtdVertices,int valorDeInicializacao)
{
    int i, j;
    int **matrix = malloc(qtdVertices*sizeof(int*));

    for(i = 0; i<qtdVertices; i++)
        matrix[i] = malloc(qtdVertices*sizeof(int));

    for(i = 0; i<qtdVertices; i++)
        for(j = 0; j<qtdVertices; j++)
            matrix[i][j] = valorDeInicializacao;

    return matrix;
}

graph *graphInit(int qtdVertices)
{
    graph *g = malloc(sizeof(graph));
    g->quantidadeVertices = qtdVertices;
    g->quantidadeArestas = 0;
    g->matrizAdjacencia = MATRIXInit(qtdVertices,0);

    return g;
}

void insereAresta(graph *g,int v1, int v2, int d)
{
    if(g->matrizAdjacencia[v1][v2] == 0) g->quantidadeArestas++;

    g->matrizAdjacencia[v1][v2] = 1;

    if(d == 2)
      g->matrizAdjacencia[v2][v1] = 1;
}

void FloydWarshall(graph *g)
{
	int i,s,t;
	g->fechoTransitivo = MATRIXInit(g->quantidadeVertices,0);
	for(s = 0; s<g->quantidadeVertices;s++)
		for(t = 0; t< g->quantidadeVertices;t++)
			g->fechoTransitivo[s][t] = g->matrizAdjacencia[s][t];

	for(s = 0; s<g->quantidadeVertices;s++) g->fechoTransitivo[s][s] = 1;

	for(i = 0; i<g->quantidadeVertices;i++)
		for(s = 0;s<g->quantidadeVertices;s++)
			if(g->fechoTransitivo[s][i] == 1)
				for(t = 0; t< g->quantidadeVertices; t++)
					if(g->fechoTransitivo[i][t] == 1)
						g->fechoTransitivo[s][t] = 1;

}

void devolveAlcancabilidade(graph *g, int v1, int v2)
{
  /*printf("fecho transitivo:%d %d\n", g->fechoTransitivo[v1][v2], g->fechoTransitivo[v2][v1]);*/
	if(g->fechoTransitivo[v1][v2] == g->fechoTransitivo[v2][v1] && g->fechoTransitivo[v1][v2] == 1) {
    printf("Ida e Volta\n");
    return;
  }
  else if(g->fechoTransitivo[v1][v2] != g->fechoTransitivo[v2][v1] && g->fechoTransitivo[v1][v2] == 1) {
    printf("Apenas Ida\n");
    return;
  }
  else if(g->fechoTransitivo[v1][v2] != g->fechoTransitivo[v2][v1] && g->fechoTransitivo[v2][v1] == 1) {
    printf("Apenas Volta\n");
    return;
  }
  else if(g->fechoTransitivo[v1][v2] == g->fechoTransitivo[v2][v1] && g->fechoTransitivo[v2][v1] == 0) {
    printf("Impossibru\n");
    return;
  }
}

int main() {
  int qtdVertices, numConexoes, i, v1, v2, aresta, j, boolean = 1;
  while(1) {
    scanf("%d%d", &qtdVertices, &numConexoes);
    if (qtdVertices == numConexoes && numConexoes == 0)
        break;

    graph *graph = graphInit(qtdVertices);
    for(i = 0; i < numConexoes; i ++) {
        scanf("%d%d%d", &v1, &v2, &aresta);
        insereAresta(graph, v1 - 1, v2 - 1, aresta);
    }

    FloydWarshall(graph);

    for(i = 0; i < qtdVertices; i ++) {
        for(j = 0; j < qtdVertices; j ++) {
            if(graph->fechoTransitivo[i][j] == 0) {
                boolean = 0;
                break;
            }
        }
        if(boolean == 0)
            break;
    }

    printf("%d\n", boolean);
    boolean = 1;

    free(graph);
  }

  return 0;
}
