#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<string> dict;

struct node {
  map<char, node*> m;
  bool isEnd = false;
};

void addTree(node* root, string word) {
  node* cur = root;
  for (char c: word) {
      if (cur->m.find(c) == cur->m.end())
          cur->m[c] = new node();
      cur = cur->m[c];
  }
  cur->isEnd = true;
}

int findString(node* root, string s) {
  node* cur = root;
  int count = 1;
  cur = cur->m[s[0]];
  for (int i = 1; i < s.size(); i++) {
    if (cur->m.size() != 1 || cur->isEnd)
      count++;
    cur = cur->m[s[i]];
  }
  return count;
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed;
  cout.precision(2);

  int N;

  while (cin >> N) {
    node root = *new node();
    dict = vector<string>(N);

    for (int i = 0; i < N; i++) {
      cin >> dict[i];
      addTree(&root, dict[i]);
    }

    int count = 0;
    for (string s: dict)
      count += findString(&root, s);

    cout << (double)count/N << "\n";
  }

	return 0;
}