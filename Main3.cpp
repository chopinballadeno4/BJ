#include <iostream>
#include <stack>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	stack<pair<int, int>> s;
	int num, height;
	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> height;

		while (!s.empty()) {
			if (height < s.top().second) {
				cout << s.top().first << " ";
				break;
			} 
			s.pop(); //  현재 입력받는 수보다 작은수들을 제거해주는 방법
		}

		if (s.empty()) {
			cout << 0 << " ";
		}
		s.push(make_pair(i + 1, height));
	}
}
