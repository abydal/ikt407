#include <iostream>
#include <vector>

struct point{
	int x;
	int y;
};

struct square{
	square *parent;
	int fValue;
	int gValue;
	int hValue;
	point pos;
};

class AStar
{
	private:
		const int straightCost = 10;
		const int diagonalCost = 14;

		vector<square*> openList;
		vector<square*> closedList;
		int levelSizeX;
		int levelSizeY;
		int *level;
		void updateLists(square pos);
		square* FindPoint(point pos);

		//int pos = level[x + y * xsize];
	

	public:

		Astar(int *level, int sizeX, int sizeY);
		~AStar();
		void FindPath(point posA, point posB);
		int CalculateManhattan(point posA, point posB);
};