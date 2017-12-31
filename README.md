# game-test CHANGELIST:

-initial commit, includes starter content

-static level with static top down view camera


-2 player gameplay both with keybord controls (2 PlayerControllers created, but controls are handled on the first one in the level blueprint - workaround to get 2 keyboard inputs working)

-players are able to walk around and place bombs

-bombs are exploding after preset time(3s), inflicting damage to walls 

-damage is applied in linear directions


-destructible walls are being destroyed by the bomb, but are blocking the blast

-indestructible walls are blocking the blast and are not destroyed

-players are not blocking the blast and are killed if in range (dying/win conditions not handled yet)

-bomb explosions are triggering other bombs when they are in blast range

-bombs are triggering particle system when exploding


-bomb class has a base class in C++ and is extended in blueprints


-one player pawn blueprint class, material colored differently on player spawning

Time spent: ~4h

--------------------------------------------------------------------------------------

-powerups spawning from destroyed wall (red - bomb count, orange - bomb range, green - player speed, blue - remote bombs)


-support for bomb count power up


-support for bomb range power up


-support for speed up power up


-support for remote controlled bombs power up



-some other changes and fixes:


--player death changed to be less broken, still WIP though

--bombs are now placed in front of the pawn



Time spent: ~4h

--------------------------------------------------------------------------------------

- Show a map timer, that counts down and ends the round


- After round end, freeze game in its current state


- Show win screen when only one player is alive

- Show draw when the last players die in the same bomb blast (or chained bombs) or multiple players are alive when the timer runs out

- Reset option on end screen


Time spent: ~3h


--------------------------------------------------------------------------------------

-cleaner win conditions, added Alive variable to the player


-added scores which are not cleared when players decide to play another round


• Bonus: camera that pans in/out depending on distance between players in the level


• Bonus: procedural generated maps


-bugfix: powerups are now destroyable by bombs (forgot to implement it before)


-players now always start in the same place


-other minor improvements/changes/bugfixes


Time spent: ~4h

----------------------------------------------------------------------------------------

Minor improvements + refactoring: 

-common power up base, functionality moved to power ups

-bomb spawning on players location again non colliding with the player until he steps out of it, changed collision check for that to be bounding box of the bomb

-multiple blueprints cleanups

Time spent: ~1h

Total time spent: 16h

=========================================

GAME CONTROLS

Player1: 
W, A, S, D - Movement
LeftShift - Place Bomb

Player2: 
I, K, J, L - Movement
RightShift - Place Bomb