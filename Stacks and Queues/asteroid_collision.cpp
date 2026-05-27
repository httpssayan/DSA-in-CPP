#include<bits/stdc++.h>
using namespace std;

vector<int> asteroids_collision(vector<int>& asteroids){
    stack<int> s;
    for(int x:asteroids){
        bool destroyed = false;
        while(!s.empty() && s.top()>0 && x<0){
            if(s.top() < abs(x)){
                s.pop();
            }
            else if(s.top()==abs(x)){
                    s.pop();
                    destroyed=true;
                    break;
                }
            else{
                destroyed = true;
                break;
            }
        }
        if(!destroyed){
            s.push(x);
        }
    }
    vector<int> result;
    while(!s.empty()){
        result.push_back(s.top());
        s.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}

int main(){
    vector<int> asteroids = {5, 10, -5};
    vector<int> result = asteroids_collision(asteroids);
    for(int x:result){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}