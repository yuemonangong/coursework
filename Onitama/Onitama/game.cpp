#include "game.h"

game::game()
{
	gameMatrix = new int *[5];
	for (int i = 0; i < 5; ++i)
		gameMatrix[i] = new int[5];
	for (int i = 0; i < 5; ++i)
		for (int j = 1; j < 4; ++j)
			gameMatrix[i][j] = 0;
	for (int i = 0; i < 5; ++i) {
		gameMatrix[i][0] = 1;
		gameMatrix[i][4] = -1;
	}
	gameMatrix[2][0] = 2;
	gameMatrix[2][4] = -2;
	areaSize = 0;
	currentplayer = true;
}


game::~game()
{
	for (int i = 0; i < 5; ++i) delete [] gameMatrix[i];
	delete [] gameMatrix;
}

void game::printMatrix() const
{
	for (int j = 4; j >= 0; --j) {
		for (int i = 0; i < 5; ++i)
			cout << gameMatrix[i][j] << '\t';
		cout << '\n' << endl;
	}
}

void game::printDeck() const
{
	if (areaSize < 13) return;
	areas[0]->display();
	for (int i = 3; i < 13; ++i) areas[i]->display();
	cout << endl;
}

bool game::posContained(int x, int y, int * A, int * B) const
{
	for (int i = 0; A[i] != -1; ++i)
		if (x == A[i] && y == B[i]) return true;
	return false;
}

void game::highlight(int x, int y, int * A, int * B) const
{
	for (int j = 4; j >= 0; --j) {
		for (int i = 0; i < 5; ++i) {
			if (i == x && j == y) cout << '(' << gameMatrix[i][j] << ')' << '\t';
			else if (posContained(i, j, A, B)) cout << '*' << gameMatrix[i][j] << '*' << '\t';
			else cout << gameMatrix[i][j] << '\t';
		}
		cout << '\n' << endl;
	}
}

void game::display() const
{
	printMatrix();
	for (int i = 0; i < areaSize; ++i) areas[i]->display();
	cout << endl;
}

string game::getCurrentPlayer() const
{
	if (currentplayer) return "player1";
	else return "player2";
}

void game::lowPreparation()
{
	string cardNames[15] = { "Dog", "Turtle", "Monkey", "Tiger", "Rooster", "Dragon", "Horse", "Ox", "Snake", "Mouse", "Rabbit", "Ostrich", "Frog", "Sheep", "Boar" };
	areas = new area *[4];
	areas[0] = new area("origin", 15);
	areas[1] = new area("player1", 2);
	areas[2] = new area("player2", 2);
	areas[3] = new area("bench", 1);
	areaSize = 4;
	for (int i = 0; i < 15; ++i) areas[0]->addCard(card(cardNames[i]));
	for (int i = 0; i < 2; ++i)
	{
		card c = areas[0]->selectRanCard();
		areas[1]->addCard(c);
		areas[0]->removeCard(c);
	}
	for (int i = 0; i < 2; ++i)
	{
		card c = areas[0]->selectRanCard();
		areas[2]->addCard(c);
		areas[0]->removeCard(c);
	}
	card c = areas[0]->selectRanCard();
	areas[3]->addCard(c);
	areas[0]->removeCard(c);
}

void game::highPreparation()
{
	string cardNames[15] = { "Dog", "Turtle", "Monkey", "Tiger", "Rooster", "Dragon", "Horse", "Ox", "Snake", "Mouse", "Rabbit", "Ostrich", "Frog", "Sheep", "Boar" };
	areas = new area *[13];
	areas[0] = new area("origin", 15);
	areas[1] = new area("player1", 3);
	areas[2] = new area("player2", 3);
	areas[3] = new area("sDeck0", 3);
	areas[4] = new area("sDeck1", 3);
	areas[5] = new area("sDeck2", 3);
	areas[6] = new area("sDeck3", 3);
	areas[7] = new area("sDeck4", 3);
	areas[8] = new area("dDeck0", 3);
	areas[9] = new area("dDeck1", 3);
	areas[10] = new area("dDeck2", 3);
	areas[11] = new area("dDeck3", 3);
	areas[12] = new area("dDeck4", 3);
	areaSize = 13;

	card c;
	int deckNum;
	for (int i = 0; i < 15; ++i) areas[0]->addCard(card(cardNames[i]));
	for (int i = 0; i < 7; ++i)
	{
		printDeck();
		cout << "Player1 Stage: " << endl;
		c = chooseCard(0);
		deckNum = chooseDeck(0);
		areas[0]->removeCard(c);
		areas[deckNum]->addCard(c);

		printDeck();
		cout << "Player2 Stage: " << endl;
		c = chooseCard(0);
		deckNum = chooseDeck(0);
		areas[0]->removeCard(c);
		areas[deckNum]->addCard(c);
	}
	c = areas[0]->selectRanCard();
	for (int i = 3; i < 8; ++i)
		if (areas[i]->isAvailable()) {
			areas[i]->addCard(c);
			areas[0]->removeCard(c);
		}
}

bool game::lowJumpAction(const card &c)
{
	if (currentplayer) {
		if (!areas[1]->isContained(c)) return false;
		areas[1]->removeCard(c);
		areas[1]->addCard(areas[3]->selectRanCard());
		areas[3]->removeCard(areas[3]->selectRanCard());
		areas[3]->addCard(c);
		currentplayer = false;
	}
	else {
		if (!areas[2]->isContained(c)) return false;
		areas[2]->removeCard(c);
		areas[2]->addCard(areas[3]->selectRanCard());
		areas[3]->removeCard(areas[3]->selectRanCard());
		areas[3]->addCard(c);
		currentplayer = true;
	}
	return true;
}

bool game::lowNormalActionI(const card &c, int x, int y, int * A, int * B)
{
	if (currentplayer) { if (!areas[1]->isContained(c)) return false; }
	else { if (!areas[2]->isContained(c)) return false; }
	if (currentplayer) getAccessPlaces(x, y, 1, c, A, B);
	else getAccessPlaces(x, y, 2, c, A, B);
	if (A[0] == -1) return false;
	return true;
}

int game::lowNormalActionII(int sx, int sy, int dx, int dy, int * A, int * B)
{
	if (!posContained(dx, dy, A, B)) return 0;
	if (currentplayer) {
		currentplayer = false;
		if (moveChessCheckWin(sx, sy, dx, dy, 1)) return 2;
	}
	else {
		currentplayer = true;
		if (moveChessCheckWin(sx, sy, dx, dy, 2)) return 2;
	}
	return 1;
}

