#include <stdio.h>
#include <stdlib.h>
#include "QuickSort.h"

int main(){
	
	int n = 5;
	
	Repo* re = criarRepositorio(n);
			
	adicionar(re, 555, 600);
	adicionar(re, 111, 10);
	adicionar(re, 444, 499);
	adicionar(re, 333, 150);
	adicionar(re, 222, 120);
	
	printRespositorio(re);
	
	quickSort(re, 0, n);
	
	printRespositorio(re);
	
	esvaziar(re);
	
}


