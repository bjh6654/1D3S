#include <iostream>
#include <vector>
#include <string>

using namespace std;

int kmp(string text) {
  int j = 0;
  vector<int> p(text.size(), 0);
  for (int i = 1; i < text.size(); i++) {
    while (j > 0 && text[i] != text[j])
      j = p[j-1];
    if (text[i] == text[j])
      p[i] = ++j;
  }

  if (p[text.size()-1] < text.size()/2) return 1;
  if (text.size()%(text.size()-p[text.size()-1])) return 1;
  return text.size()/(text.size()-p[text.size()-1]);
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string text;
  while (cin >> text) {
    if (text == ".") break;
    cout << kmp(text) << "\n";
  }

  return 0;
}