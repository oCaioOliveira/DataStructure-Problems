#include <stdlib.h>
#include <stdio.h>

/* LISTA DE ADJACENCIAS*/

int iNT_MAX = 2147483647;

/* "celula" representa cada node de uma lista encadeada*/
typedef struct celula
{
    int vertice;
    int peso;
    struct celula *prox;
} celula;

typedef struct graph
{
    int quantidadeVertices, quantidadeArestas;
    celula **listaDeAdjacencias;

} graph;

typedef struct aresta
{
    int vertice1;
    int vertice2;
    int peso;

} aresta;

aresta inicializaAresta(int v1,int v2, int pesoDaAresta)
{
    aresta a;

    a.vertice1 = v1;
    a.vertice2 = v2;
	a.peso = pesoDaAresta;


    return a;
}

celula *criaNoCabeca(int vertice)
{
    celula *novaCelula = malloc(sizeof(celula));
    novaCelula->vertice = vertice;
    novaCelula->prox = NULL;

    return novaCelula;
}

void criaAdjacencia(int valorDoVertice, celula *noCabeca, int peso)
{
    celula *novaCelula = malloc(sizeof(celula));
    novaCelula->vertice = valorDoVertice;
    novaCelula->peso = peso;
    novaCelula->prox = noCabeca->prox;
    noCabeca->prox = novaCelula;
}

graph *graphInit(int qtdVertices)
{
    int i;
    graph *g = malloc(sizeof(graph));
    g->quantidadeVertices = qtdVertices;
    g->quantidadeArestas = 0;
    g->listaDeAdjacencias = malloc(qtdVertices*sizeof(celula));

    for(i = 0; i< qtdVertices; i++)
        g->listaDeAdjacencias[i] = criaNoCabeca(i);

    return g;
}

void insereAresta(graph *g,aresta a)
{
    int peso = a.peso;
    int v1 = a.vertice1;
    int v2 = a.vertice2;
    criaAdjacencia(v2, g->listaDeAdjacencias[v1], peso);
    criaAdjacencia(v1, g->listaDeAdjacencias[v2], peso);

}

