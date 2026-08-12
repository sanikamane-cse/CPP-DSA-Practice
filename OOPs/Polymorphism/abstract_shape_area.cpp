#include<iostream>
using namespace std;
class Shape{
    public:
    virtual void area()=0;
};
class Circle:public Shape{
    public:
    void area()override{
         double radius=3;
        cout<<"Area of circle:"<<3.14*radius*radius<<endl;
}
};
class Rectangle:public Shape{
    public:
    void area()override{
        int length=5;
        int breadth=4;
        cout<<"Area of Rectangle:"<<length*breadth<<endl;
    }
};
int main(){
Circle c;
Rectangle r;
c.area();
r.area();
return 0;

}

   
