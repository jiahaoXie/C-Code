//投魔法币问题 （利用栈的先进后出）
#include<iostream>
#include<stack>

using namespace std;

int n;
stack<char> s;
int main() {
	cin >> n;
	while (n) {
		if (n % 2 == 0) {
			n = (n - 2) / 2;
			s.push('2');
		}
		else {
			n = (n - 1) / 2;
			s.push('1');
		}
	}
	while (!s.empty()) {
		printf("%c", s.top());
		s.pop();
	}
	printf("\n");

	system("pause");
	return 0;
}