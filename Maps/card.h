#include <string>
class card
{
    private:
        short int number;
        bool color; //0 red, 1 black //might just get rid of this
        short int suit; //0 heart, 1 club, 2 diamond, 3 spade

    public:
        card();
        card(int number, short int suit);
        card(card &rhs);
        ~card();

        bool getColor();
        short int getSuit();
        short int getNumber();

        void setSuit(short int suit); //also sets color
        void setNumber(short int number);
        std::string getCardSmart(); //"mac and linux"
        std::string getCardDumb(); //"windows"
        bool operator == (card &rhs);
        bool operator > (card &rhs);
        bool operator < (card &rhs);
        bool operator >= (card &rhs);
        bool operator <= (card &rhs);
        bool operator != (card &rhs);

        card& operator = (card &rhs);     

};