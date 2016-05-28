#include<iostream>
#include<cstring>
#include<fstream>
#include<cstdlib>
#include"sorryBoard.h"
#include"sorryPlayers.h"
#include"sorryCard.h"
#include"string_mc.h"
class Interface
{
    private:
        Board * boardObj;

    public:
        void validationFunction();
        void setupBoard();
        void setupCard();
        void setupPlayer();
        int diceRoll();

};
