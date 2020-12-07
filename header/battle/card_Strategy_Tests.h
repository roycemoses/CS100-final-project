#ifndef __CARD_STRATEGY_TESTS_H__
#define __CARD_STRATEGY_TESTS_H__

#include "gtest/gtest.h"
#include "../Player.h"
#include "../EnemyFactory.h"
#include "SmallHealStrategy.h"
#include "EnhanceDEFStrategy.h"
#include "EnhanceATKStrategy.h"
#include "DealDamageStrategy.h"

TEST(CardStrategyTests, SmallHealStrategy){
	Player *player = new Player("Hero");

	EnemyFactory *ef = new EnemyFactory();
	Enemy *enemy = ef->createEnemy("Green Slime");

	EXPECT_EQ(player->combatStats->HP, 10);

	player->combatStats->HP = 7;

	EXPECT_EQ(player->combatStats->HP, 7);

	CardStrategy *cs = new SmallHealStrategy();

	cs->use(player, enemy);

	EXPECT_EQ(player->combatStats->HP, 9);
}

TEST(CardStrategyTests, EnhanceDEFStrategy){
	Player *player = new Player("Hero");

	EnemyFactory *ef = new EnemyFactory();
	Enemy *enemy = ef->createEnemy("Goblin");

	EXPECT_EQ(player->combatStats->DEF, 1);

	CardStrategy *cs = new EnhaceDEFStrategy();

	cs->use(player, enemy);

	EXPECT_EQ(player->combatStats->DEF, 2);	
}

#endif //__CARD_STRATEGY_TESTS_H__