#include <string>
#include <vector>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    for(int i = citations.size(); i >= 1 ; i--){
        int cnt = 0 ;
        for(auto a : citations)
            if ( a >= i) cnt ++;
        if(cnt >= i){
            answer = i;
            break;
        }
    }
    return answer;
}