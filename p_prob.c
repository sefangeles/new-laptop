#include <stdio.h>
#include <math.h>

int main(){
    int i;

    for (i = 1; i <= 30; i++ ){
        if (i % 2 == 1)
            printf("%d ", i*i);
    }
    return 0;
}