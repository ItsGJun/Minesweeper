#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

void minesweeper(string commands, string output);

void display(char arr1[][8], ofstream& MakeOutput);

void load(ifstream& ReadBoard, ofstream& MakeOutput, char arr[][8]);

void touch(int x, int y, int& sum, char arr1[][8], char arr2[][8], ofstream& MakeOutput,bool& condition);

void endgame(char arr1[][8], char arr2[][8], ofstream& MakeOutput, int& sum);