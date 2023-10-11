#include <iostream>
#include <string>
using namespace std;

class String{
    public:
        string str;
        int* f;

        String(string init_str): str(init_str) {
            f = new int[str.length()];            
        }

        void calculate_f() {
            f[0] = -1;
            cout << f[0] << " ";
            for (int i = 1; i < str.length(); i++) {
                int f_temp = f[i-1] + 1;
                if(str[i] == str[f_temp]){
                    f[i] = f_temp;
                }
                else {
                    f[i] = -1;
                }
                cout << f[i] << " ";
            }
        }

        int FastFind(String pat);

        int Length() {
            return str.length();
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
    String pat("abcabcacab");
    pat.calculate_f();
    String s("abcabcacacabcabcacaabcabcacab");
    cout << '\n' << s.FastFind(pat) << endl;
    return 0;
}