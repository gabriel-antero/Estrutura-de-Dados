<h1 align="center">
  Estrutura de Dados
</h1> 

## :scroll:  Sumário
[Algoritimos de ordenação](algoritmos-de-ordenação)
  - [Insertion Sort](insertion-sort)
  - [Selection Sort](selection-sort)
  - [Bubble Sort](bubble-sort)
  - [Merge Sort](merge-sort)
  - [Quicksort](quicksort)
  - [Shellsort](shellsort)
  
  ## Algoritmos de ordenação
   - ### Insertion Sort
        Também chamado de ordenação por inserção é um algoritmo que percorre o array da esquerda para direita, começando pelo       segundo elemento, à medida que avança
      vai ordenando os elementos à esquerda, analisando posição por posição. Tem como vantagem a fácil implementação e um dos       mais rápidos algoritmos de ordenação
      para pequenas entradas. 
      
      - Video como exemplo: [Insertion Sort](https://www.youtube.com/watch?v=ROalU379l3U).
      </br>
      
      |                     |Melhor Caso | Caso Médio | Pior Caso |
      |---------------------|------------|------------|-----------|
      |Complexidade de Tempo|     O(n)   |    O(n²)  |   O(n²)  |
      
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

      |                     |Melhor Caso | Caso Médio | Pior Caso |
      |---------------------|------------|------------|-----------|
      |Complexidade de Tempo|     O(n²)   |    O(n²)  |   O(n²)   |


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

      |                     |Melhor Caso | Caso Médio | Pior Caso |
      |---------------------|------------|------------|-----------|
      |Complexidade de Tempo|     O(n)   |    O(n²)   |   O(n²)   |
      
      
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
     Também chamado de ordenação por intercalação, ele usa da estrategia de "dividir para conquistar". Este algoritmo divide o problema em pedações menores até cada pedaço ter apenas um elemento, resolve cada pedaço e depois junta (merge) os resultados.

      - Video como exemplo: [Merge Sort](https://www.youtube.com/watch?v=XaqR3G_NVoo).
      </br>

      |                     |Melhor Caso | Caso Médio | Pior Caso |
      |---------------------|------------|------------|-----------|
      |Complexidade de Tempo| O(nlog(n)) | O(nlog(n)) |O(nlog(n)) |
      
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
