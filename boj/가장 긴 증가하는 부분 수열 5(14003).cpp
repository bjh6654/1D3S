#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

	int N;
	cin >> N;

	vector<vector<int>> answer;
	vector<int> num(N);
	for (int i = 0; i < N; i++) {
		cin >> num[i];
		if (!answer.size() || num[answer.back().back()] < num[i]) {
			answer.push_back({i});
		} else {
			int low = 0, high = answer.size()-1;
			while (low < high) {
				int check = low + (high-low)/2;
				if (num[answer[check].back()] < num[i]) low = check+1;
				else high = check;
			}
			answer[low].push_back(i);
		}
	}

	cout << answer.size() << "\n";

	vector<int> result;
	for (int i = answer.size()-1; i >=0; i--) {
		while (result.size() && result.back() < answer[i].back()) answer[i].pop_back();
		result.push_back(answer[i].back());
	}

	for (int i = result.size()-1; i >=0; i--)
		cout << num[result[i]] << (i == 0 ? "\n" : " ");

	return 0;
}