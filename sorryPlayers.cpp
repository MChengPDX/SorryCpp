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
    removeAll();
}


void Players::insert(int player, int value)
{
    pNode * temp = new pNode(value);
    int element = player;
    temp->getNext() = head[element];
    head[element] = temp;




}

void Players::displayAll()
{
    pNode * temp;
    for(int i = 0; i < 2; i++)
    {
        temp = head[i];
        while( temp!=NULL)
        {
            temp->displaypNode();
            temp=temp->getNext();
        }

    }
}

void Players::removeAll()
{
    for(int i = 0; i < 2; i++ )
    {
        removeAll(head[i]);
    }
    delete head;

}

void Players::removeAll(pNode *& head)
{
    if(!head)
        return;
    pNode * temp = head;
    head = head->getNext();
    delete temp;
    removeAll(head->getNext());
}
