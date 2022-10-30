#include <iostream>
using namespace std;
int dice[10001][6];
int n, ans = 0;
inline int max(int x, int y) {
	return x > y ? x : y;
}
int calUpside(int bottom) {
	int upside;
	if (bottom == 0 || bottom == 5) {
		upside = 5 - bottom;
	}
	else if (bottom == 1 || bottom == 3) {
		upside = 4 - bottom;
	}
	else if (bottom == 2 || bottom == 4) {
		upside = 6 - bottom;
	}
	return upside;
}
int Dice(int index) {
	int downSideIndex = index;
	int diceSum = 0;
	for (int i = 0; i < n; i++) {
		int upSideIndex = calUpside(downSideIndex);
		int upSide = dice[i][upSideIndex];//À­¸é ¼ýÀÚ
		int maxDice = 0;
		for (int j = 0; j < 6; j++) {
			if (j != upSideIndex && j != downSideIndex) {
				maxDice = max(maxDice, dice[i][j]);
			}
		}
		diceSum += maxDice;
		if (i < n - 1) {
			for (int j = 0; j < 6; j++) {
				if (dice[i + 1][j] == upSide) {
					downSideIndex = j;
					break;
				}
			}
		}
	}
	return diceSum;
}
int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> dice[i][j];
		}
	}
	for (int i = 0; i < 6; i++) {
		ans = max(ans, Dice(i));
	}
	cout << ans;
	return 0;
}