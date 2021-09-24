#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;
int parents[200];
int find(int v){
    if(v == parents[v]) return v;
    else 
        return parents[v] = find(parents[v]);
}
void unions(int a, int b){
    int tmp_a = find(a);
    int tmp_b = find(b);
    if(tmp_a != tmp_b)
        parents[tmp_a] = tmp_b;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    set<int> s;
    for(int i = 0; i < computers.size(); i++){
        parents[i] = i;   
    }
    for(int i = 0; i <computers.size(); i++){
        for(int j = 0 ; j < computers[i].size(); j++){
            if(i != j && computers[i][j] == 1){
                unions(i,j);
            }
        }
    }
    for(int i = 0; i < computers.size(); i++){
        parents[i] = find(i);
    }
    for(int i = 0; i < computers.size(); i++){
        s.insert(parents[i]);
    }
    answer = s.size();
    return answer;
}