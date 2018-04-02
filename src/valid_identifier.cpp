/*
	Name: Liam Fitzpatrick
	Section: CPSC 323-80
	Date: Feb 21, 2018
*/

#include <iostream>		//for i/o.
#include <string>		//for string library.
#include <cctype>		//for isdigit(), isalnum(), etc.
using namespace std;

int main()
{
	/* initialize variables */
	string line = "";
	
	/* valid will be true unless one of the conditionals assigns it a value of false */
	bool valid = true;
	
	/* sentinel value of continue (y/n) */
	char sentinel = 'y';

	/* continue inputting strings until user selects 'n' or other than 'y' */
	while(tolower(sentinel) == 'y')
	{
		/* get user input */
		cout << "Enter a string: ";
		getline(cin,line);

		/* check if first character is a digit and change valid to false*/
		if(isdigit(line[0]))
			valid = false;
		
		/* check if line is empty string */
		if(line == "")
			valid = false;

		if(valid)
		{
			/* loop through the rest of the string */
			for(int i = 0; i < line.length(); i++)
				{
					/* check for underscore and increment i if the character is underscore */
					while(line[i] == '_')
						i++;

					/* advance index to next alphanumeric character */
					while(isalnum(line[i]))
						i++;

					/* check for invalid characters at current position */
					if(isspace(line[i]) || (ispunct(line[i]) && line[i] != '_'))						
						valid = false;
					
					/* check for trailing underscores */
					else if (line[i] == '_') 
						i++;
				}
		}

		/* output message to user */
		if(!valid)
		{
			cout << line << " is not a valid identifier." << endl;
		} else {
			cout << line << " is a valid identifier." << endl;
		}

		/* ask to continue */
		cout << "Continue (y/n)? ";
		cin >> sentinel;
		
		/* ignore the new line character */
		cin.ignore();
		
		/* reset valid to true for next character index */
		valid = true;
	}

	return 0;
}
