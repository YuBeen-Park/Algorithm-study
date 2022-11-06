#include<iostream>
#include<cmath>
using namespace std;
int n;
int queen[15];
int answer = 0;
bool possible(int loc) {
	for (int i = 0; i < loc; i++) {
		if (queen[loc] == queen[i] || abs(queen[loc] - queen[i]) == loc - i) {
			return false;
		}
	}
	return true;
}
void findQueen(int index) {
	if (index == n) {
		answer++;
		return;
	}
	for (int i = 0; i < n; i++) {
		queen[index] = i;
		if (possible(index)) {
			findQueen(index + 1);
		}
	}
}
int main(void) {
	cin >> n;
	findQueen(0);
	cout << answer;
	return 0;
}