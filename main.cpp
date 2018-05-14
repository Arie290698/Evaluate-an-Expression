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
