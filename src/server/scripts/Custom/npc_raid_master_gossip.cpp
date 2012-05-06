#include "ScriptPCH.h"

enum Events
{
        RAID_EVENT_BLACKWING_LAIR        = 104,
        RAID_EVENT_THE_EYE               = 105,
        RAID_EVENT_BLACK_TEMPLE          = 106,
        RAID_EVENT_ONYXIAS_LAIR 	     = 107,
        RAID_EVENT_VAULT_OF_ARCHAVON     = 108,
        RAID_EVENT_ICECROWN_CITADEL      = 109,
        RAID_EVENT_TRIAL_OF_THE_CRUSADER = 110
};

class npc_raid_master_gossip : public CreatureScript
{
    public:
        npc_raid_master_gossip(): CreatureScript("npc_raid_master_gossip"){}

        bool OnGossipHello(Player* pPlayer, Creature* pCreature)
        {
            if (pPlayer->isInCombat())
            {
                pPlayer->CLOSE_GOSSIP_MENU();
                pCreature->MonsterWhisper("You are in combat!", pPlayer->GetGUID());
                return true;
            }

            if (pPlayer->getLevel() != 80)
            {
                pPlayer->CLOSE_GOSSIP_MENU();
                pCreature->MonsterWhisper("You must be level 80!", pPlayer->GetGUID());
                return true;
            }

            else
            {
                    pPlayer->PrepareQuestMenu(pCreature->GetGUID());
                    pPlayer->SendPreparedQuest(pCreature->GetGUID());
                        if (sGameEventMgr->IsActiveEvent(RAID_EVENT_BLACKWING_LAIR))
                    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_OPTION_QUESTGIVER, "Warp me to Blackwing Lair", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
                        if (sGameEventMgr->IsActiveEvent(RAID_EVENT_THE_EYE))
                    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_OPTION_QUESTGIVER, "Warp me to Tempest Keep: The Eye", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
                        if (sGameEventMgr->IsActiveEvent(RAID_EVENT_BLACK_TEMPLE))
                    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_OPTION_QUESTGIVER, "Warp me to Black Temple", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
                        if (sGameEventMgr->IsActiveEvent(RAID_EVENT_ONYXIAS_LAIR))
                    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_OPTION_QUESTGIVER, "Warp me to Onyxia's Lair", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+3);
                        if (sGameEventMgr->IsActiveEvent(RAID_EVENT_VAULT_OF_ARCHAVON))
                    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_OPTION_QUESTGIVER, "Warp me to Vault of Archavon", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+4);
                        if (sGameEventMgr->IsActiveEvent(RAID_EVENT_ICECROWN_CITADEL))
                    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_OPTION_QUESTGIVER, "Warp me to Icecrown Citadel", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+5);
                        if (sGameEventMgr->IsActiveEvent(RAID_EVENT_TRIAL_OF_THE_CRUSADER))
                    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_OPTION_QUESTGIVER, "Warp me to Trial of the Crusader", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+6);
                    pPlayer->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, pCreature->GetGUID());
                    return true;
            }
        }

        bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 sender, uint32 uiAction)
        {
            pPlayer->PlayerTalkClass->ClearMenus();

            switch(uiAction)
            {

                case GOSSIP_ACTION_INFO_DEF:
                    pPlayer->TeleportTo(229, 161.30f, -474.97f, 116.84f, 6.27f);
                    pPlayer->CLOSE_GOSSIP_MENU();
                break;

                case GOSSIP_ACTION_INFO_DEF+1:
                    pPlayer->TeleportTo(530, 3088.19f, 1379.46f, 184.91f, 4.61f);
                    pPlayer->CLOSE_GOSSIP_MENU();
                break;

                 case GOSSIP_ACTION_INFO_DEF+2:
                    pPlayer->TeleportTo(530, -3647.81f, 316.23f, 35.27f, 2.89f);
                    pPlayer->CLOSE_GOSSIP_MENU();
                 break;

                case GOSSIP_ACTION_INFO_DEF+3:
                    pPlayer->TeleportTo(1, -4738.80f, -3751.05f, 52.41f, 3.20f);
                    pPlayer->CLOSE_GOSSIP_MENU();
                break;

                case GOSSIP_ACTION_INFO_DEF+4:
                    pPlayer->TeleportTo(571, 5472.83f, 2840.80f, 418.68f, 6.18f);
                    pPlayer->CLOSE_GOSSIP_MENU();
                break;

                case GOSSIP_ACTION_INFO_DEF+5:
                    pPlayer->TeleportTo(571, 5873.82f, 2110.98f, 636.01f, 3.55f);
                    pPlayer->CLOSE_GOSSIP_MENU();
                break;

                case GOSSIP_ACTION_INFO_DEF+6:
                    pPlayer->TeleportTo(571, 8515.88f, 629.25f, 547.39f, 1.57f);
                    pPlayer->CLOSE_GOSSIP_MENU();
                break;

                default:
                break;
            }
            return true;
        }
};

void AddSC_npc_raid_master_gossip()
{
    new npc_raid_master_gossip();
}