#include<iostream>
using namespace std;

class Notifications{
    public:

    virtual void send()=0;

};

class Email:public Notifications{

    public:

    void send(){
        cout<<"Sending email"<<endl;
    }
};

class Sms:public Notifications{

    public:

    void send(){

        cout<<"Sending sms"<<endl;
    }
};

int main(){


    Email e;
    Sms s;

    e.send();
    s.send();

    return 0;
}
