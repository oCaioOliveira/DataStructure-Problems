#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    unsigned long endereco;
    unsigned long proximo;
    unsigned long anterior;
}No;

#define key(A)(A.endereco)
#define less(A,B) (key(A) < key(B))
#define lesseq(A,B) (key(A) <= key(B))
#define exch(A,B) { No t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

void imprime(No *v,int tam)
{
    for(int i = 0;i < tam;i++)
    {
        printf("v[%d] = %lX\n",i,v[i].endereco);
    }
}

int busca_binaria(No *v,unsigned long pvalor,int tam)
{
    int left = 0;
    int right = tam;
    int encontrado = 0;
    int meio = 1;

    while(left<=right && encontrado == 0){
        meio = (left+right)/2;
        if(v[meio].endereco == pvalor)
        {
            encontrado = 1;
        }
        else if((pvalor < v[meio].endereco))
        {
            right = meio - 1;
        }
        else{
            left = meio + 1;
        }
    }

    if(encontrado == 1)
    {
        return meio;
    }
    else{
        return -1;
    }
}

void merge(No *V, int l, int m, int r)
{
    No *R=malloc(sizeof(No)*(r-l+1));
    int i=l,j=m+1,k=0;

    while(i<=m && j<=r)
    {
        if(lesseq(V[i],V[j]))
            R[k++]=V[i++];
        else
            R[k++]=V[j++];
        }

    while(i<=m)
        R[k++]=V[i++];
    while(j<=r)
        R[k++]=V[j++];


    k=0;
    for(i=l;i<=r;i++)
    V[i]=R[k++];
    free(R);
}

void mergesort(No *V,int l, int r)
{
    if (l>= r) return;
    int meio=(l+r)/2;
    mergesort(V,l,meio);
    mergesort(V,meio+1,r);
    merge(V,l,meio,r);
}


No acha_mais_a_esquerda2(No *v,int qntd,No no)
{
    No aux = no;
    int busca;

    busca = busca_binaria(v,no.anterior,qntd-1);
    if(busca == -1)
    {
        return no;
    }
    else{
        no = v[busca];
        acha_mais_a_esquerda2(v,qntd,no);
    }
    printf("%lx %lx %lx\n",no.endereco,no.anterior,no.proximo);

}

void imprime_saida(No *v,No no_esquerda, int qntd)
{
    No aux = no_esquerda;
    int busca = 0;

    while(busca != -1)
    {
        printf("%lx %lx %lx\n",aux.endereco,aux.anterior,aux.proximo);

        busca = busca_binaria(v,aux.proximo,qntd-1);
        aux = v[busca];
    }
}

void imprime_removidos(No *v,No ptr1, No ptr2,int qntd)
{
    No aux = ptr1;
    int busca = 0;

    while(aux.endereco != ptr2.proximo)
    {
        printf("%lx\n",aux.endereco);

        busca = busca_binaria(v,aux.proximo,qntd-1);
        aux = v[busca];
    }
}

int acha_anterior_ptr1(No ptr,No *v,int tam)
{
    int ind = busca_binaria(v,ptr.anterior,tam-1);
    return ind;
}

int acha_proximo_ptr2(No ptr,No *v, int tam)
{
    int ind = busca_binaria(v,ptr.proximo,tam-1);
    return ind;
}

int main(void)
{
    No v[250000];
    No ptr1 ,ptr2;
    int i = 0;
    int qntd_elem_lista = 0;

    while(scanf("%lx %lx %lx",&v[i].endereco,&v[i].anterior,&v[i].proximo) == 3)
    {

        i++;
    }

    ptr1 = v[0];
    ptr2 = v[1];

    qntd_elem_lista = i;

    mergesort(v,0,qntd_elem_lista-1);

    // impressão pra verificar se ordenou direitinho

    //imprime(v,qntd_elem_lista);

    int anterior = acha_anterior_ptr1(ptr1,v,qntd_elem_lista);
    int proximo = acha_proximo_ptr2(ptr2,v,qntd_elem_lista);

    // remocao em si
    v[anterior].proximo = ptr2.proximo;
    v[proximo].anterior = ptr1.anterior;

    No no_esquerda = acha_mais_a_esquerda2(v,qntd_elem_lista,ptr1);
    //No no_direita = acha_mais_a_direita(v,qntd_elem_lista,ptr2);



    // printa a lista com os elementos removidos
    imprime_saida(v,v[proximo],qntd_elem_lista);

    printf("\n");

    // sai de ptr1 e vai até ptr2 printando
    imprime_removidos(v,ptr1,ptr2,qntd_elem_lista);

    return 0;
}
