
#define FootSoldierHealth 100
class FootSoldier:public Soldier
{
private:
protected:
    FootSoldier(int player,int health,std::string act,int demge):Soldier{player,health,act,3-player,demge}{}
public:
    FootSoldier(int player):Soldier{player,FootSoldierHealth,"near",player,-10}{

    }
};
