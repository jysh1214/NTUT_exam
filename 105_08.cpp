#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float test01(int a, float b, float c){
    int x = a + 0.5, y = b / 2, z = (int)c;
    return x * y + z / 3;
}

int test02(int a, int b){
    int x=0;
    if(!(a==b))    x=1;
    else if (a&&b) x=2;
    return x;
}

int test03(int g){
    int score;
    switch(g){
        case 1: score = 100;
            break;
        case 2: score = 90;
            break;
        case 3: score = 80;
        case 4: score = 70;
            break;
        case 5: score = 60;
        default:score = 0;
    }
    return score;
}

int test04(int n){
    if(n==0) return 0;
    else     return n + test04(n-1);
}

int test05(int a[], int size){
    int x = 0, i, j;
    for(i=0;i<size;i++)
        for(j=0;j<i;j++)
            x += a[j];

    return x;
}

void test06(int *p, int *q){
    int **a = &q, **b = &q;
    a = b;
    (**a)++;
}

char *test07(char *str2){
    char *str1 = (char*)malloc(strlen("Happy")+strlen(str2)+2);
    strcpy(str1, str2);
    return strcat(str1, "Happy");
    
    free(str1);
}

int main(){
    int a = 0, b = 2, c = 3, array[] = {0,1,2,3,5};
    char str[] = "New Year";
    printf("Problem 8-1: %.2f\n", test01(2,5.0,3.6));   // Problem 8-1
    printf("Problem 8-2: %d\n", test02(a, b));          // Problem 8-2
    printf("Problem 8-3: %d\n", test03(array[3]));      // Problem 8-3
    printf("Problem 8-4: %d\n", test04(array[4]));      // Problem 8-4
    printf("Problem 8-5: %d\n", test05(array, 4));      // Problem 8-5
    test06(&array[1], &array[2]);        
    printf("Problem 8-6: %d %d\n", array[1], array[2]); // Problem 8-6
    printf("Problem 8-7: %s\n", test07(str));           // Problem 8-7
    return 0;
}
