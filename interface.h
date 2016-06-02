#include<iostream>
#include<cstring>
#include<fstream>
#include<cstdlib>
#include"sorryBoard.h"
#include"sorryPlayers.h"
#include"sorryCard.h"
class Interface
{
    private:
        Board * boardObj;
        Card cardObj;
    public:
        void validationFunction();

        Board *& setupBoard();
        Card &setupCard();     
        int diceRoll();
        void setPlayerOnBoard();
        void gameSetup();
        void gamePlay(Node * p1, Node * p2, Board * boardObj, Card obj);
        int turnMenu(Node *& temp, Node *& temp2, int player, Players & play, Card & cardObj);
        int AIturnMenu(Node *&, Node *&, int, Players & play, Card &);

};

