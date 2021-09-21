#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string,int> complet;
    
    for(auto a: completion){
        complet[a]++;
    }
    for(auto b : participant){
        if(complet.find(b) == complet.end()) {
            answer = b;
        }
    }
    return answer;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<string> participant = {"marina", "josipa", "nikola", "vinko", "filipa"};
    vector<string> completion = {"josipa", "filipa", "marina", "nikola"};

    string ans = solution(participant, completion);
    cout << ans << " ";
    return 0;
}