#include "Player.h"

void Player::goToNewPlace(const std::string& newPlace) {
    placeOfBeing = newPlace;
}

void Player::interactWithNPC(NPC* npc) {
    npc->giveOptionsInDialogue();
}

void Player::gainExperience(double amount) {
    experience += amount;
}