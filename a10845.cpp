#include<iostream>
#include <queue>
using namespace std;

queue<int> q;
int main(void) {
	int repeat;
	cin >> repeat;

	for (int i = 0; i < repeat; i++) {
		string command;
		cin >> command;
		if (command == "push") {
			int num;
			cin >> num;
			q.push(num);
		}
		else if (command == "pop") {
			if (!q.empty()) {
				cout << q.front() << "\n";
				q.pop();
			}
			else {
				cout << "-1\n";
			}
		}
		else if (command == "size") {
			cout << q.size() << "\n";
		}
		else if (command == "empty") {
			cout << q.empty() << "\n";
		}
		else if (command == "front") {
			if (!q.empty()) {
				cout << q.front() << "\n";
			}
			else {
				cout << "-1\n";
			}
		}
		else if (command == "back") {
			if (!q.empty()) {
				cout << q.back() << "\n";
			}
			else {
				cout << "-1\n";
			}
		}
	}
	return 0;
}