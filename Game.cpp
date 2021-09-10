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
	CastleNight = Node();
	Reason = Node();
	Surrender = Node();
	FightGoblins = CombatNode();
	FightGuard = GameOverNode();
	Flee = GameOverNode();
	GoblinCamp = GameOverNode();
	RunAway = GameOverNode();
	CowardEnding = GameOverNode();
	ValiantEnding = GameOverNode();
	LateKing = LinearNode();
	RiverSkip = LinearNode();
	LateTavern = LinearNode();
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
							"Nothing of note happened along the way, other than a weak bandit that wet himself when you drew your sword.\n"
							"...\nNevermind that. You've now reached the castle town just as night begins to fall. The lights and bustling from a nearby\n"
							"tavern draw you in. It may be best to rest for the night. The coming threat is still at least a week away. Though, the message is dire.\n"
							"Sooner may be better..", "Sooner is better. Go to the king now.", "Rest at the tavern tonight. The king is likely asleep.", "",
							&CastleNight, &LateTavern);
	RiverSkip.InitializeL("\nDespite your exhaustion, you pass the river and continue to the kingdom. About halfway there your vision begins to blur,\n"
							"and you begin to stumble... You collapse to the ground.", 
							"You've passed out from exhaustiong and dehydration", &Dehydrate);
	Dehydrate.InitializeG("\nYou wake up to a stranger pouring water into your mouth and over your face. As you slowly come to your senses\n"
							"You begin to remember what happened. You ask the stranger what time it is. To your surprise, he says it's just before noon.\n"
							"There's no way that that could be correct. You collapsed just after noon. This can't be possible, could it?\n"
							"It was. You were out for a few days, and this stranger tended to you. You thanked him, and asked him to point you\n"
							" in the direction of the kingdom.\n Just then, he tells you that the worst has come true. You don't believe it.\n"
							"You need to see it with your own eyes. He looks down, depressed, and then points you in the direction.\n"
							"Hours later you finally arrive, and you see it. The kingdom, burnt to ash. Everything has fallen. You failed your mission\n");
	CastleNight.InitializeN("\nYou've decided despite the time, you should hurry and deliver the message to the king. This is dire afterall.\n"
							"As you're approaching the castle, you don't see any guards. Maybe a rotation shift? Strange, but you press onwards.\n"
							"Just as you're about to open the main door, an arrow whizzes past your head and into the door. \nShocked, you turn around. "
							"Many guards, armed, stand in front of you. Of course, why would the allow an intruder to get the jump on them. Of course they were hidden.\n"
							"\"That is your warning. Next time I will not miss. Lay down your arms thief, assassin, whoever you are, or be prepared to lose your life,\"\n"
							"the seeming captain of the guards said to you. There are only two options here. You can try to make them see reason, that you aren't the enemy,\n"
							"or you can attempt to flee.", "Tell them what's going on", "Flee", "",
							&Reason, &Flee);
	LateTavern.InitializeL("\nYou enter the tavern. It's very lively - people playing music, singing, dancing, talking, drinking.\n"
							"You go to the barkeep and ask if any rooms are available. You give her some coin and she leads you upstairs to your\n"
							"quarters for the evening. As you settle in and lie in bed, you think about the tragedy to come, and if the kingdom\n"
							"is even ready to face such a threat. Luckily, there should be at the very least a few weeks to prepare. Hopefully the\n"
							"kingdom can become ready.", "Go see the king.", &LateKing);
	LateKing.InitializeL("\nThe next day you wake and head straight for the castle. The guards halt you at the gate\n"
							"and you explain the urgency of the sitation. They begin to hesitate but just then the king walks by through his garden and recognizes\n"
							"the insignia on your arm. He commands the guards to let you through, though they insist they take your arms.\n"
							"As you step in to his large piece of land, he asks\n"
							"what could have brought you this far west. You hand him the officially stamped letter from your lord. His face turns white.\n"
							"\"Is this true? If so, we need to begin preparing the troops immediately.\" You agree, and even offer the king to stay and aid, \n"
							"and let him know that your king is sending a full scale army as well. You went alone ahead to get the message here faster.\n"
							"Luckily, you still have much time to prepare. Or, so you thougt.\n" 
							"Just as you and the king were about to part ways, boulders begin hailing from the sky. Within moments\n"
							"the city is lit ablaze. You stand there shocked. This came much sooner than expected and the kingdom was not ready.\n"
							"You tell the king to hide, and that you will go and join the fight.", "Join the fight", &ValiantEnding);
	Flee.InitializeG("\nYou decide to flee. You burst with a sprint, running as fast as you can to get away. Though you did not make it far before you realized\n"
							"That the captain was not lying. His next shot did not miss. Nor did the many painful ones after that. After your torment, at least\n"
							"the royal guard had mercy. The soldiers came to you and prayed for their so-called enemy. Then the mercy ended. They pulled out each arrow\n"
							"and left you to bleed out and be eaten by rats. You died before you could complete your mission.");
	Reason.InitializeN("\nYou attempt to make them see reason. \"I have an urgent message to the king. It must be delivered immediately.\" The guards did not want to listen though.\n"
							"\"Surrender now, or die\" the captain said to you. It seems that they are giving you only two options. Which do you prefer?",
							"Surrender yourself", "You won't back down", "", 
							&Surrender, &FightGuard);
	FightGuard.InitializeG("\nNobody is sure what came over you that night, but you decided the best option was to draw your sword. Why would you want\n"
							"to go prison? That would be awful. Though now you're simply remembered as the traitor that allowed the kingdom to fall.\n"
							"The man who sought to fight the kingdom despite knowing the devesation coming.\nAt least you will be in the history books...");
	Surrender.InitializeN("\nThat night you decided to surrender yourself. Before doing so you hesitantly give the message you were sent with to the guard.\n"
							"Though, who knows if the letter would ever reach the king.\n\nNow, you sit in a cold, dark prison cell, and you just barely "
							"doze off...\nThe next morning you're awoken by a guard kicking you in the stomach. \"Wake up if you want a meal!\" he says "
							"sternly.\n You open your eyes as he walks out of the cell. He then returns with a small tray of what looks like pig feed.\n"
							"He gives you a smug look. \"What? Food i'n't good 'nough for ya?\" As he begins to turn away a large rock flies through\n"
							"the ceiling. Rubble falls on your head and you pass out. When you awake with your ears ringing, vision blurred, and\n"
							"a terrible cough, you see the guard lying on the ground. You're not sure if he's dead, or unconcious, but either way\n"
							"This is your chance to escape. You grab the keys from his belt and unshackle yourself. You then scramble through the huge\n"
							"hole in the wall. The kingdom is lit ablaze. The siege came faster than anyone predicted. You could use this opportunity\n"
							"among all the chaos to flee. Or, you can pick up arms and join the fight. The choice is yours.",
							"Use the chaos to escape", "Join the battle", "",
							&CowardEnding, &ValiantEnding);
	CowardEnding.InitializeG("\nYou decide escaping back home is the best option. You sneak your way through the city, hiding behind barrels, \n"
							"jumping over rooftops. You watch as the citizens of the city are ruthlessly murdered by the enemy. It's horrific.\n"
							"Your choice was made, however. Eventually you are able to escape the kingdom and head back to your own home.\n"
							"When you arrive, news has already arrived of the destruction. Everyone is shocked to see you return. They thought maybe\n"
							"you had died, but it was far worse than that. You told your lord what had occurred, and even though there was no knowing\n"
							"that the enemy would attack sooner than expecting, it doesn't change the fact that you had abandoned the kingdom in it's\n"
							"darkest hour. Even darker times are to come, however. Due to the king being dead, and an enemy threat trying to take over,\n"
							"the entire realm will be sent into war and chaos. This, is one of the worst possible outcomes. For your crimes, your lord\n"
							"brands your face with the mark to signify your crimes against the kingdom, and casts you out of the town walls.\n"
							"You will be left to walk the realm, alone, until your dying days.");
	ValiantEnding.InitializeG("\nYou know what you must do. You head out into the city. Many soldiers are already dead.\n"
							"You scavenge their bodies - you apologize and pray for their safe passage into the afterlife -\n"
							"to find any armor and weapons that you can find. You take what you can, and find your way onto the battlefield.\n"
							"Everything is worse than you can imagine. Citizens being slaughtered by the enemy. Much of the kingdoms army burnt to a crisp.\n"
							"You just walked into a lost battle, but there's no going back now. You raise your arms and go into the fight.\n"
							"Swearing to take down as many as you can.\n Even though you died that day, you still fought valiantly till the very end.\n"
							"You died a noble death.");
	
}