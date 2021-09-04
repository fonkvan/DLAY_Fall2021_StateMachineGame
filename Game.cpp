#include "Game.h"
#include <iostream>
#include "Node.h"
#include "CombatNode.h"
#include "GameOverNode.h"

Game::Game()
{
	startNode = Node();
	currentNode = &startNode;
	MakeCamp = Node();
	ContinueOn = Node();
	Sneak = Node();
	ExitForest = Node();
	River = Node();
	RiverSkip = Node();
	CastleNight = Node();
	Tavern = Node();
	Reason = Node();
	FightGoblins = CombatNode();
	FightGuard = GameOverNode();
	Flee = GameOverNode();
	GoblinCamp = GameOverNode();
	RunAway = GameOverNode();
	WaitNode = LinearNode();
	//Combat = CombatNode();
	//GameOver = GameOverNode();
}

void Game::PlayGame()
{
	while (!currentNode->getGameOver() && currentNode != nullptr)
	{
		currentNode = currentNode->process();
	}
	return;
}

//DebugGame is to Test Nodes to make sure game works properly.
//void Game::DebugGame()
//{
//	Node TestCNode = Node();
//	TestCNode.InitializeN("Test C Node", "", "", "", nullptr, nullptr);
//	GameOver.InitializeG("This is the Game Over Node");
//	Combat.InitializeC("This node is the Combat Node", "Fight", "Game Over Node", "Start Over", "TestCNode", 10, 10, 5, 5,
//	&Combat, &GameOver, &startNode, &TestCNode);
//	startNode.InitializeN("This node is the base test node", "Fight Node", "Game Over Node", "TestCNode", &Combat, &GameOver, &TestCNode);
//	currentNode = &startNode;
//	return;
//}

