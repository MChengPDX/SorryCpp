#include"sorryPlayers.h"
using namespace std;

pNode::pNode():next(NULL),cardType(0)
{
}

pNode::pNode(int value)
{
    cardType = value;
}

pNode*&pNode::getNext()
{
    return next;

}

void pNode::displaypNode()
{
    cout << "Card type : " << cardType << " " << endl;

}

Players::Players(int tableSize)
{
    int size = tableSize;
    head = new pNode * [size];
    for(int i = 0; i < size; i++)
    {
        head[i] = NULL;
    }


}

Players::~Players()
{
    /*pNode * temp;
    for(int i = 0; i <3; i++)
    {
        temp = head[i];
        while(temp->getNext() != NULL)
        {
            pNode * current = temp->getNext();
            delete temp;
            temp = current;

        }
    }
    */
    removeAll();
    delete [] head;
}


void Players::insert(int player, int value)
{
    pNode * temp = new pNode(value);
    int element = player;
    temp->getNext() = head[element];
    head[element] = temp;
    return;



}

void Players::displayAll()
{

    pNode * temp;
    for(int i = 0; i < 2; i++)
    {
        if(head[i] == NULL)
        {
            cout << "No players has been loaded" << endl;
            return;
        }
        cout << "Displaying all cards for player : " << i << endl;
        temp = head[i];
        while( temp!=NULL)
        {
            temp->displaypNode();
            temp=temp->getNext();
        }

    }
}

void Players::displayPlayer(int player)
{
    if(player >=2)
    {
        cout << "Can't find player" << endl;
        return;
    }
    pNode * temp = head[player];
    while(temp!=NULL)
    {
        temp->displaypNode();
        temp = temp->getNext();
    }
}

void Players::removeAll()
{

    for(int i = 0; i < 2; i++ )
    {
        if(head[i] == NULL)
            return;
        removeAll(head[i]);
    }

}

void Players::removeAll(pNode *& head)
{
    if(!head)
        return;
    pNode * temp = head;
    head = head->getNext();
    delete temp;
    removeAll(head);
}
