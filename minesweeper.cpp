#include "minesweeper.h"

int main() {
	cout << "Testing minesweeper" << endl;
	minesweeper(".\\test1commands.txt", "test1_output_mine.txt");
	minesweeper(".\\test2commands.txt", "test2_output_mine.txt");
	minesweeper(".\\test3commands.txt", "test3_output_mine.txt");
	minesweeper(".\\test4commands.txt", "test4_output_mine.txt");
	minesweeper(".\\test5commands.txt", "test5_output_mine.txt");
	minesweeper(".\\test6commands.txt", "test6_output_mine.txt");
	minesweeper(".\\test7commands.txt", "test7_output_mine.txt");
	minesweeper(".\\test8commands.txt", "test8_output_mine.txt");
	minesweeper(".\\test9commands.txt", "test9_output_mine.txt");
	minesweeper(".\\test10commands.txt", "test10_output_mine.txt");

	return 0;
}

// 문자열을 읽어들여서 그 파일을 읽는다. 그 다음에 output에 해당하는
//파일명 text를 만들어 거기에 output을 적는다.
void minesweeper(string commands, string output) {
	string first;
	string filename;
	string last;
	char p[8][8];
	char a[8][8];
	bool condition = true;
	for (int i = 0; i < 8; i++)
		for (int j = 0;j < 8;j++)
			a[i][j] = '.';
	int sum = 0;

	ifstream ReadCommand;
	ReadCommand.open(commands);
	ofstream MakeOutput;
	MakeOutput.open(output);
	ifstream ReadBoard;


	ReadCommand >> first;
	while (!ReadCommand.eof()) {
		int x;
		int y;
		if (first == "load") {
			ReadCommand >> filename;
			MakeOutput << "Command: load " << filename << '\n';
			ReadBoard.open(filename);
			load(ReadBoard, MakeOutput, p);//배열 p가 board에 있는 정보로 찼다.
			ReadCommand >> first;
		}

		else if (first == "display") {
			MakeOutput << "Command: display\n";
			display(a, MakeOutput);
			ReadCommand >> first;
		}

		else if (first == "touch") {
			ReadCommand >> x >> y;
			MakeOutput << "Command: touch " << x << ' ' << y << '\n';
			touch(x, y, sum, a, p, MakeOutput,condition);
			ReadCommand >> first;
			if (condition == false) {
				endgame(a, p, MakeOutput, sum);
				break;
			}
		}

		if (ReadCommand.eof() || sum == 54) {
			endgame(a, p, MakeOutput, sum);
			break;
		}
	}
}

void touch(int x, int y, int& sum, char arr1[][8],char arr2[][8],ofstream& MakeOutput,bool& condition) {
	if (x <= 0 || x >= 9 || y <= 0 || y >= 9)
		return;

	if (arr2[x-1][y-1] == '*') {
		sum++;
		arr1[x - 1][y - 1] = '*';
		condition = false;
	} // 게임 종료

	else if (arr2[x - 1][y - 1] == '.') {
		int i = 0;
		if (arr2[x - 2][y - 2] == '*' && x-2>=0 && y-2>=0)
			i++;
		if (arr2[x - 2][y - 1] == '*'&& x-2>=0)
			i++;
		if (arr2[x - 2][y] == '*'&& x-2>=0 && y<=7)
			i++;
		if (arr2[x - 1][y - 2] == '*'&& y-2>=0)
			i++;
		if (arr2[x - 1][y] == '*' && y<=7)
			i++;
		if (arr2[x][y - 2] == '*'&& x<=7 && y-2>=0)
			i++;
		if (arr2[x][y - 1] == '*'&& x<=7)
			i++;
		if (arr2[x][y] == '*' && x<=7 && y<=7)
			i++;
		sum++;
		arr1[x - 1][y - 1] = (char)(i+48);
	}
}

void load(ifstream& ReadBoard,ofstream& MakeOutput,char arr[][8]) {
	string line;
	char a;
	for (int row = 0;row < 8;row++) {
		for (int column = 0; column < 8; column++) {
			ReadBoard.get(a);
			arr[row][column] = a;
		}
		ReadBoard.get(a);
	}
} // 읽어 들여서 배열 안에 넣는것 까지 함.

void display(char arr1[][8],ofstream& MakeOutput) {
	for (int row = 0; row < 8; row++) {
		for (int column = 0; column < 8; column++) {
			MakeOutput << arr1[row][column];
		}
		MakeOutput << '\n';
	}
	MakeOutput << '\n';
}

void endgame(char arr1[][8],char arr2[][8], ofstream& MakeOutput, int& sum) {
	
	for (int i = 0;i < 8;i++) {
		for (int j = 0;j < 8;j++) {
			if (arr2[i][j] == '*') {
				if (arr1[i][j] != arr2[i][j])
					arr1[i][j] = '@';
			}
		}
	}
	MakeOutput << "Game Over\n";
	MakeOutput << "~~~~~~~~~\n";
	MakeOutput << "Final Board\n";
	display(arr1, MakeOutput);
	MakeOutput << "Spaces touched: " << sum << '\n';
	return;
}
