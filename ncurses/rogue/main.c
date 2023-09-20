#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

typedef struct Position {
	int x;
	int y;
} Position;

typedef struct Room {
	Position pos;
	int height;
	int width;
	Position doors[4];
	//Monster **monsters;
	//Item **itens;
} Room;

typedef struct Player {
	Position pos;
	int health;
} Player;

int screenSetup();
Room **mapSetup();
Player *playerSetup();
int handleInput(int input, Player *player);
int playerMove(int y, int x, Player *player);
int checkPosition(int y, int x);
//Room functions
Room *createRoom(int x, int y, int height, int width);
int drawRoom(Room *room);
int connectDoors(Position doorOne, Position doorTwo);

int main()
{
	screenSetup();
	mapSetup();
	Player *player = playerSetup();
	int ch;
	while((ch = getch()) != 'q'){
		handleInput(ch, player);		
	}
	
	endwin();
	return 0;
}

int screenSetup()
{
	initscr();
	noecho();
	refresh();
	srand(time(NULL));
	return 1;
}

Room *createRoom(int x, int y, int height, int width)
{
	Room *newRoom = malloc(sizeof(Room));
	newRoom->pos.x = x;
	newRoom->pos.y = y;
	newRoom->height = height;
	newRoom->width = width;

	//top door	
	newRoom->doors[0].x = rand() % (width - 2) + newRoom->pos.x + 1;
	newRoom->doors[0].y = newRoom->pos.y;
	//left door
	newRoom->doors[1].y = rand() % (height - 2) + newRoom->pos.y + 1;
	newRoom->doors[1].x = newRoom->pos.x;
	//bottom door
	newRoom->doors[2].x = rand() % (width - 2) + newRoom->pos.x + 1;
	newRoom->doors[2].y = newRoom->pos.y + newRoom->height - 1;
	//right door
	newRoom->doors[3].y = rand() % (height - 2) + newRoom->pos.y + 1;
        newRoom->doors[3].x = newRoom->pos.x + width - 1;

	return newRoom;
}

int drawRoom(Room *room)
{
	int x;
	int y;
	for(x = room->pos.x; x < room->pos.x + room->width; x++){
		mvprintw(room->pos.y, x, "-");
		mvprintw(room->pos.y + room->height - 1, x, "-");
	
	}
	for(y = room->pos.y + 1; y < room->pos.y + room->height - 1; y++){
	mvprintw(y, room->pos.x, "|");
	mvprintw(y, room->pos.x + room->width - 1, "|");

	for(x = room->pos.x + 1; x < room->pos.x + room->width - 1; x++)
		mvprintw(y, x, ".");
	
	}

	//draw doors
	mvprintw(room->doors[0].y, room->doors[0].x, "+");
	mvprintw(room->doors[1].y, room->doors[1].x, "+");
	mvprintw(room->doors[2].y, room->doors[2].x, "+");
	mvprintw(room->doors[3].y, room->doors[3].x, "+");

	return 1;
}

int connectDoors(Position doorOne, Position doorTwo)
{
	Position temp;

	temp.x = doorOne.x;
	temp.y = doorOne.y;

	while(1){
		//step left
		if((abs(temp.x - 1) - doorTwo.x) < abs(temp.x - doorTwo.x) && (mvinch(temp.y, temp.x - 1) == ' ')){
			mvprintw(temp.y, temp.x - 1, "#");
			temp.x--;
		} else if((abs(temp.x + 1) - doorTwo.x) < abs(temp.x - doorTwo.x) && (mvinch(temp.y, temp.x + 1) == ' ')){
			mvprintw(temp.y, temp.x + 1, "#");
			temp.x++;
		} else if((abs(temp.y + 1) - doorTwo.y) < abs(temp.y - doorTwo.y) && (mvinch(temp.y + 1, temp.x) == ' ')){
			mvprintw(temp.y + 1, temp.x, "#");
			temp.x++;
		} else if((abs(temp.y - 1) - doorTwo.y) < abs(temp.y - doorTwo.y) && (mvinch(temp.y - 1, temp.x) == ' ')){
			mvprintw(temp.y - 1, temp.x, "#");
			temp.x--;
		} else {
			return 0;
		}
	}

	return 1;
}

Room **mapSetup()
{	
	Room **rooms = malloc(sizeof(Room) * 6);
	rooms[0] = createRoom(13, 13, 6, 8);
	rooms[1] = createRoom(40, 2, 6, 8);
	rooms[2] = createRoom(40, 10, 6, 12);
	drawRoom(rooms[0]);
	drawRoom(rooms[1]);
	drawRoom(rooms[2]);

	connectDoors(rooms[0]->doors[3], rooms[2]->doors[1]);
	return rooms;

}

Player *playerSetup()
{
	Player *newPlayer = malloc(sizeof(Player));
	newPlayer->pos.x = 14;
	newPlayer->pos.y = 14;
	newPlayer->health = 100;
	mvprintw(newPlayer->pos.y, newPlayer->pos.x, "@");
	move(newPlayer->pos.y, newPlayer->pos.x);	
	return newPlayer;
}

int handleInput(int input, Player *player)
{
	switch(input){
		case 'w':
		case 'W':
			playerMove(player->pos.y - 1, player->pos.x, player);
			break;
		case 's':
		case 'S':
			playerMove(player->pos.y + 1, player->pos.x, player);
			break;
		case 'a':
		case 'A':
			playerMove(player->pos.y, player->pos.x - 1, player);

			break;
		case 'd':
		case 'D':
			playerMove(player->pos.y, player->pos.x + 1, player);

			break;
		default:
			break;

	}
}

int checkPosition(int y, int x)
{
	return mvinch(y, x) == '.' || mvinch(y, x) == '#' ||;
}

int playerMove(int y, int x, Player *player)
{
	if(!checkPosition(y, x)){
		move(player->pos.y, player->pos.x);
		return 1;	
	}
	mvprintw(player->pos.y, player->pos.x, ".");
	player->pos.x = x;
	player->pos.y = y;
	mvprintw(y, x, "@");
	move(y, x);
	return 1;
}
