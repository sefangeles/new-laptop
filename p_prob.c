#include <stdio.h>
#include <math.h>

int main(){
    int i, j, k;

    printf("Enter a positive integer: ");
    scanf("%d", &i);
    printf("Integer | Factorial\n");
    for(int x = i; x >= 1; --x){
        j = 1;  
        for(k = 1; k <= x; ++k){
            j *= k;
        }
        printf("%7d | %7d\n", x, j);    
        
    } 
    
    return 0;
}