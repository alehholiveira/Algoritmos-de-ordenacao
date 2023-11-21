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


void shellSort(num *v, int n) {
    int i, j, h;
    num aux;

    for (h = 1; h < n; h = 3 * h + 1);

    while (h > 0) {
        h = (h - 1) / 3;

        for (i = h; i < n; i++) {
            aux = v[i];
            j = i;

            while (j >= h && v[j - h].value < aux.value) {
                v[j] = v[j - h];
                j -= h;
            }

            v[j] = aux;
        }
    }
}


void Merge(num *vetor_principal, num *vetor_auxiliar, int index_vetor_inicio, int index_metade, int index_vetor_fim)
{

    int z;
    int iv = index_vetor_inicio, ic = index_metade+1;

    for(z = index_vetor_inicio; z<=index_vetor_fim; z++)
    vetor_auxiliar[z] = vetor_principal[z];

    z = index_vetor_inicio;

    while (iv <= index_metade && ic<= index_vetor_fim)
    {
        if(vetor_auxiliar[iv].value >= vetor_auxiliar[ic].value){
            vetor_principal[z++] = vetor_auxiliar[iv++];
        }else{
            vetor_principal[z++] = vetor_auxiliar[ic++];
        }

    }

    while(iv <= index_metade){
        vetor_principal[z++] = vetor_auxiliar[iv++];
    }
    while(ic <= index_vetor_fim){
        vetor_principal[z++] = vetor_auxiliar[ic++];
    }
}

void Sort(num * vetor_principal, num *vetor_auxiliar, int index_vetor_inicio, int index_vetor_fim)
{
    if(index_vetor_inicio < index_vetor_fim)
    {
        int index_metade = (index_vetor_inicio + index_vetor_fim)/2;
        Sort(vetor_principal, vetor_auxiliar,index_vetor_inicio, index_metade);
        Sort(vetor_principal,vetor_auxiliar,index_metade + 1, index_vetor_fim);

        if(vetor_principal[index_metade].value < vetor_principal[index_metade + 1].value)
        {
            Merge(vetor_principal,vetor_auxiliar, index_vetor_inicio, index_metade, index_vetor_fim);
        }
    }

}

void mergeSort(num *vetor_principal, int tamanho_vetor)
{
    num *vetor_auxiliar = malloc(sizeof(num) * tamanho_vetor);
    Sort(vetor_principal,vetor_auxiliar,0,tamanho_vetor-1);
    free(vetor_auxiliar);
}



int particao (num *v, int LI, int LS)
{
    num aux;
    unsigned long int pivo;
    int e = LI, d = LS;
    pivo = v[e].value;

    while(e<d)
    {
        while(v[e].value >= pivo && (e<LS))
        {
            e++;
        }
        while(v[d].value < pivo && (d>LI))
        {
            d--;
        }
        if(e<d)
        {
            aux = v[e];
            v[e] = v[d];
            v[d] = aux;

        }
    }

    aux = v[LI];
    v[LI] = v[d];
    v[d] = aux;

    return d;
}

int particaomeio(num *v, long int LI, long int LS)
{
    num aux;
    unsigned long int pivo;
    long int e = LI, d = LS;
    long int meio;

    meio = (LI + LS) / 2;
    pivo = v[meio].value;

    while (e <= d)
    {
        while (v[e].value > pivo)
        {
            e++;
        }
        while (v[d].value < pivo)
        {
            d--;
        }
        if (e <= d)
        {
            aux = v[e];
            v[e] = v[d];
            v[d] = aux;
            e++;
            d--;
        }
    }

    return e;
}

int particaofim (num *v, long int LI, long int LS)
{
    num aux;
    unsigned long int pivo;
    long int e = LI, d = LS;
    pivo = v[d].value;

    while(e<d)
    {
        while(v[e].value > pivo && (e<LS))
        {
            e++;
        }
        while(v[d].value <= pivo && (d>LI))
        {
            d--;
        }
        if(e<d)
        {
            aux = v[e];
            v[e] = v[d];
            v[d] = aux;

        }
    }

    aux = v[LI];
    v[LI] = v[d];
    v[d] = aux;

    return d;
}

