// --------------------------------------------------------------------------------------------
//								Name: Ryan Beebe
//								Project: Data Cleaner
//
// This project accepts a program from a text file and removes comment code and extra spaces  
//
//---------------------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	//Declare variables
	char c;
	string complete_str = "";
		fstream input, output;
		input.open("input.txt", ios::in);
	output.open("output.txt", ios::out);

	//Create string from text file
	while (!input.eof())
	{
		input.get(c);
		complete_str += c;
	}
	
	//Remove last character from the string
	complete_str.pop_back();
		
	for (int i = 0; i < complete_str.length(); ++i)
	{
			//Remove  single line comments
			if (complete_str[i] == '/' && complete_str[i + 1] == '/') //If // is read, this rest of the line is comment code
			{
					while (complete_str[i + 1] != '\n')
					{
						++i;
					}
					++i;
			}

			//Remove block comments
			else if (complete_str[i] == '/' && complete_str[i + 1] == '*')
			{
				while (!(complete_str[i] == '*' && complete_str[i + 1] == '/'))
				{
					++i;
				}
				++i;
				if (complete_str[i + 1] == '\n' && complete_str[i] == '\n') { ++i; }
			}

			//If the charactar is a space, print one and skip the rest
			else if (complete_str[i] == ' ')
			{
				output << complete_str[i];
				while (complete_str[i + 1] == ' ') 
				{
					++i;
				}
			}

			//Do nothing, i will increment on the next iteration
			else if (complete_str[i] == '	'){	}
			//Remove multiple 'new lines'
			else if (complete_str[i] == '\n' && complete_str[i+1] == '\n'){	++i;}

			else
			{
				output << complete_str[i];
				if (complete_str[i] == '\n')
					output << '	';
			}
		}
		
	input.close();
	output.close();

	system("pause");
	return 0;
}
