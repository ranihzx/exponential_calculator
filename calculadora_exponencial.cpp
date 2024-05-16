#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

int main() {
	int expoente, vezes, auxiliar, x, y;
	float base, base_aux;
	char continuar[3];
	
	setlocale(LC_ALL, "Portuguese");
    
    do {
        printf("CALCULADORA EXPONENCIAL\n\nDigite a base: ");
	    scanf("%f", &base);
	    printf("Digite o expoente: ");
	    scanf("%d", &expoente);
    
        auxiliar = 0;
        
        if(base < 0) {
        vezes = base * (-1);
        }
        else {
            vezes = base;
        }
        
	    if(base == 0 && expoente < 0) {
		    printf("\nO resultado é: Indeterminado");
    	}
        else {
            if(expoente == 0) {
	        	printf("\nO resultado é: 1");
        	}
            else {
                if(expoente < 0) {
	            	expoente = -expoente;
	            	auxiliar = 1;
            	}
	        	for(x = 1; x < expoente; x++) {
                    base_aux = base; 
		        	for(y = 1; y < vezes; y++) {
		            	base = base + base_aux;
                    } 
	    	    }
	            if(auxiliar == 1) {
	    	        base = 1/base;
	            }
                if(base < 0 && expoente % 2 == 0) {
                    base = base * (-1);
                }
	            printf("\nO resultado é: %f", base);
            }
        }
        
        printf("\n\nDeseja continuar? (Sim/Não)\n");
        scanf("%s", continuar);
        
        for(int m = 0; continuar[m]; m++) {
            continuar[m] = tolower(continuar[m]);
        }
        system("cls");
    }
    while(strcmp(continuar, "sim") == 0);
	return 0;
}