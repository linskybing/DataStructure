#include <iostream>
#include <tuple>
using namespace std;

int main() {
    tuple<int, int, char> t1(0, 1, 'a');
    cout << "(" << get<0>(t1) << "," << get<1>(t1) << "," << get<2>(t1) << ")\n";
}