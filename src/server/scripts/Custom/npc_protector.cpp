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
                                        return;//how about pets?

                        Player *player = static_cast <Player*> (who);

                        if (player->isDead())
                            player->ResurrectPlayer(1.0f);
                        player->CombatStop();
                        player->UpdatePvP(false);
                        player->SetByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_SANCTUARY);
                        player->getHostileRefManager().deleteReferences();
                        //uncomment after handling "player->IsInCustomTown = false" cases, like whenever the player ports away or he will never be able to duel
                        player->IsInCustomTown = true;
        }

    };

    CreatureAI *GetAI(Creature* creature) const
    {
        return new npc_protectorAI(creature);
    }


};

void AddSC_npc_protector()
{
    new npc_protector();
}