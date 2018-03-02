#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum COLOR {RED, YELLOW, GREEN = 10, BLUE};
typedef struct item{
    int data;
    struct item *link;
}ITEM_t;

void test01(int a, int b, int c){
    printf("Problem 6-1: ");
    printf("%d\n", a&b|c);                  // Problem 6-1
}

void test02(int a[], int size){
    int x;
    if(a[0]==0 && a[1]==a[2])     x = a[0];
    else if(!a[0] || a[1]==a[2])  x = a[1];
    else                          x = a[2];
    printf("Problem 6-2: ");
    printf("%d\n", x);                      // Problem 6-2
}

void test03(int a[], int size){
    int x = 0, i, j;
    for(i=0;i<size;i++){
        for(j=i;j<size;j++)
            x += a[j];
    }
    printf("Problem 6-3: ");
    printf("%d\n", x);                      // Problem 6-3
}

void test04(int *p, int *q, int *r){
    int **a = &p, **b = &q, **c = &r;
    a = &q; b = c;
    printf("Problem 6-4: ");
    printf("%d\n", **a + **b + **c);        // Problem 6-4 
}

char* test05(int x){
    /* original code can't work, so we adjust */
    char y = (COLOR)x;
    char *str;
    str = (char *)malloc(10);
    switch (y){
        case RED: strcpy(str, "red");
            break;
        case YELLOW: strcpy(str, "yellow");
            break;
        case GREEN: strcpy(str, "green");
            // without break, case GREEN would be case BLUE    
        case BLUE: strcpy(str, "blue");
            break;
        default: strcpy(str, "error");
            break;
    }
    return str;
}

void test06(int y, ITEM_t **top){
    ITEM_t *x;
    x = (ITEM_t *)malloc(sizeof(ITEM_t));
    x->data = y;
    x->link = (*top);
    (*top) = x;
}

int main(){
    int a = 2, b = 3, c = 4, i, array[] = {0,1,2,3,4};
    char *str1, *str2;
    ITEM_t *top = NULL;
    test01(a, b, c);
    test02(array, 3);
    test03(array, 3);
    test04(&array[0], &array[1], &array[2]);
    str1 = test05(2);
    str2 = test05(10);
    printf("Problem 6-5: ");
    printf("%s %s\n", str1, str2);           // Problem 6-5
    for(i=0;i<5;i++)
        test06(array[i], &top);
    printf("Problem 6-6: ");
    printf("%d\n", top->link->data);         // Problem 6-6
    return 0;
}
