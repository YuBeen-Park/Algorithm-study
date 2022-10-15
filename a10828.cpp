#include <iostream>
#include<stack>
#include<string>
using namespace std;

int main(void) {
	//½ºÅÃ 
	int n;
	cin >> n;
	stack<int> st;
	for (int i = 0; i < n; i++) {
		string command;
		cin >> command;
		if (command == "push") {
			int input;
			cin >> input;
			st.push(input);
		}
		else if (command == "pop") {
			if (st.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << st.top() << "\n";
				st.pop();
			}
		}
		else if (command == "size") {
			cout << st.size() << "\n";
		}
		else if (command == "empty") {
			cout << st.empty() << "\n";
		}
		else if (command == "top") {
			if (st.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << st.top() << "\n";
			}
		}
	}
	return 0;
}