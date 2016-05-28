#include<time.h>
#include"interface.h"
 using namespace std; 


int Interface::diceRoll()
{
    int dice = 0;
    srand(time(NULL));
    dice = rand() % 2+1;
    cout << dice << endl;
    return dice;

}

Board *&Interface::setupBoard()
{
    
    boardObj = new Board;
    char * test = "hello";

    fstream txt("board.txt");
    int a;
    while(txt >> a)
    {
        if(a == 0)
            boardObj -> insert(a, test);
        if(a == 1)
            boardObj -> insert(a, test);
        if(a == 2)
            boardObj -> insert(a, test);
        
    }
    return boardObj;

}

Card &Interface::setupCard()
{
    StringMC card1 = "card1";
    StringMC card2 = "card2";
    StringMC card3 = "card3";

    fstream txt("card.txt");
    int a;
    while(txt >> a)
    {
        cardObj.insert(a);
    }
    return cardObj;
}


void Interface::gameSetup()
{
    Card card;
    card = setupCard();
    /*
    Board * game = new Board;
    Card card;
    card = setupCard();
    game = setupBoard();
    Node * p1;
    Node * p2;
    p1 = game->setPlayers(p1);
    p2 = game->setPlayers(p2);
    gamePlay(p1, p2, game, card);
    */
}

void Interface::gamePlay(Node * p1, Node * p2, Board * boardObj, Card cardObj)
{

}
