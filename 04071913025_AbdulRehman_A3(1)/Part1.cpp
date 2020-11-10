#include<iostream>
#include<fstream>
#include<string>
using namespace std;
template<typename T>
struct node {
	T data;
	node<T>* next;
};
template<typename T>
class stack {
	node<T>* top_ptr;
public:
	stack() {
		top_ptr = NULL;
	}
	~stack() {
		make_empty();
	}
	void push(const T& val) {
		if (full())
			throw("Stack Overflow!");
		node<T>* temp;
		temp = new node<T>;
		temp->data = val;
		temp->next = top_ptr;
		top_ptr = temp;
	}
	void pop() {
		if (empty())
			throw("Stack Underflow!");
		node<T>* temp;
		temp = top_ptr;
		top_ptr = top_ptr->next;
		delete temp;
	}
	T top() const {
		if (empty())
			throw("Stack is empty!");
		return top_ptr->data;
	}
	bool empty() const {
		return top_ptr == NULL;
	}
	bool full() const {
		node<T>* temp;
		temp = new node<T>;
		if (temp == NULL)
			return true;
		else {
			delete temp;
			return false;
		}
	}
	void make_empty() {
		while (!empty()) {
			pop();
		}
	}
};
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
