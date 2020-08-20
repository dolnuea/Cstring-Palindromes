/*
 * Dolunay Dagci
 * Due: 10/12
 * Assignment: Cstring Palindromes 
 * This program, lets the user enter a c-string. The cstring is processed with a void function, with one, char array argument, named removePuncNspace.
 * This function removes punctuation marks, spaces, and converts any uppercase letters to lowercase. This function separates the input into tokens with delimiters of punctuation marks,
 * and spaces, then saves the processed cstring into a cstring and copies into the original cstring. Lastly, the program checks if the input is palindrome or not, and informs the user.
 */
#define _CRT_SECURE_NO_WARNINGS //I added this because my IDE kept giving me error saying strtok is unsafe and I should use strtok_s. 
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace  std;

/*This method removes all spaces and punctuation marks from its c-string as well as change any uppercase letters to lowercase. **/
void removePuncNspace(char s[])
{
	char new_s[50], *tokenptr;

	//convert from uppercase to lowercase
	for (int i = 0; i < strlen(s); i++) s[i] = tolower(s[i]);
	
	//use a cstring function and tokenize s into token pointer and eliminate spaces and punctuation marks
	tokenptr = strtok(s, " ,.?!:;");
	
	//concatenate the first token into a c-string.
	strcpy(new_s, tokenptr);
	
	while (tokenptr != NULL)
	{
		tokenptr = strtok(nullptr, " ,.?!:;"); //tokenize rest of the string
		if (tokenptr != NULL)
			strcat(new_s, tokenptr); //concatenate rest of the tokens into a c-string.
	}

	//copy back into the original c - string for the pass by reference.
	strcpy(s, new_s);
}

/*This function checks input to confirm it is palindrome
*/
bool isPalindrome(char s[50])
{
	// create another c-string (that contains the \0) that is filled up as the reverse of the argument c-string.
	char reverse_s[50];
	// s already contains the \0 from removePuncNspace, by tokenptr. Therefore reverse_s also contains the \0.
	strcpy_s(reverse_s, s);
	//reverse s cstring
	_strrev(reverse_s); 
	
	if (strcmp(s, reverse_s) != 0)
	{
		cout << "Your input is palindrome" << endl;
		return true;
	}
	else if (strcmp(s, reverse_s) == 0)
	{
		cout <<  "Your input is not palindrome" << endl;
		return false;
	}
}
 
int main()
{
	while (true)
	{
		char cstring[50];

		cout << "Enter a line:" << endl;
		cin.getline(cstring, sizeof(cstring));
		removePuncNspace(cstring);
		cout << "Your input is removed from spaces, punctuation marks, and converted to lowercase: " << cstring << endl;
		isPalindrome(cstring);

	}

	return 0;
}
