#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 1000
#define n_vertices 100

/*

  TAM 1000       -> Tamanho da MATRIZ
  n_vertices 100 -> Número de vértices criados

*/

void InicializandoMatrix(int matriz[][TAM]){  //Inicia a tabela de adjacência com -1 

  for (int i = 0; i < TAM; i++){
    for (int j = 0; j < TAM; j++){
      
      matriz[i][j] = -1;

    }
  }

}

void ConstrutorVerticeMatrix(int matriz[][TAM],int valor){  //Constrói o Vertice na Tabela de adjacência

  while(matriz[valor][valor] == 0 || matriz[valor][valor] == 1){
    valor = (rand() % TAM); //0 até 999
  }

  matriz[valor][valor] = 0;
  
}

int N_aresta_AdjacentesMatrix(int matriz[][TAM],int valor){  //Retorna numero de Aresta de um Vertice

  int soma = 0;

  for (int i = 0; i < TAM; i++){

    if(matriz[valor][i] == 1){
      soma += 1;
    }
    
  }

  return soma;

}

bool verticeExisteMatrix(int matriz[][TAM],int valor){  //Verifica se o valor de Vertice existe
  
  if(matriz[valor][valor] == 1 || matriz[valor][valor] == 0){
    
    return true;

  }
  
  return false;

}

void ConstruirArestaMatrix(int matriz[][TAM],int vertice1,int vertice2){  //Constrói as Aresta entre 2 Vértices que existem dentro do Grafo, não sendo unidirecional
 
  if(vertice1 != vertice2){
  
    if(verticeExisteMatrix(matriz,vertice1) == true && verticeExisteMatrix(matriz,vertice2) == true){

      if(N_aresta_AdjacentesMatrix(matriz,vertice1) < 3 && N_aresta_AdjacentesMatrix(matriz,vertice2) < 3){

        matriz[vertice1][vertice2] = 1;
        matriz[vertice2][vertice1] = 1;
        
      }
    
    }
        
  }
    
}

void imprimir_matrix(int matriz[][TAM]){

  for (int i = 0; i < TAM; i++){
    if(matriz[i][i] == 1 || matriz[i][i] == 0){
      printf("Matriz[%d]",i+1);  // i+1 por conta do vetor ir de 0 a 999
      for(int j = 0; j < TAM; j++){
        if(matriz[i][j] == 1){
          printf(" -> Matriz[%d]",j+1); // j+1 por conta do vetor ir de 0 a 999
        }
      }
    printf("\n");
    }
  
  }

}

void Vertices(int matriz[][TAM],int vertice[]){  //Passa os valores dos Vértices para um Vetor

  int j = 0;
  for (int i = 0; i < TAM; i++){
    if(matriz[i][i] == 1 || matriz[i][i] == 0){
      vertice[j] = i;
      j++;
    }
  }
    
}

void DFS_recursao(int matriz[][TAM],int vertice[],int valor_inicial){  //Base do DFS

  bool tem = false;
  int posicao = 0;
  
  for(int p = 0; p<n_vertices; p++){  //Verifica se o valor do vertice esta no vetor vertice[]
    if(vertice[p] == valor_inicial){
      tem = true;
      posicao = p;
    }
  } 

  if(tem == true){

    vertice[posicao] = -1;   //O vertice acaba sendo sobrescrito com valor -1 no vetor vertice[], sendo assim um vertice já visitado
    for(int i = 0; i<TAM; i++){

      if(matriz[valor_inicial][i] == 1){  //Aplicado recursividade e funcionando como uma memória de Pilha
        DFS_recursao(matriz,vertice,i);
      }
    }
  }

  if(tem == true){
    if(valor_inicial != -1){
      printf("Valor = %d\n",valor_inicial+1);  //Após o termino, o valor do vertice é imprimido, com valor_inicial+1 por conta do vetor ir de 0 a 999
    }
  }
  
}

void DFS(int matriz[][TAM]){  /*DFS completo: por conta da recursividade não
                                conseguir chegar nos vertices que não tem nenhuma aresta, 
                                foi necessário utilizar o DFS para cada vértice no grafo   */

  int vertice[n_vertices];  //Vetor que recebe todos os vertices

  Vertices(matriz,vertice);   //Vetor recebendo vertices do grafo

  for(int  i = 0; i<n_vertices;i++){          //Aplicando DFS em todos os vertices
    DFS_recursao(matriz,vertice,vertice[i]);
  }

  
}

void BFS_recursao(int matriz[][TAM],int vertice[],int valor_inicial){  //Base do BFS

  bool tem = false;
  int posicao = 0;
  
  for(int f = 0; f<n_vertices; f++){ //Verifica se o valor do vertice esta no vetor vertice[]
    if(vertice[f] == valor_inicial){
      tem = true;
      posicao = f;
    }
  } 

  if(tem == true){
    
    if(valor_inicial != -1){     
      printf("Valor = %d\n",valor_inicial+1);  //Diferente do DFS, o valor do vertice é imprimido já quando passa pelo vertice, com valor_inicial+1 por conta do vetor ir de 0 a 999
    }
    
    vertice[posicao] = -1; //O vertice acaba sendo sobrescrito com valor -1 no vetor vertice[], sendo assim um vertice já visitado

    for(int i = 0; i<TAM; i++){

      if(matriz[valor_inicial][i] == 1){
        BFS_recursao(matriz,vertice,i);  //Aplicado recursividade e funcionando como uma memória de Pilha, como o vértice é imprimido logo no começo, seu efeito é uma simulação de uma estrutura de memória Fila
      }
    }
  }
 
}

void BFS(int matriz[][TAM]){  /*  BFS completo: por conta da recursividade não
                                  conseguir chegar nos vertices que não tem nenhuma aresta, 
                                  foi necessário utilizar o BFS para cada vértice no grafo   */

  int vertice[n_vertices];   //Vetor que recebe todos os vertices

  Vertices(matriz,vertice);  //Vetor recebendo vertices do grafo

  for(int  i = 0; i<n_vertices;i++){
    BFS_recursao(matriz,vertice,vertice[i]);  //Aplicando DFS em todos os vertices
  }
  
}

int main(){

  srand(time(NULL));

  int grafo_matriz[TAM][TAM]; //Matriz de adjacencia

  InicializandoMatrix(grafo_matriz); // Inicializando todos os valores na matriz com -1



  int numero_aleatorio; 

  int vertices[n_vertices];
  
  for(int i = 0; i< n_vertices; i++){ // n_vertices = 100
    numero_aleatorio = (rand() % TAM); //0 até 999
    ConstrutorVerticeMatrix(grafo_matriz,numero_aleatorio);
    vertices[i] = numero_aleatorio;
  }

  int numero_aleatorio2;

  for(int i = 0; i< n_vertices; i++){ // n_vertices = 100
    numero_aleatorio = rand() % 4;    // 0 até 3
    for(int j = 0; j< numero_aleatorio;j++){
      numero_aleatorio2 = rand() % n_vertices; //0 até 99
      ConstruirArestaMatrix(grafo_matriz,vertices[i],vertices[numero_aleatorio2]);
    }
  }
  
  imprimir_matrix(grafo_matriz);

  int vertice[n_vertices];

  Vertices(grafo_matriz,vertice);
  
  printf("\n\nVERTICES:\n\n");

  for(int  i = 0; i<n_vertices;i++){
    printf("%d° Vertice = %d\n",i+1,vertice[i]+1);
  }

  
  printf("\n\nDFS:\n\n");

  DFS(grafo_matriz);

  printf("\n\nBFS:\n\n");

  BFS(grafo_matriz);
  
  
  return 0;
}