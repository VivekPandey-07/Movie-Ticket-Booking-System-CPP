#include <iostream>
#include <string>
using namespace std;
// Abstraction + inheritance + runtime polymorphism.
class Payment {
protected: double amount=0;
public: virtual ~Payment()=default; virtual bool pay(double amount)=0; virtual string method()const=0;
};
class UpiPayment:public Payment {
public:
    bool pay(double amount)override{this->amount=amount;string id;cout<<"Enter UPI ID: ";cin>>id;return id.find('@')!=string::npos;}
    string method()const override{return "UPI";}
};
class CardPayment:public Payment {
public:
    bool pay(double amount)override{this->amount=amount;string x;cout<<"Enter last 4 digits: ";cin>>x;return x.size()==4;}
    string method()const override{return "Card";}
};
class CashPayment:public Payment {
public:
    bool pay(double amount)override{this->amount=amount;char x;cout<<"Cash received. Confirm (y/n): ";cin>>x;return x=='y'||x=='Y';}
    string method()const override{return "Cash";}
};
