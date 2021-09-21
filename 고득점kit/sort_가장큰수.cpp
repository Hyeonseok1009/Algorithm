#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
bool cmp(const string &a , const string &b){
    int flag =  0;
    int minlength = min(a.size(), b.size());
    for(int i  = 0 ; i < minlength; i++){
        if(a[i] != b[i]){
            flag = 1;
            break;
        }
    }
    if(flag == 1){
        return a > b; // 내림차순
    }else{
        if(a.size() == b.size()) return a  > b ; 
        else if(a.size() > b.size()){
            string tmp = a.substr(minlength);
            if(cmp(tmp,b)) return a > b;
            else return a < b;
        }
        else{
            string tmp = b.substr(minlength);
            if(cmp(a,tmp)) return a < b;
            else return a > b;
        }
    }
}

string solution(vector<int> numbers) {
    string answer = "";
    vector <string> num_str;
    for(auto a : numbers){
        num_str.push_back(to_string(a));
    }
    sort(num_str.begin(), num_str.end(),cmp);
    int cnt = -1;
    for(auto a = 0 ; a < num_str.size() ; a++){
        if(num_str[a] == "0") {
            cnt = a;
        }else {
            break;
        }
    }
    for(auto a = cnt + 1 ; a< num_str.size(); a++){
        answer += num_str[a];
    }
    if(answer == "") answer = "0";
    return answer;
}