bool game::midJumpAction(const card &c)
{
	if (currentplayer) {
		if (!areas[1]->isContained(c)) return false;
		areas[1]->removeCard(c);
		areas[1]->addCard(areas[3]->selectRanCard());
		areas[3]->removeCard(areas[3]->selectRanCard());
		areas[3]->addCard(c);
	}
	else {
		if (!areas[2]->isContained(c)) return false;
		areas[2]->removeCard(c);
		areas[2]->addCard(areas[3]->selectRanCard());
		areas[3]->removeCard(areas[3]->selectRanCard());
		areas[3]->addCard(c);
	}
	return true;
}

bool game::midNormalActionI(const card & c, int x, int y, int * A, int * B)
{
	if (currentplayer) { if (!areas[1]->isContained(c)) return false; }
	else { if (!areas[2]->isContained(c)) return false; }
	if (currentplayer) getAccessPlaces(x, y, 1, c, A, B);
	else getAccessPlaces(x, y, 2, c, A, B);
	if (A[0] == -1) return false;
	return true;
}

int game::midNormalActionII(const card & c, int sx, int sy, int dx, int dy, int * A, int * B)
{
	if (!posContained(dx, dy, A, B)) return 0;
	if (currentplayer) {
		currentplayer = false;
		areas[1]->removeCard(c);
		areas[1]->addCard(areas[3]->selectRanCard());
		areas[3]->removeCard(areas[3]->selectRanCard());
		areas[3]->addCard(c);
		if (moveChessCheckWin(sx, sy, dx, dy, 1)) return 2;
	}
	else {
		currentplayer = true;
		areas[2]->removeCard(c);
		areas[2]->addCard(areas[3]->selectRanCard());
		areas[3]->removeCard(areas[3]->selectRanCard());
		areas[3]->addCard(c);
		if (moveChessCheckWin(sx, sy, dx, dy, 2)) return 2;
	}
	return 1;
}

bool game::lowAction(int player)
{
	bool flag = jumpAction();
	card c;
	pair<int, int> source, destination;
	int *A, *B;
	A = new int[5];
	B = new int[5];
	if (flag) {
		if (player == 1) {
			c = chooseCard(1);
			areas[1]->removeCard(c);
			areas[1]->addCard(areas[3]->selectRanCard());
			areas[3]->removeCard(areas[3]->selectRanCard());
			areas[3]->addCard(c);
		}
		if (player == 2) {
			c = chooseCard(2);
			areas[2]->removeCard(c);
			areas[2]->addCard(areas[3]->selectRanCard());
			areas[3]->removeCard(areas[3]->selectRanCard());
			areas[3]->addCard(c);
		}
		return false;
	}

	if (player == 1) {
		while (1) {
			c = chooseCard(1);
			source = choosePos();
			getAccessPlaces(source.first, source.second, player, c, A, B);
			if (A[0] == -1) { cout << "No availavle place to move to." << endl; continue; }
			highlight(source.first, source.second, A, B);
			while (1) {
				destination = choosePos();
				if (posContained(destination.first, destination.second, A, B)) break;
				cout << "Not available Place." << endl;
			}
			return moveChessCheckWin(source.first, source.second, destination.first, destination.second, player);
		}
	}
	if (player == 2) {
		while (1) {
			c = chooseCard(2);
			source = choosePos();
			getAccessPlaces(source.first, source.second, player, c, A, B);
			if (A[0] == -1) { cout << "No availavle place to move to." << endl; continue; }
			highlight(source.first, source.second, A, B);
			while (1) {
				destination = choosePos();
				if (posContained(destination.first, destination.second, A, B)) break;
				cout << "Not available Place." << endl;
			}
			return moveChessCheckWin(source.first, source.second, destination.first, destination.second, player);
		}
	}
}

bool game::midAction(int player)
{
	bool flag = jumpAction();
	card c;
	pair<int, int> source, destination;
	int *A, *B;
	A = new int[5];
	B = new int[5];
	if (flag) {
		if (player == 1) {
			c = chooseCard(1);
			areas[1]->removeCard(c);
			areas[1]->addCard(areas[3]->selectRanCard());
			areas[3]->removeCard(areas[3]->selectRanCard());
			areas[3]->addCard(c);
		}
		if (player == 2) {
			c = chooseCard(2);
			areas[2]->removeCard(c);
			areas[2]->addCard(areas[3]->selectRanCard());
			areas[3]->removeCard(areas[3]->selectRanCard());
			areas[3]->addCard(c);
		}
		return false;
	}

	if (player == 1) {
		while (1) {
			c = chooseCard(1);
			source = choosePos();
			getAccessPlaces(source.first, source.second, player, c, A, B);
			if (A[0] == -1) { cout << "No availavle place to move to." << endl; continue; }
			highlight(source.first, source.second, A, B);
			while (1) {
				destination = choosePos();
				if (posContained(destination.first, destination.second, A, B)) break;
				cout << "Not available Place." << endl;
			}
			flag = moveChessCheckWin(source.first, source.second, destination.first, destination.second, player);
			areas[1]->removeCard(c);
			areas[1]->addCard(areas[3]->selectRanCard());
			areas[3]->removeCard(areas[3]->selectRanCard());
			areas[3]->addCard(c);
			return flag;
		}
	}
	if (player == 2) {
		while (1) {
			c = chooseCard(2);
			source = choosePos();
			getAccessPlaces(source.first, source.second, player, c, A, B);
			if (A[0] == -1) { cout << "No availavle place to move to." << endl; continue; }
			highlight(source.first, source.second, A, B);
			while (1) {
				destination = choosePos();
				if (posContained(destination.first, destination.second, A, B)) break;
				cout << "Not available Place." << endl;
			}
			flag = moveChessCheckWin(source.first, source.second, destination.first, destination.second, player);
			areas[2]->removeCard(c);
			areas[2]->addCard(areas[3]->selectRanCard());
			areas[3]->removeCard(areas[3]->selectRanCard());
			areas[3]->addCard(c);
			return flag;
		}
	}
}

