#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
//////next_permutation => 완전탐색으로 가능한 모든 배열을 구할 수 있다.
int n;
vector<int> arr;
int cal() {
	int answer = 0;
	for (int i = 0; i < n - 1; i++) {
		answer += abs(arr[i] - arr[i + 1]);
	}
	return answer;
}
int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end());
	int answer = 0;
	do {
		answer = max(answer, cal());
	} while (next_permutation(arr.begin(), arr.end()));
	cout << answer;
	return 0;
}