#include <stdlib.h>
#include <stdio.h>

/// LISTA DE ADJACENCIAS

// "celula" representa cada nó de uma lista encadeada
typedef struct celula
{
    int vertice;
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

} aresta;

aresta inicializaAresta(int v1,int v2)
{
	aresta a;

	a.vertice1 = v1;
	a.vertice2 = v2;

	return a;
}

celula *criaLE()
{
    celula *novaCelula = malloc(sizeof(celula));
    novaCelula->vertice = -1;
    novaCelula->prox = NULL;

    return novaCelula;
}

void criaAdjacencia(int valorDoVertice, celula *c)
{
    celula *novaCelula = malloc(sizeof(celula));
    novaCelula->vertice = valorDoVertice;
    novaCelula->prox = c->prox;
    c->prox = novaCelula;
}

graph *graphInit(int qtdVertices)
{
    graph *g = malloc(sizeof(graph));
    g->quantidadeVertices = qtdVertices;
    g->quantidadeArestas = 0;
    g->listaDeAdjacencias = malloc(qtdVertices*sizeof(celula));

    for(int i = 0; i< qtdVertices; i++)
        g->listaDeAdjacencias[i] = criaLE();

    return g;
}

void insereAresta(graph *g,aresta a)
{
    int v1 = a.vertice1;
    int v2 = a.vertice2;
    criaAdjacencia(v2, g->listaDeAdjacencias[v1]);
    criaAdjacencia(v1, g->listaDeAdjacencias[v2]);

}


/// funcao remove aresta mal escrita. Reescrever quando tiver tempo para ficar mais legivel.
/// OBS: FUNCAO AINDA NAO TESTADA!
void removeAresta(graph *g,aresta a)
{
	int v1 = a.vertice1;
    int v2 = a.vertice2;

	celula *c1 = g->listaDeAdjacencias[v1];
	celula *c2 = g->listaDeAdjacencias[v2];

	while(c1->prox->vertice!= v2 && c1!= NULL)
		c1 = c1->prox;

	if(c1 == NULL) return; ///nao existe conexao

	while(c2->prox->vertice!= v1 )
		c2 = c2->prox;

	celula *novo1 = c1->prox;
	celula *novo2 = c2->prox;

	c1->prox = novo1->prox;
	c2->prox = novo2->prox;

	free(novo1);
	free(novo2);


}

int devolveQuantidadeArestas_E_formaVetorDeArestas(aresta a[],graph *g)
{
    int quantidadeArestas = 0;
    for(int indiceVertices = 0; indiceVertices<g->quantidadeVertices; indiceVertices++)
		for(celula *indiceCelulas = g->listaDeAdjacencias[indiceVertices] ; indiceCelulas!=NULL ; indiceCelulas = indiceCelulas->prox)
			if(indiceVertices < indiceCelulas -> vertice) a[quantidadeArestas++] = inicializaAresta(indiceVertices,indiceCelulas->vertice);

	return quantidadeArestas;
}

/// CODIGO PARA TESTES

/*

void printaGrafo(graph *g)
{
	for(int i = 0;i<g->quantidadeVertices;i++)
	{

		printf("VERTICE %d: noCabeca -> ",i);
		for(celula *ptr = g->listaDeAdjacencias[i]->prox; ptr != NULL ; ptr = ptr->prox)
			printf("%d -> ",ptr->vertice);
		printf("NULL \n");
	}

}



int main()
{
	int quantidadeDeVertices = 0, quantidadeDeArestas = 0;
	printf("Insira a quantidade de vertices: ");
	scanf("%d",&quantidadeDeVertices);

	graph *grafo = graphInit(quantidadeDeVertices);
	printf("INSIRA AS ARESTAS:\n");
	int v1=0,v2=0;
	while(scanf("%d %d",&v1,&v2) != EOF)
	{
		aresta a = inicializaAresta(v1,v2);
		insereAresta(grafo,a);

	}
	aresta *vetAresta = malloc(quantidadeDeVertices*sizeof(aresta));
	quantidadeDeArestas = devolveQuantidadeArestas_E_formaVetorDeArestas(vetAresta,grafo);

	printaGrafo(grafo);
	printf("\n\nQUANTIDADE DE ARESTAS: %d\n",quantidadeDeArestas);


	free(grafo);
	free(vetAresta);
	return 0;
}*/
