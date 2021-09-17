#include <iostream>
#include <map>
#include <vector>
#include <iterator>
#include <queue>
#include <algorithm>
#define pp pair<int,int> 
using namespace std;
int N, M;  // 방 너비, 바이러스 수
char room[51][51];
int virus_num = 0;
pair <int, int>  pos_virus[11];
int virus_check[11] = {0,};
int ans = 21475000;
int dir [4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
void solve(){
    int check[51][51] = {0,};
    int my_room[51][51] = {0,};
    queue < pair<int, int> > q;
    for(int i = 1; i <= virus_num ; i++){
        if(virus_check[i] == 1){
            q.push(pos_virus[i]);
            check[pos_virus[i].first][pos_virus[i].second] = 1;
            my_room[pos_virus[i].first][pos_virus[i].second]  = 1;
            //cout << pos_virus[i].first<<" " << pos_virus[i].second << endl;
        }
    }
    while(!q.empty()){
        int tmp_y = q.front().first;
        int tmp_x = q.front().second;
        q.pop();
        for(int i = 0 ; i < 4 ;i++){
            int next_y = tmp_y + dir[i][0];
            int next_x = tmp_x + dir[i][1];
            if(next_y >=1 && next_y <= N && next_x >=1 && next_x <= N){
                if(room[next_y][next_x] == 0 && check[next_y][next_x] == 0){
                    my_room[next_y][next_x] = my_room[tmp_y][tmp_x] +1;
                    check[next_y][next_x] = 1;
                    q.push({next_y,next_x});
                }else if(room[next_y][next_x] == '*' && check[next_y][next_x] == 0){
                    my_room[next_y][next_x] = my_room[tmp_y][tmp_x] +1;
                    check[next_y][next_x] = 1;
                    q.push({next_y,next_x});    
                }
            }
        }
    }
    int flag = 0;
    int max = 0;
    /*for(int i =1 ; i <= N  ;i++){
        for(int j = 1; j<= N ;j++){
       
            cout << my_room[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;*/
    for(int i =1 ; i <= N && flag == 0 ;i++){
        for(int j = 1; j<= N ;j++){
            if(my_room[i][j] == 0 && room[i][j] ==0 ){
                flag = 1; 
                break;
            }
            if(max < my_room[i][j] && room[i][j] != '*' )  max= my_room[i][j];
        }
    }
    max--;
    if(flag == 0){
           
        if(ans > max ) ans = max;
    }


}
void combi(int s, int n, int r,int cnt){
    if(n<0) return ;
    if(cnt == M)
    {
        //순회 시작.
        solve();
        
    }
    else{
        
        virus_check[s] = 1;
        combi(s+1,n-1, r-1,cnt+1);
        virus_check[s] = 0;
        combi(s+1,n-1, r,cnt);
    }
}

int main(){
    freopen("test.txt","rt",stdin);
    cin >> N >>M;
    int tmp;
    int xflag = 1;
    for(int i =1 ; i<= N ; i++){
        for(int j =1 ; j<= N ;j++){
            cin >> tmp;
            if(tmp == 2) {
                room[i][j] = '*';
                virus_num += 1; 
                pos_virus[virus_num]= {i,j};
            }
            if(tmp == 0){
               room[i][j] = 0;
               xflag = 0;     
            } 
            if(tmp == 1) room[i][j] = '-';
        }
    }
    if(xflag == 1){
        cout << 0;
        return 0;
    }
    combi(1, virus_num, M,0);
    if(ans == 21475000) {
        cout << -1;
        return 0;
    }
    
    cout << ans;
    return 0;
}