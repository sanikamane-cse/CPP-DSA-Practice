#include<iostream>
using namespace std;
class Book{
    public:

    string title;
    int price;

    Book(string t,int p){
        title=t;
        price=p;
    }
    Book(const Book &obj){
        title=obj.title;
        price=obj.price;
    }
    void display(){
        cout<<"Title : "<<title<<endl;
        cout<<"Price : "<<price<<endl;
    }
};
int main(){

    Book b1("c++ programming",450);
    
    Book b2=b1;

    cout<<"Book 1 details"<<endl;
    b1.display();

    cout<<endl;

    cout<<"Book 2 details"<<endl;
    b2.display();

    return 0;
    


}