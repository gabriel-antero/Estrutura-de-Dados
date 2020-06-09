<h1 align="center">
  <img width="200" 
  alt="Estrutura de dados" 
  src="https://github.com/gabriel-antero/Estrutura-de-Dados/blob/master/assets/cubo.svg"
  style="max-width:10%;" >
</h1>

<h2 align="center">
  Estrutura de Dados
</h2> 

<p align="center">
  <img alt="GitHub top language" src="https://img.shields.io/github/languages/top/gabriel-antero/Estrutura-de-Dados">
  <img alt="GitHub repo size" src="https://img.shields.io/github/repo-size/gabriel-antero/Estrutura-de-Dados">
  <img alt="GitHub language count" src="https://img.shields.io/github/languages/count/gabriel-antero/Estrutura-de-Dados">
  <img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/gabriel-antero/Estrutura-de-Dados">
</p>

<h4 align="center">
  Repositório com pequenos resumos sobre assuntos abordados na matéria de estrutura de dados  
</h4>

## :scroll:  Sumário
**[Algoritmos de ordenação](#algoritmos-de-ordenação)**
  - [Insertion Sort](#insertion-sort)
  - [Selection Sort](#selection-sort)
  - [Bubble Sort](#bubble-sort)
  - [Merge Sort](#merge-sort)
  
**[Busca em vetor ordenado](#busca-em-vetor-ordenado)**
  - [Busca Sequencial](#busca-sequencial)
  - [Busca Binária](#busca-binária) 
  
**[Listas Encadeadas](#listas-encadeadas)**

**[Stack (Pilha)](#pilha)**

**[Queue (Fila)](#fila)**
  
**[Árvores (Em breve)]()**

**[Grafos (Em breve)]()**

  ## Algoritmos de ordenação
   - ### Insertion Sort
        Também chamado de ordenação por inserção é um algoritmo que percorre o array da esquerda para direita, começando pelo       segundo elemento, à medida que avança
      vai ordenando os elementos à esquerda, analisando posição por posição. Tem como vantagem a fácil implementação e um dos       mais rápidos algoritmos de ordenação
      para pequenas entradas. 
      
      <h1 align="center">
       <img width="500" 
          alt="Insertion Sort" 
          src="https://github.com/gabriel-antero/Estrutura-de-Dados/blob/master/assets/insertionsort.gif"
          style="max-width:10%;" />
       </h1>
      
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
      
      <h1 align="center">
       <img width="500" 
          alt="Selection Sort" 
          src="https://github.com/gabriel-antero/Estrutura-de-Dados/blob/master/assets/Selection-Sort.gif"
          style="max-width:10%;" />
       </h1>
      
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
   
       <h1 align="center">
        <img width="500" 
          alt="Bubble Sort"
          src="https://github.com/gabriel-antero/Estrutura-de-Dados/blob/master/assets/Bubble-sort.gif"
          style="max-width:10%;" />
       </h1>
   
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
    
      <h1 align="center">
        <img width="500" 
          alt="Merge Sort" 
          src="https://github.com/gabriel-antero/Estrutura-de-Dados/blob/master/assets/merge-sort.gif"
          style="max-width:10%;" />
       </h1>

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
    
      <h1 align="center">
        <img width="500" 
          alt="Binary Search" 
          src="https://github.com/gabriel-antero/Estrutura-de-Dados/blob/master/assets/binary-search.gif"
          style="max-width:10%;" />
       </h1>    
    
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

## Listas Encadeadas
  Ao contrário de arrays que possuem os elementos um do lado do outro fisicamente na memória, as listas encadeadas possuem seus elementos espalhados, porém cada elemento estará dentro de uma célula que aponta para a próxima da lista de forma que fiquem "ligadas" ou "encadeadas" entre si, por isso o nome.
  
  - Lista encadeada também chamada de lista ligada.
  - O endereço de uma lista é o endereço da primeira célula.
  - A cabeça da lista é o primeira célula.
  - O rabo da lista é a ultima célula.
  - O ultima célula da lista simplesmente e duplamente encadeada apontam para NULL.
  
 **Lista simplesmente encadeada:** 
    É quando a lista aponta apenas para o proximo elemento, ou seja, ela percorrerá por apenas um sentido.
    
   <h1 align="center">
        <img width="500" 
          alt="Lista Simplesmente Encadeada" 
          src="https://github.com/gabriel-antero/Estrutura-de-Dados/blob/master/assets/lista-simplesmente-encadeada.png"
          style="max-width:10%;" />
    </h1>   
    
  **Lista duplamente encadeada:** 
    É quando a célula aponta para a célula anterior e para próxima, ou seja, ela percorrerá por dois sentidos.
  
  <h1 align="center">
        <img width="500" 
          alt="Lista Duplamente Encadeada" 
          src="https://github.com/gabriel-antero/Estrutura-de-Dados/blob/master/assets/lista-duplamente-encadeada.png"
          style="max-width:10%;" />
    </h1>  
  
  **Lista Circular:** 
    É quando a ultima célula tem como o seu proximo a primeira célula da lista.

  <h1 align="center">
        <img width="500" 
          alt="Lista Circular"
          src="https://github.com/gabriel-antero/Estrutura-de-Dados/blob/master/assets/lista-circular.png"
          style="max-width:10%;" />
    </h1>  

  **Implementações na lista**
  - tamanho() - Retorna o número de elementos de dados na lista, mesma coisa da função size()
  - vazio() - retorna verdade se tiver vazia, equivalente a função empty().
  - inserir_inicio(valor) - adiciona um item no início da lista, equivalente a push_front(value).
  - inserir_final(valor) - adiciona um item no final da lista, equivalente a push_back(value).
  - remover_final() - remove um item do final da lista, equivalente a pop_back().
  - mostrar() - irá imprimir todos os elementos da lista.
  - existe(valor) - irá retornar verdadeiro caso o valor exista na lista.
  
  Codigo com todas essas implementações, para uma lista simplesmente encadeada: [Lista Simplesmente Encadeada](https://github.com/gabriel-antero/Estrutura-de-Dados/blob/master/codes/lista-simplesmente-encadeada.cpp)
  
  ## Pilha
É uma estrutura de dados conhecida como LIFO (Last In First Out), ou seja, o ultimo elemento adicionado é o primeiro a sair ou então FILO(First In Last Out) o primeiro elemento adicionado é o ultimo a sair. Pode ser feita uma analogia com uma pilha (montanha) de livros, quando estamos bucando um livro que está na parte de baixo da pilha, vamos sempre removendo os livros que estão em cima até chegar aos livros que estão no embaixo.

 <h1 align="center">
        <img width="500" 
          alt="Pilha" 
          src="https://github.com/gabriel-antero/Estrutura-de-Dados/blob/master/assets/pilha.png"
          style="max-width:10%;" />
    </h1> 

**Implementações para pilha**
- empilha(valor) - Irá adicionar um elemento na ultima posição.
- desempilhar(valor) - Irá remover o outro elemento.
- getTopo() - Irá pegar o valor do ultimo elemento.
- vazia() - Irá verificar se a pilha está vazia, 0 para falso e 1 para verdadeiro.

Codigo com implementações: [Pilha](https://github.com/gabriel-antero/Estrutura-de-Dados/blob/master/codes/pilha.cpp)
 
 ## Fila
  É uma estrutura de dados como FIFO (First In First Out), ou seja, o primeiro elemento a entrar é o ultimo elemento a sair, ele é justamente o contrário da Pilha. Pode ser feita uma analogia com uma fila qualquer, por exemplo, em uma fila de supermercado o primeiro cliente a chegar será o primeiro cliente a sair ( a ser atendido) e o ultimo a chegar será o ultimo a ser atendido.
  
  <h1 align="center">
        <img width="500" 
          alt="Fila" 
          src="https://github.com/gabriel-antero/Estrutura-de-Dados/blob/master/assets/fila.png"
          style="max-width:10%;" />
    </h1> 
    
---

Por [Gabriel Antero](https://github.com/gabriel-antero).

Ícones feitos por <a href="https://www.flaticon.com/br/autores/freepik" title="Freepik">Freepik</a> from  <a href="https://www.flaticon.com/br/" title="Flaticon"> www.flaticon.com </a>
  
 
