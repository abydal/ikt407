#include <iostream>
#include <vector>
#include <math.h>

struct point{
	int x;
	int y;
};

struct square{
	square *parent;
	int fValue;
	int gValue;
	int hValue;
	point position;
};

class AStar
{
	private:
		int straightCost;
		int diagonalCost;

		vector<square*> openList;
		vector<square*> closedList;
		int levelSizeX;
		int levelSizeY;
		int *level;
		//void updateLists(square pos);
		square* FindPoint(point* pos);

		//int pos = level[x + y * xsize];
	

	public:

		AStar(int *level, int sizeX, int sizeY);
		~AStar();
		void FindPath(point posA, point posB);
		int CalculateManhattan(point posA, point posB);
};