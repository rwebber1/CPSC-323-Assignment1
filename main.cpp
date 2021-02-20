#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
using namespace std;

// TOKENS			Example Lexemes
//
// KEYWORDS 	=	int, float, bool, True, False, if, else, then, endif, endelse, while, whileend, do, enddo, for, endfor, STDinput, STDoutput, and, or, not
// IDENTIFIERS 	=	legal identifiers must start with alphabetic character follow by digits, letters, underscore or $
// SEPARATORS 	=	(){}[],.:;
// OPERATORS 	=	*+-=/><%
//
// Additional examples and symbols:
// Valid IDENTIFIERS	:  	num, num1, large$, num$1, num2, num2$, a9, ab, ab2, my_num, Max_Num, etc...
// Valid Numbers		:	integers whole numbers (0,1,2,3,...9) and reals or floats (5.0, 0.9, 1.75, ...)
// Valid Block Comments	:	!  this is a block comment to be ignored by the Lexical Analyzer !
// Special Characters   	:	the ! (exclamation mark), the _ (underscore) and the sp (space character)

/*
  Lexcal Analyzer
  - Program will read a file containing given source code and
    lexer function shall return a record (token and value) which
    shall be put into an output file
*/

//Lexical Analysis function
void lexer(char ch){
//TO DO - figures out what the character is, and assesses it
}

//Main function to iterate through file
int main(){
  ifstream file;
  char ch;

  file.open("input.txt");
  if(!file.is_open()){ cout << "File Opening Error\n"; exit(1);}

  if(file.is_open()){
    while(!file.eof()){
      ch = file.get();
      cout << ch;
      //lexer(ch);
    }
    file.close();
  }
  return 0;
}
