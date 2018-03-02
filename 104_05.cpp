#include <stdio.h>
#include <math.h>

void equation(int x1, int y1, int x2, int y2){
    int m, b, m1, m2, b1, b2;
    if ((x1==x2)&&(y1==y2))
        printf("ERROR, ");

    if (x1==x2)                   // Problem 5-1
        printf("x = %d, ", x1);

    else if (y1==y2)
        printf("y = %d, ", y1);

    else {
        m1 = y1 - y2;
        m2 = x1 - x2;
        b1 = x2*y1 - x1*y2;
        b2 = x2 - x1;
        printf("y = ");
        if ((m1<0)&&(m2<0)){
            m1 = -m1; m2 = -m2;
        }

        if (m1==m2){}

        else if (m1==-m2)         // Problem 5-2
            printf("-");

        else if (m1%m2==0){       // Problem 5-3
            m = m1 / m2;
            printf("%d", m);
        }

        else {printf("%d/%d", m1, m2);}

        printf("x");              // Problem 5-4
        if (b1*b2>0)
            printf("+");          // Problem 5-5

        if (b1==0) {printf(", ");}

        else if (b1%b2==0){
            b = b1 / b2;
            printf("%d, ", b);
        }
        
        else {printf("%d/%d, ", b1, b2);}
    } 
}

int main(void){
    equation(1, 0, 1, 0);
    equation(1, 0, 0,-1);
    equation(1, 0, 0, 1);
    equation(1, 1, 2, 2);
    equation(1, 1, 2, 4);
    equation(2, 3, 4, 5);
    equation(0, 1, 3, 3);
    equation(1, 1, 5, 2);
    printf("\n");
    return 0;
}
