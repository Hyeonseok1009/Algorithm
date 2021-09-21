#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());
    for(auto a : phone_book) cout << a <<" ";
    for(int i = 0 ; i < phone_book.size(); i++){
        for(int j = i+1; j < phone_book.size(); j++){
            if(phone_book[j].find(phone_book[j]) != string::npos) answer = false; break;
        }
    }
    return answer;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<string> phone_book = {"12", "88","123","567","1235"};
    bool ans = solution(phone_book);
    cout << ans << " ";
    return 0;
}