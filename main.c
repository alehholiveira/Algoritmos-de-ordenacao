#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct Num
{
    long value;
    float value2;
} num;

void imprime_vetor(int tam1, num *vet1)
{
    for (int i = 0; i < tam1; i++)
    {
        printf("Chave: %ld ", vet1[i].value);
        printf("Valor = %.2f\n", vet1[i].value2);
    }
}

num *preenche_vetor1(int tamseed1, int tam1)
{
    num *vet1 = (num *)malloc(sizeof(num) * tam1);

    srand(tamseed1);
    for (int i = 0; i < tam1; i++)
    {
        vet1[i].value = rand();
        vet1[i].value2 = 100 + rand();
    }
    return vet1;
}

num *preenche_vetor2(int tamseed2, int tam2)
{
    num *vet2 = (num *)malloc(sizeof(num) * tam2);

    srand(tamseed2);
    vet2[0].value = rand();
    vet2[0].value2 = 100 + rand();
    for (int i = 1; i < tam2; i++) // Corrigido para começar a partir de 1
    {
        vet2[i].value = (rand() % 10) + vet2[i - 1].value;
        vet2[i].value2 = 100 + rand();
    }
    return vet2;
}

void InsertionSort(num vetor[], int tamanho)
{
    int i, j;
    num chave;

    for (i = 1; i < tamanho; i++)
    {
        chave = vetor[i];
        j = i - 1;

        while (j >= 0 && vetor[j].value < chave.value)
        {
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }

        vetor[j + 1] = chave;
    }
}

void bubbleSort(num *vetor, int tamanho)
{
    int i, j;
    int trocas; // Variável para rastrear se houve trocas

    for (i = 0; i < tamanho - 1; i++)
    {
        trocas = 0; // Inicializa o número de trocas para cada passagem
        for (j = 0; j < tamanho - i - 1; j++)
        {
            if (vetor[j].value < vetor[j + 1].value)
            {
                num temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
                trocas = 1; // Indica que houve pelo menos uma troca nesta passagem
            }
        }
        if (trocas == 0)
            break; // Se não houve trocas, o vetor já está ordenado
    }
}


void shellSort(num *vetor, int tamanho)
{
    for (int intervalo = tamanho / 2; intervalo > 0; intervalo /= 2)
    {
        for (int i = intervalo; i < tamanho; i++)
        {
            num temp = vetor[i];
            int j;
            for (j = i; j >= intervalo && vetor[j - intervalo].value < temp.value; j -= intervalo)
            {
                vetor[j] = vetor[j - intervalo];
            }
            vetor[j] = temp;
        }
    }
}

void mergeSort(num *vetor, int inicio, int fim)
{
    if (inicio < fim)
    {
        int meio = (inicio + fim) / 2;
        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio + 1, fim);
        merge(vetor, inicio, meio, fim);
    }
}

void merge(num *vetor, int inicio, int meio, int fim)
{
    int i, j, k;
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;
    num *L = (num *)malloc(sizeof(num) * n1);
    num *R = (num *)malloc(sizeof(num) * n2);

    for (i = 0; i < n1; i++)
        L[i] = vetor[inicio + i];
    for (j = 0; j < n2; j++)
        R[j] = vetor[meio + 1 + j];

    i = 0;
    j = 0;
    k = inicio;
    while (i < n1 && j < n2)
    {
        if (L[i].value >= R[j].value)
        {
            vetor[k] = L[i];
            i++;
        }
        else
        {
            vetor[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        vetor[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        vetor[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}



int particiona(num *vetor, int inicio, int fim)
{
    num pivo = vetor[fim];
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++)
    {
        if (vetor[j].value >= pivo.value)
        {
            i++;
            num temp = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = temp;
        }
    }
    num temp = vetor[i + 1];
    vetor[i + 1] = vetor[fim];
    vetor[fim] = temp;

    return i + 1;
}

void quickSort(num vetor[], int inicio, int fim)
{
    int pilha[fim - inicio + 1];
    int topo = -1;

    pilha[++topo] = inicio;
    pilha[++topo] = fim;

    while (topo >= 0)
    {
        fim = pilha[topo--];
        inicio = pilha[topo--];

        int pivo_index = particiona(vetor, inicio, fim);

        if (pivo_index - 1 > inicio)
        {
            pilha[++topo] = inicio;
            pilha[++topo] = pivo_index - 1;
        }

        if (pivo_index + 1 < fim)
        {
            pilha[++topo] = pivo_index + 1;
            pilha[++topo] = fim;
        }
    }
}

num *determinatipo(int tipo, int tamseed, int tamvet, int tam[])
{
    num *vet;

    switch (tipo)
    {
    case 1:
        vet = preenche_vetor1(tamseed, tam[tamvet - 1]);
        break;
    case 2:
        vet = preenche_vetor2(tamseed, tam[tamvet - 1]);
        break;
    default:
        printf("\n Tipo invalido!");
        vet = NULL; // Tratar caso inválido retornando NULL
        break;
    }

    return vet;
}

int main()
{
    clock_t start, end, start_master, end_master;
    int tam[5] = {10000, 50000, 100000, 500000, 1000000};
    int tamseed[20] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100};
    int tamvet, tipo = 0;
    /// rodar o mesmo tamanho e mesmo tipo variando a seed de 0 a 9 e depois mudar para tipo 2 e rodar de 10 a 19
    /// depois mudar o tamanho e variar as seeds novamente
    int a = 0;
    start_master = clock();
    num *vet;

    printf("Qual sera o tamanho do vetor desejado?\n[1]10000\n[2]50000\n[3]100000\n[4]500000\n[5]1000000\n -> ");
    scanf("%d", &tamvet);


    printf("\nDeseja que o seu vetor seja preenchido com o tipo 1 ou tipo 2?\n");
    printf("[TIPO 1]: Vetores com valor nao ordenado \n[TIPO 2]: Vetores com valores ordenados de forma crescente\n -> ");
    scanf("%d", &tipo);
    vet = determinatipo(tipo, tamseed[a], tamvet, tam);
    printf("\n\n\tORDENANDO VETORES, AGUARDE...\n\n");
    start = clock();
    InsertionSort(vet, tam[tamvet - 1]);
    end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTempo Insertion: %.9f", time_taken);

    free(vet);

    vet = determinatipo(tipo, tamseed[a], tamvet, tam);

    start = clock();
    bubbleSort(vet, tam[tamvet - 1]);
    end = clock();
    double time_taken2 = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTempo Bubble: %.9f", time_taken2);

    free(vet);
    vet = determinatipo(tipo, tamseed[a], tamvet, tam);

    start = clock();
    shellSort(vet, tam[tamvet - 1]);
    end = clock();
    double time_taken3 = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTempo Shell: %.9f", time_taken3);

    free(vet);
    vet = determinatipo(tipo, tamseed[a], tamvet, tam);

    start = clock();
    mergeSort(vet, 0, tam[tamvet - 1] - 1);
    end = clock();
    double time_taken4 = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTempo Merge: %.9f", time_taken4);

    free(vet);
    vet = determinatipo(tipo, tamseed[a], tamvet, tam);

    start = clock();
    quickSort(vet, 0, tam[tamvet - 1]);
    end = clock();
    double time_taken5 = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTempo Quick: %.9f", time_taken5);
    free(vet);

    return 0;
}
