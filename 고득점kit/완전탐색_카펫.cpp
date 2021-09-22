#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int total = brown + yellow;
    for(int i = 2 ; i* i <= total ; i++){
        if(total % i == 0){
            int x = i; 
            int y = total / x;
            if(2*x + 2*y -4 == brown){
                answer.push_back(x);
                answer.push_back(y);
                break;
            }
        }
    }
    sort(answer.begin(), answer.end(), greater<int>());    
    return answer;
}