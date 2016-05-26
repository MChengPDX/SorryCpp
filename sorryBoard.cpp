#include"sorryBoard.h"
using namespace std;

/*
 * Class Implementation Start : Type
 *
 */

Type::Type():typeName(NULL)
{
}

Type::~Type()
{
    delete [] typeName;
    typeName = NULL;
}

Type::Type(const Type & from)
{
    typeName = new char [(strlen(from.typeName)+1)];
    strcpy(typeName, from.typeName);
}

Type::Type(char * name)
{
    typeName = new char [(strlen(name)+1)];
    strcpy(typeName, name);
}

void Type::display()
{
    cout << typeName << endl;
    cout << endl;

}

/*
 * Class Implementation End : Type
 *
 */

/*
 * Class Implemenation Start : Node
 *
 */

Node::Node():data(NULL),next(NULL),prev(NULL)
{
}

Node::Node(int type, char * name)
{
    setType(type, name);
}


Node::Node(const Node & from)
{
    data = from.data -> copy();
}

Node*&Node::getNext()
{
    return next;
}

Node*&Node::getPrev()
{
    return prev;
}

void Node::displayNode()
{
    data->display();

}

void Node::setNext(Node * temp)
{
    next = temp;
}

void Node::setType(int type, char * name)
{
    if(type == 0)
        data = new Safe(name);
    if(type == 1)
        data = new Death(name);
    if(type == 2)
        data = new Chance(name);

}


/* 
 * Class Implementation End : Node
 *
 */

/*
 * Class Implementation Start : Board
 * A douubly linked list implementation
 *
 */

Board::Board():head(NULL)
{
}

Board::~Board()
{
    removeAll();
}

void Board::insert(int data, char * name)
{
    Node * temp = new Node(data, name);
    if(!head)
    { 
        temp->getNext() = NULL;
        temp->getPrev() = NULL;
        head = temp;
    }
    else
    {
        temp->setNext(head);
        temp->getPrev() = NULL;
        head->getPrev() = temp;
        head = temp;
        return;


    }


}

void Board::removeAll()
{
    if(!head)
        return;
    Node * temp = head;
    while(temp != NULL)
    {
        head = head->getNext();
        delete temp;
        temp = head;
    }
    head = NULL;

}

void Board::displayAll()
{
    displayAll(head);
}

void Board::displayAll(Node * head)
{
    if(!head)
        return;
    head->displayNode();
    displayAll(head->getNext());
}

/*
 * Class Implementation End : Board
 *
 */


/*
 * Class Implementations Start : Dynamic Binding for Safe, Death and Chance
 *
 */


Safe::Safe()
{
}

Safe::Safe(const Safe & from)
{
    typeName = new char [(strlen(from.typeName)+1)];
    strcpy(typeName, from.typeName);
}
Safe::Safe(char * name)
{
    typeName = new char [(strlen(name)+1)];
    strcpy(typeName, name);
}

void Safe::display()
{
    cout << "Board Type : Safe" << endl;
    cout << endl;
}

Type * Safe::copy()
{
    return new Safe(*this);
}

//
//

Chance::Chance()
{
}

Chance::Chance(const Chance & from)
{
    typeName = new char [(strlen(from.typeName)+1)];
    strcpy(typeName, from.typeName);
}

Chance::Chance(char * name)
{
    typeName = new char [(strlen(name)+1)];
    strcpy(typeName, name);
}

void Chance::display()
{
    cout << "Board Type : Chance " << endl;
    cout << endl;
}

Type * Chance::copy()
{
    return new Chance(*this);
}


Death::Death()
{
}

Death::Death(const Death & from)
{
    typeName = new char [(strlen(from.typeName)+1)];
    strcpy(typeName, from.typeName);
}

Death::Death(char * name)
{
    typeName = new char [(strlen(name)+1)];
    strcpy(typeName, name);
}

void Death::display()
{
    cout << "Board Type : Death "  << endl;
    cout << endl;
}



Type * Death::copy()
{
    return new Death(*this);
}
