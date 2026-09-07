#include <iostream>
#include <limits>
#include <vector>
using namespace std;
#include "Movie.cpp"
#include "Seat.cpp"
#include "Screen.cpp"
#include "Cinema.cpp"
#include "ShowSeat.cpp"
#include "Show.cpp"
#include "Customer.cpp"
#include "Payment.cpp"
#include "PriceCalculator.cpp"
#include "Booking.cpp"
#include "TicketPrinter.cpp"
#include "BookingService.cpp"

int readInt(const string&msg){int x;while(true){cout<<msg;if(cin>>x)return x;cin.clear();cin.ignore(numeric_limits<streamsize>::max(),'\n');cout<<"Enter a valid number.\n";}}
int main(){
    Cinema cinema("City Cinema");cinema.addScreen(1);cinema.addScreen(2);
    cinema.addMovie(Movie("Skyline","Hindi",140));cinema.addMovie(Movie("The Last Mission","English",125));
    vector<Show> shows;
    shows.emplace_back(&cinema.getMovies()[0],&cinema.getScreens()[0],"06:30 PM");
    shows.emplace_back(&cinema.getMovies()[0],&cinema.getScreens()[1],"09:30 PM");
    shows.emplace_back(&cinema.getMovies()[1],&cinema.getScreens()[0],"09:00 PM");
    Customer customer("Neeraj","9999999999"); BookingService service;
    while(true){
        cout<<"\n===== MOVIE TICKET BOOKING =====\n1. List movies\n2. List shows\n3. Show seats\n4. Book ticket\n5. Cancel booking\n6. Exit\n";
        int ch=readInt("Enter choice: ");
        if(ch==1){for(size_t i=0;i<cinema.getMovies().size();++i)cout<<i+1<<". "<<cinema.getMovies()[i].getTitle()<<" | "<<cinema.getMovies()[i].getLanguage()<<" | "<<cinema.getMovies()[i].getDuration()<<" min\n";}
        else if(ch==2){for(size_t i=0;i<shows.size();++i)cout<<i+1<<". "<<shows[i].getMovie()->getTitle()<<" | Screen "<<shows[i].getScreen()->getScreenNumber()<<" | "<<shows[i].getStartTime()<<"\n";}
        else if(ch==3){int s=readInt("Show number: ");if(s<1||s>(int)shows.size()){cout<<"Invalid show.\n";continue;}shows[s-1].displaySeats();}
        else if(ch==4){
            int s=readInt("Show number: ");if(s<1||s>(int)shows.size()){cout<<"Invalid show.\n";continue;}shows[s-1].displaySeats();
            int count=readInt("Number of seats: ");if(count<1||count>12){cout<<"Invalid seat count.\n";continue;}
            vector<int>nums;for(int i=0;i<count;i++)nums.push_back(readInt("Seat number: "));
            int pm=readInt("Payment: 1-UPI  2-Card  3-Cash : ");Payment*p=nullptr;
            if(pm==1)p=new UpiPayment();else if(pm==2)p=new CardPayment();else if(pm==3)p=new CashPayment();else{cout<<"Invalid payment option.\n";continue;}
            service.createBooking(customer,shows[s-1],nums,*p);delete p;
        }
        else if(ch==5){service.cancelBooking(readInt("Booking ID: "));}
        else if(ch==6){cout<<"Thank you.\n";break;}
        else cout<<"Invalid menu choice.\n";
    }
}
