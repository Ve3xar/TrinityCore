#include "ScriptPCH.h"

enum Cards
{
    FIRE_CARD_1 = 70001,
    FIRE_CARD_2 = 70002,
    FIRE_CARD_3 = 70003,
    FIRE_CARD_4 = 70004,
    FIRE_CARD_5 = 70005,
    FIRE_CARD_6 = 70006,
    FIRE_CARD_7 = 70007,
    FIRE_CARD_8 = 70008,
    FIRE_CARD_9 = 70009,
    MINOR_DECK  = 70010,
    MEDIUM_DECK = 70011,
    MAJOR_DECK  = 70012
};

class npc_card_master_gossip : public CreatureScript
{
    public:
                npc_card_master_gossip(): CreatureScript("npc_card_master_gossip"){}

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
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_OPTION_QUESTGIVER, "Quests", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Combine my Fire Cards into a Deck", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_GOODS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Tell me more about Fire Decks", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+3);
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
                    pPlayer->PrepareQuestMenu(pCreature->GetGUID());
                    pPlayer->SendPreparedQuest(pCreature->GetGUID());
                break;

                case GOSSIP_ACTION_INFO_DEF+1:
                    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Create Minor Fire Deck", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+4);
                    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Create Medium Fire Deck", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+5);
                    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Create Major Fire Deck", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+6);
                    pPlayer->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, pCreature->GetGUID());
                break;

                case GOSSIP_ACTION_INFO_DEF+2://Advance Professions
                    pPlayer->GetSession()->SendListInventory(pCreature->GetGUID());
                break;

                case GOSSIP_ACTION_INFO_DEF+3:
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pCreature->MonsterWhisper("There are three types of deck that can be created with cards of Fire. Minor deck which consists 'Ace through Three of Fire', medium deck which consists of 'Ace through Six of Fire' and major deck which consists of 'Ace through Nine of Fire'", pPlayer->GetGUID());
                    pCreature->MonsterWhisper("Cards can be found in the different Icecrown Heroic Dungeons or Raids. Once you collect a specific amount of cards talk to me in order to combine them into a deck.", pPlayer->GetGUID());
                    pCreature->MonsterWhisper("Once you complete a deck, I will reward your efforts with appropriate reward.", pPlayer->GetGUID());
                break;

                        case GOSSIP_ACTION_INFO_DEF+4://Minor Deck
                    pPlayer->CLOSE_GOSSIP_MENU();
                    if (pPlayer->HasItemCount(FIRE_CARD_1,1) && pPlayer->HasItemCount(FIRE_CARD_2,1) && pPlayer->HasItemCount(FIRE_CARD_3,1))
                    {
                        pPlayer->DestroyItemCount(FIRE_CARD_1, 1, true);
                        pPlayer->DestroyItemCount(FIRE_CARD_2, 1, true);
                        pPlayer->DestroyItemCount(FIRE_CARD_3, 1, true);
                        pPlayer->StoreNewItemInBestSlots(MINOR_DECK, 1);
                        pCreature->MonsterWhisper("Minor Deck has been added to your inventory, use it wisely.", pPlayer->GetGUID());
                    }
                    else
                    {
                        pCreature->MonsterWhisper("You don't have the right cards in your inventory.", pPlayer->GetGUID());
                    }
                break;

                case GOSSIP_ACTION_INFO_DEF+5://Medium Deck
                    pPlayer->CLOSE_GOSSIP_MENU();
                    if (pPlayer->HasItemCount(FIRE_CARD_1,1) && pPlayer->HasItemCount(FIRE_CARD_2,1) && pPlayer->HasItemCount(FIRE_CARD_3,1) && pPlayer->HasItemCount(FIRE_CARD_4,1) &&
                    pPlayer->HasItemCount(FIRE_CARD_5,1) && pPlayer->HasItemCount(FIRE_CARD_6,1))
                    {
                        pPlayer->DestroyItemCount(FIRE_CARD_1, 1, true);
                        pPlayer->DestroyItemCount(FIRE_CARD_2, 1, true);
                        pPlayer->DestroyItemCount(FIRE_CARD_3, 1, true);
                        pPlayer->DestroyItemCount(FIRE_CARD_4, 1, true);
                        pPlayer->DestroyItemCount(FIRE_CARD_5, 1, true);
                        pPlayer->DestroyItemCount(FIRE_CARD_6, 1, true);
                        pPlayer->StoreNewItemInBestSlots(MEDIUM_DECK, 1);
                        pCreature->MonsterWhisper("Medium Deck has been added to your inventory, use it wisely.", pPlayer->GetGUID());
                    }
                    else
                    {
                        pCreature->MonsterWhisper("You don't have the right cards in your inventory.", pPlayer->GetGUID());
                    }
                break;

                case GOSSIP_ACTION_INFO_DEF+6://Major Deck
                    pPlayer->CLOSE_GOSSIP_MENU();
                    if (pPlayer->HasItemCount(FIRE_CARD_1,1) && pPlayer->HasItemCount(FIRE_CARD_2,1) && pPlayer->HasItemCount(FIRE_CARD_3,1) && pPlayer->HasItemCount(FIRE_CARD_4,1) &&
                    pPlayer->HasItemCount(FIRE_CARD_5,1) && pPlayer->HasItemCount(FIRE_CARD_6,1) && pPlayer->HasItemCount(FIRE_CARD_7,1) && pPlayer->HasItemCount(FIRE_CARD_8,1) &&
                    pPlayer->HasItemCount(FIRE_CARD_9,1))
                    {
                        pPlayer->DestroyItemCount(FIRE_CARD_1, 1, true);
                        pPlayer->DestroyItemCount(FIRE_CARD_2, 1, true);
                        pPlayer->DestroyItemCount(FIRE_CARD_3, 1, true);
                        pPlayer->DestroyItemCount(FIRE_CARD_4, 1, true);
                        pPlayer->DestroyItemCount(FIRE_CARD_5, 1, true);
                        pPlayer->DestroyItemCount(FIRE_CARD_6, 1, true);
                        pPlayer->DestroyItemCount(FIRE_CARD_7, 1, true);
                        pPlayer->DestroyItemCount(FIRE_CARD_8, 1, true);
                        pPlayer->DestroyItemCount(FIRE_CARD_9, 1, true);
                        pPlayer->StoreNewItemInBestSlots(MAJOR_DECK, 1);
                        pCreature->MonsterWhisper("Major Deck has been added to your inventory, use it wisely.", pPlayer->GetGUID());
                    }
                    else
                    {
                        pCreature->MonsterWhisper("You don't have the right cards in your inventory.", pPlayer->GetGUID());
                    }
                break;


                default:
                break;
            }
            return true;
        }
};

void AddSC_npc_card_master_gossip()
{
    new npc_card_master_gossip();
}