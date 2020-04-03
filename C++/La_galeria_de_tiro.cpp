#include <iostream>

using namespace std;

int pd[1000000];

int situarTirador(int ini, int end) {
    int n_elems = end-ini+1;
    
    if (n_elems < 3) return 0;
    else if (pd[n_elems]) return pd[n_elems];
    
    int mitad = ini + ((end-ini)/2);
    pd[n_elems] = 1 + situarTirador(ini, mitad-1) + situarTirador(mitad+1, end);
    return pd[n_elems];
}

int main() {

    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        int res = 1;

        if (n > 2) {

            res++;
            if (pd[n-2]) res += pd[n-2];
            else res += situarTirador(2, n-1);

        }
        
        cout << res << "\n";
    }

}