#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 100
#define n_vertices 100

/*

  TAM_1 1000     -> Tamanho da 1° MATRIZ
  TAM_2 100000   -> Tamanho da 1° MATRIZ
  n_vertices 100 -> Constante utilizada nas inserção

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

int main(){

  srand(time(NULL));

  int grafo_matriz[TAM][TAM]; //Matriz de adjacencia

  InicializandoMatrix(grafo_matriz); // Inicializando todos os valores na matriz com -1

  int numero_aleatorio; // 

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
  
  return 0;
}