#include "Pacman.h"

string MAP[100];

//bool CoinTime(bool SpecialCoin)
//{
//	int Time = 10;
//	while (Time)
//		Time--;
//	if (!Time)
//		return false;
//}

void WORLD :: ReadMap ()
    
{
    ofstream file_;
    file_.open("MyText.txt");
	file_<< "#################################"<<endl;
    file_<< "#..............#-#..............#"<<endl;
    file_<< "#.######.#####.#-#.######.#####.#"<<endl;
    file_<< "#0#----#.#---#.#-#.#----#.#---#0#"<<endl;
    file_<< "#.######.#####.###.######.#####.#"<<endl;
    file_<< "#...............................#"<<endl;
    file_<< "#.######.##.########.##.#######.#"<<endl;
    file_<< "#.######.##.########.##.#######.#"<<endl;
    file_<< "#........##....##....##.........#"<<endl;
    file_<< "########.#####.##.#####.#########"<<endl;
    file_<< "-------#.##----------##.#--------"<<endl;
    file_<< "########.##-###__###-##.#########"<<endl;
    file_<< "--------.---#------#---.---------"<<endl;
    file_<< "########.##-########-##.#########"<<endl;
    file_<< "-------#.##----------##.#--------"<<endl;
    file_<< "-------#.##-########-##.#--------"<<endl;
    file_<< "########.##-########-##.#########"<<endl;
    file_<< "#..............##...............#"<<endl;
    file_<< "#.######.#####.##.#####.#######.#"<<endl;
    file_<< "#.######.#####....#####.#######.#"<<endl;
    file_<< "#0....##................##.....0#"<<endl;
    file_<< "#####.##.##.########.##.##.######"<<endl;
    file_<< "#........##....##....##.........#"<<endl;
    file_<< "#.############.##.#############.#"<<endl;
    file_<< "#.############.##.#############.#"<<endl;
    file_<< "#...............................#"<<endl;
    file_<< "#################################"<<endl;
    file_.close();


    ifstream myReadFile;
    myReadFile.open("MyText.txt");
    char output[1000];
    int counter=-1;
    if (myReadFile.is_open())
    {
        while (!myReadFile.eof())
        {
            counter++;
            myReadFile >> output;
            MAP[counter]=output;
		}

    }
	for(int i=0 ; i<counter ;i++){
		for(int j=0 ; j<MAP[0].size() ;j++)
		{

			if(MAP[i][j]=='#'){MAP[i][j]=char(177);}
			else if(MAP[i][j]=='-'){MAP[i][j]=' ';}
			else if(MAP[i][j]=='_'){MAP[i][j]='-';}
			else if(MAP[i][j]=='0'){MAP[i][j]=char(15);}
		}
		cout<<MAP[i]<<endl;
	}
}


void HERO :: Eat(INDEX EnemyPlace) 
{
	if (EnemyPlace.X == HeroPlace.X && EnemyPlace.Y == HeroPlace.Y )
	{
		MAP [HeroPlace.Y][HeroPlace.X] = (char)1;
		Score +=100;

		//return Enemy To the Gate 
	}
}

void ENEMY:: Eat(INDEX HeroPlace,int& Lives)
{ 
	if (EnemyPlace.X == HeroPlace.X && EnemyPlace.Y == HeroPlace.Y )
	{
		MAP [HeroPlace.Y][HeroPlace.X] = (char)2;
		Lives --;
		//return Hero  To it's original Place
	}
}

char  WORLD :: GetInput(char& Direction) // get the direction from the user, assign same direction
{
    if (GetAsyncKeyState(VK_RIGHT))
	{
		Direction =  'R';
		return 'R';
	}
    else if (GetAsyncKeyState(VK_LEFT))
    {
		Direction =  'L';
		return 'L';
	}
    else if (GetAsyncKeyState(VK_UP))
    {
		Direction =  'U';
		return 'U';
	}
    else if (GetAsyncKeyState(VK_DOWN))
    {
		Direction =  'D';
		return 'D';
	}
    else // let the direction as it was !
        return Direction;
}

bool WORLD :: CheckPosition(char MapPostion)
{
	if(MapPostion==(char)177)
		return true ;
	return false;
}

void HERO::UpdatePosition(char Direction)  // if checking got 0 don't call this map
{
	
    if (Direction == 'R')
	{
        HeroPlace.X ++;
		
	}
    else if (Direction == 'L')
        HeroPlace.X --;
    else if (Direction == 'U')
        HeroPlace.Y --;
    else if (Direction == 'D')
       HeroPlace.Y ++;
}

