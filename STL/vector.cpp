#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
void print_vector(vector<T> v) {
    for (typename vector<T>::iterator it = v.begin(); it < v.end(); it++){
        cout << (*it) << " " ;
    }
    cout << endl;
}

int main() {
    // initial 

    vector<int> v(10,0);
    cout << "Initial" ;
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