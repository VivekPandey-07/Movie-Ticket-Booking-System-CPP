class ShowSeat {
    Seat* seat; bool booked=false;
public:
    ShowSeat(Seat* seat):seat(seat){}
    int getNumber()const{return seat->getNumber();} Seat* getSeat()const{return seat;}
    bool isAvailable()const{return !booked;}
    bool book(){if(booked)return false;booked=true;return true;} void release(){booked=false;}
};
