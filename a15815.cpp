#include<iostream>
#include<stack>
using namespace std;



int main(void) {
	stack<int> st;
	string number = "0123456789";
	string equation;
	cin >> equation;
	for (int i = 0; i < equation.length(); i++) {
		if (number.find(equation.at(i)) != -1) {
			st.push(equation.at(i) - '0');
			continue;
		}

		int a, b;
		b = st.top();
		st.pop();
		a = st.top();
		st.pop();

		switch (equation.at(i)) {
		case '+':
			st.push(a + b);
			break;
		case '-':
			st.push(a - b);
			break;
		case '*':
			st.push(a * b);
			break;
		case '/':
			st.push(a / b);
			break;
		}
	}
	cout << st.top();
	return 0; 
}