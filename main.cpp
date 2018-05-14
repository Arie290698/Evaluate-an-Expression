/*
https://github.com/Arie290698/Evaluate-an-Expression
*/

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


int CheckPrecedence(char Operator1, char Operator2){
	int Operator1Predence = PrecedenceOperator(Operator1);
	int Operator2Predence = PrecedenceOperator(Operator2);

	if(Operator1Predence == Operator2Predence){
		if(Operator1) return false;
		else return true;
	}
	return Operator1Predence > Operator2Predence ?  true: 
		false;
}


string Transform(string Q){
	stack<char> S;
	string P = ""; 
	for(int i = 0;i< Q.length();i++) {
		if(Q[i] == ' ' || Q[i] == ',') continue; 
		
		else if(OperandFound(Q[i])){
			P+=Q[i];
		}
		
		else if (Q[i] == '(') {
			S.push(Q[i]);
		}
		
		else if(Q[i] == ')') {
			while(!S.empty() && S.top() !=  '(') {
				P+=S.top();
				S.pop();
			}
			S.pop();
		}
		
		else if(OperatorFound(Q[i])) {
			while(!S.empty() && S.top() != '(' && CheckPrecedence(S.top(),Q[i])){
				P+=S.top();
				S.pop();
			}
			S.push(Q[i]);
		}
	}
	
	while(!S.empty()) {
		P+=S.top();
		S.pop();
	}
	return P;
}


int main() {
	string Q; 
	char* expression; 
	cout<<"Masukkan Infix : ";
	getline(cin,Q);
	string P = Transform(Q);
	cout<<P;
}
