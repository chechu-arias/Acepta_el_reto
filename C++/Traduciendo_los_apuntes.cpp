#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    while(true) {

        int n_teachers;
        cin >> n_teachers;

        if (n_teachers == 0) break;

        vector<pair<int, int>> intervalues;
        for (int i = 0; i < n_teachers; i++) {
            int ini, end;
            cin >> ini >> end;
            intervalues.push_back(pair<int, int>(ini, end));
        }

        sort(intervalues.begin(), intervalues.end());
        
        int cont = 0;
        int end = 0;

        for(int i = 0; i < n_teachers; i++) {

            if(end < intervalues[i].first) {

                cont += (intervalues[i].second - intervalues[i].first + 1);
                end = intervalues[i].second;

            } else if(end < intervalues[i].second) {

                cont += (intervalues[i].second - end);
                end = intervalues[i].second;

            }

        }

        cout << cont << "\n";

    }

}