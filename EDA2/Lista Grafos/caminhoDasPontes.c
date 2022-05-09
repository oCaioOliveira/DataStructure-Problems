#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int destino, origem, vertices = 0;
int custo, *custos = NULL;

void dijkstra(int vertices,int origem,int destino,int *custos)
{
	int i,v, cont = 0;
	int *ant, *tmp;
	int *z;     /* vertices para os quais se conhece o caminho minimo */
	double min;
	double dist[vertices]; /* vetor com os custos dos caminhos */


	/* aloca as linhas da matriz */
	ant = calloc (vertices, sizeof(int *));
	tmp = calloc (vertices, sizeof(int *));
	z = calloc (vertices, sizeof(int *));

	for (i = 0; i < vertices; i++) {
		if (custos[(origem - 1) * vertices + i] != -1) {
			ant[i] = origem - 1;
			dist[i] = custos[(origem-1)*vertices+i];
		}
		else {
			ant[i]= -1;
			dist[i] = HUGE_VAL;
		}
		z[i]=0;
	}
	z[origem-1] = 1;
	dist[origem-1] = 0;

	/* Laco principal */
	do {

		/* Encontrando o vertice que deve entrar em z */
		min = HUGE_VAL;
		for (i=0;i<vertices;i++)
			if (!z[i])
				if (dist[i]>=0 && dist[i]<min) {
					min=dist[i];
					v=i;
				}

		/* Calculando as distancias dos novos vizinhos de z */
		if (min != HUGE_VAL && v != destino - 1) {
			z[v] = 1;
			for (i = 0; i < vertices; i++)
				if (!z[i]) {
					if (custos[v*vertices+i] != -1 && dist[v] + custos[v*vertices+i] < dist[i]) {
					   	dist[i] = dist[v] + custos[v*vertices+i];
						ant[i] =v;
				   	}
        		}
		}
	} while (v != destino - 1 && min != HUGE_VAL);

	/* Mostra o Resultado da busca */
	printf("\tDe %d para %d: \t", origem, destino);
	if (min == HUGE_VAL) {
		printf("Nao Existe\n");
		printf("\tCusto: \t- \n");
	}
	else {
		i = destino;
		i = ant[i-1];
		while (i != -1) {
			tmp[cont] = i+1;
			cont++;
			i = ant[i];
		}

		for (i = cont; i > 0 ; i--) {
			printf("%d -> ", tmp[i-1]);
		}
		printf("%d", destino);

		printf("\n\tCusto:  %d\n",(int) dist[destino-1]);
	}
}

void add(int qtdArestas)
{
	int i;

	custos = (int *) malloc(sizeof(int)*vertices*vertices);
	for (i = 0; i <= vertices * vertices; i++)
		custos[i] = -1;

    for(i = 0; i < qtdArestas; i ++) {
        scanf("%d%d%d", &origem, &destino, &custo);
        origem ++;
        destino ++;
        /*matriz usando matematica*/
        custos[(origem - 1) * vertices + destino - 1] = custo;
    }
}

int main(int argc, char **argv) {
    int qtdArestas;
    scanf("%d%d", &vertices, &qtdArestas);

    vertices += 2;

    add(qtdArestas);

    dijkstra(vertices, 1, vertices, custos);

	return 0;
}
