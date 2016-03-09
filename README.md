47RL
====
A Hitman and Wolfenstein inspired RogueLike

Main Game Concepts
-------------

__Static Campaign__: The game will feature a static campaign - levels will not be randomly generated.

__No AI Cheating__: Every NPC has a line-of-sight, and responds to events within their LOS - i.e. weapon discovery, blood discovery, etc.

# Play-styles:

__Disguises__: Player can improve disguise skill to lower penalty for bloodied disguises, lower suspicion gain per tick per rank, etc.

__Stealth__: Player can improve stealth skill to increase distance for detection (dependent on illumination), lower sound production, etc. Useful for camera evasion.

__Firearms__: Player can increase accuracy with firearms, and chance for critical headshots.

__Reflexes__: Player can improve reflexes for better chance to get first move when NPC alerted.

__Perception__: Player can improve perception for better LOS.

# Character Attributes:

# Game Systems:

__Line Of Sight__: LOS decided by distance, perception and illumination. Ability to peer through keyhole on closed doors for narrow LOS.

__Trespassing__: Distinction between warning zones and deadly zones. Different zones require different disguises. Escorting AI in warning zones.

__Sound__: Weapons, opening doors, moving, etc. - all produce different sound which can draw attention.

__Illumination__: Illumination limits LOS, stealth checks.

__Rating__: Player is rated at the end of each mission.

# AI:

State-based system dependent on NPC class. E.g. civilians go to safe zone and alert guards when alerted, guards radio and then fight, etc. 

# Actions:

Special actions for poison, etc.

# Weaponry

__Fibre Wire__: Silent guaranteed kill if not in LOS and adjacent.

__Pistols__: Close range, can be "silenced", % depends on accuracy, distance, alert state

__SMGs__: Fire three shots in one tick. 

__Shotguns__: Fire one shot which spreads to adjacent 3 tiles.

__Sniper Rifles__: Long range, highly accurate - good for headshots. Need to reload after every shot.

__Bombs__: Remote, tick-based. 3x3 AOE.

__Environmental Objects__: Explosives...

Programming Details:
--------------------

# State management

Game always tracks global state. Game loop runs state specific main function for that state.

Input -> Processing -> Output

* Start Menu
* Game Start (difficulty options)
* Load Menu
* Save Menu

* Mission selection and loadout choice/character review
* In-mission play
* Inventory screen
* Briefing screen

# Main game UI

* Message log for events in bottom
* Character stats in bottom
* Trespassing indicator in top
* Disguise indicator in bottom
* Equipped weapon on bottom

# Save/Load

# Map storage + patrols, etc.

# AI states

Different states for different NPC types


# Pathfinding

A\* Maybe use library for this, may need threads
