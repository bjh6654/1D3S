#include <string>
#include <vector>
#include <set>

using namespace std;

vector<string> user, banned;
vector<int> visit;
set<int> result;

bool isMatched(string a, string b) {
    if (a.size() != b.size()) return false;
    for (int i = 0; i < a.size(); i++)
        if (a[i] != '*' && a[i] != b[i]) return false;
    return true;
}

void dfs(int idx, int selected) {
    if (idx == banned.size()) {
        result.insert(selected);
        return;
    }
    
    string ban = banned[idx];
    for (int i = 0; i < user.size(); i++) {
        if (visit[i] || !isMatched(ban, user[i])) continue;
        visit[i] = 1;
        dfs(idx+1, selected+(1<<i));
        visit[i] = 0;
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    user = user_id;
    banned = banned_id;
    visit = vector<int>(user.size(), 0);
    
    dfs(0, 0);
    
    return result.size();
}