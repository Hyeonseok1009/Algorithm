#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int Dp[1000002];
int solution(vector<int> money) {
    int answer = 0;
    
    int maxx = 0 ;
    Dp[0] = money[0];  
    Dp[1] = Dp[0];
    for(int i = 2 ; i < money.size()-1;i++){
        Dp[i] = max(Dp[i-2] + money[i], Dp[i-1]);            
    }
    maxx = Dp[money.size()-2];    
    Dp[0] = 0;
    Dp[1] = money[1];
    for(int i = 2 ; i < money.size();i++){
        Dp[i] = max(Dp[i-2] + money[i], Dp[i-1]);
       
    }
    if(maxx < Dp[money.size()-1]) maxx = Dp[money.size()-1];
    answer = maxx;
    return answer;
}