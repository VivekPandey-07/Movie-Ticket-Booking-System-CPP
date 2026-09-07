#include <vector>
#include <memory>
#include <algorithm>
#include <iostream>
using namespace std;
class BookingService {
    vector<unique_ptr<Booking>> bookings; PriceCalculator calculator; TicketPrinter printer;
    ShowSeat* findSeat(Show&show,int n){for(auto&s:show.getShowSeats())if(s.getNumber()==n)return &s;return nullptr;}
public:
    Booking* createBooking(Customer&c,Show&show,const vector<int>&nums,Payment&p){
        vector<ShowSeat*> chosen;
        for(int n:nums){
            ShowSeat*s=findSeat(show,n);
            if(!s){cout<<"Invalid seat "<<n<<".\n";return nullptr;}
            if(!s->isAvailable()){cout<<"Seat "<<n<<" is already BOOKED.\n";return nullptr;}
            if(find(chosen.begin(),chosen.end(),s)!=chosen.end()){cout<<"Seat "<<n<<" entered twice.\n";return nullptr;}
            chosen.push_back(s);
        }
        double total=calculator.calculate(chosen); cout<<"Total amount: Rs."<<total<<"\n";
        for(auto*s:chosen)s->book();
        if(!p.pay(total)){for(auto*s:chosen)s->release();cout<<"Payment failed. Booking NOT confirmed.\n";return nullptr;}
        auto b=make_unique<Booking>(&c,&show,chosen,total); b->confirm(); Booking*result=b.get(); bookings.push_back(move(b)); printer.print(*result); return result;
    }
    bool cancelBooking(int id){
        for(auto&b:bookings)if(b->getBookingId()==id&&b->getStatus()==Booking::Status::CONFIRMED){
            for(auto*s:b->getSeats())s->release();b->cancel();cout<<"Booking cancelled. Seats are AVAILABLE again.\n";return true;
        }
        cout<<"Confirmed booking not found.\n";return false;
    }
};
