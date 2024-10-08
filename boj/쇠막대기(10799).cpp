#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;

  queue<char> q;
  int answer = 0;
  char pre = '(';
  for (char c: s) {
    if (c == '(') q.push(c);
    else {
      if (q.empty()) continue;
      q.pop();
      if (pre == '(') answer += q.size();
      else answer++;
    }
    pre = c;
  }

  cout << answer;
  return 0;
}
