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

    char death[] = "Death";
    boardObj->searchFor(death);

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


Board *&Interface::setupBoard()
{
    
    boardObj = new Board;
    /*
    char * Safe = new char[(strlen("Safe")+1)];
    strcpy(Safe, "Safe");
    
    char * Death = new char[(strlen("Death")+1)];
    strcpy(Death, "Death");

    char * Chance = new char[(strlen("Chance")+1)];
    strcpy(Chance, "Chance");
*/
    char Safe[5] = "Safe";
    char Death[6] = "Death";
    char Chance[7] = "Chance";
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
{/*
    char * card1 = new char[(strlen("Card1")+1)];
    strcpy(card1, "card1");
    char * card2 = new char[(strlen("Card1")+1)];
    strcpy(card2, "card2");
    char * card3 = new char[(strlen("Card3")+1)];
    strcpy(card3, "card3");
*/
    char card1[6] = "card1";
    char card2[6] = "card2";
    char card3[6] = "card3";
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
    cardObj = setupCard();
    boardObj = setupBoard();
    Node * p1;
    Node * p2;
    p1 = boardObj->setPlayers(p1);
    p2 = boardObj->setPlayers(p2);
    gamePlay(p1, p2, boardObj, cardObj);
    
}

void Interface::gamePlay(Node * p1, Node * p2, Board * boardObj, Card cardObj)
{
    int value;
    Players play(1);
    int current = 2;
    bool done = false;
    while(!done)
    {
        if(current % 2 == 0)
        {
            cout << "--------------------------------" << endl;
            cout << "Player One Turn" << endl;
            cout << "--------------------------------" << endl;
            cout << endl;
            value = turnMenu(p1, p2, 0, play, cardObj);
            cout << value << endl;
            current++;
        }
        else
        {
            cout << "--------------------------------" << endl;
            cout << "Player Two Turn" << endl;
            cout << "--------------------------------" << endl;
            value = AIturnMenu(p2, p1, 1, play, cardObj);
            cout << endl;
            
            current++;
        }
        char play;
        if(value == 1)
        {
            done = true;
        }
    }

}

int Interface::AIturnMenu(Node *& temp, Node *& temp2, int player, Players & play, Card & c)
{
    int check;
    check = boardObj->checkWin(temp);
    if(check == 1)
    {
        return 1;
    }
    cout << "Player 2 is current at : " << endl;
    temp->displayNode();
    int dice = diceRoll();
    cout << "Player 2 has rolled a " << dice << endl;
    cout << "Player 2 will now move " << dice << " spaces. "<< endl;
    temp = boardObj->movement(temp, 1, dice);
    cout << "Player 2 is now at " << endl;
    temp->displayNode();
    if(temp == temp2)
    {
        cout << "Player 2 is in the same spot as player 1, player 2 loses" << endl;
        return 1;
    }
    else
        return 0;
}

int Interface::turnMenu(Node *& temp, Node *& temp2, int player, Players & play, Card & cardObj)   
{
    char option;
    int dices = 0;
    cout << "Current position on the board is : " << endl;
    temp->displayNode();
    cout << endl;
    bool done = false;
    while(!done)
    {
        cout << "A. Roll the dice to move on the board" << endl;
        cout << "B. Display your current possesions " << endl;
        cout << "C. Give up " << endl;
        cin.clear();
        option = cin.get();
        cin.ignore(256, '\n');
        switch(toupper(option))
        {
            case 'A':
                dices = diceRoll();
                cout << "You rolled a " << dices << endl;
                cout << "You will be now moved " << dices << " spaces " << endl;
                temp = boardObj->movement(temp, 0, dices);
                
                cout << "You are now at " << endl;
                temp->displayNode();
                cout << endl;
                if(strcmp(temp->getInfo(),"Chance")==0)
                {
                    Bnode * temp;
                    cout << "You landed on Chance, time to draw a card" << endl;
                    cout << "Drawing a card from the deck, you have just drawn : " << endl;
                    cout << cardObj.getCard(temp) << endl;
                    play.insert(0,1);
                }
                if(temp == temp2)
                {
                    cout << "Uh-oh, it looks like player 1 is in the same spot as player 2" << endl;
                    cout << "Player 1 loses " << endl;
                    return 1;
                }
                else
                    return 0;
                break;
            case 'B':
                cout<< "Here are all things in your possesion " << endl;
                play.displayPlayer(0);
                break;
            case 'C':
                cout << "You have given up " << endl;
                done = true;
                return 1;
                break;
            default:
                cout << "Not a valid option " << endl;
                break;
        }


}
}
