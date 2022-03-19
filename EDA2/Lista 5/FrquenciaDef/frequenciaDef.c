#include <stdio.h>
#include <stdlib.h>

#define key(A) (A)
#define lessq(A,B) (key(A) <= key(B))

typedef struct CharFreq {
    int code;
    int freq;
}CharFreq;

void merge(struct CharFreq *charFreq, int e, int m, int d) {
    struct CharFreq *aux = malloc(96 * sizeof(CharFreq));
    int i = e, j = m + 1, k = 0;

    while(i <= m && j <= d) {
        if(lessq(charFreq[i].freq, charFreq[j].freq)) {
            aux[k].code = charFreq[i].code;
            aux[k++].freq = charFreq[i++].freq;
        } else {
            aux[k].code = charFreq[j].code;
            aux[k++].freq = charFreq[j++].freq;
        }
    }

    while(i <= m) {
        aux[k].code = charFreq[i].code;
        aux[k++].freq = charFreq[i++].freq;
    }

    while(j <= d) {
        aux[k].code = charFreq[j].code;
        aux[k++].freq = charFreq[j++].freq;
    }

    k = 0;

    for(i = e; i <= d; i ++) {
        charFreq[i].code = aux[k].code;
        charFreq[i].freq = aux[k++].freq;
    }
}

void mergeSort(struct CharFreq *charFreq, int e, int d) {
    if(e >= d) return;

    mergeSort(charFreq, e, (e+d)/2);
    mergeSort(charFreq, ((e+d)/2) + 1, d);
    merge(charFreq, e, (e+d)/2, d);
}

int main()
{
    char line[1002];
    int first = 1;
    int code;

    while (fgets(line, 1002, stdin)) {
        struct CharFreq *charFreq = malloc(96 * sizeof(CharFreq));
        char *ptr;
        int i;

        for (i = 0; i < 96; ++i) {
            charFreq[i].code = i + 32;
            charFreq[i].freq = 0;
        }

        for (ptr = line; *ptr != '\n'; ++ptr)
            ++charFreq[*ptr - 32].freq;

        mergeSort(charFreq, 0, 95);

        if (!first)
            putchar('\n');

        for (i = 0; i < 96; ++i) {

            if (charFreq[i].freq > 0)
                printf("%d %d\n", charFreq[i].code, charFreq[i].freq);
        }

        first = 0;
    }

    return 0;
}
