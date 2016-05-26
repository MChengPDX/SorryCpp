#include"sorryPlayers.h"
#include"sorryCard.h"

int main()
{
    Players p(1);
    p.insert(0, 1);
    p.insert(0, 2);
    p.insert(0, 4);
    p.insert(1, 231);
    p.displayAll();

    Card c;
    c.insert(23);
    c.insert(34);
    c.insert(2);
    c.insert(234234);
    c.display_all();
}
