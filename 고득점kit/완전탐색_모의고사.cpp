#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> my;
    int cnt1 = 0 ;
    //수포자 1
    int i = 0 ;
    while(i != answers.size()){
        if( (i % 5 +1) == answers[i] ) cnt1++;
        i++;
    }
    int max = cnt1;
    cout<< cnt1 << endl;
    // 수포자 2
    int cnt2 = 0 ;
    i = 0 ;
    int tmp[4] =  {1,3,4,5};
    while(i != answers.size()){
        if(i % 2 == 0){
            if(answers[i] == 2) cnt2++;
        }
        else{
            if(tmp[ ((i-1)/2) %4 ] == answers[i]) {
                cnt2++;
            }
        }
        i++;
    }
    if(cnt2 > max) max = cnt2;
    cout<< cnt2 <<endl;
    // 수포자 3
    int cnt3 = 0 ;
    i = 0 ;
    while(i != answers.size()){
        int tmp = 0 ;
        if( i % 10 == 0 || i % 10 == 1){
            tmp = 3;
        }else if( i % 10 == 2 || i % 10 == 3){
            tmp = 1;
        }else if( i % 10 == 4 || i % 10 == 5){
            tmp = 2;
        }else if( i % 10 == 6 || i % 10 == 7){
            tmp = 4;
        }else{
            tmp = 5;
        }
        if(tmp == answers[i]) cnt3++;
        i++;
    }
    if(cnt3 > max) max = cnt3;
    cout<< cnt3 << endl;

    if(cnt1 == max){
        my.push_back(1);
    }
    if(cnt2 == max){
        my.push_back(2);
    }
    if(cnt3 == max){
        my.push_back(3);
    }
    return my;
}