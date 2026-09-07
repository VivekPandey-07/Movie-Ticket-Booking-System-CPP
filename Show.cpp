#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;
class Show {
    Movie* movie; Screen* screen; string startTime; vector<ShowSeat> showSeats;
public:
    Show(Movie*m,Screen*s,string time):movie(m),screen(s),startTime(time){for(auto&seat:s->getSeats())showSeats.emplace_back(&seat);}
    Movie* getMovie()const{return movie;} Screen* getScreen()const{return screen;} string getStartTime()const{return startTime;}
    vector<ShowSeat>& getShowSeats(){return showSeats;}
    void displaySeats()const{
        cout<<"\nScreen "<<screen->getScreenNumber()<<" | "<<startTime<<"\n";
        for(const auto&s:showSeats) cout<<"Seat "<<setw(2)<<s.getNumber()<<"  "<<(s.isAvailable()?"AVAILABLE":"BOOKED")<<"  "<<Seat::typeName(s.getSeat()->getType())<<" Rs."<<Seat::price(s.getSeat()->getType())<<"\n";
    }
};
