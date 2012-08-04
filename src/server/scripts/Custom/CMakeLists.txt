# Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

set(scripts_STAT_SRCS
  ${scripts_STAT_SRCS}
    Custom/go_portals.cpp
    Custom/item_arena_stone.cpp
    Custom/item_donation.cpp
    Custom/npc_card_master_gossip.cpp   
    Custom/npc_level_master_gossip.cpp    
    Custom/npc_mini_pet_gossip.cpp
    Custom/npc_protector.cpp
    Custom/npc_raid_master_gossip.cpp
    Custom/npc_trainer_gossips.cpp
    Custom/npc_vendor_gossips.cpp
    Custom/npc_warper_gossips.cpp
    Custom/npc_illusionist_gossip.cpp
    Custom/npc_transmogrifier_gossip.cpp
)

message("  -> Prepared: Custom")
