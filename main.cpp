#include<iostream>
#include<stack>
#include<string>

using namespace std;

bool OperandFound(char Character) {
	if(Character >= '0' && Character <= '9' || Character >= 'a' && Character <= 'z' || Character >= 'A' && Character <= 'Z') 
		return true;
		
	return false;
}

