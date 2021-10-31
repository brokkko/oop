#include "Battle.h"

void Battle::AttackPlayer(Player& player, Enemy* enemy) {

	if (player.GetHealth() < enemy->GetDamage()) player.SetLife(false);
	else if (player.GetHealth() > enemy->GetDamage()) enemy->SetLife(false);
	else {
		player.SetLife(false);
		enemy->SetLife(false);
	}
	player.SetHealth(player.GetHealth() - enemy->GetDamage());
}

