#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <conio.h>
#include <fstream>
#include <string>

using namespace std;

const int MAXCOINS = 1000 , MAXENEMIES = 4;

 struct INDEX
{
    int X;
    int Y;
};
 
char PreChecking(INDEX Place , char Direction);

struct HERO
{
    char Shape;
	char Direction;
    INDEX HeroPlace;
    int Lives;
    long long Score;
	void UpdatePosition( char Direction); //update the pacman position
    void GotoXY(char OutPut);
	void Eat(INDEX EnemyPlace); // Calling only in case of specail coin , Hero Eat Enemyy 
	void UpdateScore (int& CoinsNumber); //Count Hero Score
};

struct ENEMY
{
	char Shape;
	char Direction;
	INDEX EnemyPlace;// get random direction in case of enemy
	void UpdatePosition(char Direction); //update the enemy position
	void GotoXY(char OutPut);
	void Eat(INDEX HeroPlace, int& Lives);

};

struct COIN //normal coins =268
{
	char Shape;
	INDEX CoinPlace;
    bool SpecialCoin;
	void CoinTime();
};

struct WORLD 
{
	void ReadMap ();
	void StartGame ();
	bool CheckPosition(char MapPosition); // checking for the hash
	HERO PacMan;
	ENEMY Enemies [MAXENEMIES];
	COIN Coins [MAXCOINS];
	char GetInput(char& Direction);// get the direction from the user, assign same direction
	char SetRandomDirection(); //Set Direction for enemy
	
};
