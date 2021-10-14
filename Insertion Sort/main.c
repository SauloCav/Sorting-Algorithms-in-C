#include <stdio.h>
#include <stdlib.h>
#include "InsertionSort.h"

int main(){
	
	Repo* re = criarRepositorio(5);
			
	adicionar(re, 555, 600);
	adicionar(re, 111, 10);
	adicionar(re, 444, 499);
	adicionar(re, 333, 150);
	adicionar(re, 222, 120);
	
	printRespositorio(re);
	
	insertionSort(re);
	
	printRespositorio(re);
	
	esvaziar(re);
	
}


