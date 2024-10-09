#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool isDivide(vector<int> line, vector<int> points) {
  vector<int> pa = {points[0], points[1]}, pb = {points[2], points[3]};
  if (line[0] != line[2]) {
    double incline = (double)(line[3]-line[1])/(line[2]-line[0]);
    double incline2 = (double)(points[3]-points[1])/(points[2]-points[0]);
    double aloc = incline*(pa[0]-line[0])-(pa[1]-line[1]);
    double bloc = incline*(pb[0]-line[0])-(pb[1]-line[1]);
    if (!aloc && !bloc) {
      if (min(line[0], line[2]) <= max(points[0], points[2]) && max(line[0], line[2]) >= min(points[0], points[2])) return true;
      return false;
    }
    if (aloc*bloc <= 0) return true;
    return false;
  } else {
    if (points[0] == points[2] && points[0] == line[0]) {
      if (min(line[1], line[3]) <= max(points[1], points[3]) && max(line[1], line[3]) >= min(points[1], points[3])) return true;
      return false;
    }
    return (pa[0]-line[0])*(pb[0]-line[0]) <= 0;
  }
}

bool isCrossed(vector<int> a, vector<int> b) {
  return isDivide(a, b) && isDivide(b, a);
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  vector<vector<int>> lines;
  for (int i = 0; i < n; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    lines.push_back({x1, y1, x2, y2});
  }

  vector<vector<vector<int>>> group(n);

  group[0].push_back(lines[0]);
  int gi = 1;
  for (int i = 1; i < n; i++) {
    vector<int> la = lines[i];
    stack<int> s;
    for (int g = 0; g < n; g++) {
      for (vector<int> lb: group[g]) {
        if (isCrossed(la, lb)) {
          s.push(g);
          break;
        }
      }
    }

    if (s.empty()) {
      group[gi].push_back(la);
      gi++;
    } else if (s.size() == 1) {
      group[s.top()].push_back(la);
      s.pop();
    } else {
      group[gi].push_back(la);
      while (s.size()) {
        int top = s.top();
        s.pop();
        for (vector<int> line: group[top]) group[gi].push_back(line);
        group[top] = {};
      }
      gi++;
    }
  }

  int count = 0;
  int max = 0;
  for (vector<vector<int>> g: group) {
    if (g.size()) {
      count++;
      if (g.size() > max) max = g.size();
    }
  }
  cout << count << "\n";
  cout << max;
  return 0;
}
