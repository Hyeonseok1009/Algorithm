#include <iostream>
#include <vector>

using namespace std;
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

int R,C,M;

struct shark{
    int y;
    int x;
    int s;
    int dir;
    int big;
    bool die;
    shark(int a, int b, int c, int d, int e, bool dd = false){
        y = a; x = b; s = c; dir = d; big = e; die = dd;
    }
};

vector <shark> sharks;

int main() {
    freopen("test.txt","rt",stdin);
    cin >> R >> C >> M;
    vector < vector <int> > map(R+1, vector<int> (C+1,0));
    int r,c,s,d,z;
    for(int i = 1; i <= M ;++i){
        cin >> r >> c >> s >> d >> z;
        sharks.push_back(shark(r,c,s,d,z));
        map[r][c] = 1;
    }   
    
    int time = 0;
    int ans = 0; 
    while(time < C){
        //ÀÌµ¿
        int c_pos = time + 1;
       /* cout <<"["<< c_pos<<"]"<<endl;
        for(auto sha : sharks){
            if(sha.die == false){
                cout << sha.y << " " << sha.x << " | ";
            }
        }
        cout << endl;*/
        //³¬½Ã
        for(int i = 1; i <= R; i++){
            if(map[i][c_pos] == 1){
                for(auto sh = sharks.begin(); sh != sharks.end() ; sh++){
                    if(sh->y == i && sh->x == c_pos && sh->die == false){
                        ans += sh->big;
                        //cout << sh->y <<" " <<sh->x <<endl;
                        sh->die = true;
                        map[i][c_pos] -= 1;
                        break;
                    }
                }
                break;
            }
        }
        /*for(auto sha : sharks){
            if(sha.die == false){
                cout << sha.y << " " << sha.x << " | ";
            }
        }
        cout << endl;*/
        
        // sharks move
        for(auto sh= sharks.begin() ; sh != sharks.end();  sh++){
            if(sh->die == false){
                int rest = sh->s;
                map[sh->y][sh->x] -= 1;
                while(rest >0){
                    if(sh->dir == 2){
                        if( R - sh->y < rest){
                            rest -= (R - sh->y);
                            sh->y = R;
                            sh->dir = 1;
                        }
                        else {
                            sh->y = sh->y + rest;
                            rest = 0;
                        }
                    }
                    else if(sh->dir == 3){
                        if( C - sh->x < rest){
                            rest -= (C - sh->x);
                            sh->x = C;
                            sh->dir = 4;
                        }
                        else {
                            sh->x = sh->x + rest;
                            rest = 0;
                        }
                    }  
                    else if(sh->dir == 1){
                        if( sh->y <= rest){
                            rest -= (sh->y-1);
                            sh->y = 1;
                            sh->dir = 2;
                        }
                        else {
                            sh->y = sh->y - rest;
                            rest = 0;
                        }
                    }else if(sh->dir == 4){
                        if( sh->x <= rest){
                            rest -= (sh->x-1);
                            sh->x = 1;
                            sh->dir = 3;
                        }
                        else {
                            sh->x = sh->x - rest;
                            rest = 0;
                        }
                    }          
                }
                map[sh->y][sh->x] += 1;
            }
        }
        for(int i = 1; i < map.size(); i++){
            for(int j = 1; j < map[i].size(); j++){
               if(map[i][j] > 1){
                   int tmp = -1;
                   int cnt = 0;
                   for(auto k= 0; k < sharks.size(); k++ ){
                       if(cnt == map[i][j]) break;
                       if(sharks[k].x == i && sharks[k].y == j && sharks[k].die == false){
                           cnt++;
                           if(tmp == -1) tmp = k;
                           else{
                               if(sharks[k].big > sharks[tmp].big){
                                 sharks[tmp].die = true;
                                 tmp = k;   
                               } 
                               else sharks[k].die = true;
                           }
                       }
                   }
                   map[i][j] = 1;
               }else if(map[i][j] <0){
                   map[i][j] = 0;
               }
            }
        }
        
        time++;
    }
    cout << ans ;
    return 0;
}