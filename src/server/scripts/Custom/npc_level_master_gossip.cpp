#include "ScriptPCH.h"

enum Quests
{
    QUEST_WELCOME = 80000
};

class npc_level_master_gossip : public CreatureScript
{
    public:
        npc_level_master_gossip(): CreatureScript("npc_level_master_gossip"){}

        bool OnGossipHello(Player* pPlayer, Creature* pCreature)
        {
            if (pPlayer->isInCombat())
            {
                pPlayer->CLOSE_GOSSIP_MENU();
                pCreature->MonsterWhisper("You are in combat!", pPlayer->GetGUID());
                return false;
            }
            else
            {
                pPlayer->PrepareQuestMenu(pCreature->GetGUID());
                pPlayer->SendPreparedQuest(pCreature->GetGUID());
                if ((pPlayer->GetQuestStatus(QUEST_WELCOME) == QUEST_STATUS_REWARDED) && (!pPlayer->HasAura(48756)))
                {
                    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Would you like to be leveled up to the level of your choice?", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);                    
                }
                pPlayer->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, pCreature->GetGUID());
                return true;
            }
        }

        //This function is called when the player clicks an option on the gossip menubool
        bool OnGossipSelect(Player *pPlayer, Creature *pCreature, uint32 uiSender, uint32 uiAction )
        {
            switch(uiAction)
            {
                case GOSSIP_ACTION_INFO_DEF:
                    pPlayer->ADD_GOSSIP_ITEM_EXTENDED(GOSSIP_ICON_CHAT, " - Yes, please", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1, "", 0, true);
                    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, " - No, thanks", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
                    pPlayer->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, pCreature->GetGUID());
                    break;

                case GOSSIP_ACTION_INFO_DEF+2:
                    pPlayer->CastSpell(pPlayer, 48756, true);
                    pPlayer->CLOSE_GOSSIP_MENU();
                    break;
            }
            return true;
        }

        bool OnGossipSelectCode(Player * pPlayer, Creature * pCreature, uint32 uiSender, uint32 uiAction, const char * sCode )
        {
            pPlayer->PlayerTalkClass->ClearMenus();
            if (uiSender == GOSSIP_SENDER_MAIN)
            {
                switch (uiAction)
                {
                    case GOSSIP_ACTION_INFO_DEF+1:
                        int level = atoi(sCode);
                        if ((level >= 2 && level <= 80) && (pPlayer->getLevel() < level))
                        {
                            pPlayer->GiveLevel(level);
                            pPlayer->CastSpell(pPlayer, 48756, true);
                            pPlayer->CLOSE_GOSSIP_MENU();
                        }
                        else
                        {
                            pCreature->MonsterWhisper("The value must be between 2-80 and greater then your current level", pPlayer->GetGUID());
                            pPlayer->CLOSE_GOSSIP_MENU();
                        }
                        return true;
                        break;
                }
            }
            return false;
        }
};

void AddSC_npc_level_master_gossip()
{
    new npc_level_master_gossip();
}