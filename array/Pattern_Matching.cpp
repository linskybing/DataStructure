#include <iostream>
#include <string>
using namespace std;

class String{
    public:
        string str;
        int* f;
        String(string init_str): str(init_str) {
            f = (int*) malloc(sizeof(int) * str.size());
        }

        int FastFind(String pat);

        int Length() {
            return str.size();
        }

        ~String() {
            free(f);
        }        
};

int String::FastFind(String pat){

    // Determine if pat is a substring of s
    int PosP = 0, PosS = 0; 
    int LengthP = pat.Length(), LenghtS = Length();

    while((PosP < LengthP) && (PosS < LenghtS)) {
        if (pat.str[PosP] == str[PosS]) {
            PosP++; PosS++;
        }
        else {
            if (PosP == 0) PosS++;
            else PosP = pat.f[PosP-1] + 1;
        }
    }

    if (PosP < LengthP) return -1;
    else return PosS - LengthP;
}

int main() {

    return 0;
}