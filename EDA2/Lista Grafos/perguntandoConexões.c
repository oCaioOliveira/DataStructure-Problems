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

void insereAresta(graph *g,int v1, int v2, int d)
{
    /*printf("v1 e v2: %d %d", v1, v2);*/
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
  int qtdVertices;
  scanf("%d", &qtdVertices);

  verticesJaVisitados = iniciaVetor_verticesJaVisitados(qtdVertices);
  
  graph *graph = graphInit(qtdVertices);

  int v, w, d;
  
  while(1) {
    scanf("%d%d%d", &v, &w, &d);
    if(v == 0 && w == 0 && d == 0) break;
    insereAresta(graph, v, w, d);
  }
  
  /*int i, j;
  for(i = 0; i < qtdVertices; i ++){
    for(j = 0; j < qtdVertices; j ++) {
      printf("%d ", graph->matrizAdjacencia[i][j]);
    }
  printf("\n");
  }*/
  
  FloydWarshall(graph);

  /*
  printf("\n\n");

  for(i = 0; i < qtdVertices; i ++){
    for(j = 0; j < qtdVertices; j ++) {
      printf("%d ", graph->fechoTransitivo[i][j]);
    }
  printf("\n");
  }*/

  int t, x;
  while(scanf("%d%d", &t, &x) != EOF) {
    devolveAlcancabilidade(graph, t, x);
  }
  
  return 0;
}
