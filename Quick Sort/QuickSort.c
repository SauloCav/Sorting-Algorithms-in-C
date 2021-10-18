#include <stdio.h>
#include <stdlib.h>
#include "QuickSort.h"

struct repositoriodeprodutos{
	Prod** dados;
	int n;
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

void quickSort(Repo* re, int ini, int fim){
	
	int i, j;
	Prod *pivo = (Prod*) malloc(sizeof(Prod));
	Prod *aux = (Prod*) malloc(sizeof(Prod));
	
	i = ini;
	j = fim-1;
	pivo = re->dados[(ini + fim)/2];
	
	while(i <= j){
		
		while((re->dados[i]->valor < pivo->valor) && (i < fim)){
			i++;
		}
		while((re->dados[j]->valor > pivo->valor) && (j > ini)){
			j--;
		}
		
		if(i <= j){
			aux = re->dados[i];
			re->dados[i] = re->dados[j];
			re->dados[j] = aux;
			i++;
			j--;
		}
	}
	
	if(j > ini){
		quickSort(re, ini, j+1);
	}	
	if(i < fim){
		quickSort(re, i, fim);
	}	
		
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
