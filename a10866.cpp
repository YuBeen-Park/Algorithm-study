#include<iostream>
#include <deque>
using namespace std;

deque<int> dq;
int main(void) {
	int repeat;
	cin >> repeat;

	for (int i = 0; i < repeat; i++) {
		string command;
		cin >> command;
		if (command == "push_front") {
			int num;
			cin >> num;
			dq.push_front(num);
		}
		else if (command == "push_back") {
			int num;
			cin >> num;
			dq.push_back(num);
		}
		else if (command == "pop_front") {
			if (!dq.empty()) {
				cout << dq.front() << "\n";
				dq.pop_front();
			}
			else {
				cout << "-1\n";
			}
		}
		else if (command == "pop_back") {
			if (!dq.empty()) {
				cout << dq.back() << "\n";
				dq.pop_back();
			}
			else {
				cout << "-1\n";
			}
		}
		else if (command == "size") {
			cout << dq.size() << "\n";
		}
		else if (command == "empty") {
			cout << dq.empty() << "\n";
		}
		else if (command == "front") {
			if (!dq.empty()) {
				cout << dq.front() << "\n";
			}
			else {
				cout << "-1\n";
			}
		}
		else if (command == "back") {
			if (!dq.empty()) {
				cout << dq.back() << "\n";
			}
			else {
				cout << "-1\n";
			}
		}
	}
	return 0;
}