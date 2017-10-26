#include "tilemap.h"

#ifndef __BREADTH__
#define __BREADTH__

int* find_neighbors(TileMap* map, Vector2D start);
Vector2D convert(int num, TileMap* map);
void bfs(TileMap* map);

#endif // !1
