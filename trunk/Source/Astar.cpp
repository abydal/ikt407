#include "../Header/AStar.h"

using namespace std;

void AStar::FindPath(point posA, point posB)
{
	square start;
	start.position.x = posA.x;
	start.position.y = posA.y;
	start.gValue = 0;
	start.hValue = 0;

	square destination;
	destination.position.x = posA.x;
	destination.position.y = posA.y;
	destination.gValue = 0;
	destination.hValue = 0;
}


square* AStar::FindPoint(point* pos)
{
	for(int i = 0; i < (int)openList.size(); i++)
	{
	//	if(openList[i]->position.x == pos->x && openList[i]->position.y == pos->y)
	//		return openList[i];
		cout << pos->x;
	}
	return NULL;
}

int AStar::CalculateManhattan(point posA, point posB)
{
	return fabs((double)posA.x - (double)posB.x)*10 + fabs((double)posA.y - (double)posB.y)*10;
}

