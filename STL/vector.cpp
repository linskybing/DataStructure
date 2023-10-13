#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

template <typename T>
void print_vector(vector<T> v) {
    for (int i = 0; i < v.size(); i++){        
        cout << v[i] << " ";
    }
    cout << endl;
}
template <typename T>
bool cmp (const T& left,const T& right) {
    return left > right;
}

int main() {
    // initial 

    vector<int> v= {10,9,8,7,6,5,4,3,2,1};
    sort(v.begin(), v.end(), cmp<int>);
    cout << "Initial" << endl ;
    print_vector(v);

    //vector<int> v2 = {0,1,2,3,4,5,6,7,8,9,10};


    //insert    
    //v.insert(v.end()-1, 5);    


    //erase
    //v.erase(v.end()-2);

    //size
    //cout << "Size: " << v.size() << endl;

    //position
    //v.front() = 1;
    //v.back() = 10;
    //cout << "Front and back: "; 
    //print_vector(v);
    
    // algorithm reverse
    //reverse(v.begin(), v.end());
    //cout << "Reverse: ";
    //print_vector(v);


    // algorithm fill
    //fill(v.begin(), v.end(), 1);
    //cout << "Fill: ";
    //print_vector(v);

    
}