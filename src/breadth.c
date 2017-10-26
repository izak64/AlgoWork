#include "breadth.h"
#include "tilemap.h"
#include <stdio.h>

int* find_neighbors(TileMap* map, Vector2D start)
{
	int* neighbors = (int*)malloc(4 * sizeof(int)); 
	int n;
	n = (start.y * map->width) + start.x;
	neighbors[0] = ((start.y == 0) ? -1 : n - map->width);
	neighbors[1] = ((start.x == 0) ? -1 : n - 1);
	neighbors[2] = ((start.y == map->height - 1) ? -1 : n + map->width);
	neighbors[3] = ((start.x == map->width - 1) ? -1 :n + 1);
	return neighbors;
}

Vector2D convert(int num, TileMap* map)
{
	Vector2D result;
	result.x = (int)(num % map->width);
	result.y = (int)(num / map->width);
	return result;
}

int check_in(Vector2D target, Vector2D* list, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		if (target.x == list[i].x && target.y == list[i].y)
		{
			return 1;
		}
	}
	return 0;
}

void bfs(TileMap* map)
{
	int size = map->width * map->height;
	Vector2D* open = (Vector2D*)malloc(size * sizeof(Vector2D));
	Vector2D* closed = (Vector2D*)malloc(size * sizeof(Vector2D));
	memset(open, 0, sizeof(Vector2D));
	memset(closed, 0, sizeof(Vector2D));
	Vector2D curr = map->start;
	int i;

	while (!(curr.x == map->end.x && curr.y == map->end.y))
	{
		int* found = find_neighbors(map, curr);
		//check curr
		//check if not in closed
		if (check_in(curr, closed, size))
		{

		}

		for (i = 0; i < 4; i++)
		{
			if (found[i] > -1)
			{
				Vector2D coord = convert(found[i], map);
				//if not in closed
				//check if end
				//if not, add to open
			}
		}
	}
	free(open);
	free(closed);
}