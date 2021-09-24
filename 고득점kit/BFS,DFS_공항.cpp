#include <string>
#include <vector>
#include <iostream>

using namespace std;
vector <string> backup;
vector <int> visited;
void DFS(string start, int depth, vector<string>res, vector<vector<string>> tickets){
    if(depth == tickets.size()){
        // 도착 // 백업과 비교후, 백업 다시 갱신
        res.push_back(start);
       /* for(auto a : res)
            cout << a << " ";
        cout << endl;
        for(auto a : backup)
            cout << a << " ";
        cout << endl;*/
        if(backup.size() == 0){
            backup.resize(res.size());
            copy(res.begin(),res.end(),backup.begin());
        }else{
            int flag = 0 ;
            for(int i = 0 ; i < res.size(); i++){
                if(res[i] < backup[i]){
                    //cout<<"Here res: " <<res[i]<<" backup: " << backup[i]<<endl;;
                    flag = 1;
                    break;
                }else if(res[i] > backup[i]){
                    break;    
                }
            }
            if(flag==1) swap(backup, res);     
        }
        
        return;
    }
    else{
        for(int i = 0 ; i < tickets.size() ; i++){
            if(visited[i] == 0){
                if(tickets[i][0] == start){
                    visited[i] = 1;
                    res.push_back(start);
                    /*for(auto a : res)
                        cout << depth<<" " << a << " ";
                    cout << endl;*/
                    DFS(tickets[i][1], depth+1, res, tickets);
                    res.pop_back();
                    visited[i] = 0;
                }
            }
        }
    }
}

    

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    
    visited.resize(tickets.size());
    //cout << visited.size();
    for(int i = 0 ; i < tickets.size();i++){
        visited[i] = 0 ;        
    }    // 이따가 auto로 했을때 값 변경되는 지 확인해보자
    vector<string> tmp;
    DFS("ICN",0,tmp,tickets);
    visited[0] = 1;
    swap(answer, backup);
    return answer;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    //vector<vector<string>> tickets = {{"ICN", "JFK"}, {"HND", "IAD"}, {"JFK", "HND"}};
    vector<vector<string>> tickets = {{"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL","SFO"}};
    vector<string> ans = solution(tickets);
    for(auto a : ans)
        cout << a <<" ";
    return 0;
}