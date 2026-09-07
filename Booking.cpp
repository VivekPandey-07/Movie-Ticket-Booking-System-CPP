#include <vector>
#include <string>
using namespace std;
class Booking {
public: enum class Status{PENDING,CONFIRMED,CANCELLED};
private:
    static int nextBookingId; int bookingId; Customer* customer; Show* show; vector<ShowSeat*> seats; double totalAmount; Status status=Status::PENDING;
public:
    Booking(Customer*c,Show*s,const vector<ShowSeat*>&seats,double total):bookingId(nextBookingId++),customer(c),show(s),seats(seats),totalAmount(total){}
    int getBookingId()const{return bookingId;} Customer* getCustomer()const{return customer;} Show* getShow()const{return show;}
    const vector<ShowSeat*>&getSeats()const{return seats;} double getTotalAmount()const{return totalAmount;}
    Status getStatus()const{return status;} void confirm(){status=Status::CONFIRMED;} void cancel(){status=Status::CANCELLED;}
};
int Booking::nextBookingId=1001;
