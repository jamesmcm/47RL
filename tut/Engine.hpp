class Engine {
public :
   int fovRadius;
   TCODList<Actor *> actors;
   Actor *player;
   Map *map;
   bool quitNow;

   Engine();
   ~Engine();
   void update();
   void render();

private :
  bool computeFov;
};

extern Engine engine;
