#include <iostream>
#include <string>


using namespace std; 

struct Board
{
	char board[8][8] = {
						{' ','x',' ','x',' ','x',' ','x'},
						{ 'x',' ','x',' ','x',' ','x',' ' },
						{ ' ','x',' ','x',' ','x',' ','x' },
						{ ' ',' ',' ',' ',' ',' ',' ',' ' },
						{ ' ',' ',' ', ' ', ' ',' ',' ',' '},
						{ 'o',' ','o',' ','o',' ','o',' ' },
						{ ' ','o',' ','o',' ','o',' ','o' },
						{ 'o',' ','o',' ','o',' ','o',' ' },
	};
};

struct Account
{
	string name;
	string username; 
	string password; 
	string email; 
	int wins; 
	string rank;
	

};

//PROTOTYPE
void createAccount( Account * , int);//create account
void instruction(); //display introduction
void game(Account *);//will start game 
void gameBoard(Board &);//display gameboard
void move(Board &, int, int, int, int, char); //if move is valid  move piece
void input(Board &, char); //will take user input 
void check_move(Board &, int, int, int, int, char); // will check move by user. 
bool checkwinMultiplayer(char, Board &, Account *); //will check to see who is the winner
char switchPlayer(char); //switch player each time 
void king(Board &, int, int, int, int, char);//will check the piece to king 
void scores(Account *);//display score by user
void logIn(Account *, int);//will log in user to his/her account
void inputVsComputer(Board &, char);//will be used if user chooses to play against computer 
void computerMove(Board &);//will be used by computer to move its pieces 
void checkInput(Board &, int, int,char );//check input by user to see if piece chosen is his/her 
bool checkwinVsComputer(char, Board &, Account *);//check win user vs computer 
void doLeap(Board &, int , int , int , int , char );// do leap if user wants to 

int main()
{
	 

	
	Account personalInfo[60]; 
	int answer; 
	do
	{
		system("cls");
		cout << "****************************************************" << endl;
		cout << "*********************CHECKER************************" << endl;
		cout << "*****************************************************" << endl;
		cout << "*****************************************************" << endl;
		cout << "\t\t 1. Play\n"
				"\t\t 2.Scores\n"
				"\t\t 3.Create Account\n"
				"\t\t 4.Instructions\n"
				"\t\t 5.Exit" << endl;
		cin >> answer;

		switch (answer)
		{
			case 1:game(personalInfo);  break;
			case 2:scores(personalInfo);  break;
			case 3:createAccount(personalInfo, 0); break;
			case 4: instruction(); break;
				

		}
	} while (answer != 5);

		
		return 0;
}
/*

	user information, log in and scores

*/
void createAccount(Account *personalInfo, int win)//create account 
{
	
	system("cls");

	int sum = 0; 

	
	string answer = "N";
	int i = 0; 

	cout << "******Create Account******" << endl;
	while(answer=="N" || answer=="n")

	{
		
		cout << "Please enter your name?" << endl;
		cin.ignore();
		getline(cin, personalInfo[i].name);
		

		cout << "Please enter your username" << endl;
		cin >> personalInfo[i].username;

		cout << "Please enter password" << endl;
		cin >> personalInfo[i].password;

		cout << "Please enter your email" << endl;
		cin >> personalInfo[i].email;


		personalInfo[i].wins = win ;
		personalInfo[i].rank = "novice";
		
		cout << "To return  press y" << endl; 
		cin >> answer; 

		
		i++;
		
		
	}
	
}
void scores(Account *personalInfo)
{
	system("cls");
	int answer; 

	cout << "******Score*****"<<endl; 
	cout << "You must log in to view your score" << endl; 
	cout << "1. Log in\n"
			"2.Create an Account\n" << endl;
	cin >> answer; 
	switch (answer)
	{
	case 1: logIn(personalInfo, 0); break;
	case 2:createAccount(personalInfo, 0); break; 
	}




}

