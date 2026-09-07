#include <iostream>
#include <iomanip>
using namespace std;
class TicketPrinter {
public:
    void print(const Booking&b)const{
        cout<<"\n================ TICKET ================\n";
        cout<<"Booking ID : "<<b.getBookingId()<<"\nCustomer   : "<<b.getCustomer()->getName()<<"\nMovie      : "<<b.getShow()->getMovie()->getTitle()<<"\nScreen     : "<<b.getShow()->getScreen()->getScreenNumber()<<"\nTime       : "<<b.getShow()->getStartTime()<<"\nSeats      : ";
        for(auto*s:b.getSeats())cout<<s->getNumber()<<" ";
        cout<<"\nTotal      : Rs."<<fixed<<setprecision(2)<<b.getTotalAmount()<<"\nStatus     : CONFIRMED\n=========================================\n";
    }
};
