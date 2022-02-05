#include <iostream>
#include <stack>
#include <string>
using namespace std;
unsigned int T;

int main() {
	cin >> T;

	for (int turn = 0; turn < T; turn++) {
		string testString = "";
		stack<char> testData;
		bool correct = true;	

		cin >> testString;
		for (int s = 0; s < testString.length(); s++) {
			if (testString[s] == '(') {
				testData.push('(');
			}
			else if (testString[s] == ')') {
				if (testData.size() == 0) {
					correct = false;
					break;
				}
				else {
					testData.pop();
				}
			}
		}
		cout << ((correct && testData.size()==0) ? "YES" : "NO") << '\n';
	}

	return 0;
}