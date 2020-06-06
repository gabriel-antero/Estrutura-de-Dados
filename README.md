<h1 align="center">
  Estrutura de Dados
</h1> 

## :scroll:  Sumário
[Algoritimos de ordenação](algoritmos-de-ordenação)
  - [Insertion Sort](Insertion-Sort)
  - [Selection Sort](Selection-Sort)
  - [Bubble Sort](Bubble-Sort)
  - [Merge Sort](merge-Sort)
  
[Busca Binária]()

  ## Algoritmos de ordenação
   - ### Insertion Sort
        Também chamado de ordenação por inserção é um algoritmo que percorre o array da esquerda para direita, começando pelo       segundo elemento, à medida que avança
      vai ordenando os elementos à esquerda, analisando posição por posição. Tem como vantagem a fácil implementação e um dos       mais rápidos algoritmos de ordenação
      para pequenas entradas. 
      
      - Video como exemplo: [Insertion Sort](https://www.youtube.com/watch?v=ROalU379l3U).
      </br>
      
      |                     |Melhor Caso | Caso Médio | Pior Caso | Estável |
      |---------------------|------------|------------|-----------|---------|
      |Complexidade de Tempo|     O(n)   |    O(n²)  |   O(n²)    |   Sim   |
      
```
void insertionSort(int *array, int N){ 
    int aux;
    for(int i = 1; i < N; ++i){
       aux = array[i];
       for(int j = i; (j > 0) && (aux < array[j-1]); --j)
          array[j] = array[j-1];
       array[j] = aux;
     }
}
```

  - ### Selection Sort
      Também chamado de ordenação por seleção, ele irá selecionar o valor mais a esquerda e comparar com todos os valores a sua direita, 
      caso algum valor a direita do selecionado seja menor, eles irão trocar de posição. Tem como vantagem a fácil implementação 
      e desvantagem de baixa eficência para valores muito grandes.
      
      - Video como exemplo: [Selection Sort](https://www.youtube.com/watch?v=Ns4TPTC8whw).
      </br>

      |                     |Melhor Caso | Caso Médio | Pior Caso |  Estável  |
      |---------------------|------------|------------|-----------|-----------|
      |Complexidade de Tempo|     O(n²)   |    O(n²)  |   O(n²)   |   Sim     |


```
void selectionSort(int *array, int N){ 
    int min, aux;
    for(int i = 0; i < N - 1; ++i){
       min = i;
       for(int j = i + 1; j < N; ++j){
          if(array[j] < array[min])
            min = j;
       }
       if(i != min){
          aux = array[i];
          array[i] = array[min];
          array[min] = aux;
      }
   }
}
```
  - ### Bubble Sort
    Também chamado de ordenação por bolha, compara pares de valores adjacentes e troca de lugar caso a ordem esteja errada, o    processo de troca ocorrerá quantas vezes forem necessarios para que todos os valores estejam ordenados. Tem como vantagem    a facil implementação e desvantagem a baixa eficiência para valores de entradas grandes.
   
      - Video como exemplo: [Bubble Sort](https://www.youtube.com/watch?v=lyZQPjUT5B4).
      </br>

      |                     |Melhor Caso | Caso Médio | Pior Caso |  Estável |
      |---------------------|------------|------------|-----------|----------|
      |Complexidade de Tempo|     O(n)   |    O(n²)   |   O(n²)   |   Sim    |
      
      
```
void bubbleSort(int *array, int N){ 
    int aux, stay ,final = N;
    do {
      stay = 0;
      for(int i = 0; i < final - 1; ++i){
         if(array[i] > array[i + 1]) {
           aux = array[i];
           array[i] = array[i + 1];
           array[i + 1] = aux;
           stay = 1;
         }
      }
      final--;
    } while (stay != 0);
}
```
  - ### Merge Sort
     Também chamado de ordenação por intercalação, ele usa da estrategia de "dividir para conquistar". Este algoritmo divide o problema em pedações menores até cada pedaço ter apenas um elemento, resolve cada pedaço e depois junta (merge) os resultados. Tem como vantagem ser mais rapido do que os algoritmos insertion sort, selection sort e bubble sort e desvantagem que ele possui gasto maior no espaço de memória do que os outros algoritmos.

      - Video como exemplo: [Merge Sort](https://www.youtube.com/watch?v=XaqR3G_NVoo).
      </br>

      |                     |Melhor Caso | Caso Médio | Pior Caso |  Estável |
      |---------------------|------------|------------|-----------|----------|
      |Complexidade de Tempo| O(nlog(n)) | O(nlog(n)) |O(nlog(n)) |    Sim   |
      
 ```  
    void mergeSort(int *vetor, int posicaoInicio, int posicaoFim) {
    int i, j, k, metadeTamanho, *vetorTemp;
    if(posicaoInicio == posicaoFim) return;
    metadeTamanho = (posicaoInicio + posicaoFim ) / 2;

    mergeSort(vetor, posicaoInicio, metadeTamanho);
    mergeSort(vetor, metadeTamanho + 1, posicaoFim);

    i = posicaoInicio;
    j = metadeTamanho + 1;
    k = 0;
    vetorTemp = (int *) malloc(sizeof(int) * (posicaoFim - posicaoInicio + 1));

    while(i < metadeTamanho + 1 || j  < posicaoFim + 1) {
        if (i == metadeTamanho + 1 ) { 
            vetorTemp[k] = vetor[j];
            j++;
            k++;
        }
        else {
            if (j == posicaoFim + 1) {
                vetorTemp[k] = vetor[i];
                i++;
                k++;
            }
            else {
                if (vetor[i] < vetor[j]) {
                    vetorTemp[k] = vetor[i];
                    i++;
                    k++;
                }
                else {
                    vetorTemp[k] = vetor[j];
                    j++;
                    k++;
                }
            }
        }

    }
    for(i = posicaoInicio; i <= posicaoFim; i++) {
        vetor[i] = vetorTemp[i - posicaoInicio];
    }
    free(vetorTemp);
}
```
  ## Busca em vetor ordenado 
  - ### Busca Sequencial
    Irá procurar o elemento posição por posição, caso o valor procurado seja menor do que a posição atual, o  algoritmo encerra a busca na hora, pois temos a certeza que ele não estará no restante do array. 

  
      |                     |Melhor Caso | Caso Médio | Pior Caso |  Estável |
      |---------------------|------------|------------|-----------|----------|
      |Complexidade de Tempo|       O(1) |   O(n/2)   |  O(n) |    Sim   |
  
  
``` 
  int buscaSequencia(int *array, int N, int elem){
    for(int i = 0; i < N; ++i){
      if(elem == array[i)
        return i;
      else if(elem < array[i])
        return -1;
    }
    return -1;
  }
```

  - ### Busca Binária
    A busca binária se trata de um eficiente algoritmo para buscar um item em um array. Ele é baseado na idéia de "divisão e conquista" ou seja ele irá dividir o array ao meio quantas vezes por necessario até buscar o elemento procurado.
    
    
      |                     |Melhor Caso | Caso Médio | Pior Caso |  Estável |
      |---------------------|------------|------------|-----------|----------|
      |Complexidade de Tempo|       O(1) | O(log n)   |  O(log n) |    Sim   |

``` 
  int buscaBinaria(int *array, int N, int elem){
    int inicio, meio, final;
    inicio  = 0;
    final = N - 1;
    while(inicio <= final) {
      meio = (inicio + final)/2;
      if(elem < array[meio])
        final = meio - 1;
      else if (elem > array[meio])
        inicio = meio + 1;
      else
        return meio;
    }
    return -1;
  }
```
