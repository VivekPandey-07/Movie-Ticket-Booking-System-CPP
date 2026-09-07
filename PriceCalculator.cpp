#include <vector>
using namespace std;
class PriceCalculator {
public:
    double calculate(const vector<ShowSeat*>& seats)const{double total=0;for(auto*s:seats)total+=Seat::price(s->getSeat()->getType());return total;}
    double calculate(const ShowSeat* seat)const{return Seat::price(seat->getSeat()->getType());}
};
