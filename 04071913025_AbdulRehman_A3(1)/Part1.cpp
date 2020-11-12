#include"stack.h"
#include<fstream>
#include<string>
bool balanceCheck(const char* filename) {
	char c;
	stack<char> s;
	ifstream thefile(filename);
	if (thefile.is_open()) {
		while (thefile.good()) {
			thefile.get(c);
			if (thefile.gcount() > 0) {
				if (c == '(' || c == '{' || c == '[')
					s.push(c);
				else if (c == ')') {
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
		return s.empty();
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
