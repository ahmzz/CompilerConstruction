#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;
int isKeyword(char buffer[]);
void lexicalAnalyzer();

int main() {

	lexicalAnalyzer();


	_getch();
	return 0;


}

int isKeyword(char buffer[]) {
	char keywords[40][40] = {
							 "string","myOutput","myIf",
							"myElse","num","myElse if"
	};
	int i, Flag = 0;

	for (i = 0; i < 32; ++i) {
		if (strcmp(keywords[i], buffer) == 0) {
			Flag = 1;
			break;
		}
	}
	return Flag;
}

void lexicalAnalyzer() {

	

	//char ch, buffer[15], operators[] = "+-*/%=:(),{}";
	char ch, buffer[15], operators[] = "+-*%=:(),{}";



	ifstream fin("Input.txt");
	int i, j = 0;

	if (!fin.is_open()) {
		cout << "issue in opening the file" << endl;
		exit(0);
	}

	bool c = false;
	bool ote = false;
	bool cl = true;
	bool ml = false;
	bool cml = false;
	bool ros = false;

	while (!fin.eof()) {

		ch = fin.get();
		if (cl || cml)
		{
			for (i = 0; i < 12; ++i)
			{
				if (ch == operators[i])
					cout << ch << " is operator" << endl;
			}
		}
		//for single line comment
		if (ote == false)
		{
			if (ch == '/')
			{
				c = true;
				ml = true;

			}

		}
		if (ml == true)
		{
			if (ch == '*')
			{
				cml = true;
			}
		}
		if (c == true)
		{
			if (ch == '/')
			{

				c = false;
				cl = false;
				ros = true;

			}


		}
		if (ros)
		{
			if (ch == '*')
			{
				cml = false;
			}
		}


		if (ch == '\n' || ch == '\r')
		{


			c = false;
			ote = false;
			cl = true;
		}



		if (cl || cml)
		{
			if (isalnum(ch))
			{
				buffer[j++] = ch;
			}
			else if ((ch == ' ' || ch == '\n') && (j != 0))
			{
				buffer[j] = '\0';
				j = 0;

				if (isKeyword(buffer) == 1)
					cout << buffer << " is keyword" << endl;
				else
					cout << buffer << " : indentifier" << endl;
			}
		}


	}

	fin.close();


}