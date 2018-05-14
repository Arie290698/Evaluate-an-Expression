#include<iostream>
#include<stack>
#include<string>

using namespace std;

bool OperandFound(char Character) {
	if(Character >= '0' && Character <= '9' || Character >= 'a' && Character <= 'z' || Character >= 'A' && Character <= 'Z') 
		return true;
		
	return false;
}


bool OperatorFound(char Character){
	if(Character == '*' ||  Character == '/' || Character == '%' || Character == '+' || Character== '-')
		return true;

	return false;
}


int PrecedenceOperator(char Operator){
	int precedence = -1;
	switch(Operator){
    case '(':	precedence = 4;
        break;
	case '+':
	case '-':	precedence = 2;
		break;
	case '*':
	case '/':	precedence = 3;
		break;
    case ')':	precedence = 1;
        break;
	}
	return precedence;
}
