#include <iostream>

using namespace std;

class Polygon{
    protected:
        int width, height;
    public:
        virtual void setup(int w, int h){
            width = w; height = h;
        }
        void name(){cout<<"Polygon"<<endl;}
        virtual int area() = 0;
};

class Rectangle: public Polygon{
    public:
        void name(){cout<<"Rectangle"<<endl;}
        virtual int area(){return (width*height);}
};

class Triangle: public Polygon{
    public:
        void name(){cout<<"Triangle"<<endl;}
        int area(){return (width*height/2);}
};

class Square: public Rectangle{
    protected:
        int width;
    public:
        void setup(int w){width = w;}
        void name(){cout<<"Square"<<endl;}
        void area(){return (width*width);}
        Square(){width = 3;}
};

int main(){
    Rectangle *rectangle = new Rectangle;
    Triangle *triangle = new Triangle;
    Square *square = new Square;
    Rectangle * ptr_polygon1 = rectangle;
    Triangle * ptr_polygon2 = triangle;
    Square * ptr_polygon3 = square;
    ptr_polygon1->setup(2,2);
    cout<<ptr_polygon1->area()<<endl;       // Problem 7-1
    cout<<ptr_polygon3->area()<<endl;       // Problem 7-2
    Rectangle * ptr_polygon4 = ptr_polygon3;
    ptr_polygon4->setup(4,4);
    cout<<ptr_polygon4->area()<<endl;       // Problem 7-3
    ptr_polygon2->name();                   // Problem 7-4
    ptr_polygon3->name();                   // Problem 7-5
    ptr_polygon4->name();                   // Problem 7-6
    return 0;
}
