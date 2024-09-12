#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int toint(string time) {
    return stoi(time.substr(0, 2))*60+stoi(time.substr(3, 5));
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    int vend = toint(video_len), cur = toint(pos), ostart = toint(op_start), oend = toint(op_end);
    if (ostart <= cur && cur <= oend) cur = oend;
    
    for (string c: commands) {
        if (c == "prev") {
            cur = max(0, cur-10);
        } else {
            cur = min(vend, cur+10);
        }
        
        if (ostart <= cur && cur <= oend) cur = oend;
    }
    
    // string a = std::format("{}", 10);
    
    string result = (cur < 600 ? "0" : "") + to_string(cur/60)
        + ":" + (cur%60 < 10 ? "0" : "") + to_string(cur%60);
    
    return result;
}

// 2024-09-11