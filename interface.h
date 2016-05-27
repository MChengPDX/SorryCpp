#include<iostream>
#include<cstring>
#include<fstream>
#include"sorryBoard.h"
#include"sorryPlayers.h"
#include"sorryCard.h"

class Interface
{

    public:
        void setupBoard();
        void setupCard();
        void setupPlayer();
        int diceRoll();

};
