#include "../Header/AStar.h"

using namespace std;

void AStar::FindPath(point posA, point posB)
{
	diagonalCost = 14;
	straightCost = 10;

	start.position.x = posA.x;
	start.position.y = posA.y;
	start.gValue = 0;
	start.hValue = 0;

	destination.position.x = posA.x;
	destination.position.y = posA.y;
	destination.gValue = 0;
	destination.hValue = 0;
}


square* AStar::InOpenList(point* pos)
{
	for(int i = 0; i < (int)openList.size(); i++)
	{
		if(openList[i]->position.x == pos->x && openList[i]->position.y == pos->y)
			return openList[i];
	}
	return NULL;
}

square* AStar::InClosedList(point* pos)
{
	for(int i = 0; i < (int)closedList.size(); i++)
	{
		if(closedList[i]->position.x == pos->x && closedList[i]->position.y == pos->y)
			return closedList[i];
	}
	return NULL;
}

int AStar::CalculateManhattan(point posA, point posB)
{
	return fabs((double)posA.x - (double)posB.x)*10 + fabs((double)posA.y - (double)posB.y)*10;
}

void AStar::CalculateAdjecentSquares(square* parent)
{
	for(int x = -1; x < 2;x++)
	{
		for (int y = -1; y < 2; y++)
		{
			if(x == 0 && y == 0)
				continue;

			point tempPoint;
			tempPoint.x = x + parent->position.x;
			tempPoint.y = y + parent->position.y;
			
			if(IsWalkable(&tempPoint) && !InClosedList(&tempPoint))
			{
				square *tempSquare = InOpenList(&tempPoint);
				square newSquare;

				if(temp == NULL)
				{
					//Insert new square into open list
					newSquare.parent = parent;
					newSquare.position.x = tempPoint.x;
					newSquare.position.y = tempPoint.y;
					newSquare.hValue = CalculateManhattan(newSquare.position,destination.position);
					if((fabs(x) + fabs(y)) == 2)
					{
						newSquare.gValue = parent->gValue + diagonalCost;
					}
					else
					{
						newSquare.gValue = parent->gValue + straightCost;
					}
					newSquare.fValue = newSquare.hValue + newSquare.gValue;

					openList.insert(newSquare);

				}
				else
				{
					if(tempSquare->gValue > newSquare.gValue)
					{
						//Uncertain about this
						tempSquare->parent = parent;
						if((fabs(x) + fabs(y)) == 2)
						{
							tempSquare.gValue = parent->gValue + diagonalCost;
						}
						else
						{
							tempSquare.gValue = parent->gValue + straightCost;
						}
						tempSquare.fValue = tempSquare.hValue + tempSquare.gValue;
					}//end if
				}// end else
			}//end if
		}//end for
	}//end for
}//end CalculateAjecentSquares

