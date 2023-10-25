#include <iostream>

using namespace std;

int main() {
    string e;
    cin >> e;
    int* failure = new int[e.size()];
    failure[0] = -1;
    for(auto it = 1; it < e.size(); it++){
        if(e[failure[it-1]+1] == e[it]) {
            failure[it] = failure[it-1] + 1;
        }
        else {
            failure[it] = -1;
        }
    }

    for(int i = 0; i < e.size(); i++) {
        cout << failure[i] << " ";
    }
    cout << endl;
    
}