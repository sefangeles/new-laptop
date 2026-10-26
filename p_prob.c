#include <stdio.h>
#include <math.h>

int main(){
    int i, j;

    for (i = 1; i <= 7 ; i++ ){
        for( j = 1; j <= i; j++){
            printf("%d ", (i+1) - (j));
        }
        printf("\n");
    }
    return 0;
}