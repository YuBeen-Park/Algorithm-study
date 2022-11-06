#include<iostream>
using namespace std;
int n, m;
int num[8];
bool check[9];
void findSequence(int length, int prev) {
	if (length == m) {
		for (int i = 0; i < m; i++) {
			cout << num[i] << " ";
		}
		cout << '\n';
	}
	for (int i = 1; i <= n; i++) {
		if (!check[i] && i > prev) {
			check[i] = true;
			num[length] = i;
			findSequence(length + 1, i);
			check[i] = false;
		}
	}
}
int main(void) {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		check[i] = false;
	}
	findSequence(0, 0);

	return 0;
}