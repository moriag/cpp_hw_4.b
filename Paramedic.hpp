
#define ParamedicHealth 100
class Paramedic:public Soldier
{
private:
    /* data */
protected:
    Paramedic(int player,int health,std::string act):Soldier{player,health,act,player,2147483647}{}    
public:
    Paramedic(int player):Soldier{player,ParamedicHealth,"near",player,2147483647}{}
};
