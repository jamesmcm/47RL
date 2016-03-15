#ifndef ACTOR_H
#define ACTOR_H

class Actor { 
public :
   int x,y; // position on map
   int ch; // ascii code
   TCODColor col; // color
   const char *name;

   Actor(int x, int y, int ch, const char *name, const TCODColor &col);
   void update();
   bool moveOrAttack(int x, int y);
   void render() const;
};
#endif
