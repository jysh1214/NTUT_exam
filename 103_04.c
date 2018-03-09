#include <stdio.h>
#include <string.h>

void test01(int a, int b, int c){
    float result;
    result = (a+b/c-a%b)/4.0;
    printf("Problem 4-1: %.1f\n", result);          // Problem 4-1
}

void test02(int a, int b){
    int shift;
    if(!(0<=a && b<=100))
        shift = a>>1 | b<<1;
    else
        shift = a<<1 | b>>1;
    printf("Problem 4-2: %d\n", shift);             // Problem 4-2
}

void test03(int a[], int size){
    int x = 0, i, j;
    for(i=0;i<size;i++){
        for(j=0;j<i;j++)
            x += a[j]; 
    } 
    printf("Problem 4-3: %d\n", x);                 // Problem 4-3
}

void test04(int a[], int size){
    enum GRADE {FRESHMAN = 1, SOPHOMORE, JUNIOR, SENIOR};
    int sum = 0, i, level;
    for(i=0;i<size;i++){
        switch(a[i]){
            case FRESHMAN:  level = 1;
            case SOPHOMORE: level = 2;
                break;
            case SENIOR:    level = 3;
            case JUNIOR:    level = 4;
                break;
            default:        level = 0;
                break;
        }
        sum = sum + level;
    }
    printf("Problem 4-4: %d\n", sum);               // Problem 4-4
}

void test05(int *p, int *q, int *r){
    int **pp = &p, **qq = &q, **rr = &r;
    qq = &p; *rr = q;
    printf("Problem 4-5: %d\n", **qq + **rr);       // Problem 4-5
} 

void test06(char *list[], int size){
    int i = 0, first = 0;
    while(i<size){
        /* strcmp: compare two strings 
        return < 0: the first character has lower
                    value in ptr1 than in ptr2
        */
        if(strcmp(list[i], list[first])<0)
            first = i;
        i++;
    }
    printf("Problem 4-6: %s\n", list[first]);       // Problem 4-6
}

int test07(int n){
    int ans;
    if(n==1)
        ans = 0;
    else
        ans = 1 + test07(n/2);
    return (ans);
}

int main(int argc, char *argv[]){
    int a = 9, b = 5, c = 3, array[] = {1,2,3,4,5};
    
    char *s[] = {"happy", "birthday", "new year",
                 "memorial day", "festival"};
    
    test01(a, b, c);
    test02(a, b);
    test03(array, 3);
    test04(array, 5);
    test05(&array[0], &array[1], &array[2]);
    test06(s, 5);
    printf("Problem 4-7: %d\n", test07(5));        // Problem 4-7
    return 0;
}
