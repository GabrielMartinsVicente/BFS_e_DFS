#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 100
#define n_vertices 10

/*

  TAM 1000       -> Tamanho da MATRIZ
  n_vertices 100 -> Número de vértices criados

*/

void InicializandoMatrix(int matriz[][TAM]){

  for (int i = 0; i < TAM; i++){
    for (int j = 0; j < TAM; j++){
      
      matriz[i][j] = -1;

    }
  }

}

void ConstrutorVerticeMatrix(int matriz[][TAM],int valor){ 
  
  while(matriz[valor][valor] == 0 || matriz[valor][valor] == 1){
    valor = (rand() % TAM); //0 até 999
  }

  matriz[valor][valor] = 0;
  
}

int N_aresta_AdjacentesMatrix(int matriz[][TAM],int valor){

  int soma = 0;

  for (int i = 0; i < TAM; i++){

    if(matriz[valor][i] == 1){
      soma += 1;
    }
    
  }

  return soma;

}

bool verticeExisteMatrix(int matriz[][TAM],int valor){
  
  if(matriz[valor][valor] == 1 || matriz[valor][valor] == 0){
    
    return true;

  }
  
  return false;

}

void ConstruirArestaMatrix(int matriz[][TAM],int vertice1,int vertice2){
 
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
      printf("Matriz[%d]",i);
      for(int j = 0; j < TAM; j++){
        if(matriz[i][j] == 1){
          printf(" -> Matriz[%d]",j);
        }
      }
    printf("\n");
    }
  
  }

}

void Vertices(int matriz[][TAM],int vertice[]){


  int j = 0;
  for (int i = 0; i < TAM; i++){
    if(matriz[i][i] == 1 || matriz[i][i] == 0){
      vertice[j] = i;
      j++;
    }
  }
    
}

void DFS(int matriz[][TAM],int vertice[],int valor_inicial){

  bool tem = false;
  int posicao = 0;
  
  for(int p = 0; p<n_vertices; p++){
    if(vertice[p] == valor_inicial){
      tem = true;
      posicao = p;
    }
  } 

  if(tem == true){

    vertice[posicao] = -1;
    for(int i = 0; i<TAM; i++){

      if(matriz[valor_inicial][i] == 1){
        DFS(matriz,vertice,i);
      }
    }
  }

  if(tem == true){
    if(valor_inicial != -1){
      printf("Valor = %d\n",valor_inicial);
    }
  }
  
}

void BFS(int matriz[][TAM],int vertice[],int valor_inicial){

  bool tem = false;
  int posicao = 0;
  
  for(int f = 0; f<n_vertices; f++){
    if(vertice[f] == valor_inicial){
      tem = true;
      posicao = f;
    }
  } 

  if(tem == true){
    
    if(valor_inicial != -1){
      printf("Valor = %d\n",valor_inicial);
    }
    
    vertice[posicao] = -1;

    for(int i = 0; i<TAM; i++){

      if(matriz[valor_inicial][i] == 1){
        BFS(matriz,vertice,i);
      }
    }
  }
 
}

int main(){

  srand(time(NULL));

  int grafo_matriz[TAM][TAM]; //Matriz de adjacencia

  InicializandoMatrix(grafo_matriz); // Inicializando todos os valores na matriz com -1

  /*

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

  */
  //-----------------------------------------------------------------------


  ConstrutorVerticeMatrix(grafo_matriz,7);
  ConstrutorVerticeMatrix(grafo_matriz,19);
  ConstrutorVerticeMatrix(grafo_matriz,1);
  ConstrutorVerticeMatrix(grafo_matriz,12);
  ConstrutorVerticeMatrix(grafo_matriz,31);
  ConstrutorVerticeMatrix(grafo_matriz,21);
  ConstrutorVerticeMatrix(grafo_matriz,14);
  ConstrutorVerticeMatrix(grafo_matriz,23);
  ConstrutorVerticeMatrix(grafo_matriz,6);
  ConstrutorVerticeMatrix(grafo_matriz,77);

  ConstruirArestaMatrix(grafo_matriz,7,19);
  ConstruirArestaMatrix(grafo_matriz,7,21);
  ConstruirArestaMatrix(grafo_matriz,7,14);
  ConstruirArestaMatrix(grafo_matriz,19,1);
  ConstruirArestaMatrix(grafo_matriz,19,12);
  ConstruirArestaMatrix(grafo_matriz,12,31);
  ConstruirArestaMatrix(grafo_matriz,14,23);
  ConstruirArestaMatrix(grafo_matriz,14,6);

  imprimir_matrix(grafo_matriz);
  //-----------------------------------------------------------------------

  int vertice[n_vertices];

  Vertices(grafo_matriz,vertice);

  printf("\n\nVERTICES\n");

  for(int  i = 0; i<n_vertices;i++){
    printf("Vertice[%d] = %d\n",i,vertice[i]);
  }


  /*
  printf("\n\nTESTE DFS\n");


  for(int  i = 0; i<n_vertices;i++){
    DFS(grafo_matriz,vertice,vertice[i]);
  }

  */
  
  printf("\n\nTESTE BFS\n");
  for(int  i = 0; i<n_vertices;i++){
    //BFS(grafo_matriz,vertice,vertice[i]);
  }
  
  BFS(grafo_matriz,vertice,vertice[2]);
  
  
  
  
  
  
  
  
  
  
  return 0;
}