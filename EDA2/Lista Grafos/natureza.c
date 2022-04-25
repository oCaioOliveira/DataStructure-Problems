#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

int *posicaoComponenteHash;
int countComponente = 0;
int tamanhoMaiorComponente = 0;

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

int *verticesJaVisitados;

int *iniciaVetor_verticesJaVisitados(int qtdVertices)
{
    int i;
    int *vetor = malloc(qtdVertices*sizeof(int));
    for(i = 0; i<qtdVertices; i++)
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
    int indiceDeVertices;
	int qtdConexos = 0;
	for(indiceDeVertices = 0; indiceDeVertices < g->quantidadeVertices; indiceDeVertices++)
	{
		if(verticesJaVisitados[indiceDeVertices] == 0)
		{
    dadosComponente[qtdConexos].posicaoInicialComponente = indiceDeVertices;
    countComponente = 1;
    DFS_buscaEmProfundidade_RECURSIVA(g,indiceDeVertices, indiceDeVertices, qtdConexos);
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

int main() {
  int qtdVertices, posicao;
  while(1) {
  scanf("%d%d", &qtdVertices, &posicao);
  if(qtdVertices == posicao && posicao == 0)
    break;

  dadosComponente *dadosComponentes = malloc(qtdVertices * sizeof(dadosComponentes));

  verticesJaVisitados = iniciaVetor_verticesJaVisitados(qtdVertices);

  graph *graph = graphInit(qtdVertices);

  int i, j;
  char vertice[qtdVertices][31];
  for(i = 0; i < qtdVertices; i ++) {
    scanf("%s", vertice[i]);
  }
  char aux[posicao * 2][31];
  for(i = 0; i < posicao * 2; i ++) {
    scanf("%s", aux[i]);
  }
  int v1, v2;
  for(i = 0; i < posicao * 2; i ++) {
    for(j = 0; j < qtdVertices; j ++) {
        if(strcmp(aux[i], vertice[j]) == 0)
            if(i % 2 == 0) {
                v1 = j;
                break;
            }
            else {
                v2 = j;
                insereAresta(graph, v1, v2);
                break;
            }
    }
  }

  posicaoComponenteHash = iniciaVetor_verticesJaVisitados(qtdVertices);

  int qtdComponentesConexos = devolveQuantidadeDeComponentesConexos(graph, dadosComponentes);

  printf("%d\n", tamanhoMaiorComponente);
  free(graph);
  free(verticesJaVisitados);
  free(dadosComponentes);
  free(posicaoComponenteHash);
  }

  return 0;
}
