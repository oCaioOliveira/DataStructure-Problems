#include <stdio.h>
#include <stdlib.h>

int *posicaoComponenteHash;
int countComponente = 0;
int tamanhoMaiorComponente = 0;

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

typedef struct dadosComponente
{
    int posicaoInicialComponente;
    int tamanhoComponente;

} dadosComponente;

void DFS_buscaEmProfundidade_RECURSIVA(graph *g, int v1, int v2, int qtdConexos)
{
    verticesJaVisitados[v2] = 1;
    posicaoComponenteHash[v2] = qtdConexos;

    for(v1 = 0; v1 < g->quantidadeVertices; v1++)
        if(g->matrizAdjacencia[v2][v1] != 0) {
            if(verticesJaVisitados[v1] == 0)
            {
              countComponente ++;
              DFS_buscaEmProfundidade_RECURSIVA(g, v2, v1, qtdConexos);
            }
          }
  
}

int devolveQuantidadeDeComponentesConexos(graph *g, dadosComponente *dadosComponente)
{
	int qtdConexos = 0;
	for(int indiceDeVertices = 0; indiceDeVertices < g->quantidadeVertices; indiceDeVertices++)
	{
		if(verticesJaVisitados[indiceDeVertices] == 0)
		{
    dadosComponente[qtdConexos].posicaoInicialComponente = indiceDeVertices; 
    countComponente = 1;      DFS_buscaEmProfundidade_RECURSIVA(g,indiceDeVertices, indiceDeVertices, qtdConexos);
          if(countComponente > tamanhoMaiorComponente)
            tamanhoMaiorComponente = countComponente; 
          dadosComponente[qtdConexos].tamanhoComponente = countComponente;
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

void verificaPosicao(dadosComponente *dadosComponente, int posicao, int qtdComponentesConexos) {
  for(int i = 0; i < qtdComponentesConexos; i ++) {
    if(dadosComponente[i].tamanhoComponente == tamanhoMaiorComponente) {
      printf("Vamos para %d\n", dadosComponente[i].posicaoInicialComponente);
      return;
    }
  }
}

void ifeelses(dadosComponente *dadosComponente, int posicao, int qtdComponentesConexos) {
  if(dadosComponente[posicaoComponenteHash[posicao]].tamanhoComponente == tamanhoMaiorComponente)
    if(tamanhoMaiorComponente != 1)
      printf("Bora pra estrada\n");
    else 
      printf("Fique em casa\n");
else {
  verificaPosicao(dadosComponente, posicao, qtdComponentesConexos);
}
}

int main() {
  int qtdVertices, posicao;
  scanf("%d%d", &qtdVertices, &posicao);

  dadosComponente *dadosComponentes = malloc(qtdVertices * sizeof(dadosComponentes));

  verticesJaVisitados = iniciaVetor_verticesJaVisitados(qtdVertices);
  
  graph *graph = graphInit(qtdVertices);

  int v1, v2;
  while(scanf("%d%d", &v1, &v2) != EOF) {
    insereAresta(graph, v1, v2);
  }
  
  posicaoComponenteHash = iniciaVetor_verticesJaVisitados(qtdVertices);
  
  int qtdComponentesConexos = devolveQuantidadeDeComponentesConexos(graph, dadosComponentes);

  ifeelses(dadosComponentes, posicao, qtdComponentesConexos);
  
  return 0;
}
