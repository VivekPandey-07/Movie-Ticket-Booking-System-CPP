#include <string>
using namespace std;
class Seat {
public: enum class Type{SILVER,GOLD,PLATINUM};
private: int number; Type type;
public:
    Seat(int number,Type type):number(number),type(type){}
    int getNumber()const{return number;} Type getType()const{return type;}
    static int price(Type type){ if(type==Type::SILVER)return 150; if(type==Type::GOLD)return 250; return 400; }
    static string typeName(Type type){if(type==Type::SILVER)return "SILVER";if(type==Type::GOLD)return "GOLD";return "PLATINUM";}
};
