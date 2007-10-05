#include "AStar.h"

using namespace std;

void AStar::FindPath(point posA, point posB)
{
	square start;
	start.pos.x = posA.x;
	start.pos.y = posA.y;
	start.gValue = 0;
	start.hValue = 0;



}

void AStar::updateLists(square* pos)
{
	
}

square* AStar::FindPoint(point* pos)
{
	for(int i = 0; i < AStar::openList.size; i++)
	{
		if(openList[i]->pos.x == pos->x && openList[i]->pos.y == pos->y)
			return openList[i];
	}
	return NULL;
}