
#include "map.h"
#include "game.h"
#include "Square.h"

int main()
{
    Game caro;
    //caro.gameLoad();
    
    Matrix a(3, 3);

    Square oVuong;

    caro.gameStart(a, oVuong);

    caro.gameCheckWinner(a);

}

