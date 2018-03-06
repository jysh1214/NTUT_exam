#include <stdio.h>
#include <math.h>

// Transfer x_(base1=10) to result(base2)
// Transfer x_(base1) to result(base2=10)

int transform10(int x, int base1, int base2){
    int remainder = 0;
    int result = 0;
    int index = 1;
    while(x>0){                                  // Problem 7-1
        remainder = x % base2;                   // Problem 7-2
        result = result + remainder * index;     // Problem 7-3
        index = index * base1;                   // Problem 7-4
        x = x / base2;
    }
    return result;
}

int transform(int x, int base1, int base2){
    int temp = transform10(x, base1, 10);
    return transform10(temp, 10, base2);
}

int main(){
    int x;
    int base1 = 0, base2 = 0;
    printf("Input x, base1, base2: "); // demo
    scanf("%d %d %d", &x,  &base1, &base2);
    printf("%d_(%d) = %d_(%d)\n", x, base1, transform(x, base1, base2), base2);
    return 0;
}
