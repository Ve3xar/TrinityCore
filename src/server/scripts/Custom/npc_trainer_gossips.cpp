#include "ScriptPCH.h"

#define MAX_SKILL_LEVEL 450

class npc_profession_trainer_gossip : public CreatureScript
{
    public:
        npc_profession_trainer_gossip(): CreatureScript("npc_profession_trainer_gossip"){}

        bool OnGossipHello(Player* pPlayer, Creature* pCreature)
        {
            if (pPlayer->isInCombat())
            {
                pPlayer->CLOSE_GOSSIP_MENU();
                pCreature->MonsterWhisper("You are in combat!", pPlayer->GetGUID());
                return true;
            }
            else
            {
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, GOSSIP_TEXT_TRAIN, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_GOODS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Advance My Professions" , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
                pPlayer->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,pCreature->GetGUID());
                return true;
            }
        }

        bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 sender, uint32 uiAction)
        {
            pPlayer->PlayerTalkClass->ClearMenus();

            switch(uiAction)
            {

                case GOSSIP_ACTION_INFO_DEF:
                    pPlayer->GetSession()->SendTrainerList(pCreature->GetGUID());
                break;

                case GOSSIP_ACTION_INFO_DEF+1:
                    pPlayer->GetSession()->SendListInventory(pCreature->GetGUID());
                break;

                case GOSSIP_ACTION_INFO_DEF+2://Advance Professions
                    pPlayer->CLOSE_GOSSIP_MENU();
                    //Alchemy
                    if (pPlayer->GetPureMaxSkillValue(SKILL_ALCHEMY) && pPlayer->GetSkillValue(SKILL_ALCHEMY) <= MAX_SKILL_LEVEL)
                    {
                        pPlayer->SetSkill(SKILL_ALCHEMY, 0, MAX_SKILL_LEVEL, MAX_SKILL_LEVEL);
                        pCreature->MonsterWhisper("Alchemy has been advanced.", pPlayer->GetGUID());
                    }
                    //Blacksmith
                    if (pPlayer->GetPureMaxSkillValue(SKILL_BLACKSMITHING) && pPlayer->GetSkillValue(SKILL_BLACKSMITHING) <= MAX_SKILL_LEVEL)
                    {
                        pPlayer->SetSkill(SKILL_BLACKSMITHING, 0, MAX_SKILL_LEVEL, MAX_SKILL_LEVEL);
                        pCreature->MonsterWhisper("Blacksmithing has been advanced.", pPlayer->GetGUID());
                    }
                    //Enchanting
                    if (pPlayer->GetPureMaxSkillValue(SKILL_ENCHANTING) && pPlayer->GetSkillValue(SKILL_ENCHANTING) <= MAX_SKILL_LEVEL)
                    {
                        pPlayer->SetSkill(SKILL_ENCHANTING, 0, MAX_SKILL_LEVEL, MAX_SKILL_LEVEL);
                        pCreature->MonsterWhisper("Enchanting has been advanced.", pPlayer->GetGUID());
                    }
                    //Engineering
                    if (pPlayer->GetPureMaxSkillValue(SKILL_ENGINEERING) && pPlayer->GetSkillValue(SKILL_ENGINEERING) <= MAX_SKILL_LEVEL)
                    {
                        pPlayer->SetSkill(SKILL_ENGINEERING, 0, MAX_SKILL_LEVEL, MAX_SKILL_LEVEL);
                        pCreature->MonsterWhisper("Engineering has been advanced.", pPlayer->GetGUID());
                    }
                    //Inscription
                    if (pPlayer->GetPureMaxSkillValue(SKILL_INSCRIPTION) && pPlayer->GetSkillValue(SKILL_INSCRIPTION) <= MAX_SKILL_LEVEL)
                    {
                        pPlayer->SetSkill(SKILL_INSCRIPTION, 0, MAX_SKILL_LEVEL, MAX_SKILL_LEVEL);
                        pCreature->MonsterWhisper("Inscription has been advanced.", pPlayer->GetGUID());
                    }
                    //Jewelcrafting
                    if (pPlayer->GetPureMaxSkillValue(SKILL_JEWELCRAFTING) && pPlayer->GetSkillValue(SKILL_JEWELCRAFTING) <= MAX_SKILL_LEVEL)
                    {
                        pPlayer->SetSkill(SKILL_JEWELCRAFTING, 0, MAX_SKILL_LEVEL, MAX_SKILL_LEVEL);
                        pCreature->MonsterWhisper("Jewelcrafting has been advanced.", pPlayer->GetGUID());
                    }
                    //Leatherworking
                    if (pPlayer->GetPureMaxSkillValue(SKILL_LEATHERWORKING) && pPlayer->GetSkillValue(SKILL_LEATHERWORKING) <= MAX_SKILL_LEVEL)
                    {
                        pPlayer->SetSkill(SKILL_LEATHERWORKING, 0, MAX_SKILL_LEVEL, MAX_SKILL_LEVEL);
                        pCreature->MonsterWhisper("Leatherworking has been advanced.", pPlayer->GetGUID());
                    }
                    //Tailoring
                    if (pPlayer->GetPureMaxSkillValue(SKILL_TAILORING) && pPlayer->GetSkillValue(SKILL_TAILORING) <= MAX_SKILL_LEVEL)
                    {
                        pPlayer->SetSkill(SKILL_TAILORING, 0, MAX_SKILL_LEVEL, MAX_SKILL_LEVEL);
                        pCreature->MonsterWhisper("Tailoring has been advanced.", pPlayer->GetGUID());
                    }
                    //Herbalism
                    if (pPlayer->GetPureMaxSkillValue(SKILL_HERBALISM) && pPlayer->GetSkillValue(SKILL_HERBALISM) <= MAX_SKILL_LEVEL)
                    {
                        pPlayer->SetSkill(SKILL_HERBALISM, 0, MAX_SKILL_LEVEL, MAX_SKILL_LEVEL);
                        pCreature->MonsterWhisper("Herbalism has been advanced.", pPlayer->GetGUID());
                    }
                    //Mining
                    if (pPlayer->GetPureMaxSkillValue(SKILL_MINING) && pPlayer->GetSkillValue(SKILL_MINING) <= MAX_SKILL_LEVEL)
                    {
                        pPlayer->SetSkill(SKILL_MINING, 0, MAX_SKILL_LEVEL, MAX_SKILL_LEVEL);
                        pCreature->MonsterWhisper("Mining has been advanced.", pPlayer->GetGUID());
                    }
                    //Skinning
                    if (pPlayer->GetPureMaxSkillValue(SKILL_SKINNING) && pPlayer->GetSkillValue(SKILL_SKINNING) <= MAX_SKILL_LEVEL)
                    {
                        pPlayer->SetSkill(SKILL_SKINNING, 0, MAX_SKILL_LEVEL, MAX_SKILL_LEVEL);
                        pCreature->MonsterWhisper("Mining has been advanced.", pPlayer->GetGUID());
                    }
                break;

                default:
                break;
            }
            return true;
        }
};

