
#define ParamedicCommandrHealth 200
class ParamedicCommander:public Paramedic
{
private:
    /* data */
public:
    ParamedicCommander(int player):Paramedic{player,ParamedicCommandrHealth,"cnear"}{};
};