bool game::highAction(int player)
{
	bool flag;
	card c;
	pair<int, int> source, destination;
	int *A, *B, deckNum, fullNum;
	static int chooseOrder = 1;	//chooseOrder为1，玩家1先选，为2，玩家2先选。
	A = new int[5];
	B = new int[5];

	if (areas[1]->isEmpty() && areas[2]->isEmpty())
	{
		cout << "Choosing hand cards: " << endl;

		fullNum = 0;
		for (int i = 3; i < 8; ++i)
			if (!areas[i]->isEmpty()) ++fullNum;
		if (fullNum == 1) {
			for (int i = 3; i < 8; ++i)
				if (!areas[i]->isEmpty()) {
					for (int j = 0; j < 3; ++j) {
						c = areas[i]->selectRanCard();
						areas[i]->removeCard(c);
						for (int k = 8; k < 13; ++k)
							if (areas[k]->isAvailable()) {
								areas[k]->addCard(c);
								break;
							}
					}
					break;
				}
			for (int i = 0; i < 5; ++i) swap(areas[i + 3], areas[i + 8]);
		}

		display();
		
		if (chooseOrder == 1) {
			while (1) {
				cout << "Player1 selecting hand cards, please input deck num: ";
				cin >> deckNum;
				if (deckNum >= 0 && deckNum <= 4 && !areas[deckNum + 3]->isEmpty()) break;
				else cout << "Wrong deck num." << endl;
			}
			deckNum += 3;
			for (int i = 0; i < 3; ++i) {
				c = areas[deckNum]->selectRanCard();
				areas[1]->addCard(c);
				areas[deckNum]->removeCard(c);
			}

			while (1) {
				cout << "Player2 selecting hand cards, please input deck num: ";
				cin >> deckNum;
				if (deckNum >= 0 && deckNum <= 4 && !areas[deckNum + 3]->isEmpty()) break;
				else cout << "Wrong deck num." << endl;
			}
			deckNum += 3;
			for (int i = 0; i < 3; ++i) {
				c = areas[deckNum]->selectRanCard();
				areas[2]->addCard(c);
				areas[deckNum]->removeCard(c);
			}

			chooseOrder = 2;
		}
		else {
			while (1) {
				cout << "Player2 selecting hand cards, please input deck num: ";
				cin >> deckNum;
				if (deckNum >= 0 && deckNum <= 4 && !areas[deckNum + 3]->isEmpty()) break;
				else cout << "Wrong deck num." << endl;
			}
			deckNum += 3;
			for (int i = 0; i < 3; ++i) {
				c = areas[deckNum]->selectRanCard();
				areas[2]->addCard(c);
				areas[deckNum]->removeCard(c);
			}

			while (1) {
				cout << "Player1 selecting hand cards, please input deck num: ";
				cin >> deckNum;
				if (deckNum >= 0 && deckNum <= 4 && !areas[deckNum + 3]->isEmpty()) break;
				else cout << "Wrong deck num." << endl;
			}
			deckNum += 3;
			for (int i = 0; i < 3; ++i) {
				c = areas[deckNum]->selectRanCard();
				areas[1]->addCard(c);
				areas[deckNum]->removeCard(c);
			}

			chooseOrder = 1;
		}
	}

	display();
	if (player == 1) cout << "Player1 Stage: " << endl;
	else cout << "Player2 Stage: " << endl;
	flag = jumpAction();

	if (flag)
	{
		if (player == 1) {
			c = chooseCard(1);
			deckNum = chooseDeck(1);
			areas[1]->removeCard(c);
			areas[deckNum]->addCard(c);
		}
		if (player == 2) {
			c = chooseCard(2);
			deckNum = chooseDeck(1);
			areas[2]->removeCard(c);
			areas[deckNum]->addCard(c);
		}
		return false;
	}

	if (player == 1) {
		while (1) {
			c = chooseCard(1);
			source = choosePos();
			getAccessPlaces(source.first, source.second, player, c, A, B);
			if (A[0] == -1) { cout << "No availavle place to move to." << endl; continue; }
			highlight(source.first, source.second, A, B);
			while (1) {
				destination = choosePos();
				if (posContained(destination.first, destination.second, A, B)) break;
				cout << "Not available Place." << endl;
			}
			flag = moveChessCheckWin(source.first, source.second, destination.first, destination.second, player);
			deckNum = chooseDeck(1);
			areas[1]->removeCard(c);
			areas[deckNum]->addCard(c);
			return flag;
		}
	}
	if (player == 2) {
		while (1) {
			c = chooseCard(2);
			source = choosePos();
			getAccessPlaces(source.first, source.second, player, c, A, B);
			if (A[0] == -1) { cout << "No availavle place to move to." << endl; continue; }
			highlight(source.first, source.second, A, B);
			while (1) {
				destination = choosePos();
				if (posContained(destination.first, destination.second, A, B)) break;
				cout << "Not available Place." << endl;
			}
			flag = moveChessCheckWin(source.first, source.second, destination.first, destination.second, player);
			deckNum = chooseDeck(1);
			areas[2]->removeCard(c);
			areas[deckNum]->addCard(c);
			return flag;
		}
	}
}

void game::lowPlay()
{
	lowPreparation();
	display();
	while (1)
	{
		cout << "Player1 Stage: " << endl;
		if (lowAction(1)) {
			cout << "Player1 wins." << endl;
			return;
		}
		display();
		cout << "Player2 Stage: " << endl;
		if (lowAction(2)) {
			cout << "Player2 wins." << endl;
			return;
		}
		display();
	}
}

void game::midPlay()
{
	lowPreparation();
	display();
	while (1)
	{
		cout << "Player1 Stage: " << endl;
		if (midAction(1)) {
			cout << "Player1 wins." << endl;
			return;
		}
		display();
		cout << "Player2 Stage: " << endl;
		if (midAction(2)) {
			cout << "Player2 wins." << endl;
			return;
		}
		display();
	}
}

void game::highPlay()
{
	highPreparation();
	while (1)
	{
		if (highAction(1)) {
			cout << "Player1 wins." << endl;
			return;
		}
		if (highAction(2)) {
			cout << "Player2 wins." << endl;
			return;
		}
	}
}

bool game::moveChessCheckWin(int sx, int sy, int dx, int dy, int player)
{
	bool win = false;
	if (gameMatrix[dx][dy] == 2 || gameMatrix[dx][dy] == -2) win = true;
	if (player == 1 && dx == 2 && dy == 4 && gameMatrix[sx][sy] == 2) win = true;
	if (player == 2 && dx == 2 && dy == 0 && gameMatrix[sx][sy] == -2) win = true;
	gameMatrix[dx][dy] = gameMatrix[sx][sy];
	gameMatrix[sx][sy] = 0;
	return win;
}