enum Mounts
{
    //Horde Category
    ORC_MOUNTS          = 1,
    TROLL_MOUNTS        = 2,
    TAUREN_MOUNTS       = 3,
    UNDEAD_MOUNTS       = 4,
    BLOOD_ELF_MOUNTS    = 5,
    //Alliance Category
    HUMAN_MOUNTS        = 6,
    DWARF_MOUNTS        = 7,
    GNOME_MOUNTS        = 8,
    DRAENEI_MOUNTS      = 9,
    NIGHT_ELF_MOUNTS    = 10,
};

class npc_riding_trainer_gossip : public CreatureScript
{
    public:
        npc_riding_trainer_gossip(): CreatureScript("npc_riding_trainer_gossip"){}

        bool OnGossipHello(Player* pPlayer, Creature* pCreature)
        {
            if (pPlayer->isInCombat())
            {
                pPlayer->CLOSE_GOSSIP_MENU();
                pCreature->MonsterWhisper("You are in combat!", pPlayer->GetGUID());
                return true;
            }
            else
            {

                pPlayer->PrepareQuestMenu(pCreature->GetGUID());
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, GOSSIP_TEXT_TRAIN, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_GOODS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
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
                    pPlayer->GetSession()->SendTrainerList(pCreature->GetGUID());
                    break;

                case GOSSIP_ACTION_INFO_DEF+1:
                    if (pPlayer->GetTeam() == HORDE)
                    {
                        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, "Orc Mounts", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
                        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, "Troll Mounts", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+3);
                        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, "Tauren Mounts", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+4);
                        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, "Undead Mounts", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+5);
                        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, "Blood Elf Mounts", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+6);
                        pPlayer->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, pCreature->GetGUID());
                    }
                    if (pPlayer->GetTeam() == ALLIANCE)
                    {
                        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, "Human Mounts", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+7);
                        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, "Dwarf Mounts", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+8);
                        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, "Gnome Mounts", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+9);
                        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, "Draenei Mounts", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+10);
                        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, "Night Elf Mounts", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+11);
                        pPlayer->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, pCreature->GetGUID());
                    }
                    break;
       
                case GOSSIP_ACTION_INFO_DEF+2:
                    pPlayer->SEND_VENDORLIST_ADVANCED(pCreature->GetGUID(), ORC_MOUNTS);
                    break;

                case GOSSIP_ACTION_INFO_DEF+3:
                    pPlayer->SEND_VENDORLIST_ADVANCED(pCreature->GetGUID(), TROLL_MOUNTS);
                    break;

                case GOSSIP_ACTION_INFO_DEF+4:
                    pPlayer->SEND_VENDORLIST_ADVANCED(pCreature->GetGUID(), TAUREN_MOUNTS);
                    break;

                case GOSSIP_ACTION_INFO_DEF+5:
                    pPlayer->SEND_VENDORLIST_ADVANCED(pCreature->GetGUID(), UNDEAD_MOUNTS);
                    break;

                case GOSSIP_ACTION_INFO_DEF+6:
                    pPlayer->SEND_VENDORLIST_ADVANCED(pCreature->GetGUID(), BLOOD_ELF_MOUNTS);
                    break;

                case GOSSIP_ACTION_INFO_DEF+7:
                    pPlayer->SEND_VENDORLIST_ADVANCED(pCreature->GetGUID(), HUMAN_MOUNTS);
                    break;

                case GOSSIP_ACTION_INFO_DEF+8:
                    pPlayer->SEND_VENDORLIST_ADVANCED(pCreature->GetGUID(), DWARF_MOUNTS);
                    break;

                case GOSSIP_ACTION_INFO_DEF+9:
                    pPlayer->SEND_VENDORLIST_ADVANCED(pCreature->GetGUID(), GNOME_MOUNTS);
                    break;

                case GOSSIP_ACTION_INFO_DEF+10:
                    pPlayer->SEND_VENDORLIST_ADVANCED(pCreature->GetGUID(), DRAENEI_MOUNTS);
                    break;

                case GOSSIP_ACTION_INFO_DEF+11:
                    pPlayer->SEND_VENDORLIST_ADVANCED(pCreature->GetGUID(), NIGHT_ELF_MOUNTS);
                    break;

                default:
                break;
            }
            return true;
        }
};


