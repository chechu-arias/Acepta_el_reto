#include <iostream>
#include <algorithm>
#include <array>

#define kaprekar 6174
#define SIZE 4

using namespace std;

int main() {

    int n_cases;
    cin >> n_cases;

    for(int c = 0; c < n_cases; c++) {

        int val, rest;
        cin >> val;

        if (val == kaprekar) { 
            cout << "0\n";
            continue;
        }

        array<int,4> dig;
        dig[0] = val/1000;
        rest = val%1000;
        dig[1] = rest/100;
        rest = rest%100;
        dig[2] = rest/10;
        dig[3] = rest%10;

        if (dig[0] == dig[1] && dig[2] == dig[3] && dig[0] == dig[2]) {
            cout << "8\n";
            continue;
        }

        int cont = 0;
        while(true) {

            sort(dig.begin(),dig.end());
            array<int,4> asc = dig;
            reverse(dig.begin(),dig.end());
            array<int,4> desc = dig;

            int asc_v = 1000*asc[0] + 100*asc[1] + 10*asc[2] + asc[3];
            int desc_v = 1000*desc[0] + 100*desc[1] + 10*desc[2] + desc[3];

            int actual = abs(desc_v - asc_v);

            dig[0] = actual/1000;
            rest = actual%1000;
            dig[1] = rest/100;
            rest = rest%100;
            dig[2] = rest/10;
            dig[3] = rest%10;

            cont++;
            
            if (dig[0] == 6 && dig[1] == 1 && dig[2] == 7 && dig[3] == 4) break;

        }

        cout << cont << "\n";

    }

}