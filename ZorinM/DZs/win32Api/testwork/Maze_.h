#include <iostream>
#include <ctime>

#define EMPTY 0
#define WALL  1
#define NODE  2
#define PREV  3

class MazeRB {
private:
	int rows, cols;
	int** maze; //	char** maze;
	enum Direction { UP = 0, RIGHT, DOWN, LEFT };
	struct Node { int x, y; } currentNode, player;
	Node* nodes;
	bool dir[4];
	bool isWon;
	int* true_num_i;

public:
	MazeRB () : rows(0), cols(0) { maze = NULL; }
	MazeRB (int r, int c) : rows(r), cols(c) {
		maze = NULL;
		maze = new int* [rows]; //		maze = new char* [rows];
		player.y = currentNode.y = rows - 1;
		player.x = currentNode.x = cols - 1;
		isWon = false;

		for(int i = 0; i < rows; i++)
			maze[i] = new int[cols]; //			maze[i] = new char[cols]; 
	}
	~MazeRB() {
		if (maze) {
			for (int i = 0; i < rows; i++)
				delete[] maze[i];
			delete [] maze;

			maze = NULL;
		}
	}
	void create() {
		// обраний currentNode додаємо до node
 		maze[currentNode.y][currentNode.x] = NODE;
	
		// перевірка напряму "прогризання"
		std::fill ( dir, dir + 4, false ); 

		if ( currentNode.y - 1 >= 0 ) { // up check carving
			if ( (maze[currentNode.y - 2][currentNode.x] == PREV) && maze[currentNode.y - 1][currentNode.x] == WALL )
				dir[UP] = true;
		}
				
		if ( currentNode.x + 2 <= cols - 1 ){ // right
			if ( (maze[currentNode.y][currentNode.x + 2] == PREV) && maze[currentNode.y][currentNode.x + 1] == WALL )
				dir[RIGHT] = true;
		}
		
		if ( currentNode.y + 2 <= rows - 1 ) { // down
			if ( (maze[currentNode.y + 2][currentNode.x] == PREV) && maze[currentNode.y + 1][currentNode.x] == WALL )
				dir[DOWN] = true;
		}

		if ( currentNode.x - 2 >= 0 ) { // left
			if ( (maze[currentNode.y][currentNode.x - 2] == PREV) && maze[currentNode.y][currentNode.x - 1] == WALL )
				dir[LEFT] = true;
		}

		// рахуємо кількісь true в dir
		int true_num = 0;
		
		for (int i = 0; i < 4; i++)	{
			if ( dir[i] == true ) true_num++;
		}

		// "прогризання" 
		if (true_num != 0) 	{
			// створення динамічного масиву для визначення рандомного напрямку "прогризання"
			true_num_i = NULL;
			true_num_i = new int [true_num];
		
			int j = 0;
			for (int i = 0; i < 4; i++) {
				if (dir[i] == true)	{
					true_num_i[j] = i;
					j++;
				}
			}

			if (true_num != 0) {
				int et = true_num_i[rand() % true_num];

				switch (et)	{
				case UP:
					maze[currentNode.y - 1][currentNode.x] = EMPTY;
					currentNode.y = currentNode.y - 2;
					break;
				case RIGHT:
					maze[currentNode.y][currentNode.x + 1] = EMPTY;
					currentNode.x = currentNode.x + 2;
					break;
				case DOWN:
					maze[currentNode.y + 1][currentNode.x] = EMPTY;
					currentNode.y = currentNode.y + 2;
					break;
				case LEFT:
					maze[currentNode.y][currentNode.x - 1] = EMPTY;
					currentNode.x = currentNode.x - 2;
					break;
				}
			}	
		}
		else {
			// саме backtraking
			int check_back = 0;
			
			if ( currentNode.y - 2 >= 0 ) { // up
				if ( maze[currentNode.y - 2][currentNode.x] == NODE &&
					 maze[currentNode.y - 1][currentNode.x] == EMPTY)	{
					check_back = 0;
				}
			}
			if ( currentNode.x + 2 <= cols - 1 ) { // up
				if ( maze[currentNode.y][currentNode.x + 2] == NODE &&
					 maze[currentNode.y][currentNode.x + 1] == EMPTY) {
					check_back = 1;
				}
			}
			if ( currentNode.y + 2 <= rows - 1 ) { // up
				if ( maze[currentNode.y + 2][currentNode.x] == NODE &&
					 maze[currentNode.y + 1][currentNode.x] == EMPTY) {
					check_back = 2;
				}
			}
			if ( currentNode.x - 2 >= 0 ) { // left
				if ( maze[currentNode.y][currentNode.x - 2] == NODE &&
					 maze[currentNode.y][currentNode.x - 1] != WALL ) {
					check_back = 3;
				}
			}
			
			switch(check_back)	{
			case UP:
				maze[currentNode.y][currentNode.x] = EMPTY;
				currentNode.y -= 2;
				break;
			case RIGHT:
				maze[currentNode.y][currentNode.x] = EMPTY;
				currentNode.x += 2;
				break;
			case DOWN:
				maze[currentNode.y][currentNode.x] = EMPTY;
				currentNode.y += 2;
				break;
			case LEFT:
				maze[currentNode.y][currentNode.x] = EMPTY;
				currentNode.x -= 2;
				break;
			}
		}

		if (currentNode.x != cols - 1 || currentNode.y != rows - 1) {
			this->create();
		}
		else {
			maze[currentNode.y][currentNode.x] = EMPTY;
		}
	}
	void preFill()
	{
		for(int i = 0; i < rows; i++)
			for(int j = 0; j < cols; j++)
				if ( i % 2 == 0 && j % 2 == 0)
					maze[i][j] = PREV;
				else
					maze[i][j] = WALL;
	}
	void show() const {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				std::cout << maze[i][j];
			}
			std::cout << std::endl;
		}
	}
	bool move(int dir) {
		ifWon();
		switch (dir) {
		case UP:
			if(player.y - 1 < 0) return false;
			if(maze[player.y - 1][player.x] == WALL) return false;
			else {
				--player.y;
				return true;
			}
			break;
		case RIGHT:
			if(player.x + 1 > cols - 1) return false;
			if(maze[player.y][player.x + 1] == WALL) return false;
			else {
				++player.x;
				return true;
			}
			break;
		case DOWN:
			if(player.y + 1 > rows - 1) return false;
			if(maze[player.y + 1][player.x] == WALL) return false;
			else {
				++player.y;
				return true;
			}
			break;
		case LEFT:
			if(player.x <= 0) return false;
			if(maze[player.y][player.x - 1] == WALL) return false;
			else {
				--player.x;
				return true;
			}
			break;
		}
		return false;
	}
	bool ifWon() {
		if (player.x == 0 && player.y == 0)
			return true;
		return false;
	}
	void start () {
		player.y = currentNode.y = rows - 1;
		player.x = currentNode.x = cols - 1;
		
		isWon = false;
		preFill();
		create();
	}

	int getElement(int y, int x) { return maze[y][x]; }
};