void logIn(Account *personalInfo, int win)
{
	system("cls");
	
	string answer = "N";
	int i = 0;
	string name; 
	string username; 
	string password; 
	string email; 
	cout << "******Log in******" << endl;
	while (answer == "N" || answer == "n")

	{

		

		cout << "Please enter your username" << endl;//user enters user name 
		cin >> username;

		for (int i = 0; i < 60; i++)//search through array 
		{
			while (personalInfo[i].username == username)//if found ask for password 
			{
				cout << "Please enter password" << endl;
				cin >> password;

				while (personalInfo[i].password != password)//if incorrect password ask again 
				{
					cout << "Invalid password.Please enter the password again" << endl;
					cin >> password; 
				}
				
				personalInfo[i].wins = (personalInfo[i].wins) + win; 

				cout <<"Wins "<< personalInfo[i].wins << endl; 
				if (personalInfo[i].wins < 15)//Display rank 
				{
					personalInfo[i].rank = "Novice"; 
					cout << "Rank:  " << personalInfo[i].rank << endl;
					goto stop;

				}
				else if (personalInfo[i].wins > 15 && personalInfo[i].wins<=30)
				{
					personalInfo[i].rank = "Getting there";
					cout << "Rank:  " << personalInfo[i].rank << endl;
					goto stop;
				}
				else if (personalInfo[i].wins > 30)
				{
					personalInfo[i].rank = "Expert";
					cout << "Rank: " << personalInfo[i].rank << endl;
					goto stop;
				}
			}
				
					
				
		}
		stop:cout << "To return menu press y" << endl; 
		cin >> answer; 

	}

			




}
		


	







void instruction()//instruction on how to play game. 
{
	
	string answer;
	cout << "********Instructions*******" << endl << endl;
	do
	{
		cout <<"1.Checkers is played by two players. Each player begins the game with 12 pieces.\n" 
				"Player 1 will always be x and Player 2 will always be o.)" << endl << endl;
		cout <<"2.The board consists of 64 squares" << endl ;
		cout <<"3. x  moves first.Players then alternate moves." << endl << endl;
		cout <<"4.Pieces always move diagonally.\n"
				"Single pieces are always limited to forward moves(toward the opponent)." << endl << endl;
		cout <<"5.A piece making a non - capturing move(not involving a jump) may move only one square." << endl << endl;
		cout <<"6.A piece making a capturing move(a jump) leaps over one of the opponent's\n "
				"pieces, landing in a straight diagonal line on the other side.\n "
				"Only one piece may be captured in a single jump" << endl << endl;
		cout <<"7.When a piece is captured, it is removed from the board." << endl << endl;
		cout <<"8.If a player is able to make a capture, there is no option -- the jump must be made.\n" << endl;
		cout <<"9.When a piece reaches the furthest row from the player who controls that piece, it is crowned and becomes a king. \n"
			   "That piece will turn X or O ." << endl << endl;
		cout <<"10.Kings are limited to moving diagonally, but may move both forward and backward.\n"
				"(Remember that single pieces, i.e.non - kings, are always limited to forward moves.)." << endl << endl;
		cout <<"11.Kings may combine jumps in several directions -- forward and backward -- on the same turn.\n"
				"Single pieces may shift direction diagonally during a multiple capture turn, but must always jump forward(toward the opponent)." << endl << endl;
		cout <<"12.A player wins the game when the opponent cannot make a move.In most cases,\n"
			"this is because all of the opponent's pieces have been captured, but it could also be because all of his pieces are blocked in." << endl << endl;
		
		cout << "To exit to main menu press y" << endl;
		cin >> answer;
	} while (answer == "n" || answer == "N");
	system("cls");


}

void game(Account *personalInfo)//start game 
{
	system("cls");
	bool winner = false;
	char player1 = 'x';
	char player2 = 'o';
	char computer = 'o';
	char currentPlayer = player1;
	int answer;
	string response = "y";
	Board board;

	while (response == "y" || response == "y")
	{
		
		cout << "1.Single Mode (You against computer)\n" << endl; 
		cout<<	"2.Multiplayer" << endl;
			cin >> answer;

		if (answer == 2)
		{
			while (winner == false)
			{

				gameBoard(board);//display gameboard
				cout << "Player  " << currentPlayer << " " << "is your turn" << endl;
				input(board, currentPlayer);
				winner = checkwinMultiplayer(currentPlayer, board, personalInfo);
				currentPlayer = switchPlayer(currentPlayer);//switch player each turn 
			}
		}


		if (answer == 1)
		{
			while (winner == false)
			{

				gameBoard(board);//display gameboard
				cout << "Player  " << currentPlayer << " " << "is your turn" << endl;
				inputVsComputer(board, currentPlayer);
				winner = checkwinVsComputer(currentPlayer, board, personalInfo);
				currentPlayer = switchPlayer(currentPlayer);//switch player each turn 
			}
		}

		cout << "Do you want to continue playing" << endl;
		cin >> response;
		system("cls");
	}
	

	

	
}

