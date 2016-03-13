#include "libtcod.hpp"
#include "Actor.hpp"
#include "Map.hpp"
#include "Engine.hpp"

Engine::Engine() {
   TCODConsole::setCustomFont("terminal16x16_gs_ro.png",TCOD_FONT_LAYOUT_ASCII_INROW,16,16);
   TCODConsole::initRoot(80,50,"libtcod C++ tutorial",false);
   player = new Actor(40,25,'@',TCODColor::white);
   actors.push(player);
   //actors.push(new Actor(60,13,'@',TCODColor::yellow));
   map = new Map(80,45);
   quitNow = false;
}

Engine::~Engine() {
   actors.clearAndDelete();
   delete map;
}


void Engine::update() {
   TCOD_key_t key;
   TCODSystem::checkForEvent(TCOD_EVENT_KEY_PRESS,&key,NULL);
   switch(key.vk) {
       case TCODK_UP : 
           if ( ! map->isWall(player->x,player->y-1)) {
               player->y--;
               computeFov=true;
           }
       break;
       case TCODK_DOWN : 
           if ( ! map->isWall(player->x,player->y+1)) {
               player->y++;
               computeFov=true;
           }
       break;
       case TCODK_LEFT : 
           if ( ! map->isWall(player->x-1,player->y)) {
               player->x--;
               computeFov=true;
           }
       break;
       case TCODK_RIGHT : 
           if ( ! map->isWall(player->x+1,player->y)) {
               player->x++;
               computeFov=true;
           }
       break;
       case TCODK_CHAR :
        switch(key.c) {
          case 'q' :
          case 'Q' :
          //quit
            quitNow = true;
            break;
          default: break;
          }
       default:break;
   }
   if(computeFov){
    map->computeFov();
    computeFov=false;
   }
}

void Engine::render() {
   TCODConsole::root->clear();
   // draw the map
   map->render();
   // draw the actors
    for (Actor **iterator=actors.begin(); 
       iterator != actors.end(); iterator++) {
         Actor *actor=*iterator;
         if ( map->isInFov(actor->x,actor->y) ) {
             actor->render();
         }
    }
}
