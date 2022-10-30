#include<iostream>
#include<vector>
using namespace std;

vector<pair<int, int>> people;
int rate[51] = { 0, };
int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		people.push_back(pair<int, int>(x, y));
		rate[i] = 1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (people.at(i).first > people.at(j).first && people.at(i).second > people.at(j).second) {
				//i의 덩치가 더 큰 경우
				rate[j]++;
			}
			else if (people.at(i).first < people.at(j).first && people.at(i).second < people.at(j).second) {
				//j의 덩치가 더 큰 경우
				rate[i]++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << rate[i];
		if (i != n - 1) {
			cout << " ";
		}
	}

	return 0;
}