void gameBoard(Board &gameboard)//display game board
{
	
	
	
	
	cout << "Player 1\t\t" << "Player 2" << endl;
	cout << "     x\t\t\t" << "o" << endl;
	cout << "____________________________________" << endl;
	cout << endl;



	cout << "     0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |\n";
	cout << "   ----------------------------------" << endl; 
	
	for (int i = 0; i < 8; i++)
	{
		cout << i  << " | ";
		for (int j = 0; j < 8; j++)
		{
			cout <<"_" << gameboard.board[i][j]<< "_|" ;

		}
		cout << endl;
	}
	 


	
}

void input(Board &gameboard, char current_player)//takes player input. This is for multiplayer
{
	
	int x;
	int y;
	int x1;
	int y1;
	
		cout << "Please choose a piece. Enter row and column. For example 3 2 " << endl;
		cin >> x >> y;
		
		checkInput(gameboard, x, y, current_player);
		
		cout << "Choose location where you want to move it. Enter row and column. For example 3 2" << endl;
		cin >> x1 >> y1;

		check_move(gameboard, x, y, x1, y1, current_player);
		

}
void checkInput(Board &gameboard, int x1, int y1, char player)//check to see if player is chosen his/her piece
{
	if (player == 'x')
	{
		while (!(gameboard.board[x1][y1] == 'x' || gameboard.board[x1][y1] == 'X'))
		{
			cout << "invalid input. choose your own piece" << endl;
			cin >> x1 >> y1;


		}
	}
	else if (player == 'o')
	{
		while (!(gameboard.board[x1][y1] == 'o' || gameboard.board[x1][y1] == 'O'))
		{
			cout << "invalid input. choose your own piece" << endl;
			cin >> x1 >> y1;

		}
	}


}
void king(Board &gameboard, int x, int y, int x1, int y1, char player)//if user gets to the end of opposite board change piece to king X or O 
{

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (gameboard.board[7][j] == 'x')
			{
				gameboard.board[7][j] = 'X';
			}

			else if (gameboard.board[0][j] == 'o')
			{

				gameboard.board[0][j] = 'O';

			}
		}
	}

	

}

void move(Board &gameboard, int x, int y , int x1, int y1, char player)//move piece 
{
	king(gameboard,  x,  y,  x1,  y1,  player);

	if (gameboard.board[x][y] == 'X')
	{
		gameboard.board[x][y] = ' ';
		gameboard.board[x1][y1] = 'X';
	}
	else if (gameboard.board[x][y] == 'O')
	{
		gameboard.board[x][y] = ' ';
		gameboard.board[x1][y1] = 'O';
	}

	else
	{
		gameboard.board[x][y] = ' ';
		gameboard.board[x1][y1] = player;

	}
	

	
}



