#include <math.h>
class Soldier
{
public:
    int player;
    int health;
    int max_helth;
    int demge;
    int target;
    std::string act;

     Soldier(int player,int health,std::string act,int target,int demge):player(player),health(health),act(act),target(target),demge(demge){}
    int get_player(){
        return player;
    }
};

