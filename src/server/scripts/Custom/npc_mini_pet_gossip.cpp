#include "ScriptPCH.h"

enum Quests
{
    QUEST_STARTING       = 70000,
    QUEST_TO_AZEROTH     = 80003,
    QUEST_TO_OUTLANDS    = 80004,
    QUEST_TO_NORTHREND   = 80005,
    QUEST_TO_CUSTOM_TOWN = 80006,
};

//Custom Function to check if player has completed all required quests.
bool GetRequiredQuestStatus(Player* player)
{
    if (player->GetQuestStatus(QUEST_TO_AZEROTH) == QUEST_STATUS_REWARDED || player->GetQuestStatus(QUEST_TO_OUTLANDS) == QUEST_STATUS_REWARDED || 
        player->GetQuestStatus(QUEST_TO_NORTHREND) == QUEST_STATUS_REWARDED || player->GetQuestStatus(QUEST_TO_CUSTOM_TOWN) == QUEST_STATUS_REWARDED)
        return true;
    else
        return false;
}

class npc_mini_pet_gossip : public CreatureScript
{
    public:
        npc_mini_pet_gossip(): CreatureScript("npc_mini_pet_gossip"){}

        bool OnGossipHello(Player* player, Creature* pCreature)
        {
            if (player->isInCombat())
            {
                player->CLOSE_GOSSIP_MENU();
                pCreature->MonsterWhisper("You are in combat!", player->GetGUID());
                return false;
            }
                else
                {
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Train me my Class Spells" , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Reset my Talents" , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_GOODS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);                    
                    if (GetRequiredQuestStatus(player) || player->getLevel() == 80)
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Take me to Custom Town", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+15);
                    player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, pCreature->GetGUID());
                    return true;
                }
        }

        bool OnGossipSelect(Player* player, Creature* pCreature, uint32 sender, uint32 uiAction)
        {
            player->PlayerTalkClass->ClearMenus();

            switch(uiAction)
            {
                case GOSSIP_ACTION_INFO_DEF:
                    switch (player->getClass())
                    {
                        case CLASS_DEATH_KNIGHT:
                            if (player->getLevel() >= 55)
                            {
                                player->learnSpell(48778, false);
                                player->learnSpell(53428, false);
                                player->learnSpell(50977, false);
                                player->learnSpell(48743, false);
                            }
                            if (player->getLevel() >= 61)
                            {
                                player->learnSpell(3714, false);
                            }
                            if (player->getLevel() >= 65)
                            {
                                player->learnSpell(57330, false);
                            }
                            if (player->getLevel() >= 67)
                            {
                                player->learnSpell(56815, false);
                            }
                            break;

                        case CLASS_WARLOCK:
                            if (player->getLevel() >= 20)
                            {
                                player->learnSpell(5784, false);
                            }
                            if (player->getLevel() >= 40)
                            {
                                player->learnSpell(23161, false);
                            }
                            break;

                        case CLASS_PALADIN:
                            if (player->getFaction() == ALLIANCE)
                            {
                                if (player->getLevel() >= 20)
                                {
                                    player->learnSpell(13819, false);
                                }
                                if (player->getLevel() >= 40)
                                {
                                    player->learnSpell(23214, false);
                                }
                            }
                            if (player->getFaction() == HORDE)
                            {
                                if (player->getLevel() >= 20)
                                {
                                    player->learnSpell(34769, false);
                                }
                                if (player->getLevel() >= 40)
                                {
                                    player->learnSpell(34767, false);
                                }
                            }
                            break;

                        case CLASS_DRUID:
                            if(player->getLevel() >= 60)
                            {
                                player->learnSpell(33943, false);
                            }
                            if(player->getLevel() >= 71)
                            {
                                player->learnSpell(40120, false);
                            }
                            break;

                        default:
                            break;
                    }
                    player->GetSession()->SendTrainerList(pCreature->GetGUID());
                    break;

                case GOSSIP_ACTION_INFO_DEF+1:
                    player->SendTalentWipeConfirm(pCreature->GetGUID());
                    player->CLOSE_GOSSIP_MENU();
                    break;

                case GOSSIP_ACTION_INFO_DEF+2:
                    player->GetSession()->SendListInventory(pCreature->GetGUID());
                    break;

                case GOSSIP_ACTION_INFO_DEF+15:
                    player->TeleportTo(1, -9456.155f, 1643.156f, 19.301f, 2.832f);
                    player->CLOSE_GOSSIP_MENU();
                    break;

                case GOSSIP_ACTION_INFO_DEF+16:
                    player->GiveLevel(80);
                    player->CLOSE_GOSSIP_MENU();
                    break;

                default:
                    break;
            }
            return true;
        }
};

void AddSC_npc_mini_pet_gossip()
{
    new npc_mini_pet_gossip();
}