void ENEMY::UpdatePosition(char Direction ) // if checking got 0 don't call this map
{
    if (Direction == 'R')
	    EnemyPlace.X ++; 
    else if (Direction == 'L')
        EnemyPlace.X --;
    else if (Direction == 'U')
	    EnemyPlace.Y --;
    else if (Direction == 'D')
        EnemyPlace.Y ++;
}

void HERO::GotoXY(char OutPut) //it takes the char and cout it of that place
{
    COORD CurrentCoordinate = { HeroPlace.X , HeroPlace.Y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CurrentCoordinate);
	cout << OutPut;
}

char PreChecking(INDEX Place , char Direction)
{
	if(Direction=='U'){
		return MAP[Place.Y-1][Place.X];}
	else if(Direction=='D'){
		return MAP[Place.Y+1][Place.X];}
	else if(Direction=='L'){
		return MAP[Place.Y][Place.X-1];}
	else if(Direction=='R'){
		return MAP[Place.Y][Place.X+1];}
}

void ENEMY::GotoXY(char OutPut) //it takes the random direction and set it and cout the character of that place
{
	COORD CurrentCoordinate = { EnemyPlace.X , EnemyPlace.Y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CurrentCoordinate);
	cout << OutPut;
}

void HERO::UpdateScore (int& CoinsNumber)
{
	if (MAP[HeroPlace.Y][HeroPlace.X] == '.')
        {
			//MAP[HeroPlace.Y][HeroPlace.X]=' ';
            cout<<MAP[HeroPlace.Y][HeroPlace.X];
            Score +=10;
			CoinsNumber --;
	}
        else if (MAP[HeroPlace.Y][HeroPlace.X] == '0')
       {
            //MAP[HeroPlace.Y][HeroPlace.X]=' ';
            cout<<MAP[HeroPlace.Y][HeroPlace.X];
            Score +=50;
	}
}

char  WORLD :: SetRandomDirection() // get random direction in case of enemy
{
	unsigned seed;
    char arr[] = { 'R', 'L', 'U', 'D' };
    return arr[(rand() % 4)];
}

void WORLD :: StartGame ()
{

	int CoinsNumber  = 268;
	int Lives = 4;
	int Score = 0;
	char EnemyOverWrittenPlace;
	ReadMap();

	PacMan.Shape = (char)1;
	PacMan.HeroPlace.X = 15;
	PacMan.HeroPlace.Y = 14;

	Enemies[0].Shape = char (2);
	Enemies[1].Shape = char (2);
    Enemies[2].Shape = char (2);
    Enemies[3].Shape = char (2);
	EnemyOverWrittenPlace=MAP[10][10];
	Enemies[0].EnemyPlace.X = 10;
	Enemies[0].EnemyPlace.Y = 10;
	Enemies[1].EnemyPlace.Y = 10;
	Enemies[1].EnemyPlace.X = 10;
	Enemies[2].EnemyPlace.Y = 10;
	Enemies[2].EnemyPlace.X = 10;
	Enemies[3].EnemyPlace.Y = 10;
	Enemies[3].EnemyPlace.X = 10;

	while (true)
	{
		PacMan.Lives=Lives;
		PacMan.Score =Score;
	    PacMan.Direction = GetInput (PacMan.Direction);
		if ((CheckPosition (PreChecking(PacMan.HeroPlace,PacMan.Direction))) == false)
		{
			PacMan.GotoXY(' ');
     		PacMan.UpdatePosition (PacMan.Direction);
			PacMan.GotoXY(PacMan.Shape);
			PacMan.UpdateScore (CoinsNumber);
			//Special Coin Function of Eat
		}
		for (int i = 0 ; i < 4 ; i++ )
			if ((CheckPosition (PreChecking(Enemies[i].EnemyPlace,Enemies[i].Direction))) == false)
			{

				Enemies[i].GotoXY (EnemyOverWrittenPlace);
				Enemies[i].Direction = SetRandomDirection ();
				Enemies[i].UpdatePosition(Enemies[i].Direction);
				EnemyOverWrittenPlace = MAP[Enemies[i].EnemyPlace.Y][Enemies[i].EnemyPlace.X];
				Enemies[i].GotoXY(Enemies[i].Shape);
				
				Enemies[i].Eat(PacMan.HeroPlace,PacMan.Lives); // Special coin False
			}

	
		if (Coins == 0 || PacMan.Lives == 0)
			 break;
		Sleep (200);
	}
	if (Coins  == 0)
		cout << "You've Finished The Level" << endl;
	if (Lives  == 0)
		cout << "Good Luck, You Lose The Game" << endl;
}
