#include <iostream>
#include <queue>
#include <functional>
using namespace std;
int n, m;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	priority_queue<unsigned long long, vector<unsigned long long>, greater<unsigned long long>> cards;
	int i;

	cin >> n >> m;

	long long c;
	for (i = 0; i < n; i++) {
		cin >> c;
		cards.push(c);
	}

	unsigned long long min1, min2, plus;
	for (i = 0; i < m; i++) {
		min1 = cards.top();
		cards.pop();
		min2 = cards.top();
		cards.pop();
		plus = min1 + min2;
		cards.push(plus);
		cards.push(plus);
	}

	int len = cards.size();
	unsigned long long result = 0;
	for (i = 0; i < len; i++) {
		result += cards.top();
		cards.pop();
	}
	
	cout << result << '\n';

	return 0;
}