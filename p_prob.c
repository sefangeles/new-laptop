#include <stdio.h>
#include <math.h>

int main(){
    int i, j = i;

    printf("Enter a positive integer: ");
    scanf("%d", &i);

    for(int x = 1; x <= i; ++x){
        j *= x;
    } 

    printf("The factorial of %d is %d", i, j);
    return 0;
}