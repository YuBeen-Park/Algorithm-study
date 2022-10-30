#include<iostream>
using namespace std;
int num[21];
int n, s, total = 0;
void dfs(int index, int partial_sum) {
	if (index == n) {
		if (partial_sum == s) {
			total++;
		}
		return;
	}
	int cur_num = num[index];
	dfs(index + 1, partial_sum + cur_num);//cur_num을 포함한 경우
	dfs(index + 1, partial_sum);//cur_num을 포함하지 않은 경우
}

int main(void) {
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	dfs(0, 0);

	cout << total - 1 * (s == 0) << "\n";
	return 0;
}