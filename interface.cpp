#include<time.h>
#include"interface.h"
 using namespace std; 

void Interface::validationFunction()
{
    cout << "-----------------------------------------------------" << endl;
    cout << "Quick Validation of all data structures and functions" << endl;
    cout << "-----------------------------------------------------" << endl;
        
    cout << "***Testing Self Balancing Tree***" << endl << endl;
    cardObj = setupCard();
    cout << "Displaying Tree after loading all cards from a text file." << endl;
    cardObj.display_all();
    cout << "Display left and right side of the tree." << endl;
    cout << "Balance factor should not differ by more than 2." << endl;
    cardObj.test();
    cout << endl;

    cout << "***Testing Doubly Linked List***" << endl << endl;
    cout << "Displaying all board types after loading from a text file." << endl << endl;
    boardObj = new Board;
    boardObj = setupBoard();
    boardObj->displayAll();
    cout << "Searching for a occurance of a  specific type of board : Death " << endl << endl;

    boardObj->searchFor("Death");

    boardObj->removeAll();
    cout << "Displaying after remove all nodes of the board " << endl << endl;
    boardObj->displayAll();

    cout << "***Testing Array of Linked List for Players ***" << endl << endl;

    Players play(1);
    play.insert(0, 1);
    play.insert(0, 2);
    play.insert(0, 1);
    play.insert(1, 0);
    play.insert(1, 2);
    play.insert(1, 1);
    cout << "Displaying players and their cards. " << endl << endl;
    play.displayAll(); 
    cout << "Seaerching for player 2 and displaying all items that it has " << endl;
    play.displayPlayer(1);
    cout << "Displaying after removing everything " << endl;
    play.removeAll();
    play.displayAll();

}


int Interface::diceRoll()
{
    int dice = 0;
    srand(time(NULL));
    dice = rand() % 2+1;
    cout << dice << endl;
    return dice;

}

Players *&Interface::setupPlayer()
{


}

Board *&Interface::setupBoard()
{
    
    boardObj = new Board;
    char * Safe = "Safe";
    char * Death = "Death";
    char * Chance = "Chance";

    fstream txt("board.txt");
    int a;
    while(txt >> a)
    {
        if(a == 0)
            boardObj -> insert(a, Safe);
        if(a == 1)
            boardObj -> insert(a, Death);
        if(a == 2)
            boardObj -> insert(a, Chance);
        
    }
    return boardObj;

}

Card &Interface::setupCard()
{
    char * card1 = "Safe";
    char * card2 = "Death";
    char * card3 = "Hot Dogs";

    fstream txt("card.txt");
    int a;
    while(txt >> a)
    {
        if(a == 0)
            cardObj.insert(a, card1);
        if(a == 1)
            cardObj.insert(a, card2);
        if(a == 2)
            cardObj.insert(a, card3);
    }
    return cardObj;
}


void Interface::gameSetup()
{
    Card card;
    card = setupCard();
    card.display_all();
    card.test();
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