card game::chooseCard(int index) const
{
	string cardName;
	while (1) {
		cout << "Selecting card: ";
		cin >> cardName;
		if (areas[index]->isContained(card(cardName))) return card(cardName);
		else cout << "This area does not contain this card." << endl;
	}
}

pair<int, int> game::choosePos() const
{
	pair<int, int> p;
	while (1) {
		cout << "Selecting position: ";
		cin >> p.first >> p.second;
		if (p.first >= 0 && p.first <= 4 && p.second >= 0 && p.second <= 4) return p;
		else cout << "This position is out of bound." << endl;
	}
}

int game::chooseDeck(int index) const
{
	int deckNum;
	if (index == 0) {
		while (1) {
			cout << "Selecting deck num: ";
			cin >> deckNum;
			if (deckNum >= 0 && deckNum <= 4 && areas[deckNum + 3]->isAvailable()) return deckNum + 3;
			else cout << "Not available deck num." << endl;
		}
	}
	if (index == 1) {
		while (1) {
			cout << "Selecting deck num: ";
			cin >> deckNum;
			if (deckNum >= 0 && deckNum <= 4 && areas[deckNum + 8]->isAvailable()) return deckNum + 8;
			else cout << "Not available deck num." << endl;
		}
	}
}

bool game::jumpAction() const
{
	int jump;
	cout << "Jump action stage or not? (1 is yes, 0 is no): ";
	cin >> jump;
	if (jump == 0) return 0;
	else return 1;
}

void game::getAccessPlaces(int x, int y, int player, card c, int * A, int * B) const
{
	if (x<0 || x>4 || y<0 || y>4) {
		A[0] = -1;
		B[0] = -1;
		return;
	}
	else {
		if (c.getname() == "Dog")
			dognextstep(x, y, player, A, B);
		if (c.getname() == "Turtle")
			turtlenextstep(x, y, player, A, B);
		if (c.getname() == "Monkey")
			monkeynextstep(x, y, player, A, B);
		if (c.getname() == "Tiger")
			tigernextstep(x, y, player, A, B);
		if (c.getname() == "Rooster")
			roosternextstep(x, y, player, A, B);
		if (c.getname() == "Dragon")
			dragonnextstep(x, y, player, A, B);
		if (c.getname() == "Horse")
			horsenextstep(x, y, player, A, B);
		if (c.getname() == "Ox")
			oxnextstep(x, y, player, A, B);
		if (c.getname() == "Snake")
			snakenextstep(x, y, player, A, B);
		if (c.getname() == "Mouse")
			mousenextstep(x, y, player, A, B);
		if (c.getname() == "Rabbit")
			rabbitnextstep(x, y, player, A, B);
		if (c.getname() == "Ostrich")
			ostrichnextstep(x, y, player, A, B);
		if (c.getname() == "Frog")
			frognextstep(x, y, player, A, B);
		if (c.getname() == "Sheep")
			sheepnextstep(x, y, player, A, B);
		if (c.getname() == "Boar")
			boarnextstep(x, y, player, A, B);
	}
}

void game::dognextstep(int x, int y, int player, int * A, int * B)const
{
	int num = 0;
	if (player == 1) {                                                   //player 1
		if (gameMatrix[x][y]<1) {
			A[0] = -1;
			B[0] = -1;
			return;
		}
		else {
			if (x - 1 >= 0 && y + 1 <= 4 && gameMatrix[x - 1][y + 1] <= 0) {                                           //x-1,y+1 ok?
				A[num] = x - 1;
				B[num] = y + 1;
				num++;
			}
			if (x - 1 >= 0 && gameMatrix[x - 1][y] <= 0) {                                          //x-1,y ok?
				A[num] = x - 1;
				B[num] = y;
				num++;
			}
			if (x - 1 >= 0 && y - 1 >= 0 && gameMatrix[x - 1][y - 1] <= 0) {                                 //x-1,y-1 ok?
				A[num] = x - 1;
				B[num] = y - 1;
				num++;
			}
			A[num] = -1;
			B[num] = -1;
			return;
		}
	}
	if (player == 2) {                                                       //player 2
		if (gameMatrix[x][y]>-1) {
			A[0] = -1;
			B[0] = -1;
			return;
		}
		else {
			if (x + 1 <= 4 && y + 1 <= 4 && gameMatrix[x + 1][y + 1] >= 0) {                                           //x+1,y+1 ok?
				A[num] = x + 1;
				B[num] = y + 1;
				num++;
			}
			if (x + 1 <= 4 && gameMatrix[x + 1][y] >= 0) {                                          //x+1,y ok?
				A[num] = x + 1;
				B[num] = y;
				num++;
			}
			if (x + 1 <= 4 && y - 1 >= 0 && gameMatrix[x + 1][y - 1] >= 0) {                                 //x+1,y-1 ok?
				A[num] = x + 1;
				B[num] = y - 1;
				num++;
			}
			A[num] = -1;
			B[num] = -1;
			return;
		}
	}
}

void game::monkeynextstep(int x, int y, int player, int * A, int * B)const
{
	int num = 0;
	if (player == 1) {                                                   //player 1
		if (gameMatrix[x][y]<1) {
			A[0] = -1;
			B[0] = -1;
			return;
		}
		else {
			if (x + 1 <= 4 && y + 1 <= 4 && gameMatrix[x + 1][y + 1] <= 0) {                                           //x+1,y+1 ok?
				A[num] = x + 1;
				B[num] = y + 1;
				num++;
			}
			if (x + 1 <= 4 && gameMatrix[x + 1][y] <= 0) {                                          //x+1,y ok?
				A[num] = x + 1;
				B[num] = y;
				num++;
			}
			if (x + 1 <= 4 && y - 1 >= 0 && gameMatrix[x + 1][y - 1] <= 0) {                                 //x+1,y-1 ok?
				A[num] = x + 1;
				B[num] = y - 1;
				num++;
			}
			A[num] = -1;
			B[num] = -1;
			return;
		}
	}
	if (player == 2) {                                                       //player 2
		if (gameMatrix[x][y]>-1) {
			A[0] = -1;
			B[0] = -1;
			return;
		}
		else {
			if (x - 1 >= 0 && y + 1 <= 4 && gameMatrix[x - 1][y + 1] >= 0) {                                           //x-1,y+1 ok?
				A[num] = x - 1;
				B[num] = y + 1;
				num++;
			}
			if (x - 1 >= 0 && gameMatrix[x - 1][y] >= 0) {                                          //x-1,y ok?
				A[num] = x - 1;
				B[num] = y;
				num++;
			}
			if (x - 1 >= 0 && y - 1 >= 0 && gameMatrix[x - 1][y - 1] >= 0) {                                 //x-1,y-1 ok?
				A[num] = x - 1;
				B[num] = y - 1;
				num++;
			}
			A[num] = -1;
			B[num] = -1;
			return;
		}
	}
}

