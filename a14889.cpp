#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int n;
int score[21][21];
bool team[21];
int answer = 987654321;

void countScore() {
	vector<int> start, link;
	for (int i = 1; i <= n; i++) {
		if (team[i]) {
			start.push_back(i);
		}
		else {
			link.push_back(i);
		}
	}
	if (start.size() != link.size()) {
		return;
	}
	int score1 = 0, score2 = 0;
	for (int i = 0; i < start.size(); i++) {
		for (int j = 0; j < start.size(); j++) {
			if (start.at(i) != start.at(j)) {
				score1 += score[start.at(i)][start.at(j)];
			}
		}
	}
	for (int i = 0; i < link.size(); i++) {
		for (int j = 0; j < link.size(); j++) {
			if (link.at(i) != link.at(j)) {
				score2 += score[link.at(i)][link.at(j)];
			}
		}
	}
	answer = min(answer, abs(score1 - score2));
}
void makeTeam(int index) {
	if (index == n + 1) {
		countScore();
		return;
	}
	team[index] = true;
	makeTeam(index + 1);
	team[index] = false;
	makeTeam(index + 1);
}
int main(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> score[i][j];
		}
		team[i] = false;
	}
	makeTeam(1);
	cout << answer;

	return 0;
}