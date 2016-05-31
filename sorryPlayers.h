#include<iostream>
#include<cstring>


class pNode
{
    private:
        pNode * next;
        int cardType;

    public:
        pNode();
        pNode(int);
        pNode *& getNext();
        void displaypNode();

};

class Players
{
    private:
        pNode ** head;

    public:
        Players(int size);
        ~Players();
        void removeAll();
        void removeAll(pNode *& head);
        void displayAll();
        void displayAll(pNode * head);
        void insert(int player, int value);
        void displayPlayer(int player);

};
