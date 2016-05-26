#include"manager.h"
using namespace std;

void manager::test_dll()
{
    boardList = new Board;
    char test[] = "asdfsa";
    int z = 1;
    boardList->insert(2, test);
    boardList->insert(1, test);
    boardList->insert(0, test);
    boardList->displayAll();
}



