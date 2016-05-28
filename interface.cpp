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

void Interface::setupBoard()
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
        
        cout << a << endl;
    }
    boardObj->displayAll();
    return; 

}
