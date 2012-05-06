#include "ScriptPCH.h"

class item_weapon : public ItemScript
{
    public:
        item_weapon() : ItemScript("item_weapon") {}


        bool OnUse(Player* player, Item* pItem, SpellCastTargets const &pTargets)
        {
            if (player->isInCombat() || player->isInFlight() || player->isDead() || player->IsMounted())
            {
                player->SendEquipError(EQUIP_ERR_NOT_IN_COMBAT, pItem, NULL);
                return true;
            }

            else
            {
                uint32 itemId = pItem->GetEntry();
                ItemPosCountVec dest;
                uint8 msg = player->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, itemId, 1);
                if (msg == EQUIP_ERR_OK)
                {
                    switch (itemId)
                    {
                        case 90000:
                        {
                                player->StoreNewItem(dest, 90001, true, Item::GenerateItemRandomPropertyId(90001));
                                player->DestroyItemCount(itemId, 1, true);
                                break;
                        }
                        case 90001:
                        {
                                player->StoreNewItem(dest, 90000, true, Item::GenerateItemRandomPropertyId(90001));
                                player->DestroyItemCount(itemId, 1, true);
                                break;
                        }
                    }
                    return true;
                }
                else
                {
                     player->SendEquipError(EQUIP_ERR_CANT_DO_RIGHT_NOW, pItem, NULL);
                     return true;
                }
                    
            }
        }
};

void AddSC_item_donation()
{
    new item_weapon();
}