#include <iostream>
#include <time.h>

using namespace std;

char repeat;

void rep() {
    cout << "\nRepeat with another multiple? (y/n) ";
    cin >> repeat;
    if (repeat == 'y' || repeat == 'n') {
        cout << "\n-------------------------------------------------\n\n";
        return;
    }
    else {
        rep();
    }
}

void main() {
    
    int m[13];
    double ans;
    srand(time(0));

    cout << "---------Multiplication Game---------\n\n";

    do {
        int count = 0;
        int score = 0;
        int lvl = 0;
        int i = 0;

        int mw[100], randw[100];

        cout << "Choose number of multiples: ";
        cin >> lvl;
        for (int k = 0; k < lvl; k++) {
            cout << "Enter a multiple: ";
            cin >> m[k];
        }
        cout << "\n";

        clock_t start = clock();

        while (((clock() - start) / CLOCKS_PER_SEC) <= 60) {
            count++;

            int random = rand() % 11;
            int randm = rand() % lvl;
            cout << m[randm] << " x " << random << " = ";
            cin >> ans;

            if (ans == m[randm] * random) {
                score++;
            }
            else {
                mw[i] = m[randm];
                randw[i] = random;
                i++;
            }
        }

        cout << "\nYou got " << score << " / " << count;
        cout << "\nWrong answers: \n";
        for (int j = 0; j < i; j++) {
            cout << mw[j] << " x " << randw[j] << " = " << mw[j] * randw[j] << "\n";
        };

        rep();

    } while (repeat == 'y');

}
