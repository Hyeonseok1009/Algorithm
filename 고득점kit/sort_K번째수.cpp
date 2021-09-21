#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int i = 0 ; i< commands.size() ;i++){
        int a,j,k;
        a = commands[i][0];
        j = commands[i][1];
        k = commands[i][2];
        vector<int> my_array(array.begin()+(a-1), array.begin()+j);
        sort(my_array.begin(), my_array.end());
        answer.push_back(my_array[k-1]);
    }
    
    return answer;
}