void game::tigernextstep(int x, int y, int player, int * A, int * B)const
{
	int num = 0;
	if (player == 1) {                                                   //player 1
		if (gameMatrix[x][y]<1) {
			A[0] = -1;
			B[0] = -1;
			return;
		}
		else {
			if (y + 2 <= 4 && gameMatrix[x][y + 2] <= 0) {                                           //x,y+2 ok?
				A[num] = x;
				B[num] = y + 2;
				num++;
			}
			A[num] = -1;
			B[num] = -1;
			return;
		}
	}
	if (player == 2) {                                                   //player 2
		if (gameMatrix[x][y]>-1) {
			A[0] = -1;
			B[0] = -1;
			return;
		}
		else {
			if (y - 2 >= 0 && gameMatrix[x][y - 2] >= 0) {                                           //x,y-2 ok?
				A[num] = x;
				B[num] = y - 2;
				num++;
			}
			A[num] = -1;
			B[num] = -1;
			return;
		}
	}
}

void game::roosternextstep(int x, int y, int player, int * A, int * B)const
{
	int num = 0;
	if (player == 1) {                                                   //player 1
		if (gameMatrix[x][y]<1) {
			A[0] = -1;
			B[0] = -1;
			return;
		}
		else {
			if (x + 1 <= 4 && y + 1 <= 4 && gameMatrix[x + 1][y + 1] <= 0) {                                           //x+1,y+1 ok?
				A[num] = x + 1;
				B[num] = y + 1;
				num++;
			}
			if (x + 1 <= 4 && gameMatrix[x + 1][y] <= 0) {                                           //x+1,y ok?
				A[num] = x + 1;
				B[num] = y;
				num++;
			}
			if (x - 1 >= 0 && gameMatrix[x - 1][y] <= 0) {                                          //x-1,y ok?
				A[num] = x - 1;
				B[num] = y;
				num++;
			}
			if (x - 1 >= 0 && y - 1 >= 0 && gameMatrix[x - 1][y - 1] <= 0) {                                 //x-1,y-1 ok?
				A[num] = x - 1;
				B[num] = y - 1;
				num++;
			}
			A[num] = -1;
			B[num] = -1;
			return;
		}
	}
	if (player == 2) {                                                       //player 2
		if (gameMatrix[x][y]>-1) {
			A[0] = -1;
			B[0] = -1;
			return;
		}
		else {
			if (x + 1 <= 4 && y + 1 <= 4 && gameMatrix[x + 1][y + 1] >= 0) {                                           //x+1,y+1 ok?
				A[num] = x + 1;
				B[num] = y + 1;
				num++;
			}
			if (x + 1 <= 4 && gameMatrix[x + 1][y] >= 0) {                                          //x+1,y ok?
				A[num] = x + 1;
				B[num] = y;
				num++;
			}
			if (x - 1 >= 0 && gameMatrix[x - 1][y] >= 0) {                                          //x-1,y ok?
				A[num] = x - 1;
				B[num] = y;
				num++;
			}
			if (x - 1 >= 0 && y - 1 >= 0 && gameMatrix[x - 1][y - 1] >= 0) {                                 //x-1,y-1 ok?
				A[num] = x - 1;
				B[num] = y - 1;
				num++;
			}
			A[num] = -1;
			B[num] = -1;
			return;
		}
	}
}

void game::dragonnextstep(int x, int y, int player, int * A, int * B)const
{
	int num = 0;
	if (player == 1) {                                                   //player 1
		if (gameMatrix[x][y]<1) {
			A[0] = -1;
			B[0] = -1;
			return;
		}
		else {
			if (x + 1 <= 4 && y + 1 <= 4 && gameMatrix[x + 1][y + 1] <= 0) {                                           //x+1,y+1 ok?
				A[num] = x + 1;
				B[num] = y + 1;
				num++;
			}
			if (x + 1 <= 4 && gameMatrix[x + 1][y] <= 0) {                                           //x+1,y ok?
				A[num] = x + 1;
				B[num] = y;
				num++;
			}
			if (x - 1 >= 0 && gameMatrix[x - 1][y] <= 0) {                                          //x-1,y ok?
				A[num] = x - 1;
				B[num] = y;
				num++;
			}
			if (x - 1 >= 0 && y + 1 <= 4 && gameMatrix[x - 1][y + 1] <= 0) {                                 //x-1,y+1 ok?
				A[num] = x - 1;
				B[num] = y + 1;
				num++;
			}
			A[num] = -1;
			B[num] = -1;
			return;
		}
	}
	if (player == 2) {                                                       //player 2
		if (gameMatrix[x][y]>-1) {
			A[0] = -1;
			B[0] = -1;
			return;
		}
		else {
			if (x + 1 <= 4 && y - 1 >= 0 && gameMatrix[x + 1][y - 1] >= 0) {                                           //x+1,y-1 ok?
				A[num] = x + 1;
				B[num] = y - 1;
				num++;
			}
			if (x + 1 <= 4 && gameMatrix[x + 1][y] >= 0) {                                          //x+1,y ok?
				A[num] = x + 1;
				B[num] = y;
				num++;
			}
			if (x - 1 >= 0 && gameMatrix[x - 1][y] >= 0) {                                          //x-1,y ok?
				A[num] = x - 1;
				B[num] = y;
				num++;
			}
			if (x - 1 >= 0 && y - 1 >= 0 && gameMatrix[x - 1][y - 1] >= 0) {                                 //x-1,y-1 ok?
				A[num] = x - 1;
				B[num] = y - 1;
				num++;
			}
			A[num] = -1;
			B[num] = -1;
			return;
		}
	}
}

