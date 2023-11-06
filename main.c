#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Num
{
    long value;
    float value2;
} num;

void imprime_vetor(int tam1, num* vet1)
{
    for (int i = 0; i < tam1; i++)
    {
        printf("Chave: %d ", vet1[i].value);
        printf("Valor = %.2f\n", vet1[i].value2);
    }
}

num *preenche_vetor1(int tamseed1, int tam1)
{
    num *vet1 = (num*)malloc(sizeof(num)*tam1);

    srand(tamseed1);
    for(int i = 0; i < tam1; i++){
        vet1[i].value = rand();
        vet1[i].value2 = 100 + rand();
    }
    return vet1;

}

num *preenche_vetor2 (int tamseed2, int tam2)
{
    num *vet2 = (num*)malloc(sizeof(num)*tam2);

    srand (tamseed2);
    vet2[0].value = rand();
    vet2[0].value2 = 100+rand();
     for(int i = 0; i < tam2; i++){
        vet2[i].value = (rand()% 10) + vet2[i-1].value;
        vet2[i].value2 = 100 + rand();
    }
    return vet2;
}




int main()
{
    clock_t start, end, start_master, end_master;
    int tam[5] = {10000, 50000, 100000, 500000, 1000000};
    int tamseed = 34;
    int tamvet;
    start_master = clock();
    num *vet;
    printf("Qual sera o tamanho do vetor desejado?\n[1]10000\n[2]50000\n[3]100000\n[4]500000\n[5]1000000");
    scanf("%d",&tamvet);

    vet = preenche_vetor1(tamseed, tam[tamvet-1]);
    ///imprime_vetor(tam[tamvet-1], vet);

    free(vet);

    return 0;
}