void check_move(Board &gameboard,int x, int y, int x1, int y1, char player)// make sure movement chosen by user  is valid
{
	string answer; 
	
	
	while (y == y1 || x == x1 )//check to see if player is moving diagnolly 
	{
		cout << "Invalid move. You can only move diagonally. Please choose another location " << endl;
		cin >> x1 >> y1;
	}

	if (!(gameboard.board[x][y] == 'X' || gameboard.board[x][y] == 'O'))//If not king check to see if moving backwards 
	{
		while ((player == 'x' && x > x1) || (player == 'o' && x1 > x))//check to see if user is moving backwards
		{
			cout << "You cannot move backwards. Please choose another location" << endl;
			cin >> x1 >> y1;

		}


	}

	while (gameboard.board[x1][y1] !=' ')//check if square is chosen by player is not empty 
	{
		cout << "Invalid move.Space needs to be empty. Please choose another location " << endl;
		cin >> x1 >> y1;

	}

	cout << "Do you want to leap" << endl;//will let user leap over opponent and remove piece 
	cin >> answer;

	if (answer == "y" || answer == "Y")
	{
		doLeap(gameboard, x, y, x1, y1, player);

	} 
	else
	{
		while ( (! (x1 == x + 1 || x1 == x - 1 )) ||(!(y1 == y - 1 || y1 == y + 1)))//It checks if piece is moving by more than 1 row and column
		{
			cout << "Invalid move. You can only move 1 space. Please choose another location " << endl;
			cin >> x1 >> y1;
		}
		
		
	
	}

	
	 if (gameboard.board[x1][y1] == ' ')//if square chosen is empty move pieces 
	{

		move(gameboard, x, y, x1, y1, player);


	}

	
		
}
void doLeap(Board &gameboard, int x, int y, int x1, int y1, char player)//leap if taking over opponent 
{
	

	//It removes the checker piece after leap. 
	if (x1 > x && y1 > y)
		{
			gameboard.board[x1 - 1][y1 - 1] = ' ';
		}
	else if (x1 > x && y1 < y)
		{
			gameboard.board[x1 - 1][y1 + 1] = ' ';
		}
	else if (x1 < x && y1 > y)
		{
			gameboard.board[x1 + 1][y1 - 1] = ' ';
		}
	else if (x1 < x && y1 < y)
		{
			gameboard.board[x1 + 1][y1 + 1] = ' ';
		}

	

}
char switchPlayer(char currentPlayer)//Switch player each turn
{

	if (currentPlayer == 'x' )
	{
		 currentPlayer = 'o';
	}
	else if (currentPlayer == 'o' )
	{

		 currentPlayer = 'x';
	}

	return currentPlayer; 



}
bool checkwinMultiplayer(char currentPlayer, Board &gameboard, Account *personalInfo)// will check win if in multiplayer mode 
{
	bool winner=true; 
	string answer; 
	int count = 0;//will be use to check whole board depending on the player and  if count==64 then announce the winner 
	
	while (currentPlayer == 'x')
	{
		
		for (int i = 0; i < 8; i++)//check whole board looking for opponent piece. if not found declare winner. 
		{
			
			for (int j = 0; j < 8; j++)
			{
				if (gameboard.board[i][j] != 'o')
				{
					count++;
					if (count == 64)
					{
						/*next lines will let player enter his/her account or  create a new account to record win*/
						cout << "winner is player 1" << endl; 
						if (winner == true)
						{
							cout << "if you want to record win press y" << endl; 
							cin >> answer; 
							if (answer == "y" || answer == "Y")
							{
								cout << "You must log in to record win. If you have an account press y" << endl; 
								cin >> answer; 
								if (answer == "y" || answer == "Y")
								{
									logIn(personalInfo, 1);
									return true; 

								}
								else if (answer == "n" || answer == "N")
								{
									cout << "If you want to create an account. press y" << endl; 
									cin >> answer; 
									if (answer == "y" || answer == "yes")
									{

										createAccount(personalInfo, 1 );
										return true;
									}

								}

							}
							else
							{
								return true; 

							}

						}

					}
				}

			}
			
		}

		break; //end look after loop through whole board and no winner found 
	}

	while (currentPlayer == 'o')
	{
		
		for (int i = 0; i < 8; i++)
		{

			for (int j = 0; j < 8; j++)
			{
				if (gameboard.board[i][j] != 'x')
				{
					count++;
					if (count == 64)
					{
						/*next lines will let player enter his/her account or  create a new account to record win*/
						cout << "winner is player 2" << endl;
						if (winner == true)
						{
							cout << "if you want to record win press y" << endl;
							cin >> answer;
							if (answer == "y" || answer == "Y")
							{
								cout << "You must log in to record win. If you have an account press y" << endl;
								cin >> answer;
								if (answer == "y" || answer == "Y")
								{
									logIn(personalInfo, 1);
									return true;

								}
								else if (answer == "n" || answer == "N")
								{
									cout << "If you want to create an account. press y" << endl;
									cin >> answer;
									if (answer == "y" || answer == "yes")
									{

										createAccount(personalInfo, 1);
										return true;
									}

								}

							}
							else
							{
								return true;

							}

						}

					}
				}

			}

		}

		
		break; 
	}
	


	return false; 

	

}


