#include <iostream>
using namespace std;

int main() {
    int a[5][5] = {0};
    
    a[1][2] = 1; a[1][3] = 1; a[3][4] = 1;
    a[2][1] = 1; a[3][1] = 1; a[4][3] = 1;
    
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}