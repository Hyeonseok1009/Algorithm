#include <iostream>
#include <map>
#include <vector>
#include <iterator>
#include <algorithm>
#define pp pair<int,int> 
using namespace std;
int r,c,k;
int arr[101][101];

bool com(const pp &a, const pp &b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    else return a.second < b.second;
}
int main(){
    freopen("test.txt","rt",stdin);
    cin >> r >> c >>k;
    for(int i = 1 ; i <= 3 ;i++){
        for(int j = 1; j <= 3 ; j++){
            cin >> arr[i][j];
        }
    }   
    int time = 0;
    int row_max = 3;
    int col_max = 3;
    while(1){
        
        if(arr[r][c] == k) break;
        if(time >= 100) break;
        /*cout <<row_max << " " <<col_max<<endl;*/
        if(row_max >= col_max){ //R연산
            //cout << "A" << endl;
            vector< map <int,int> > mm (row_max+1);
            int tmp_maxx = 0;
            for(int i = 1; i <= row_max; i++){
                int tmp_max = 0;
                for(int j =1; j <= col_max; j++){
                    if(arr[i][j] == 0) continue;
                    else{
                        mm[i][arr[i][j]]++;
                        
                    }
                }
                if(tmp_max < mm[i].size()) tmp_max = mm[i].size();
                if(tmp_maxx < tmp_max) tmp_maxx = tmp_max;
                int k = 1;
                // mm[i]를 정렬 한다 . // value 오름차순. key 오름차순
                vector < pp > tmp(mm[i].begin(), mm[i].end());
                sort(tmp.begin(), tmp.end(), com);
                // 다시 arr 에 대입한다. 나머지는 비워둔다.
                int ptr = 1 ;
                for(int u = 0 ; u < tmp.size() ; u++){
                   arr[i][ptr] = tmp[u].first;
                   ptr++;
                   arr[i][ptr] = tmp[u].second;
                   ptr++;
                   if(ptr> 100) break;       
                }
                for(int u = ptr ; u <= 100; u++){
                    arr[i][u] = 0;
                }
            }
            col_max = tmp_maxx*2;
           // cout << row_max << " "<<col_max<<endl;
        }
        else{
            //cout << "B" << endl;
            vector< map <int,int> > mm (col_max+1);
            int tmp_maxx = 0;
            for(int i = 1; i <= col_max; i++){
                int tmp_max = 0;
                for(int j =1; j <= row_max; j++){
                    if(arr[j][i] == 0) continue;
                    else{
                        mm[i][arr[j][i]]++;
                    }
                }
                if(tmp_max < mm[i].size()) tmp_max = mm[i].size();
                if(tmp_maxx < tmp_max) tmp_maxx = tmp_max;
                int k = 1;
                // mm[i]를 정렬 한다 . // value 오름차순. key 오름차순
                vector < pp > tmp(mm[i].begin(), mm[i].end());
                sort(tmp.begin(), tmp.end(), com);
                // 다시 arr 에 대입한다. 나머지는 비워둔다.
                int ptr = 1 ;
                for(int u = 0 ; u < tmp.size() ; u++){
                   arr[ptr][i] = tmp[u].first;
                   ptr++;
                   arr[ptr][i] = tmp[u].second;
                   ptr++;
                   if(ptr> 100) break;       
                }
                for(int u = ptr ; u <= 100; u++){
                    arr[u][i] = 0;
                }
            }
            row_max = tmp_maxx*2;
            //cout << row_max << " "<<col_max<<endl;
        }
        /*for(int i = 1; i <= 10; i++){
            for(int j = 1; j<= 10 ;j++){
                cout <<arr[i][j] << " ";
            }
            cout<< endl;
        }
        cout << endl;*/
        time++;
    }
    if(time == 100) cout << -1;
    else cout << time;
    return 0;
}