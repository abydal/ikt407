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
		int levelSizeX;
		int levelSizeY;
		int *level;

		square destination;
		square start;

		std::vector<square*> openList;
		std::vector<square*> closedList;
		//void updateLists(square pos);
		square* InOpenList(point* pos);
		square* InClosedList(point* pos);

		//int pos = level[x + y * xsize];
	

	public:

		AStar(int *level, int sizeX, int sizeY);
		~AStar();
		void FindPath(point posA, point posB);
		int CalculateManhattan(point posA, point posB);
		void CalculateAdjecentSquares(square* parent);
		bool IsWalkable();
};