#include <stdio.h>
#include <stdlib.h>
#include "Sorting_Algorithms.h"

void bubbleSort(int TAM, int *vetor){
	
	int i, segue, f = TAM, aux;
	
	do{
		
		segue = 0;
		
		for(i=0; i<f-1; i++){
			if(vetor[i] > vetor[i+1]){
				aux = vetor[i];
				vetor[i] = vetor[i+1];
				vetor[i+1] = aux;
				segue = i;
			}
		}
		
		f--;
		
	}while(segue != 0);
	
}

void quickSort(int TAM, int *vetor, int ini, int fim){
	
	int i, j, pivo, aux;
	
	i = ini;
	j = fim-1;
	pivo = vetor[(ini + fim)/2];
	
	while(i <= j){
		
		while((vetor[i] < pivo) && (i < fim)){
			i++;
		}
		while((vetor[j] > pivo) && (j > ini)){
			j--;
		}
		
		if(i <= j){
			aux = vetor[i];
			vetor[i] = vetor[j];
			vetor[j] = aux;
			i++;
			j--;
		}
	}
	
	if(j > ini){
		quickSort(TAM, vetor, ini, j+1);
	}	
	if(i < fim){
		quickSort(TAM, vetor, i, fim);
	}	
		
}

void mergeSort(int TAM, int *vetor, int ini, int fim){	
	
	int mei;
	
	if(ini<fim){
		mei = ((ini+fim)/2);
		mergeSort(TAM, vetor, ini, mei);
		mergeSort(TAM, vetor, mei+1, fim);
		mergeSortaux(TAM, vetor, ini, mei, fim);
	}
	
}

void mergeSortaux(int TAM, int *vetor, int ini, int mei, int fim){
	
	int p1, p2, tam, i, j, k, fim1 = 0, fim2 = 0;
	
	int *aux = (int*) malloc(sizeof(int)*tam-1);
	
	tam = (fim - ini) + 1;
	p1 = ini;
	p2 = mei + 1;
	
	if(aux != NULL){
		
		for(i=0; i<tam; i++){
			if(!fim1 && !fim2){
				if(vetor[p1] < vetor[p2]){
					aux[i] = vetor[p1++];
				}
				else{
					aux[i] = vetor[p2++];
				}
				
				if(p1 > mei){
					fim1 = 1;
				}
				if(p2 > fim){
					fim2 = 1;
				}
			}
			else{
				if(!fim1){
					aux[i] = vetor[p1++];
				}
				else{
					aux[i] = vetor[p2++];
				}
			}
		}
		
	}
	
	free(aux);
	
}

void selectionSort(int TAM, int *vetor){
	
	int i, j, min, aux;
	
	for(i=0; i<TAM-1; i++){
		
		min = i;
		
		for(j=i+1; j<TAM; j++){
			if(vetor[j] < vetor[min]){
				min = j;
			}
		}
		
		if(i != min){
			aux = vetor[i];
			vetor[i] = vetor[min];
			vetor[min] = aux;
		}
		
	}
	
}

