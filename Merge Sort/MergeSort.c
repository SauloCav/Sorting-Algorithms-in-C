#include <stdio.h>
#include <stdlib.h>
#include "MergeSort.h"

struct repositoriodeprodutos{
	Prod** dados;
	int n;
	int i;
	int k;
};

struct produto{
	int codigo;
	float valor;
};

Repo* criarRepositorio(int n){
	
	Repo* re = (Repo*) malloc(sizeof(Repo));
 	
 	re->n = n;
 	re->k = 0;
 	re->i = 0;
 	
 	re->dados = (Prod**) malloc(sizeof(Prod*) * n+1);
 	
 	return re;
	
}

int adicionar(Repo* re, int cod, float val){
	
	if((re != NULL) && (re->k < re->n)) {
		
		Prod *pr = criaProduto(cod, val); 
		re->dados[re->k] = pr;
		re->k++;
		
		return 1;
		
	}
	else{
		
		return 0;
		
	}
	
}

void mergeSort(Repo* re, int ini, int fim){
	
	int mei;
	
	if(ini<fim){
		mei = ((ini+fim)/2);
		mergeSort(re, ini, mei);
		mergeSort(re, mei+1, fim);
		mergeSortaux(re, ini, mei, fim);
	}
	
}

void mergeSortaux(Repo* re, int ini, int mei, int fim){
	
	int p1, p2, tam, i, j, k, fim1 = 0, fim2 = 0;
	Prod **aux = (Prod**) malloc(sizeof(Prod*)*re->n);
	
	tam = (fim - ini) + 1;
	p1 = ini;
	p2 = mei + 1;
	
	if(aux != NULL){
		
		for(i=0; i<tam; i++){
			if(!fim1 && !fim2){
				if(re->dados[p1]->valor < re->dados[p2]->valor){
					aux[i] = re->dados[p1++];
				}
				else{
					aux[i] = re->dados[p2++];
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
					aux[i] = re->dados[p1++];
				}
				else{
					aux[i] = re->dados[p2++];
				}
			}
		}
			
		for(j=0, k=ini; j < tam; j++, k++){
			re->dados[k] = aux[j];
		}
		
	}
	
	free(aux);
	
}

void esvaziar(Repo* re){
	
	free(re);
	
}

void printRespositorio(Repo* re){
	
	int i = 0;
	
	if((re!=NULL) && (re->k>0)){
		
		printf("\nLista de Compras:\n");
		for(i=0; i<re->k; i++){
			printf("Codigo: [%d], Valor: [%.2f]\n", re->dados[i]->codigo, re->dados[i]->valor);
		}
		
	}
	else{
		printf("\nLista de Compras Vazia!");
	}
	
}

Prod* criaProduto(int cod, float val){
	
	Prod *c = (Prod*) malloc(sizeof(Prod));
	
	c->codigo = cod;
	c->valor = val;
	return c;
	
}