void game::horsenextstep(int x, int y, int player, int * A, int * B)const
{
	int num = 0;
	if (player == 1) {                                                   //player 1
		if (gameMatrix[x][y]<1) {
			A[0] = -1;
			B[0] = -1;
			return;
		}
		else {
			if (x + 1 <= 4 && y + 1 <= 4 && gameMatrix[x + 1][y + 1] <= 0) {                                           //x+1,y+1 ok?
				A[num] = x + 1;
				B[num] = y + 1;
				num++;
			}
			if (y + 1 <= 4 && gameMatrix[x][y + 1] <= 0) {                                           //x,y+1 ok?
				A[num] = x;
				B[num] = y + 1;
				num++;
			}
			if (x - 1 >= 0 && y + 1 <= 4 && gameMatrix[x - 1][y + 1] <= 0) {                                 //x-1,y+1 ok?
				A[num] = x - 1;
				B[num] = y + 1;
				num++;
			}
			A[num] = -1;
			B[num] = -1;
			return;
		}
	}
	if (player == 2) {                                                       //player 2
		if (gameMatrix[x][y]>-1) {
			A[0] = -1;
			B[0] = -1;
			return;
		}
		else {
			if (x + 1 <= 4 && y - 1 >= 0 && gameMatrix[x + 1][y - 1] >= 0) {                                           //x+1,y-1 ok?
				A[num] = x + 1;
				B[num] = y - 1;
				num++;
			}
			if (y - 1 >= 0 && gameMatrix[x][y - 1] >= 0) {                                           //x,y-1 ok?
				A[num] = x;
				B[num] = y - 1;
				num++;
			}
			if (x - 1 >= 0 && y - 1 >= 0 && gameMatrix[x - 1][y - 1] >= 0) {                                 //x-1,y-1 ok?
				A[num] = x - 1;
				B[num] = y - 1;
				num++;
			}
			A[num] = -1;
			B[num] = -1;
			return;
		}
	}
}

void game::oxnextstep(int x, int y, int player, int * A, int * B)const
{
	int num = 0;
	if (player == 1) {                                                   //player 1
		if (gameMatrix[x][y]<1) {
			A[0] = -1;
			B[0] = -1;
			return;
		}
		else {
			if (x + 1 <= 4 && gameMatrix[x + 1][y] <= 0) {                                           //x+1,y ok?
				A[num] = x + 1;
				B[num] = y;
				num++;
			}
			if (y + 1 <= 4 && gameMatrix[x][y + 1] <= 0) {                                           //x,y+1 ok?
				A[num] = x;
				B[num] = y + 1;
				num++;
			}
			if (x - 1 >= 0 && gameMatrix[x - 1][y] <= 0) {                                 //x-1,y ok?
				A[num] = x - 1;
				B[num] = y;
				num++;
			}
			A[num] = -1;
			B[num] = -1;
			return;
		}
	}
	if (player == 2) {                                                       //player 2
		if (gameMatrix[x][y]>-1) {
			A[0] = -1;
			B[0] = -1;
			return;
		}
		else {
			if (x + 1 <= 4 && gameMatrix[x + 1][y] >= 0) {                                           //x+1,y ok?
				A[num] = x + 1;
				B[num] = y;
				num++;
			}
			if (y - 1 >= 0 && gameMatrix[x][y - 1] >= 0) {                                           //x,y-1 ok?
				A[num] = x;
				B[num] = y - 1;
				num++;
			}
			if (x - 1 >= 0 && gameMatrix[x - 1][y] >= 0) {                                 //x-1,y ok?
				A[num] = x - 1;
				B[num] = y;
				num++;
			}
			A[num] = -1;
			B[num] = -1;
			return;
		}
	}
}

void game::snakenextstep(int x, int y, int player, int * A, int * B)const
{
	int num = 0;
	if (player == 1) {                                                   //player 1
		if (gameMatrix[x][y]<1) {
			A[0] = -1;
			B[0] = -1;
			return;
		}
		else {
			if (x + 1 <= 4 && y - 1 >= 0 && gameMatrix[x + 1][y - 1] <= 0) {                                           //x+1,y-1 ok?
				A[num] = x + 1;
				B[num] = y - 1;
				num++;
			}
			if (y + 1 <= 4 && gameMatrix[x][y + 1] <= 0) {                                           //x,y+1 ok?
				A[num] = x;
				B[num] = y + 1;
				num++;
			}
			if (x - 1 >= 0 && y - 1 >= 0 && gameMatrix[x - 1][y - 1] <= 0) {                                 //x-1,y-1 ok?
				A[num] = x - 1;
				B[num] = y - 1;
				num++;
			}
			A[num] = -1;
			B[num] = -1;
			return;
		}
	}
	if (player == 2) {                                                       //player 2
		if (gameMatrix[x][y]>-1) {
			A[0] = -1;
			B[0] = -1;
			return;
		}
		else {
			if (x + 1 <= 4 && y + 1 <= 4 && gameMatrix[x + 1][y + 1] >= 0) {                                           //x+1,y+1 ok?
				A[num] = x + 1;
				B[num] = y + 1;
				num++;
			}
			if (y - 1 >= 0 && gameMatrix[x][y - 1] >= 0) {                                           //x,y-1 ok?
				A[num] = x;
				B[num] = y - 1;
				num++;
			}
			if (x - 1 >= 0 && y + 1 <= 4 && gameMatrix[x - 1][y + 1] >= 0) {                                 //x-1,y+1 ok?
				A[num] = x - 1;
				B[num] = y + 1;
				num++;
			}
			A[num] = -1;
			B[num] = -1;
			return;
		}
	}
}

void game::mousenextstep(int x, int y, int player, int * A, int * B)const
{
	int num = 0;
	if (player == 1) {                                                   //player 1
		if (gameMatrix[x][y]<1) {
			A[0] = -1;
			B[0] = -1;
			return;
		}
		else {
			if (x + 2 <= 4 && gameMatrix[x + 2][y] <= 0) {                                           //x+2,y ok?
				A[num] = x + 2;
				B[num] = y;
				num++;
			}
			if (y + 1 <= 4 && gameMatrix[x][y + 1] <= 0) {                                           //x,y+1 ok?
				A[num] = x;
				B[num] = y + 1;
				num++;
			}
			if (x - 2 >= 0 && gameMatrix[x - 2][y] <= 0) {                                 //x-2,y ok?
				A[num] = x - 2;
				B[num] = y;
				num++;
			}
			A[num] = -1;
			B[num] = -1;
			return;
		}
	}
	if (player == 2) {                                                       //player 2
		if (gameMatrix[x][y]>-1) {
			A[0] = -1;
			B[0] = -1;
			return;
		}
		else {
			if (x + 2 <= 4 && gameMatrix[x + 2][y] >= 0) {                                           //x+2,y ok?
				A[num] = x + 2;
				B[num] = y;
				num++;
			}
			if (y - 1 >= 0 && gameMatrix[x][y - 1] >= 0) {                                           //x,y-1 ok?
				A[num] = x;
				B[num] = y - 1;
				num++;
			}
			if (x - 2 >= 0 && gameMatrix[x - 2][y] >= 0) {                                 //x-2,y ok?
				A[num] = x - 2;
				B[num] = y;
				num++;
			}
			A[num] = -1;
			B[num] = -1;
			return;
		}
	}
}

