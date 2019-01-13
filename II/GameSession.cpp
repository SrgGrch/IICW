#include "GameSession.h"

void GameSession::printBoard()
{
	system("cls");
	printTurn();
	board.printBoard();
	printScoreBoard();
}

void GameSession::endGame()
{
	// Выявление победителя и вывод на экран
	system("cls");
	std::cout << std::endl << std::endl << std::endl << std::endl << "					";
	if (player1.getScore() > player2.getScore()) std::cout << "Победил игрок " << player1.name << " ";
	else if (player1.getScore() < player2.getScore()) std::cout << "Победил игрок " << player2.name << " ";
	else std::cout << "Ничья";
	printScoreBoard();
}

void GameSession::skipTurn()
{
	draw++;  // Увелечение счетчика ничьи
	if (currentPlayer == 1) { // Смена хода
		currentPlayer = 2;
	} else {
		currentPlayer = 1;
	} 
	printBoard(); // Вывод на экран
}

void GameSession::printScoreBoard()
{
	std::cout << std::endl << "	" << player1.name << " " << player1.getScore() << "		" << player2.name << " " << player2.getScore() << std::endl;
}

void GameSession::printTurn()
{
	std::cout << "					Ход игрока ";
	if (currentPlayer == 1) std::cout << player1.getName() << std::endl << std::endl;
	else std::cout << player2.getName() << std::endl << std::endl;
}

void GameSession::getMoveDirection()
{
	bool isActive = GetConsoleWindow() == GetForegroundWindow(); // Флаг, который сообщает нам о том, находится ли окно сейчас в "фокусе"
	if (GetAsyncKeyState(VK_LEFT) && isActive) // Получение нажатой кнопки
	{
		system("cls");
		board.movePointer(LEFT);
		printBoard();
	} else if (GetAsyncKeyState(VK_RIGHT) && isActive)
	{
		system("cls");
		board.movePointer(RIGHT);
		printBoard();
	} else if (GetAsyncKeyState(VK_DOWN) && isActive)
	{
		system("cls");
		board.movePointer(DOWN);
		printBoard();
	} else if (GetAsyncKeyState(VK_UP) && isActive)
	{
		system("cls");
		board.movePointer(UP);
		printBoard();
	}
}

void GameSession::getHighlightDirection(int &tmpDir)
{
	bool isActive = GetConsoleWindow() == GetForegroundWindow();
	if (GetAsyncKeyState(VK_LEFT) && isActive)
	{
		system("cls");
		if (RIGHT == tmpDir) board.highlightWord(true, LEFT);
		else {
			board.highlightWord(false, LEFT);
			tmpDir = LEFT;
		}
		printBoard();

	} else if (GetAsyncKeyState(VK_RIGHT) && isActive)
	{
		system("cls");
		if (LEFT == tmpDir) board.highlightWord(true, RIGHT);
		else {
			board.highlightWord(false, RIGHT);
			tmpDir = RIGHT;
		}
		printBoard();

	} else if (GetAsyncKeyState(VK_DOWN) && isActive)
	{
		system("cls");
		if (UP == tmpDir) board.highlightWord(true, DOWN);
		else {
			board.highlightWord(false, DOWN);
			tmpDir = DOWN;
		}
		printBoard();

	} else if (GetAsyncKeyState(VK_UP) && isActive)
	{
		system("cls");
		if (DOWN == tmpDir) board.highlightWord(true, UP);
		else {
			board.highlightWord(false, UP);
			tmpDir = UP;
		}
		printBoard();
	}
}

void GameSession::setPlayers()
{
	system("cls");
	std::cout << "Введите имя 1го игрока: ";
	std::cin >> player1.name;
	std::cout << "Введите имя 2го игрока: ";
	std::cin >> player2.name;
	system("cls");
	printBoard();
}

void GameSession::run()
{
	bool isActive = false;
	while (true) { // Бесконечный цикл игры

		isActive = GetConsoleWindow() == GetForegroundWindow();
		getMoveDirection();

		if (busyCells == 25 || draw == 6) {
			endGame();
			break;
		}

		if (GetAsyncKeyState(VK_END) && isActive) // Ввод буквы
		{
			insertCh();
		} else if (GetAsyncKeyState(VK_MENU) && isActive && isInserted) // Выделение
		{
			highlightWord();

		}else if (GetAsyncKeyState(VK_HOME) && isActive) // Пропуск хода 
		{ 
			skipTurn();
		} else if (GetAsyncKeyState(VK_DELETE) && isActive) // Выход из игры
		{
			break;
		}
		Sleep(200);
	}
}

void GameSession::highlightWord()
{
	bool isActive = false; // Окно в фокусе?
	int tmpDir = -1; 
	bool isHighlighting = true; 
	board.startHighlighting(); // Начало выделения
	while (isHighlighting) { // Пока выделеляется
		isActive = GetConsoleWindow() == GetForegroundWindow(); // Проверить в фокусе ли окно
		getHighlightDirection(tmpDir); // Получить направление перемещения курсора
		if (GetAsyncKeyState(VK_CONTROL) && isActive) { // Если нажат ctrl и окно в фокусе
			if (board.checkWord(currentPlayer)) { // Если слово прошло проверку
				if (currentPlayer == 1) { // Начислить очки и отдать ход следующему игроку 
					player1.addScore();  
					currentPlayer = 2;
				}
				else {
					player2.addScore();
					currentPlayer = 1;
				}
				draw = 0; // Сброс счетчика ничьи
				busyCells++; // Увеличение кол-ва занятых ячеек
				isHighlighting = false; // Остановить выделение
			}
			isHighlighting = board.getHighlighting();
		}
		Sleep(200);
	}
	board.stopHighlighting();
	isInserted = false;
	printBoard();

}

void GameSession::insertCh() {
	char tmp; 
	std::cin >> tmp;
	board.setCharacter(tmp);
	system("cls");
	printTurn();
	board.printBoard();
	printScoreBoard();
	isInserted = true;
}

void GameSession::setPlayerFirst(std::string name)
{
	player1.setName(name);
}

void GameSession::setPlayerSecond(std::string name)
{
	player2.setName(name);
}
