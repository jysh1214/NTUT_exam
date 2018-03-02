#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class RangeException: public runtime_error{
public:
    RangeException(string msg):
        runtime_error(msg){}
};

class NumberException: public runtime_error{
public:
    NumberException():
        runtime_error("input an Integer"){}
};

class Student{
public:
    int parseInt(string);
    void inputScore(string str[]);

private:
    int score;                                 // Problem 4-1
};

int Student::parseInt(string str){
    int sum = 0, i = 0;
    if(str.at(i)=='-'){
        sum = ~sum;                            // Problem 4-2
        i++;
    }
    for(;i<str.length();i++){
        /* the ASCII code of character should between 48('0') and 57('9') */
        if((str.at(i)<'0')||(str.at(i)>'9'))
            throw NumberException();
        
        sum = sum * 10 + (str.at(i)-'0');      // Problem 4-3
        /* why - '0' ? 
           
           The ASCII code of character - '0' ASCII code
           
           = the number of character
        */
    }
    
    if(sum>100||sum<0)
        throw RangeException("{0..100}");

    return sum;
}

void Student::inputScore(string str[]){
    bool valid = true;
    int i = 0;
    do{                                        // Problem 4-4
        valid = true;
        try{                                   // Problem 4-5
            score = parseInt(str[i++]);

        } catch(NumberException e1){
            // Java e.getMessage()
            cout<<e1.what()<<",";
            valid = false;
        } catch(RangeException e2){
            cout<<e2.what()<<",";
            valid = false;
        }

    }while(i<=str->length()+1);                // Problem 4-6
    cout<<score<<",";
}

int main(void){
    Student s;
    string p[] = {"p1","-1", "101", "89"};
    cout<<s.parseInt("0")<<",";
    cout<<s.parseInt("99")<<",";
    cout<<s.parseInt("100")<<",";
    s.inputScore(p);
    cout<<"\n";
    return 0;
}