void quicksort(num *v, long int LI, long int LS)
{
    while (LI < LS)
    {
        int p = particao(v, LI, LS);
        if  (p- LI < LS - p)
        {
            quicksort(v, LI, p-1);
            LI = p +1;
        }
        else
        {
            quicksort(v, p+1, LS);
            LS = p-1;
        }
    }
}

void quicksortmeio(num *v, long int LI, long int LS)
{
    if (LI < LS)
    {
        int p = particaomeio(v, LI, LS);
        quicksortmeio(v, LI, p - 1);
        quicksortmeio(v, p, LS);
    }
}


void quicksortfim(num *v, int LI, int LS)
{
    while (LI < LS)
    {
        int p = particaofim(v, LI, LS);
        if  (p- LI < LS - p)
        {
            quicksortfim(v, LI, p-1);
            LI = p +1;
        }
        else
        {
            quicksortfim(v, p+1, LS);
            LS = p-1;
        }
    }
}


void heapify(num *vetor, int tamanho, int indice)
{
    int maior = indice;
    int filho_esquerda = 2 * indice + 1;
    int filho_direita = 2 * indice + 2;

    // Verifica se o filho da esquerda é menor que a raiz
    if (filho_esquerda < tamanho && vetor[filho_esquerda].value < vetor[maior].value)
        maior = filho_esquerda;

    // Verifica se o filho da direita é menor que a raiz
    if (filho_direita < tamanho && vetor[filho_direita].value < vetor[maior].value)
        maior = filho_direita;

    // Se o maior não é a raiz, troca
    if (maior != indice)
    {
        num temp = vetor[indice];
        vetor[indice] = vetor[maior];
        vetor[maior] = temp;

        // Continua a heapify recursivamente no subárvore afetado
        heapify(vetor, tamanho, maior);
    }
}

void heapSort(num *vetor, int tamanho)
{
    // Constrói o heap (rearranja o array)
    for (int i = tamanho / 2 - 1; i >= 0; i--)
        heapify(vetor, tamanho, i);

    // Extrai elementos um por um do heap
    for (int i = tamanho - 1; i > 0; i--)
    {
        // Move a raiz (o maior elemento) para o final
        num temp = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = temp;

        // Chama o heapify na subárvore reduzida
        heapify(vetor, i, 0);
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
    int a = 10;
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
    mergeSort(vet, tam[tamvet - 1]);
    end = clock();
    double time_taken4 = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTempo Merge: %.9f", time_taken4);
    free(vet);

    vet = determinatipo(tipo, tamseed[a], tamvet, tam);
    start = clock();
    heapSort(vet, tam[tamvet - 1]);
    end = clock();
    double time_taken5 = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTempo Heap: %.9f", time_taken5);
    free(vet);


    vet = determinatipo(tipo, tamseed[a], tamvet, tam);
    start = clock();
    quicksort(vet,0, tam[tamvet-1]);
    end = clock();
    double time_taken6 = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTempo QuickLI: %.9f", time_taken6);
    free(vet);

    vet = determinatipo(tipo, tamseed[a], tamvet, tam);
    start = clock();
    quicksortfim(vet,0, tam[tamvet-1]);
    end = clock();
    double time_taken7 = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTempo QuickLS: %.9f", time_taken7);
    free(vet);

    vet = determinatipo(tipo, tamseed[a], tamvet, tam);
    start = clock();
    quicksortmeio(vet,0, tam[tamvet-1]);
    end = clock();
    double time_taken8 = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTempo QuickMeio: %.9f", time_taken8);
    imprime_vetor(tam[tamvet-1],vet);
    free(vet);

    return 0;
}
