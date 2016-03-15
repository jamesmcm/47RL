#ifndef MAP_H
#define MAP_H
struct Tile {
   bool explored; // have we explored this tile??
   Tile() : explored(false) {}
};

class Map {
public :
   int width,height;

   Map(int width, int height);
   ~Map();
   bool isWall(int x, int y) const;
   bool canWalk(int x, int y) const;
   bool isInFov(int x, int y) const;
   bool isExplored(int x, int y) const;
   void computeFov();
   void render() const;
   void addMonster(int x, int y);
protected :
   TCODMap *map;
   Tile *tiles;
   friend class BspListener;

   void dig(int x1, int y1, int x2, int y2);
   void createRoom(bool first, int x1, int y1, int x2, int y2);
};
#endif
