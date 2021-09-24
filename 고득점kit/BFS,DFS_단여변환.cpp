#include <string>
#include <vector>
#include <iostream>
using namespace std;
string targ;
int visited[50];
int minn = 2147000000;
int diff(string a, string b){
    int cnt = 0;
    for(int i = 0 ; i < a.size() && cnt < 2; i++){
        if(a[i] != b[i]) cnt++;
    }
    if(cnt == 1) return 1;
    else return 0;
    
}
void DFS(int depth, string cur_word, vector<string> &words){
    if(cur_word == targ) {
        if(minn > depth) minn = depth;
        return;
    }
    if(depth == words.size()) return;
    for(int i = 0 ; i < words.size(); i++){
        if(visited[i] == 0){
            if(diff(cur_word,words[i])){
                visited[i] = 1;
                //cout << words[i] <<" "<< depth <<" | ";
                DFS(depth+1, words[i], words);
                visited[i] = 0;
            }
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    targ = target;
    DFS(0,begin,words);
    answer = minn;
    if (answer == 2147000000) answer = 0;
    return answer;
}