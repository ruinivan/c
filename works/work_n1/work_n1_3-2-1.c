#include <stdio.h>
#include <limits.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL,"portuguese");
    int tam_max = INT_MAX; 
    int tam_min = INT_MIN;
    printf("| TIPO                   | MINIMO                | MAXIMO              \n");
    printf("|-----------------------------------------------------------------------\n");
    printf("| char                    %d                   %d                 \n", CHAR_MIN, CHAR_MAX);
    printf("| int                     %d            %d          \n", INT_MIN, INT_MAX);
    printf("| short int               %d                %d               \n", SHRT_MIN, SHRT_MAX);
    printf("| unsigned int            0                      %u          \n", UINT_MAX);
    printf("| long int                %ld            %ld          \n", LONG_MIN, LONG_MAX);
    printf("| unsigned long int       0                      %lu          \n", ULONG_MAX);
    printf("| long long int           %lld   %lld \n", LLONG_MIN, LLONG_MAX);
    printf("| unsigned long long int  0                      %llu\n", ULLONG_MAX);
    printf("\nTamanho máximo int :%d\n", tam_max);
	tam_max += 1;   
    printf("Resultado final após o incremento de 1: %d\n", tam_max);   
   	printf("\nTamanho minimo int :%d\n", tam_min);
   	tam_min -= 1;  
	printf("Resultado final após o decremento de 1: %d\n", tam_min);     
    return 0;
}