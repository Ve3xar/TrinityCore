#include "ScriptPCH.h"

class go_dalaran : public GameObjectScript
{
    public:
        go_dalaran() : GameObjectScript("go_dalaran") {}

        bool OnGossipHello(Player* pPlayer, GameObject* pGo)
        {
            if (pPlayer->isInCombat())
            {
                pGo->MonsterWhisper("You can't do this in combat!", pPlayer->GetGUID());
                return true;
            }
            else
            {
                pPlayer->TeleportTo(571, 5804.150f, 624.771f, 647.767f, 1.640f);
                return true;
            }
        }
};

class go_shattrath : public GameObjectScript
{
    public:
        go_shattrath() : GameObjectScript("go_shattrath") {}

        bool OnGossipHello(Player* pPlayer, GameObject* pGo)
        {
            if (pPlayer->isInCombat())
            {
                std::stringstream msg;
                msg << "You can't do this in combat!";
                return true;
            }
            else
            {
                pPlayer->TeleportTo(530, -1838.160f, 5301.790f, -12.428f, 5.952f);
                return true;
            }
        }
};

void AddSC_go_portals()
{
    new go_dalaran();
    new go_shattrath();
}