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
6. **Heap Sort** (escolhido pela equipe de desenvolvimento)

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
   
# Conclusão

Ao longo deste projeto, realizamos uma análise comparativa de diversos métodos de ordenação, explorando diferentes características dos algoritmos em termos de eficiência e desempenho. Abordamos o **Insertion Sort**, **Bubble Sort**, **Shell Sort**, **Merge Sort**, **Quick Sort** (com diferentes escolhas de pivô) e **Heap Sort**.

## Insertion Sort
- Demonstrou eficiência em vetores de pequeno a médio porte.
- O desempenho deteriora-se significativamente com tamanhos maiores, evidenciando um comportamento menos eficiente para conjuntos extensos de dados.

## Bubble Sort
- Revelou ser um método menos eficiente em comparação com outros.
- Apresentou tempos elevados, especialmente à medida que o tamanho do vetor aumenta.
- A eficiência foi comprometida, evidenciando limitações práticas.

## Shell Sort
- Mostrou-se eficaz em todos os tamanhos de vetores.
- Apresentou tempos consistentemente rápidos, inclusive para conjuntos extensos.
- A abordagem de intervalos foi crucial para a eficiência do algoritmo.

## Merge Sort
- Destacou-se pela consistência e eficiência em diferentes cenários.
- Apresentou tempos de execução relativamente estáveis, independentemente da distribuição dos dados.
- Demonstrou ser robusto e adequado para grandes volumes de dados.

## Quick Sort
- Apresentou variações significativas com base na escolha do pivô.
- O pivô no meio destacou-se como a escolha mais eficiente na maioria dos casos.
- Revelou-se eficaz, especialmente para conjuntos de dados aleatórios.

## Heap Sort
- Mostrou uma eficiência razoável, embora não tão rápida quanto outros métodos.
- Destacou-se por ser menos sensível à distribuição inicial dos dados, mantendo um desempenho relativamente consistente.

A escolha do algoritmo de ordenação deve levar em conta características específicas do conjunto de dados. Métodos como **Merge Sort** e **Shell Sort** demonstraram eficiência em diferentes contextos. **Quick Sort** com pivô no meio destacou-se como uma escolha sólida em muitos cenários. A análise gráfica revelou padrões de desempenho e comportamento assintótico dos algoritmos. O dimensionamento do problema (tamanho do vetor) impactou significativamente o desempenho, destacando a importância de escolher algoritmos adequados para diferentes casos de uso.

