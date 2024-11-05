#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>

using namespace std;

unordered_set<string> name;

struct node {
  map<char, node*> m;
  bool isEnd = false;

  void insert(int idx, string& s) {
    if (this->m.find(s[idx]) == this->m.end())
      this->m[s[idx]] = new node();

    if (idx == s.size()-1) this->m[s[idx]]->isEnd = true;
    else this->m[s[idx]]->insert(idx+1, s);
  }
};

bool findString(node* color, string& s) {
  node* cur = color;
  for (int i = 0; i < s.size()-1; i++) {
    char c = s[i];
    if (cur->m.find(c) == cur->m.end()) return false;
    cur = cur->m[c];
    if (cur->isEnd && name.find(s.substr(i+1)) != name.end()) return true;
  }
  return false;
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  node color;

  int C, N, Q;
  cin >> C >> N;

  string s;
  for (int i = 0; i < C; i++) {
    cin >> s;
    color.insert(0, s);
  }
  for (int i = 0; i < N; i++) {
    cin >> s;
    name.insert(s);
  }

  cin >> Q;
  for (int i = 0; i < Q; i++) {
    cin >> s;
    if (findString(&color, s)) cout << "Yes\n";
    else cout << "No\n";
  }
  
	return 0;
}