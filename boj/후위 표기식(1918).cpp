#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>

using namespace std;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string str;
  cin >> str;

  string answer = "";
  stack<vector<int>> op;
  map<char, int> p;
  p['+'] = 1;
  p['-'] = 1;
  p['*'] = 2;
  p['/'] = 2;

  int prioity = 0;
  for (char c: str) {
    if ('A' <= c && c <= 'Z') answer += c;
    else {
      if (c == '(') prioity += 10;
      else if (c == ')') prioity -= 10;
      else {
        while (op.size() && op.top()[1] >= prioity + p[c]) {
          answer += op.top()[0];
          op.pop();
        }
        op.push({c, prioity+p[c]});
      }
    }
  }
  while (op.size()) {
    answer += op.top()[0];
    op.pop();
  }

  cout << answer << "\n";

	return 0;
}