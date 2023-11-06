# Projeto: Análise Empírica de Algoritmos de Ordenação

## Descrição

Este projeto tem como objetivo a compreensão e análise de métodos de ordenação, como discutido na disciplina de Estrutura de Dados. O projeto consiste na simulação e análise de alguns métodos de ordenação utilizando diferentes tipos de estruturas e tamanhos de vetores.

## Métodos Implementados

Os seguintes métodos de ordenação serão implementados e analisados:

1. **Insertion Sort**
2. **Bubble Sort**
3. **Shell Sort**
4. **Merge Sort**
5. **Quick Sort**
6. **Método adicional escolhido e apresentado pelo Time**

## Estrutura dos Dados

Os vetores serão ordenados em ordem **DECRESCENTE** e serão utilizadas estruturas com dois campos:

- Um valor inteiro (chave de ordenação)
- Um valor real (com valor superior a 100)

## Tamanhos dos Vetores

Serão considerados cinco tamanhos diferentes de vetores para cada método:

1. 10^4
2. 5x10^4
3. 10^5
4. 5x10^5
5. 10^6

Para cada tamanho de vetor, serão gerados no mínimo 10 casos diferentes.

## Geração de Valores

Os valores para preenchimento do vetor serão gerados de duas formas:

1. **Aleatoriamente** - tanto a chave quanto o número real.
2. **Chave em ORDEM CRESCENTE e número real ALEATORIAMENTE**.

## Observações Específicas para Alguns Métodos

1. **Shell Sort**: O cálculo de 'h' seguirá a regra h(i) = 1 para i = 1, e h(i) = 3h(i-1) + 1 para i > 1.

2. **Quick Sort**: Será feita uma análise extra para avaliar a escolha do pivô, considerando as seguintes opções:
   - Valor da posição do Limite Inferior do sub-vetor
   - Valor da posição do Limite Superior do sub-vetor
   - Valor da posição do Limite Meio do sub-vetor

## Observações Gerais

Para garantir a validade da análise, todos os métodos serão testados com o mesmo conjunto de dados e na mesma máquina.

---

**IMPORTANTE:** Certifique-se de documentar e relatar os resultados de forma clara e organizada. Considerando a natureza do projeto, a análise empírica dos algoritmos é fundamental para obter conclusões significativas sobre o desempenho de cada método de ordenação.
