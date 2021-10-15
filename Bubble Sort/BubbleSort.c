#include <stdio.h>
#include <stdlib.h>
#include "BubbleSort.h"

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

void bubbleSort(Repo* re){
	
	int i, segue, f = re->k;
	Prod *aux = (Prod*) malloc(sizeof(Prod));
	
	do{
		
		segue = 0;
		
		for(i=0; i<f-1; i++){
			if(re->dados[i]->valor > re->dados[i+1]->valor){
				aux = re->dados[i];
				re->dados[i] = re->dados[i+1];
				re->dados[i+1] = aux;
				segue = i;
			}
		}
		
		f--;
		
	}while(segue != 0);
	
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
