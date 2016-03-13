#include "libtcod.hpp"
#include "Map.hpp"
#include "Actor.hpp"
#include "BspListener.hpp"
#include "Engine.hpp"

const int ROOM_MAX_SIZE = 12;
const int ROOM_MIN_SIZE = 3;

Map::Map(int width, int height) : width{width},height{height} {
   map=new TCODMap(width,height);
   tiles=new Tile[width*height];
   TCODBsp bsp(0,0,width,height);
   bsp.splitRecursive(NULL,8,ROOM_MAX_SIZE,ROOM_MAX_SIZE,1.5f,1.5f);
   BspListener listener(*this);
   bsp.traverseInvertedLevelOrder(&listener,NULL);
}

Map::~Map() {
   delete [] tiles;
   delete map;
}

void Map::dig(int x1, int y1, int x2, int y2) {
   if ( x2 < x1 ) {
       int tmp=x2;
       x2=x1;
       x1=tmp;
   }
   if ( y2 < y1 ) {
       int tmp=y2;
       y2=y1;
       y1=tmp;
   }
   for (int tilex=x1; tilex <= x2; tilex++) {
       for (int tiley=y1; tiley <= y2; tiley++) {
       map->setProperties(tilex,tiley,true,true);
       }
   }
}

void Map::createRoom(bool first, int x1, int y1, int x2, int y2) {
   dig (x1,y1,x2,y2);
   if ( first ) {
       // put the player in the first room
       engine.player->x=(x1+x2)/2;
       engine.player->y=(y1+y2)/2;
   } else {
       TCODRandom *rng=TCODRandom::getInstance();
       if ( rng->getInt(0,3)==0 ) {
           engine.actors.push(new Actor((x1+x2)/2,(y1+y2)/2,'@',
               TCODColor::yellow));
       }
   }
}

bool Map::isWall(int x, int y) const {
   return !map->isWalkable(x,y);
}

bool Map::isExplored(int x, int y) const {
  return tiles[x+y*width].explored;
}

bool Map::isInFov(int x, int y) const {
   if ( map->isInFov(x,y) ) {
       tiles[x+y*width].explored=true;
       return true;
   }
   return false;
}

void Map::computeFov() {
   map->computeFov(engine.player->x,engine.player->y,
       engine.fovRadius);
}

void Map::render() const {
   static const TCODColor darkWall(0,0,100);
   static const TCODColor darkGround(50,50,150);
   static const TCODColor lightWall(130,110,50);
   static const TCODColor lightGround(200,180,50);

    for (int x=0; x < width; x++) {
       for (int y=0; y < height; y++) {
         if ( isInFov(x,y) ) {
             TCODConsole::root->setCharBackground(x,y,
                 isWall(x,y) ? lightWall :lightGround );
         } else if ( isExplored(x,y) ) {
             TCODConsole::root->setCharBackground(x,y,
                 isWall(x,y) ? darkWall : darkGround );
         }
      }
  }
}

