#include<iostream>
#include <algorithm>

#include<queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int repeat;
	cin >> repeat;
	for (int i = 0; i < repeat; i++) {
		int num;
		cin >> num;
		if (num == 0) {//배열에서 가장 작은 값을 출력하고 그 값을 제거
			if (pq.empty()) {
				cout << "0\n";
			}
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else {
			pq.push(num);
		}
	}

	return 0;
}