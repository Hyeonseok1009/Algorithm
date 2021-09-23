#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;
int dp[502][502];
int map[502][502];
int solution(vector<vector<int>> triangle) {
    for(int i = 0 ; i < triangle.size() ; i++){
        for(int j = 0 ; j < triangle[i].size() ;j++){
            int value = triangle[i][j];
            if(i== 0 && j ==0){
                map[i][j] = value;
            }else if(j-1<0){
                map[i][j] = value + map[i-1][j];
            }else if(j > i-1){
                map[i][j] = value + map[i-1][j-1];
            }
            else {
                map[i][j] = value + max(map[i-1][j],map[i-1][j-1]);
            }
        }
    }
    int answer = 0;
    int lastrow = triangle.size()-1;
    for(int i = 0 ; i < triangle[lastrow].size(); i++){
        if(answer<map[lastrow][i]) answer = map[lastrow][i];
    }
    
    return answer;
}