#include <stdio.h>
#include <iostream>

using namespace std;

class Shape{
    public:
    void print(){                      // A                 
        cout<< "S:\n";
    }
    void print(int s1, int s2){
        cout<<"S:"<<s1<<s2<<"\n";
    }
    void print(string side){           // B
        cout<<"S:"<<side<<"\n";
    }
};

class Rectangle: public Shape{
    public:
    void print(int side){              // C
        cout<<"R:"<<side<<"\n";
    }
    void print(string side){           // D
        cout<<"R:"<<side<<"\n";
    }
    int print(){                       // E
        cout<<"R:"<<"\n";
        return 4;
    }
    Rectangle(int m=1){length=m; width=2;}
    int width;                         // F
    
    private:
    int length;
};
	
void test01(){
    Rectangle r;
    Shape *sp1 = new Shape();
    Rectangle *rp1 = new Rectangle(2);
    Shape *sp2 = new Rectangle();
    /* cpp:42:32: error: invalid conversion from ‘Shape*’ to ‘Rectangle*’ [-fpermissive] */
    // Rectangle *rp2 = new Shape();   // G
    cout<<"G: error: invalid conversion from ‘Shape*’ to ‘Rectangle*’"<<"\n";
    cout<<"H: ";    
    r.print();                         // H
    cout<<"I: ";
    r.print(5);                        // I
    cout<<"J: ";
    rp1->print("x");                   // J
    cout<<"K: ";
    rp1->print(3);                     // K
    cout<<"L: ";
    sp2->print("x");                   // L
    /* cpp:55:19: error: no matching function for call to ‘Rectangle::print(int, int)’ */    
    // rp1->print(1,2);                // M
    cout<<"M: error: no matching function for call to ‘Rectangle::print(int, int)’"<<"\n";
    /* cpp:34:9: error: ‘int Rectangle::length’ is private */    
    // rp1->length=3;                  // N
    cout<<"N: error: ‘int Rectangle::length’ is private"<<"\n";
}

void test02(int data[][4]){
    int i, j, data2[4][4];
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
            data2[i][3-j] = data[j][i];// O

    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
            data[i][j] = data2[i][j]; 

    // test02 demo
    cout<<"data2: "<<"\n";
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
            printf("%2d ",data[i][j]);

    cout<<"\n";
}

int main(){
    int data[4][4] = {{1,2,3,4},{5,6,7,8},
                      {9,10,11,12},{13,14,15,16}};
 
    test01();       
    test02(data);
    return 0;
}
