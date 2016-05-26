#include"sorryPlayers.h"
using namespace std;

pNode::pNode():next(NULL)
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

Players::Players(int size)
{
    size = 1;
    head = new pNode * [size];
    for(int i = 0; i < size; i++)
    {
        head[i] = NULL;
    }


}

Players::~Players()
{
}

void Players::determine(int player, int cardType)
{
    insert(head[player], cardType);
}


void Players::insert(pNode * head, int value)
{
    cout << "INSERT" << endl;
    pNode * temp = new pNode(value);

}

void Players::displayAll()
{
    for(int i = 0; i < 1; i++)
    {
        cout << "HELLO " << endl;

        displayAll(head[i]);
    }

}

void Players::displayAll(pNode * head)
{
    if(!head)
        return;
    head->displaypNode();
    displayAll(head->getNext());

}