int devolveQuantidadeArestas_E_formaVetorDeArestas(aresta a[],graph *g)
{
    int indiceVertices;
    celula *indiceCelulas;
    int quantidadeArestas = 0;
    for(indiceVertices = 0; indiceVertices<g->quantidadeVertices; indiceVertices++)
        for(indiceCelulas = g->listaDeAdjacencias[indiceVertices] ; indiceCelulas!=NULL ; indiceCelulas = indiceCelulas->prox)
            if(indiceVertices < indiceCelulas -> vertice) a[quantidadeArestas++] = inicializaAresta(indiceVertices,indiceCelulas->vertice,indiceCelulas->peso);

    return quantidadeArestas;
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

void DFS_buscaEmProfundidade_RECURSIVA(graph *g, aresta a)
{
    celula *indiceVertices;
    int v2 = a.vertice2;
    verticesJaVisitados[v2] = 1;

    for(indiceVertices = g->listaDeAdjacencias[v2]->prox; indiceVertices!=NULL; indiceVertices = indiceVertices->prox)
    {
        int v1 = indiceVertices->vertice;
        if(verticesJaVisitados[v1] == 0)
        {
            aresta novaAresta;
            novaAresta.vertice1 = v2;
            novaAresta.vertice2 = v1;
            DFS_buscaEmProfundidade_RECURSIVA(g, novaAresta);
        }
    }
}

int devolveQuantidadeDeComponentesConexos(graph *g)
{
    int indiceDeVertices;
    int qtdConexos = 0;
    verticesJaVisitados = iniciaVetor_verticesJaVisitados(g->quantidadeVertices);
    for(indiceDeVertices = 0; indiceDeVertices < g->quantidadeVertices; indiceDeVertices++)
    {
        if(verticesJaVisitados[indiceDeVertices] == 0)
        {
            aresta novaAresta;
            novaAresta.vertice1 = indiceDeVertices;
            novaAresta.vertice2 = indiceDeVertices;

            DFS_buscaEmProfundidade_RECURSIVA(g,novaAresta);
            qtdConexos++;

        }
    }

    return qtdConexos;
}


/* implementacao de fila circular utilizando listas encadeadas*/
typedef struct fila
{
    aresta aAresta;
    struct fila *prox;

} fila;

fila *criaFila()
{
    fila *novaFila = malloc(sizeof(fila));

    novaFila->prox = novaFila;
    novaFila->aAresta.vertice1 = -1;
    novaFila->aAresta.vertice2 = -1;

    return novaFila;
}

void enfileira(fila **f, aresta a)
{
    fila *novaCelula = malloc(sizeof(fila));
    novaCelula->prox = (*f)->prox;
    (*f)->prox = novaCelula;
    (*f)->aAresta.vertice1 = a.vertice1;
    (*f)->aAresta.vertice2 = a.vertice2;

    *f = novaCelula;
    (*f)->aAresta.vertice1 = -1;
    (*f)->aAresta.vertice2 = -1;
}

void desenfileira(fila **f)
{
    fila *novaCelula = malloc(sizeof(fila));
    novaCelula = (*f)->prox;
    if(novaCelula->aAresta.vertice1 == -1) /* FILA VAZIA!*/
    {
        return;
    }

    (*f)->prox = novaCelula->prox;
    free(novaCelula);

}

void BFS_buscaEmLargura(graph *g, aresta a)
{
    fila *f = criaFila();

    int v2 = a.vertice2;
    verticesJaVisitados[v2] = 1;

    enfileira(&f,a);

    while(f->prox->aAresta.vertice1!=-1 && f->prox->aAresta.vertice2 != -1) /* FILA VAZIA!*/
    {
        celula *indiceVertices;
        a.vertice1 = f->prox->aAresta.vertice1;
        a.vertice2 = f->prox->aAresta.vertice2;
        desenfileira(&f);
        v2 = a.vertice2;

        for(indiceVertices = g->listaDeAdjacencias[v2]->prox; indiceVertices!=NULL; indiceVertices = indiceVertices->prox)
        {
            int v1 = indiceVertices->vertice;
            if(verticesJaVisitados[v1] == 0)
            {
                aresta novaAresta;
                novaAresta.vertice1 = v2;
                novaAresta.vertice2 = v1;

                enfileira(&f,novaAresta);
                verticesJaVisitados[v1] = 1;

            }
        }
    }
}

/* GRAFOS DIRIGIDOS (DIGRAPHS)*/

void insereAresta_DIRECAO_UNICA(graph *g,aresta a)
{
    int peso = a.peso;
    int v1 = a.vertice1;
    int v2 = a.vertice2;

    criaAdjacencia(v2, g->listaDeAdjacencias[v1], peso);

}

graph *inverteArestas_DIGRAPH(graph* g)
{
    celula *indexArestas;
    int indexVertices;
    graph *novoGrafo = graphInit(g->quantidadeVertices);
    for(indexVertices = 0; indexVertices < g->quantidadeVertices ; indexVertices++)
        for(indexArestas = g->listaDeAdjacencias[indexVertices]->prox; indexArestas!=NULL; indexArestas = indexArestas->prox)
        {
            aresta novaAresta;
            novaAresta.vertice1 = indexArestas->vertice;
            novaAresta.vertice2 = indexVertices;

            insereAresta_DIRECAO_UNICA(novoGrafo,novaAresta);
        }

    return novoGrafo;
}

typedef struct filaDeVertices
{
    int vertice;
    struct filaDeVertices *prox;

} filaDeVertices;

filaDeVertices *criaFilaDeVertices()
{
    filaDeVertices *novaFila = malloc(sizeof(filaDeVertices));

    novaFila->prox = novaFila;
	novaFila->vertice = -1;

    return novaFila;
}

void enfileiraFilaDeVertices(filaDeVertices **f, int vertice)
{
    filaDeVertices *novaCelula = malloc(sizeof(filaDeVertices));
    novaCelula->prox = (*f)->prox;
    (*f)->prox = novaCelula;
    (*f)->vertice = vertice;

    *f = novaCelula;
    (*f)->vertice = -1;
}

int desenfileiraFilaDeVertices(filaDeVertices **f)
{
    filaDeVertices *novaCelula = malloc(sizeof(filaDeVertices));
    novaCelula = (*f)->prox;
    if(novaCelula->vertice == -1) /* FILA VAZIA!*/
    {
        return -1;
    }

	int x = novaCelula->vertice;

    (*f)->prox = novaCelula->prox;
    free(novaCelula);

	return x;
}

int Bellfor_Roxo(graph *g,int vertice, int *pa, int *distanciaEntreVertices)
{
    int i;
	int naFila[g->quantidadeVertices];
	for(i = 0;i<g->quantidadeVertices;i++)
	{
		pa[i] = -1;
		distanciaEntreVertices[i] = iNT_MAX;
		naFila[i] = 0;
	}
	pa[vertice] = vertice;
	distanciaEntreVertices[vertice] = 0;
	filaDeVertices *fila = criaFilaDeVertices();
	enfileiraFilaDeVertices(&fila,vertice);
	naFila[vertice] = 1;
	enfileiraFilaDeVertices(&fila,g->quantidadeVertices);
	int k = 0;
	while(1)
	{
	    int t;
	    celula *a;
		int v = desenfileiraFilaDeVertices(&fila);
		if(v < g->quantidadeVertices)
		{
			for(a = g->listaDeAdjacencias[v]->prox; a!=NULL; a = a->prox)
			{
				if(distanciaEntreVertices[v] + a->peso < distanciaEntreVertices[a->vertice])
				{
					distanciaEntreVertices[a->vertice] = distanciaEntreVertices[v] + a->peso;
					pa[a->vertice] = v;
					if(naFila[a->vertice] == 0)
					{
						enfileiraFilaDeVertices(&fila,a->vertice);
						naFila[a->vertice] = 1;
					}
				}
			}
		}
		else
		{
			if(fila->prox->vertice==-1) return 1;
			if(++k >= g->quantidadeVertices) return 0;
			enfileiraFilaDeVertices(&fila,v);
			for(t = 0;t<g->quantidadeVertices;t++)
				naFila[t] = 0;
		}
	}

}

void GRAPHcptD1(graph *graph, int s) {
  int mature[1000]; /*MAX_VERTICES*/
  int v;
  int *distances = malloc(graph->quantidadeVertices * sizeof(int));
  int *parent = malloc(graph->quantidadeVertices * sizeof(int));

  for(v = 0; v < graph->quantidadeVertices; v++) {
    parent[v] = -1;
    distances[v] = iNT_MAX;
    mature[v] = 0;
  }

  parent[s] = s;
  distances[s] = 0;
  int z, i;
  celula *t;

  while(1) {
    int min = iNT_MAX, y;

    for(z = 0; z < graph->quantidadeVertices; z++) {
      if(mature[z]) continue;
      if(distances[z] < min) {
        min = distances[z];
        y = z;
      }
    }
    if(min == iNT_MAX) break;

    for(t = graph->listaDeAdjacencias[y]; t != NULL; t = t->prox) {
      if(mature[t->vertice] == 1) continue;
      if(distances[y] + t->peso < distances[t->vertice]) {
        distances[t->vertice] = distances[y] + t->peso;
        parent[t->vertice] = y;
      }
    }
    mature[y] = 1;
  }
  printf("%d\n", distances[graph->quantidadeVertices-1]);
}

int main() {
    int qtdVertices, qtdArestas, i, j;
    scanf("%d%d", &qtdVertices, &qtdArestas);

    qtdVertices += 2;

    graph *g = graphInit(qtdVertices);

    int v1, v2, peso;
    for(i = 0; i < qtdArestas; i ++) {
        scanf("%d%d%d", &v1, &v2, &peso);
        aresta a = inicializaAresta(v1, v2, peso);
        insereAresta(g, a);
    }

    /*celula *t;

    printf("\n");

    for(i = 0; i < qtdVertices; i ++) {
        for(t = g->listaDeAdjacencias[i]; t != NULL; t = t->prox) {
            printf("vertice:%d\n", t->vertice);
            printf("peso:%d\n", t->peso);
        }
        printf("\n");
    }*/


    GRAPHcptD1(g, 0);

    return 0;
}
