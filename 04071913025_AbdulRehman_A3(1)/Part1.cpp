#include"stack.h"
#include<fstream>
#include<string>
//function to check the brackets in the file are balanced or not
bool balanceCheck(const char* filename) {
	char c; //character to read file character by character
	stack<char> s; //stack to push or pop the brackets when appeared
	ifstream thefile(filename); //opening the file in read mode
	if (thefile.is_open()) {
		while (thefile.good()) { //while the file is not ended
			thefile.get(c); //getting a char from file
			if (thefile.gcount() > 0) { //check to ignore double consideration of last character
				if (c == '(' || c == '{' || c == '[') //if opening bracket appears push it to stack
					s.push(c);
				else if (c == ')') { //else if any closing bracket appears then the top most element at the stack must be its opening bracket otherwise the brackets are not  balance
					if (s.top() == '(')
						s.pop();
					else
						return false;
				}
				else if (c == '}') {
					if (s.top() == '{')
						s.pop();
					else
						return false;
				}
				else if (c == ']') {
					if (s.top() == '[')
						s.pop();
					else
						return false;
				}
			}
		}
		return s.empty(); //in the end if the stack is empty then it means there is no bracket without pair so the eqaution is balanced otherwise it is not balanced
	}
	else {
		cout << "File doesn't exist. Please create a file!" << endl;
		//return false;
		exit(1);
	}
}
int main(int argc, char* argv[]) {
	if (balanceCheck(argv[1]))
		cout << "Balanced Equation" << endl;
	else
		cout << "Not Balanced" << endl;
	return 0;
}