void game::rabbitnextstep(int x, int y, int player, int * A, int * B)const
{
	int num = 0;
	if (player == 1) {                                                   //player 1
		if (gameMatrix[x][y]<1) {
			A[0] = -1;
			B[0] = -1;
			return;
		}
		else {
			if (x + 1 <= 4 && y + 1 <= 4 && gameMatrix[x + 1][y + 1] <= 0) {                                           //x+1,y+1 ok?
				A[num] = x + 1;
				B[num] = y + 1;
				num++;
			}
			if (y - 1 >= 0 && gameMatrix[x][y - 1] <= 0) {                                           //x,y-1 ok?
				A[num] = x;
				B[num] = y - 1;
				num++;
			}
			if (x - 1 >= 0 && y + 1 <= 4 && gameMatrix[x - 1][y + 1] <= 0) {                                 //x-1,y+1 ok?
				A[num] = x - 1;
				B[num] = y + 1;
				num++;
			}
			A[num] = -1;
			B[num] = -1;
			return;
		}
	}
	if (player == 2) {                                                       //player 2
		if (gameMatrix[x][y]>-1) {
			A[0] = -1;
			B[0] = -1;
			return;
		}
		else {
			if (x + 1 <= 4 && y - 1 >= 0 && gameMatrix[x + 1][y - 1] >= 0) {                                           //x+1,y-1 ok?
				A[num] = x + 1;
				B[num] = y - 1;
				num++;
			}
			if (y + 1 <= 4 && gameMatrix[x][y + 1] >= 0) {                                           //x,y+1 ok?
				A[num] = x;
				B[num] = y + 1;
				num++;
			}
			if (x - 1 >= 0 && y - 1 >= 0 && gameMatrix[x - 1][y - 1] >= 0) {                                 //x-1,y-1 ok?
				A[num] = x - 1;
				B[num] = y - 1;
				num++;
			}
			A[num] = -1;
			B[num] = -1;
			return;
		}
	}
}

void game::sheepnextstep(int x, int y, int player, int * A, int * B)const
{
	int num = 0;
	if (player == 1) {                                                   //player 1
		if (gameMatrix[x][y]<1) {
			A[0] = -1;
			B[0] = -1;
			return;
		}
		else {
			if (x + 1 <= 4 && y + 1 <= 4 && gameMatrix[x + 1][y + 1] <= 0) {                                           //x+1,y+1 ok?
				A[num] = x + 1;
				B[num] = y + 1;
				num++;
			}
			if (x + 1 <= 4 && y - 1 >= 0 && gameMatrix[x + 1][y - 1] <= 0) {                                           //x+1,y-1 ok?
				A[num] = x + 1;
				B[num] = y - 1;
				num++;
			}
			if (x - 1 >= 0 && y - 1 >= 0 && gameMatrix[x - 1][y - 1] <= 0) {                                          //x-1,y-1 ok
				A[num] = x - 1;
				B[num] = y - 1;
				num++;
			}
			if (x - 1 >= 0 && y - 1 <= 4 && gameMatrix[x - 1][y + 1] <= 0) {                                 //x-1,y+1 ok?
				A[num] = x - 1;
				B[num] = y + 1;
				num++;
			}
			A[num] = -1;
			B[num] = -1;
			return;
		}
	}
	if (player == 2) {                                                       //player 2
		if (gameMatrix[x][y]>-1) {
			A[0] = -1;
			B[0] = -1;
			return;
		}
		else {
			if (x + 1 <= 4 && y - 1 >= 0 && gameMatrix[x + 1][y - 1] >= 0) {                                           //x+1,y-1 ok?
				A[num] = x + 1;
				B[num] = y - 1;
				num++;
			}
			if (x + 1 <= 4 && y + 1 <= 4 && gameMatrix[x + 1][y + 1] >= 0) {                                          //x+1,y+1 ok?
				A[num] = x + 1;
				B[num] = y + 1;
				num++;
			}
			if (x - 1 >= 0 && y + 1 <= 4 && gameMatrix[x - 1][y + 1] >= 0) {                                          //x-1,y+1 ok?
				A[num] = x - 1;
				B[num] = y + 1;
				num++;
			}
			if (x - 1 >= 0 && y - 1 >= 0 && gameMatrix[x - 1][y - 1] >= 0) {                                 //x-1,y-1 ok?
				A[num] = x - 1;
				B[num] = y - 1;
				num++;
			}
			A[num] = -1;
			B[num] = -1;
			return;
		}
	}
}

void game::boarnextstep(int x, int y, int player, int * A, int * B)const
{
	int num = 0;
	if (player == 1) {                                                   //player 1
		if (gameMatrix[x][y]<1) {
			A[0] = -1;
			B[0] = -1;
			return;
		}
		else {
			if (y + 1 <= 4 && gameMatrix[x][y + 1] <= 0) {                                           //x,y+1 ok?
				A[num] = x;
				B[num] = y + 1;
				num++;
			}
			if (y - 1 >= 0 && gameMatrix[x][y - 1] <= 0) {                                           //x,y-1 ok?
				A[num] = x;
				B[num] = y - 1;
				num++;
			}
			A[num] = -1;
			B[num] = -1;
			return;
		}
	}
	if (player == 2) {                                                       //player 2
		if (gameMatrix[x][y]>-1) {
			A[0] = -1;
			B[0] = -1;
			return;
		}
		else {
			if (y - 1 >= 0 && gameMatrix[x][y - 1] >= 0) {                                           //x,y-1 ok?
				A[num] = x;
				B[num] = y - 1;
				num++;
			}
			if (y + 1 <= 4 && gameMatrix[x][y + 1] >= 0) {                                           //x,y+1 ok?
				A[num] = x;
				B[num] = y + 1;
				num++;
			}
			A[num] = -1;
			B[num] = -1;
			return;
		}
	}
}

