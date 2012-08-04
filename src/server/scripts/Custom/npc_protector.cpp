class npc_protector : public CreatureScript
{
public:
    npc_protector() : CreatureScript("npc_protector") { }

    struct npc_protectorAI : public ScriptedAI
    {
        npc_protectorAI(Creature *c) : ScriptedAI(c) {}

        void MoveInLineOfSight(Unit* who)
        {
            if (who->GetTypeId() != TYPEID_PLAYER)
                return;

            Player *player = static_cast <Player*> (who);

            if (player->isDead())
                player->ResurrectPlayer(1.0f);

            player->SetByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_SANCTUARY);
            player->pvpInfo.inNoPvPArea = true;
            player->CombatStopWithPets();
            player->allowDueling = false;
        }

    };

    CreatureAI *GetAI(Creature* creature) const
    {
        return new npc_protectorAI(creature);
    }
};

class npc_protector_duel : public CreatureScript
{
public:
    npc_protector_duel() : CreatureScript("npc_protector_duel") { }

    struct npc_protector_duelAI : public ScriptedAI
    {
        npc_protector_duelAI(Creature *c) : ScriptedAI(c) {}

        void MoveInLineOfSight(Unit* who)
        {
            if (who->GetTypeId() != TYPEID_PLAYER)
                            return;

            Player *player = static_cast <Player*> (who);

            if (player->isDead())
                player->ResurrectPlayer(1.0f);

            player->SetByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_SANCTUARY);
            player->pvpInfo.inNoPvPArea = true;
            player->CombatStopWithPets();
            player->allowDueling = true;

        }

    };

    CreatureAI *GetAI(Creature* creature) const
    {
        return new npc_protector_duelAI(creature);
    }


};

void AddSC_npc_protector()
{
    new npc_protector();
    new npc_protector_duel();
}