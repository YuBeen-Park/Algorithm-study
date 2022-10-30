#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int map[8][8];
int temp[8][8];
int n, m, maxSum = 0;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
vector<pair<int, int>> virus;
void copyMap() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			temp[i][j] = map[i][j];
		}
	}
}
void Virus() {
	queue<pair<int, int>> q;
	for (int i = 0; i < virus.size(); i++) {
		q.push(virus[i]);
	}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx >= n || xx <= -1 || yy >= m || yy <= -1) {
				continue;
			}
			if (temp[xx][yy] == 0) {
				temp[xx][yy] = 2;
				q.push(make_pair(xx, yy));
			}
		}

	}
}
int countSafeZone() {
	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (temp[i][j] == 0) {
				count++;
			}
		}
	}
	return count;
}
void makeWall(int x, int wall) {
	if (wall == 3) {
		copyMap();
		Virus();
		maxSum = max(maxSum, countSafeZone());
		return;
	}
	for (int i = x; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				map[i][j] = 1;
				makeWall(i, wall + 1);
				map[i][j] = 0;
			}
		}
	}
}
int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				virus.push_back(make_pair(i, j));
			}
		}
	}
	makeWall(0, 0);
	cout << maxSum;

	return 0;
}