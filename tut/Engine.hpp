class Engine {
public :
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