//USER VS COMPUTER 

void inputVsComputer(Board &gameboard , char currentPlayer)// input from user vs computer 
{

	int x;
	int y;
	int x1;
	int y1;
	
	 if (currentPlayer == 'x')
		{
			cout << "Please choose a piece. Enter row and column. For example 3 2 " << endl;
			cin >> x >> y;

			checkInput(gameboard, x, y, currentPlayer);

			cout << "Choose location where you want to move it. Enter row and column. For example 3 2" << endl;
			cin >> x1 >> y1;

			check_move(gameboard, x, y, x1, y1, currentPlayer);
		
	}

	else if (currentPlayer == 'o')
	{
		computerMove(gameboard);
		




	}


}

void computerMove(Board &gameboard)// This has all the movement computer can make 
{
	string goback; 
	for (int i = 0; i < 8; i++)
	{
			//search throught the whole board for 'o' if found do move
		for (int j = 0; j < 8; j++)
		{
			while (gameboard.board[i][j]=='o')
			{
				if (gameboard.board[i - 1][j + 1] == ' ')//if  square right is empyt make move
				{
					
						gameboard.board[i - 1][j + 1] = 'o';
						gameboard.board[i][j] = ' ';


						goto stop;

				
					
				}

				else if (gameboard.board[i - 1][j - 1] == ' ')//if  square left is empyt make move
				{
					
						gameboard.board[i - 1][j - 1] = 'o';
						gameboard.board[i][j] = ' ';

						goto stop;
						

					
					
				}
			

				else if (gameboard.board[i - 1][j + 1] == 'x')//if next square is equals to x check square behind to see if empty. if empty make move
				{
					if (gameboard.board[i - 2][j + 2] == ' ')
					{
						gameboard.board[i][j] = ' ';
						gameboard.board[i - 2][j + 2] = 'o';
						gameboard.board[i - 1][j + 1] = ' ';
						goto stop;

					}
				}
				

					break; //break from while loop 
				
				
			

			}

		}
		
	}

stop: 	 goback;
	

}



bool checkwinVsComputer(char currentPlayer, Board &gameboard, Account *personalInfo)//check win user vs computer 
{
	bool winner = true;
	string answer;
	int count = 0;//will be use to check whole board depending on the player and  if count==64 then announce the winner 

	while (currentPlayer == 'x')
	{

		for (int i = 0; i < 8; i++)//check whole board looking for opponent piece. if not found declare winner. 
		{

			for (int j = 0; j < 8; j++)
			{
				if (gameboard.board[i][j] != 'o')
				{
					count++;
					if (count == 64)
					{
						/*next lines will let player enter his/her account or  create a new account to record win*/
						cout << "winner is player 1" << endl;
						if (winner == true)
						{
							cout << "if you want to record win press y" << endl;
							cin >> answer;
							if (answer == "y" || answer == "Y")
							{
								cout << "You must log in to record win. If you have an account press y" << endl;
								cin >> answer;
								if (answer == "y" || answer == "Y")
								{
									logIn(personalInfo, 1);
									return true;

								}
								else if (answer == "n" || answer == "N")
								{
									cout << "If you want to create an account. press y" << endl;
									cin >> answer;
									if (answer == "y" || answer == "yes")
									{

										createAccount(personalInfo, 1);
										return true;
									}

								}

							}
							else
							{
								return true;

							}

						}

					}
				}

			}

		}

		break; //end look after loop through whole board and no winner found 
	}

	while (currentPlayer == 'o')
	{

		for (int i = 0; i < 8; i++)
		{

			for (int j = 0; j < 8; j++)
			{
				if (gameboard.board[i][j] != 'x')
				{
					count++;
					if (count == 64)
					{

						cout << "winner is computer" << endl;
						return true; 

					}

					
				}

			}

		}


		break;
	}



	return false;





}