void game::turtlenextstep(int x, int y, int player, int * A, int * B)const
{
	int num = 0;
	if (player == 1) {                                                   //player 1
		if (gameMatrix[x][y] == 0 || gameMatrix[x][y] == -1) {
			A[0] = -1;
			B[0] = -1;
			return;
		}
		if (gameMatrix[x][y]>0) {
			if (y + 1 <= 4 && gameMatrix[x][y + 1] <= 0) {                                           //x,y+1 ok?
				A[num] = x;
				B[num] = y + 1;
				num++;
			}
			A[num] = -1;
			B[num] = -1;
			return;
		}
		if (gameMatrix[x][y] == -2) {
			if (y - 1 >= 0 && gameMatrix[x][y - 1] >= 0) {                                           //x,y-1 ok?
				A[num] = x;
				B[num] = y - 1;
				num++;
			}
			A[num] = -1;
			B[num] = -1;
			return;
		}
	}
	if (player == 2) {                                                   //player 2
		if (gameMatrix[x][y] == 1 || gameMatrix[x][y] == 0) {
			A[0] = -1;
			B[0] = -1;
			return;
		}
		if (gameMatrix[x][y]<0) {
			if (y - 1 >= 0 && gameMatrix[x][y - 1] >= 0) {                                           //x,y-1 ok?
				A[num] = x;
				B[num] = y - 1;
				num++;
			}
			A[num] = -1;
			B[num] = -1;
			return;
		}
		if (gameMatrix[x][y] == 2) {
			if (y + 1 <= 4 && gameMatrix[x][y + 1] <= 0) {                                           //x,y+1 ok?
				A[num] = x;
				B[num] = y + 1;
				num++;
			}
			A[num] = -1;
			B[num] = -1;
			return;
		}
	}
}

void game::ostrichnextstep(int x, int y, int player, int * A, int * B)const
{
	int num = 0;
	if (player == 1) {                                                   //player 1
		if (gameMatrix[x][y]<1) {
			A[0] = -1;
			B[0] = -1;
			return;
		}
		if (gameMatrix[x][y] == 1) {
			if (y + 1 <= 4 && gameMatrix[x][y + 1] <= 0) {                                           //x,y+1 ok?
				A[num] = x;
				B[num] = y + 1;
				num++;
			}
			A[num] = -1;
			B[num] = -1;
			return;
		}
		if (gameMatrix[x][y] == 2) {
			if (x - 2 >= 0 && y + 2 <= 4 && gameMatrix[x - 2][y + 2] <= 0) {                                           //x-2,y+2 ok?
				A[num] = x - 2;
				B[num] = y + 2;
				num++;
			}
			if (x + 2 <= 4 && y + 2 <= 4 && gameMatrix[x + 2][y + 2] <= 0) {                                           //x+2,y+2 ok?
				A[num] = x + 2;
				B[num] = y + 2;
				num++;
			}
			A[num] = -1;
			B[num] = -1;
			return;
		}
	}
	if (player == 2) {                                                   //player 2
		if (gameMatrix[x][y]>-1) {
			A[0] = -1;
			B[0] = -1;
			return;
		}
		if (gameMatrix[x][y] == -1) {
			if (y - 1 >= 0 && gameMatrix[x][y - 1] >= 0) {                                           //x,y-1 ok?
				A[num] = x;
				B[num] = y - 1;
				num++;
			}
			A[num] = -1;
			B[num] = -1;
			return;
		}
		if (gameMatrix[x][y] == -2) {
			if (x - 2 >= 0 && y - 2 >= 0 && gameMatrix[x - 2][y - 2] >= 0) {                                           //x-2,y-2 ok?
				A[num] = x - 2;
				B[num] = y - 2;
				num++;
			}
			if (x + 2 <= 4 && y - 2 >= 0 && gameMatrix[x + 2][y - 2] >= 0) {                                           //x+2,y-2 ok?
				A[num] = x + 2;
				B[num] = y - 2;
				num++;
			}
			A[num] = -1;
			B[num] = -1;
			return;
		}
	}
}

void game::frognextstep(int x, int y, int player, int * A, int * B)const
{
	int num = 0;
	if (player == 1) {                                                   //player 1
		if (gameMatrix[x][y]<1) {
			A[0] = -1;
			B[0] = -1;
			return;
		}
		if (gameMatrix[x][y] == 2) {
			if (y + 1 <= 4 && gameMatrix[x][y + 1] <= 0) {                                           //x,y+1 ok?
				A[num] = x;
				B[num] = y + 1;
				num++;
			}
			A[num] = -1;
			B[num] = -1;
			return;
		}
		if (gameMatrix[x][y] == 1) {
			if (x - 2 >= 0 && y + 1 <= 4 && gameMatrix[x - 2][y + 1] <= 0) {                                           //x-2,y+1 ok?
				A[num] = x - 2;
				B[num] = y + 1;
				num++;
			}
			if (x + 2 <= 4 && y + 1 <= 4 && gameMatrix[x + 2][y + 1] <= 0) {                                           //x+2,y+1 ok?
				A[num] = x + 2;
				B[num] = y + 1;
				num++;
			}
			A[num] = -1;
			B[num] = -1;
			return;
		}
	}
	if (player == 2) {                                                   //player 2
		if (gameMatrix[x][y]>-1) {
			A[0] = -1;
			B[0] = -1;
			return;
		}
		if (gameMatrix[x][y] == -2) {
			if (y - 1 >= 0 && gameMatrix[x][y - 1] >= 0) {                                           //x,y-1 ok?
				A[num] = x;
				B[num] = y - 1;
				num++;
			}
			A[num] = -1;
			B[num] = -1;
			return;
		}
		if (gameMatrix[x][y] == -1) {
			if (x - 2 >= 0 && y - 1 >= 0 && gameMatrix[x - 2][y - 1] >= 0) {                                           //x-2,y-1 ok?
				A[num] = x - 2;
				B[num] = y - 1;
				num++;
			}
			if (x + 2 <= 4 && y - 1 >= 0 && gameMatrix[x + 2][y - 1] >= 0) {                                           //x+2,y-1 ok?
				A[num] = x + 2;
				B[num] = y - 1;
				num++;
			}
			A[num] = -1;
			B[num] = -1;
			return;
		}
	}
}