//actual game made for class
void Game::MainQuest()
{
	startNode.InitializeN("You are on your way to a nearby kingdom to deliver an important message to their king.\n"
							"The sun has begun to fall. What will you do?\n", 
							"Stop and make camp.", "Continue on. This is important", "",
							&MakeCamp, &ContinueOn);
	currentNode = &startNode;
	MakeCamp.InitializeN("\nYou have stopped to make camp. You lay down your cot, and setup a camp fire.\n"
							"You close your eyes, and begin to drift off...\n...\nHOURS LATER\n\n"
							"You wake up, still dark out - your fire has gone out, and you hear shuffling. Someone is approaching.\n"
							"You hide in the brush and see them. Goblins, but only a few. You may be able to take them...\n",
							"Wait for them to leave.", "Ambush and fight them.", "RUN AWAY!",
							&WaitNode, &FightGoblins, &RunAway);
	ContinueOn.InitializeN("\nYou've decided to continue on. Nothing is more important this message being delivered.\n"
							"As you're walking through the dark, you start to see a light. You approach it to find a very large camp.\n"
							"Goblins. And alot of them. Too many for one person to fight. You don't have many options here...\n",
							"Sneak around them.", "Fight anyways. You're no coward.", "RUN AWAY",
							&Sneak, &GoblinCamp, &RunAway);
	WaitNode.InitializeL("\nYou clamber up a nearby tree and decide to wait. A couple of goblins come by your old campfire.\n"
							"The smell of the fire must have gotten them off of your trail, because it seems they don't smell you.\n"
							"They look around, to make sure they are in the clear. After they believe no one is near\n"
							"the goblins let out a large scream, and more come over. For a moment you fear they were aware\n"
							"of you, but that quickly changed when they bring out a large dead pig and start relighting the fire.\n"
							"\nThe goblin's party has begun. Despite the noise, you find it best to get some shut eye.\n"
							"You wake up just at the break of dawn. The goblin's have gone, the ground stomped all over\n"
							"and the smell that was left over was less than pleasant. You hop down from the tree,\n"
							"and continue on your way.", "Continue", &ExitForest);
	RunAway.InitializeG("\nYou begin sprinting away from the goblins, without any regard for how much noise you're making.\n"
							"Unfortunately for you, the goblins heard you. Heck, they may have even smelled you.\n"
							"They shout their warcry as loud as they can, and begin to string their bows.\n"
							"You try your best to avoid the arrows but it was no use. More arrows than necessary flew into your back.\n"
							"You have died.\n"
							"Game over.");
	FightGoblins.InitializeC("\nThe goblins are aware of your presence and are ready for a fight. Will you battle? Or will you back out"
								"now?", "Battle the goblins!", "I change my mind. I'm getting out of here!", "Start Over", "",
								25, 15, 4, 5, &FightGoblins, &RunAway, &startNode, &ExitForest);
	GoblinCamp.InitializeG("\nYou fought valiantly against the goblins, and took many to the underworld with you. Alas, in the end\n"
							"you were still bested by these foul foes. The few remaining goblins dance on your carcass before feasting\n"
							"on you.\n Some comrades back home will consider you a traitor. They'll never learn of what happened, only\n"
							"knowing you abandoned the realm, and that your message never reached that ruined kingdom. Some will guess\n"
							"that you were killed by a troll or ogre - something much more powerful than a goblin. Some will still have\n"
							"faith, that you found something even more dire, and that one day you will return home with news that will change the world.\n"
							"But we know the truth. You were killed and eaten by goblins. Unfortunate.");
	ExitForest.InitializeN("\nYou've made it out of the forest. The sun shines brightly now.\n"
							"As you walk out of the brush you see it - a large"
							" kingdom surrounded by walls that seem they could touch the sky.\n"
							"The treck to the kingdom will take the majority of the day. On your way you walk by a river.\n"
							"The water seems clear. Will you stop to get water? Or will you continue onwards towards the kingdom?",
							"Stop to get water", "Continue towards the kingdom", "", &River, &RiverSkip);
	River.InitializeN("\nYou stop next to the water and take a few drinks. Refreshing. Hydrating. REJUVINATING. You feel much better.\n"
							"After getting regaining some strength you continue on to the castle town at the edge of the walled kingdom.\n"
							"Nothing wonderfully eventful happened along the way, other than a weak bandit that wet himself when you drew your sword.\n"
							"...\nNevermind that. You've now reached the castle town just as night begins to fall. The lights and bustling from a nearby\n"
							"tavern draw you in. It may be best to rest for the night. The coming threat is still at least a week away. Though, the message is dire.\n"
							"Sooner may be better..", "Sooner is better. Go to the king now.", "Rest at the tavern tonight. The king is likely asleep.", "",
							&CastleNight, &Tavern);
	CastleNight.InitializeN("\nYou've decided despite the time, you should hurry and deliver the message to the king. This is dire afterall.\n"
							"As you're approaching the castle, you don't see any guards. Maybe a rotation shift? Strange, but you press onwards.\n"
							"Just as you're about to open the main door, an arrow whizzes past your head and into the door. \nShocked, you turn around. "
							"Many guards, armed, stand in front of you. Of course, why would the allow an intruder to get the jump on them. Of course they were hidden.\n"
							"\"That is your warning. Next time I will not miss. Lay down your arms thief, assassin, whoever you are, or be prepared to lose your life\,\n"
							"the seeming captain of the guards said to you. There are only two options here. You can try to make them see reason, that you aren't the enemy,\n"
							"or you can attempt to flee.", "Tell them what's going on", "Flee", "",
							&Reason, &Flee);
	Flee.InitializeG("\nYou decide to flee. You burst with a sprint, running as fast as you can to get away. Though you did not make it far before you realized\n"
							"That the captain was not lying. His next shot did not miss. Nor did the many painful ones after that. After your torment, at least\n"
							"the royal guard had mercy. The soldiers came to you and prayed for their so-called enemy. Then the mercy ended. They pulled out each arrow\n"
							"and left you to bleed out and be eaten by rats. You died before you could complete your mission.");
}