#include "ScriptPCH.h"

enum cost
{
    ILLUSION_COST = 500000, //50 gold
    ILLUSION_SPECIAL_COST = 1000000 //100 gold
};

class npc_illusionist_gossip : public CreatureScript
{
    public:
        npc_illusionist_gossip(): CreatureScript("npc_illusionist_gossip"){}

        bool OnGossipHello(Player* player, Creature* creature)
        {
            if (player->isInCombat())
            {
                player->CLOSE_GOSSIP_MENU();
                creature->MonsterWhisper("You are in combat!", player->GetGUID());
                return false;
            }
            else
            {
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Alliance Illusions", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Horde Illusions", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Special Illusions", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
                player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
                return true;
            }
        }

        bool IsShapeshifted(Player* player)
        {
            if (player->HasAura(5487, player->GetGUID()) || player->HasAura(9634, player->GetGUID()) || player->HasAura(768, player->GetGUID()) || player->HasAura(24858, player->GetGUID()) ||
            player->HasAura(33891, player->GetGUID()) || player->HasAura(1066, player->GetGUID()) || player->HasAura(783, player->GetGUID()) || player->HasAura(33943, player->GetGUID()) ||
            player->HasAura(40120, player->GetGUID()))
                return true;
            else
                return false;
        }

        bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 uiAction)
        {
            switch(uiAction)
            {
                case GOSSIP_ACTION_INFO_DEF:
                    if (player->GetTeam() == HORDE && player->GetSession()->GetSecurity() != SEC_MODERATOR )
                    {
                        creature->MonsterWhisper("You must be VIP in order to recieve opposite faction illusions", player->GetGUID());
                        player->CLOSE_GOSSIP_MENU();
                    }
                    else
                    {
                        player->PlayerTalkClass->ClearMenus();
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Human Male Illusion :: 50 gold", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+6);
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Human Female Illusion :: 50 gold", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+7);
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Gnome Male Illusion :: 50 gold", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+8);
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Gnome Female Illusion :: 50 gold", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+9);
                        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
                    }
                    break;

                case GOSSIP_ACTION_INFO_DEF+1:
                    if (player->GetTeam() == ALLIANCE && player->GetSession()->GetSecurity() != SEC_MODERATOR )
                    {
                        creature->MonsterWhisper("You must be VIP in order to recieve opposite faction illusions", player->GetGUID());
                        player->CLOSE_GOSSIP_MENU();
                    }
                    else
                    {
                        player->PlayerTalkClass->ClearMenus();
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Tauren Male Illusion :: 50 gold", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+10);
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Tauren Female Illusion :: 50 gold", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+11);
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Blood Elf Male Illusion :: 50 gold", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+12);
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Blood Elf Female Illusion :: 50 gold", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+13);
                        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
                    }
                    break;

               case GOSSIP_ACTION_INFO_DEF+2:
                        player->PlayerTalkClass->ClearMenus();
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Leeper Gnome Illusion :: 100 gold", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+14);
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Pirate Illusion :: 100 gold", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+15);
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Ninja Illusion :: 100 gold", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+16);
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Skeleton Illusion :: 100 gold", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+17);
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Ghost Illusion :: 100 gold", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+18);
                        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
                    break;

                case GOSSIP_ACTION_INFO_DEF+6:
                    if (IsShapeshifted(player))
                    {
                        creature->MonsterWhisper("You can't do this while shapeshifted.", player->GetGUID());
                        player->CLOSE_GOSSIP_MENU();
                    }
                    if (player->HasEnoughMoney(ILLUSION_COST))
                    {
                        player->CastSpell(player, 35466, true);
                        player->ModifyMoney(-ILLUSION_COST);
                        player->CLOSE_GOSSIP_MENU();
                    }
                    else
                    {
                        creature->MonsterWhisper("You don't have enough money to receive an illusion", player->GetGUID());
                        player->CLOSE_GOSSIP_MENU();
                    }
                    break;

                case GOSSIP_ACTION_INFO_DEF+7:
                    if (IsShapeshifted(player))
                    {
                        creature->MonsterWhisper("You can't do this while shapeshifted.", player->GetGUID());
                        player->CLOSE_GOSSIP_MENU();
                    }
                    if (player->HasEnoughMoney(ILLUSION_COST))
                    {
                        player->CastSpell(player, 37805, true);
                        player->ModifyMoney(-ILLUSION_COST);
                        player->CLOSE_GOSSIP_MENU();
                    }
                    else
                    {
                        creature->MonsterWhisper("You don't have enough money to receive an illusion", player->GetGUID());
                        player->CLOSE_GOSSIP_MENU();
                    }
                    break;

                case GOSSIP_ACTION_INFO_DEF+8:
                    if (IsShapeshifted(player))
                    {
                        creature->MonsterWhisper("You can't do this while shapeshifted.", player->GetGUID());
                        player->CLOSE_GOSSIP_MENU();
                    }
                    if (player->HasEnoughMoney(ILLUSION_COST))
                    {
                        player->CastSpell(player, 37808, true);
                        player->ModifyMoney(-ILLUSION_COST);
                        player->CLOSE_GOSSIP_MENU();
                    }
                    else
                    {
                        creature->MonsterWhisper("You don't have enough money to receive an illusion", player->GetGUID());
                        player->CLOSE_GOSSIP_MENU();
                    }
                    break;

                case GOSSIP_ACTION_INFO_DEF+9:
                    if (IsShapeshifted(player))
                    {
                        creature->MonsterWhisper("You can't do this while shapeshifted.", player->GetGUID());
                        player->CLOSE_GOSSIP_MENU();
                    }
                    if (player->HasEnoughMoney(ILLUSION_COST))
                    {
                        player->CastSpell(player, 37809, true);
                        player->ModifyMoney(-ILLUSION_COST);
                        player->CLOSE_GOSSIP_MENU();
                    }
                    else
                    {
                        creature->MonsterWhisper("You don't have enough money to receive an illusion", player->GetGUID());
                        player->CLOSE_GOSSIP_MENU();
                    }
                    break;

                case GOSSIP_ACTION_INFO_DEF+10:
                    if (IsShapeshifted(player))
                    {
                        creature->MonsterWhisper("You can't do this while shapeshifted.", player->GetGUID());
                        player->CLOSE_GOSSIP_MENU();
                    }
                    if (player->HasEnoughMoney(ILLUSION_COST))
                    {
                        player->CastSpell(player, 37810, true);
                        player->ModifyMoney(-ILLUSION_COST);
                        player->CLOSE_GOSSIP_MENU();
                    }
                    else
                    {
                        creature->MonsterWhisper("You don't have enough money to receive an illusion", player->GetGUID());
                        player->CLOSE_GOSSIP_MENU();
                    }
                    break;

                case GOSSIP_ACTION_INFO_DEF+11:
                    if (IsShapeshifted(player))
                    {
                        creature->MonsterWhisper("You can't do this while shapeshifted.", player->GetGUID());
                        player->CLOSE_GOSSIP_MENU();
                    }
                    if (player->HasEnoughMoney(ILLUSION_COST))
                    {
                        player->CastSpell(player, 37811, true);
                        player->ModifyMoney(-ILLUSION_COST);
                        player->CLOSE_GOSSIP_MENU();
                    }
                    else
                    {
                        creature->MonsterWhisper("You don't have enough money to receive an illusion", player->GetGUID());
                        player->CLOSE_GOSSIP_MENU();
                    }
                    break;

                case GOSSIP_ACTION_INFO_DEF+12:
                    if (IsShapeshifted(player))
                    {
                        creature->MonsterWhisper("You can't do this while shapeshifted.", player->GetGUID());
                        player->CLOSE_GOSSIP_MENU();
                    }
                    if (player->HasEnoughMoney(ILLUSION_COST))
                    {
                        player->CastSpell(player, 37807, true);
                        player->ModifyMoney(-ILLUSION_COST);
                        player->CLOSE_GOSSIP_MENU();
                    }
                    else
                    {
                        creature->MonsterWhisper("You don't have enough money to receive an illusion", player->GetGUID());
                        player->CLOSE_GOSSIP_MENU();
                    }
                    break;

                case GOSSIP_ACTION_INFO_DEF+13:
                    if (IsShapeshifted(player))
                    {
                        creature->MonsterWhisper("You can't do this while shapeshifted.", player->GetGUID());
                        player->CLOSE_GOSSIP_MENU();
                    }
                    if (player->HasEnoughMoney(ILLUSION_COST))
                    {
                        player->CastSpell(player, 37806, true);
                        player->ModifyMoney(-ILLUSION_COST);
                        player->CLOSE_GOSSIP_MENU();
                    }
                    else
                    {
                        creature->MonsterWhisper("You don't have enough money to receive an illusion", player->GetGUID());
                        player->CLOSE_GOSSIP_MENU();
                    }
                    break;

                //Leaper Gnome Option 100 Gold
                case GOSSIP_ACTION_INFO_DEF+14:
                    if (IsShapeshifted(player))
                    {
                        creature->MonsterWhisper("You can't do this while shapeshifted.", player->GetGUID());
                        player->CLOSE_GOSSIP_MENU();
                    }
                    if (player->HasEnoughMoney(ILLUSION_SPECIAL_COST))
                    {
                        player->CastSpell(player, 24713, true);
                        player->ModifyMoney(-ILLUSION_SPECIAL_COST);
                        player->CLOSE_GOSSIP_MENU();
                    }
                    else
                    {
                        creature->MonsterWhisper("You don't have enough money to receive an illusion", player->GetGUID());
                        player->CLOSE_GOSSIP_MENU();
                    }
                    break;
                
                //Pirate Costume 100 gold
                case GOSSIP_ACTION_INFO_DEF+15:
                    if (IsShapeshifted(player))
                    {
                        creature->MonsterWhisper("You can't do this while shapeshifted.", player->GetGUID());
                        player->CLOSE_GOSSIP_MENU();
                    }
                    if (player->HasEnoughMoney(ILLUSION_SPECIAL_COST))
                    {
                        if (player->getGender() == GENDER_MALE)
                        {
                            player->CastSpell(player, 24708, true);
                            player->ModifyMoney(-ILLUSION_SPECIAL_COST);
                            player->CLOSE_GOSSIP_MENU();
                        }
                        else
                        {
                            player->CastSpell(player, 24709, true);
                            player->ModifyMoney(-ILLUSION_SPECIAL_COST);
                            player->CLOSE_GOSSIP_MENU();
                        }
                    }
                    else
                    {
                        creature->MonsterWhisper("You can't do this while shapeshifted.", player->GetGUID());
                        player->CLOSE_GOSSIP_MENU();
                    }
                    break;

                //Ninja Costume 100 gold
                case GOSSIP_ACTION_INFO_DEF+16:
                    if (IsShapeshifted(player))
                    {
                        creature->MonsterWhisper("You can't do this while shapeshifted.", player->GetGUID());
                        player->CLOSE_GOSSIP_MENU();
                    }
                    if (player->HasEnoughMoney(ILLUSION_SPECIAL_COST))
                    {
                        if (player->getGender() == GENDER_MALE)
                        {
                            player->CastSpell(player, 24711, true);
                            player->ModifyMoney(-ILLUSION_SPECIAL_COST);
                            player->CLOSE_GOSSIP_MENU();
                        }
                        else
                        {
                            player->CastSpell(player, 24710, true);
                            player->ModifyMoney(-ILLUSION_SPECIAL_COST);
                            player->CLOSE_GOSSIP_MENU();
                        }

                    }
                    else
                    {
                        creature->MonsterWhisper("You don't have enough money to receive an illusion", player->GetGUID());
                        player->CLOSE_GOSSIP_MENU();
                    }
                    break;

                //Skeleton Option 100 Gold
                case GOSSIP_ACTION_INFO_DEF+17:
                    if (IsShapeshifted(player))
                    {
                        creature->MonsterWhisper("You can't do this while shapeshifted.", player->GetGUID());
                        player->CLOSE_GOSSIP_MENU();
                    }
                    if (player->HasEnoughMoney(ILLUSION_SPECIAL_COST))
                    {
                        player->CastSpell(player, 24723, true);
                        player->ModifyMoney(-ILLUSION_SPECIAL_COST);
                        player->CLOSE_GOSSIP_MENU();
                    }
                    else
                    {
                        creature->MonsterWhisper("You don't have enough money to receive an illusion", player->GetGUID());
                        player->CLOSE_GOSSIP_MENU();
                    }
                    break;

                //Ghost Costume 100 gold
                case GOSSIP_ACTION_INFO_DEF+18:
                    if (IsShapeshifted(player))
                    {
                        creature->MonsterWhisper("You can't do this while shapeshifted.", player->GetGUID());
                        player->CLOSE_GOSSIP_MENU();
                    }
                    if (player->HasEnoughMoney(ILLUSION_SPECIAL_COST))
                    {
                        if (player->getGender() == GENDER_MALE)
                        {
                            player->CastSpell(player, 24735, true);
                            player->ModifyMoney(-ILLUSION_SPECIAL_COST);
                            player->CLOSE_GOSSIP_MENU();
                        }
                        else
                        {
                            player->CastSpell(player, 24736, true);
                            player->ModifyMoney(-ILLUSION_SPECIAL_COST);
                            player->CLOSE_GOSSIP_MENU();
                        }
                    }
                    else
                    {
                        creature->MonsterWhisper("You don't have enough money to receive an illusion", player->GetGUID());
                        player->CLOSE_GOSSIP_MENU();
                    }
                    break;
                    
                default:
                    break;
            }
            return true;
        }
};

void AddSC_npc_illusionist_gossip()
{
    new npc_illusionist_gossip();
}