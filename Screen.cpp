#include <vector>
using namespace std;
class Screen {
    int screenNumber; vector<Seat> seats;
public:
    Screen(int screenNumber,int count=12):screenNumber(screenNumber){
        for(int i=1;i<=count;i++){Seat::Type t=i<=4?Seat::Type::SILVER:(i<=8?Seat::Type::GOLD:Seat::Type::PLATINUM);seats.emplace_back(i,t);}
    }
    int getScreenNumber()const{return screenNumber;} vector<Seat>& getSeats(){return seats;} const vector<Seat>& getSeats()const{return seats;}
};
