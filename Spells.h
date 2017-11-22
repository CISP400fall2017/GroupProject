/*******************************************************************************
 *                  Class declarations for all Spells
 *******************************************************************************/
#ifndef GROUPPROJECT_SPELLS_H
#define GROUPPROJECT_SPELLS_H

#include <string>
#include "Character.h"
using namespace std;

/*******************************************************************************
 * Base spell class
 *******************************************************************************/
class Spell {
protected:
    string spellName;
    int energyCostPerLevel;
    int spellLevel;         // Influences spell potency
public:
    Spell();
    Spell(string spellName, int spellLevel);
    string GetSpellName() const;
    int GetSpellLevel() const;
    int GetTotalEnergyCost() const;
    void SetSpellName(string name);
    virtual void Cast(Character *target) = 0;

};
/*******************************************************************************
 * Healing spells
 *******************************************************************************/
class HealingSpell : public Spell {
private:
    int healingPerLevel;
public:
    HealingSpell();
    HealingSpell(int spellLevel);
    void Cast(Character *target);
};
/*******************************************************************************
 * Damage Spells
 *******************************************************************************/
class MagicMissile : public Spell {
private:
    int damagePerLevel;
public:
    MagicMissile();
    MagicMissile(int spellLevel);
    void Cast(Character *target);
};
#endif //GROUPPROJECT_SPELLS_H
