// OOP8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <cstdlib>
#include "board.h"
#include <Windows.h>

void draw_pointer(int coord) {
	gotoXY(35, coord);
	cout << ">";
	gotoXY(72, coord);
	cout << "<";
}
void end_game(board b) {
	system("cls");
	b.ShowBoard(50);
	b.ShowValues(52, 57, 62);
	gotoXY(53, 12);
	if (b.win() == 1) {
		SetColor(Green, Black);
		cout << "Крестики победили!";
	}
	else {
		SetColor(Red, Black);
		cout << "Нолики победили!";
	}
}
void game_with_ai() {
	system("cls");
	SetColor(White, Black);
	cout << "Кем будете играть? (Х , 0)";
	char key = _getch();
	if (key == 'x') key = 'X';
	else key = '0';
	char ai_char;
	if (key == 'X') ai_char = '0';
	else ai_char = 'X';
	board ai_board;
	ai_board.init();
	while (true) {
		if (ai_board.board_is_full()) ai_board.init();
		if (!ai_board.win()) ai_board.input(key); else break;
		if (!ai_board.win()) {
			if (ai_board.is_empty_position(1, 1)) ai_board.setChar(1, 1, ai_char);
			else if (ai_board.is_empty_position(0, 0)) ai_board.setChar(0, 0, ai_char);
			else if (ai_board.is_empty_position(2, 2)) ai_board.setChar(2, 2, ai_char);
			else if (ai_board.is_empty_position(0, 2)) ai_board.setChar(0, 2, ai_char);
			else if (ai_board.is_empty_position(2, 0)) ai_board.setChar(2, 0, ai_char);
			else if (ai_board.is_empty_position(1, 0)) ai_board.setChar(1, 0, ai_char);
			else if (ai_board.is_empty_position(1, 2)) ai_board.setChar(1, 2, ai_char);
			else if (ai_board.is_empty_position(0, 1)) ai_board.setChar(0, 1, ai_char);
			else if (ai_board.is_empty_position(2, 0)) ai_board.setChar(2, 0, ai_char);
		}
		else break;
	}
	end_game(ai_board);
	_getch();
}
void game_with_second_player() {
	board Board;
	Board.init();
	while (true) {
		if (!Board.win()) {
			if (Board.board_is_full()) Board.init();
			Board.input('X');
		}
		else break;
		if (!Board.win()) {
			if (Board.board_is_full()) Board.init();
			Board.input('0');
		}
		else break;
	}
	end_game(Board);
	//getch();
}
void ShowMenu() {
	gotoXY(0, 0);
	cout << "========================================================================================================================";
	gotoXY(0, 6);
	cout << "========================================================================================================================";
	gotoXY(40, 6);
	gotoXY(40, 2);
	cout << "Крестики-нолики";
	gotoXY(40, 3);
	cout << "Игра для лабы";
	gotoXY(40, 4);
	cout << "Михальцов Д.А. 944691";
	gotoXY(40, 10);
	cout << "Начать игру со вторым игроком";
	gotoXY(40, 12);
	cout << "Начать игру с AI";
	gotoXY(40, 14);
	cout << "Об игре";
	gotoXY(40, 16);
	cout << "Выйти из игры";
}
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	HANDLE StdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	ShowMenu();
	KeyValue key;
	int n = 1;
	SetColor(LightGreen, Black);
	while (true) {
		switch (n) {
		case 1:
			draw_pointer(10);
			break;
		case 2:
			draw_pointer(12);
			break;
		case 3:
			draw_pointer(14);
			break;
		case 4:
			draw_pointer(16);
			break;
		}
		int(key) = _getch();
		if (key == LEFT) {
			if (n == 1) n = 4;
			else n--;
		}
		if (key == DOWN) {
			if (n == 4) n = 1;
			else n++;
		}
		if (key == UP) {
			if (n == 1) n = 4;
			else n--;
		}
		if (key == ENTER) {
			switch (n) {
			case 4:
				return 0;
			case 1:
				game_with_second_player();
				break;
			case 3:
				SetColor(Yellow, Black);
				system("cls");
				gotoXY(40, 2);
				cout << "Игра Крестики - нолики";
				gotoXY(40, 4);
				cout << "Спешл фо 8 лабораторная по ооп\n";
				cout << endl << "==========================================================================================\n";
				cout << endl << "Игра сделана\nДля лабораторной работы\nпо ООП\nС помощью сторонних источников\nСдаёт\nМихальцов Д.А. 944691\n";
				cout << endl << "==========================================================================================";
				gotoXY(40, 17);
				cout << "Тык на любую клавишу!";
				_getch();
				break;
			case 2:
				game_with_ai();
				break;
			}
			system("cls");
			SetColor(White, Black);
			ShowMenu();
			SetColor(Green, Black);
		}
		for (int i = 10; i <= 16; i += 2) {
			gotoXY(35, i);
			cout << " ";
			gotoXY(72, i);
			cout << " ";
		}
	}
}
