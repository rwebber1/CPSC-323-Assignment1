#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

// TOKENS			Example Lexemes
vector<string> KEYWORDS 	=	{"int", "float", "bool", "True", "False", "if", "else", "then", "endif", "endelse", "while", "whileend", "do", "enddo", "for", "endfor", "STDinput", "STDoutput", "and", "or", "not"};
char separators[] = "'(){}[],:;";
char operators[] = {'*', '+', '-', '=', '/', '>', '<', '%'};

//Globals
bool commentFlag = false;
bool separatorFlag = false;
bool operatorFlag = false;
string buffer;

//IDENTIFIERS 	=	legal identifiers must start with alphabetic character follow by digits, letters, underscore or $
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
void lexer(char symbol, ofstream &fout){
  if(symbol == '!'){
    if(commentFlag){
      commentFlag = false;
    }
    else{
      commentFlag = true;
    }
  }
  if(!commentFlag){
    //Checks separators
    for(int i = 0; i < 10; i++){
      if(symbol == separators[i]){
        separatorFlag = true;
      }
    }
    //Check Operators
    for(int i = 0; i < 7; i++){
      if(symbol == operators[i]){
        operatorFlag = true;
      }
    }

    //Add symbol to buffer if not operator or separator
    if(isalnum(symbol) || symbol == '$' || symbol == '_'){
      buffer.push_back(symbol);
    }

    //Check for Keywords
    for(vector<string>::iterator iter = KEYWORDS.begin(); iter < KEYWORDS.end(); iter++){
      if(buffer.compare(*iter) == 0){
        fout << left << setw(20) << "KEYWORD" << setw(15) << '=' << right << buffer << endl;
        buffer.clear();
      }
    }
    //Output if end of identifier
    if(symbol == ' ' || separatorFlag || operatorFlag){
      if(buffer.size() != 0){
        fout << left << setw(20) << "IDENTIFIER" << setw(15) << '=' << right << buffer << endl;
        buffer.clear();
      }
      if(separatorFlag){
        fout << left << setw(20) << "SEPARATOR" << setw(15) << '=' << right << symbol << endl;
        separatorFlag = false;
      }
      if(operatorFlag){
        fout << left << setw(20) << "OPERATOR" << setw(15) << '=' << right << symbol << endl;
        operatorFlag = false;
      }
    }

  }
}

//Main function to iterate through file
int main(int argc, char *argv[]){
  string input;
  ifstream fin;
  ofstream fout;
  char ch;

  //Checks if input file was sent in
  if(argc < 2){ cout << "ERROR - format should be: ./main inputFile\n"; exit(1);}
  else{
    input = argv[1];
  }

  //Error checking for input file
  fin.open(input);
  if(!fin.is_open()){ cout << "File Opening Error\n"; exit(1);}

  //Error checking for output file
  fout.open("output.txt");
  if(!fout.is_open()){ cout << "Output File Error\n"; exit(1);}

  if(fin.is_open()){
    fout << setw(10) << "Token:" << setw(32) << "Lexeme:\n\n";
    while(!fin.eof()){
      ch = fin.get();
      lexer(ch, fout);
    }
  }
  fin.close();
  fout.close();
  return 0;
}
