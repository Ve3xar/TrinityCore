#include "ScriptPCH.h"

class item_arena_stone : public ItemScript
{
    public:

        item_arena_stone() : ItemScript("item_arena_stone") {}


        bool OnUse(Player* pPlayer, Item* pItem, SpellCastTargets const &pTargets)
        {
            if (pPlayer->isInCombat() || pPlayer->isInFlight() || pPlayer->isDead() || pPlayer->IsMounted())
            {
                pPlayer->SendEquipError(EQUIP_ERR_NOT_IN_COMBAT, pItem, NULL);
                return true;
            }

            else
            {
                pPlayer->ModifyArenaPoints(+100);
                pPlayer->DestroyItemCount(pItem->GetEntry(),1,true);
                return true;
            }
        }
};

void AddSC_item_arena_stone()
{
    new item_arena_stone();
}