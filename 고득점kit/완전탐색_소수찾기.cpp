#include <cstring>
#include <vector>
#include <string>
#include <set>
#include <iostream>
using namespace std;

bool isincluded[7];
int aa[7];
set <int> s;
void foo (int k, int r, string numbers){
    if(k == r){
        string tmp = "";
        for(int i = 0 ; i < r ; i++){
            tmp += numbers[aa[i]];       
        }
        //cout << tmp <<" ";
        if(tmp != ""){
            s.insert(stoi(tmp));
        }
    }else{
        for(int i = 0 ; i < numbers.size() ; i++){
            if(isincluded[i] == false){
                isincluded[i] = true;
                aa[k] = i;
                foo(k+1, r, numbers);
                isincluded[i] = false;
            }
        }
    }
}
bool isprime(int n){
    if(n == 0 || n == 1){
        return false;
    }
    int flag = 1;
    for(int i = 2 ; i*i <= n ; i++){
        if(n % i == 0){
            flag = 0;
            break;
        }
    }
    if(flag == 1) return true;
    else return false;
}

int solution(string numbers) {
    int answer = 0;
    for(int i = 1; i <= numbers.size() ; i++){
        memset(isincluded, 0, sizeof(isincluded));
        foo(0,i,numbers);
    }
    
    for(auto a : s)
        if(isprime(a)) answer++;
    return answer;
}