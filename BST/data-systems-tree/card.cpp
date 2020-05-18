#include <string>
#include "card.h"

card::card()
{
    number = NULL;
    color = NULL;
    suit = NULL;
}

card::card(int num, short int suit)
{
    number = num;
    this -> suit = suit;
    color = suit%2;
}

card::card(card &rhs)
{
    number = rhs.number;
    suit = rhs.suit;
    color = rhs.color;
}

bool card::getColor()
{
    return color;
}

short int card::getNumber()
{
    return number;
}

short int card::getSuit()
{
    return suit;
}

void card::setSuit(short int suit)
{
    this -> suit = suit;
    color = suit%2;
}

void card::setNumber(short int number)
{
    this -> number = number;
}

std::string card::getCardSmart()
{
//TODO: jack
}

std::string card::getCardDumb()
{
//TODO: n8
}

bool card::operator==(card &rhs)
{
    return ((number == rhs.number) && (suit == rhs.suit));
}

bool card::operator>(card &rhs)
{
    return ((number > rhs.number) && (color != rhs.color));
}

bool card::operator<(card &rhs)
{
    return (number < rhs.number);
}

bool card::operator>=(card &rhs)
{
    
}

bool card::operator<=(card &rhs)
{
    
}

bool card::operator!=(card &rhs)
{
    
}

card& card::operator=(card &rhs)
{
    
}