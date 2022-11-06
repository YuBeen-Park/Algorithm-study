#include<iostream>
using namespace std;
int n, m;
int num[8] = {0, };
bool check[9];
void findSequence(int length) {
	if (length == m) {
		for (int i = 0; i < m; i++) {
			cout << num[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (check[i] == false) {
			check[i] = true;
			num[length] = i;
			findSequence(length + 1);
			check[i] = false;
		}
	}
}
int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		check[i] = false;
	}
	findSequence(0);

	return 0;
}