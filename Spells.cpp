/*******************************************************************************
 *                 Class declarations for all Spells
 *******************************************************************************/

#include "Spells.h"

/*******************************************************************************
 * Base spell class
 *******************************************************************************/
Spell::Spell() {
    // Base class for all castable spells
    this->spellName  = "Unknown spell";
    this->spellLevel = 1;
    this->energyCostPerLevel = 5;
}
Spell::Spell(string spellName, int spellLevel) {
    this->spellName  = spellName;
    this->spellLevel = spellLevel;
    this->energyCostPerLevel = 5;
}
string Spell::GetSpellName() const {
    return this->spellName;
}
int Spell::GetTotalEnergyCost() const {
    return this->energyCostPerLevel * this->spellLevel;
}
int Spell::GetSpellLevel() const {
    return this->spellLevel;
}
void Spell::SetSpellName(string name) {
    this->spellName = name;
}
/*******************************************************************************
 * Healing Spells
 *******************************************************************************/
HealingSpell::HealingSpell() {
    this->spellName  = "Healing Spell";
    this->healingPerLevel = 10;
    this->energyCostPerLevel = 10;
}
HealingSpell::HealingSpell(int spellLevel) {
    this->spellName  = "Healing Spell";
    this->spellLevel = spellLevel;
    this->healingPerLevel    = 10;
    this->energyCostPerLevel = 10;
}
void HealingSpell::Cast(Character *target) {
    // Heal the target character
    int amountHealed = this->healingPerLevel * this->spellLevel;
    target->IncreaseHealth(amountHealed);
}
/*******************************************************************************
 * Damage Spells
 ******************************************************************************/
MagicMissile::MagicMissile() {
    this->spellName = "Magic Missile";
    this->damagePerLevel = 15;
    this->energyCostPerLevel = 20;
}
MagicMissile::MagicMissile(int spellLevel) {
    this->spellName = "Magic Missile";
    this->spellLevel = spellLevel;
    this->damagePerLevel = 15;
    this->energyCostPerLevel = 20;
}
void MagicMissile::Cast(Character *target) {
    // Deal damage that is unmitigated by character's defense stat
    int damageDealt = this->damagePerLevel * this->spellLevel;
    target->DecreaseHealth(damageDealt);
}
