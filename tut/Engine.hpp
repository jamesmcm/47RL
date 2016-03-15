#ifndef ENGINE_H
#define ENGINE_H

class Engine {
public :
   enum GameStatus {
     STARTUP,
     IDLE,
     NEW_TURN,
     VICTORY,
     DEFEAT} gameStatus;
   int fovRadius;
   TCODList<Actor *> actors;
   Actor *player;
   Map *map;
   bool quitNow;

   Engine();
   ~Engine();
   void update();
   void render();

};

extern Engine engine;
#endif
