#include<iostream>
using namespace std;

class Shape{

    public:

    virtual void draw()=0;
};

class Circle:public Shape{

    public:

    void draw(){
        cout<<"drawing circle"<<endl;
    }
};

class Rectangle:public Shape{

    public:

    void draw(){
        cout<<"drawing rectangle";
    }
};

int main(){

    Circle c;
    Rectangle r;

    c.draw();
    r.draw();
   
}