
#define SniperHealth 100
class Sniper: public Soldier{
private:
    /* data */
protected:
    Sniper(int player,int health,std::string act,int demge):Soldier{player,health,act,3-player,demge}{}
public:
    Sniper(int player):Soldier(player,SniperHealth,"strong",3-player,-50){}
};
