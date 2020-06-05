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
        Também chamado de ordenação por inserção é um algoritmo que percorre o array da esquerda para direita, começando pelo segundo elemento, à medida que avança
      vai ordenando os elementos à esquerda, analisando posição por posição. Tem como vantagem a fácil implementação e um dos mais rápidos algoritmos de ordenação
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
       for(int j = i + 1; j < N; --j){
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
