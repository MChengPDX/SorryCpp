#include"sorryPlayers.h"

int main()
{
    Players p(1);
    p.determine(0,1);
    p.determine(0,2);
    p.determine(0,1);
    p.determine(0,534345);
    p.displayAll();
}
