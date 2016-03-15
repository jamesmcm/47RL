#ifndef BSPLISTENER_H
#define BSPLISTENER_H
class Map;
class BspListener : public ITCODBspCallback {
private :
   Map &map; // a map to dig
   int roomNum; // room number
   int lastx,lasty; // center of the last room

public :
   BspListener(Map &map);
   bool visitNode(TCODBsp *node, void *userData);
};
extern const int ROOM_MAX_SIZE;
extern const int ROOM_MIN_SIZE;
#endif
