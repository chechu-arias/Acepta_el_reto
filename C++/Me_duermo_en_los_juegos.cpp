#include <iostream>

using namespace std;

int main() {

    int n_cases;
    cin >> n_cases;

    for (int c = 0; c < n_cases; c++) {

        int n_save_points, mins_per_day;
        cin >> n_save_points >> mins_per_day;

        int save_points_mins[n_save_points];
        for (int i = 0; i < n_save_points; i++) {
            cin >> save_points_mins[i];
        }

        int res = 0, time = 0, actual = 0;
        while (actual < n_save_points) {
            while ( (time+mins_per_day) >= save_points_mins[actual] ) {
                actual++;
            }
            res++;
            time = save_points_mins[actual-1];
        }

        cout << res << "\n";

    }

}