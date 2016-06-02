#include<iostream>
#include<cstring>

/*
 * Class : Type
 * An abstract base class that three different spot types
 * on the board will be derived from. 
 * -SafeZone
 * -ChanceZone
 * -DeathZone
 *
 * To simulate the board type, it will be implemented with a doubly linked list.
 * Each node will be determine through late binding, pattern will be 2 nodes
 * per safe zone, 1 node per death, 1 node per chance and follow that will
 * be 2 more node for safe.
 *
 */
class Type
{
    protected:
        char * typeName; 
        virtual ~Type();
    public:
        Type();
        Type(char * typeName);
        Type(const Type & );
        virtual Type * copy() = 0;
        virtual void display();
        char * getName();

};

class Node
{
    private:
        Type * data;
        Node * next;
        Node * prev;

    public:
        Node();
        Node(int , char *);
        Node(const Node &);
        Node *& getNext();
        Node *& getPrev();
        void setNext(Node *);
        Type *& returnType();
        void displayNode();
        void setType(int, char *);
        char *getInfo();
        
};

/*
 * Class : Board
 * Class abstraction of a board through the usage of a doubly linked list.
 * Douly linked list allows for back and forth movement.
 */

class Board
{
    private:
        Node * head;
    public:
        Board();
        ~Board();
        void insert(int, char *);
        void removeAll();
        void displayAll();
        void displayAll(Node * head);
        void searchFor(char * c);
        void searchFor(Node * head, char * value);
        Node *& movement(Node *&current,int player, int move);
        Node*&setPlayers(Node *& temp);
        char * getInfo(Node * head);
        int checkWin(Node * temp); 

};

class Safe : public Type
{
    public:
        Safe();
        Safe(const Safe &);
        Safe(char * typeName);
        void display();
        Type * copy();

};

class Chance : public  Type
{
     public:
        Chance();
        Chance(const Chance &);
        Chance(char * typeName);
        void display();
        Type * copy();

};

class Death : public Type
{
     public:
        Death();
        Death(const Death &);
        Death(char * typeName);
        void display();
        Type * copy();

};