class npc_dk_trainer_gossip : public CreatureScript
{
    public:
        npc_dk_trainer_gossip(): CreatureScript("npc_dk_trainer_gossip"){}

        bool OnGossipHello(Player* pPlayer, Creature* pCreature)
        {
            if (pPlayer->isInCombat())
            {
                pPlayer->CLOSE_GOSSIP_MENU();
                pCreature->MonsterWhisper("You are in combat!", pPlayer->GetGUID());
                return true;
            }
            if (pPlayer->getClass() != CLASS_DEATH_KNIGHT)
            {
                pPlayer->CLOSE_GOSSIP_MENU();
                pCreature->MonsterWhisper("You must be a Death Knight in order to speak to me!", pPlayer->GetGUID());
                return true;
            }
            else
            {
                pPlayer->PrepareQuestMenu(pCreature->GetGUID());
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, GOSSIP_TEXT_TRAIN, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_GOODS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
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
                    pPlayer->GetSession()->SendTrainerList(pCreature->GetGUID());
                break;
       
                case GOSSIP_ACTION_INFO_DEF+1:
                    pPlayer->GetSession()->SendListInventory(pCreature->GetGUID());
                break;

                default:
                break;
            }
            return true;
        }
};

void AddSC_npc_trainer_gossips()
{
    new npc_profession_trainer_gossip();
    new npc_riding_trainer_gossip();
    new npc_dk_trainer_gossip();
}