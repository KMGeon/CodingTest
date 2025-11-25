#include <iostream>
#include <algorithm>
using namespace std;

int student[10000];	// 학생들의 코딩역량

int main() {
    int N;	// 팀의 개수
    int current = 0;
    int min = 0;

    cin >> N;

    for (int i = 0; i < 2 * N; i++) {
        cin >> student[i];
    }

    // 학생들의 코딩 역량 정렬
    sort(student, student + 2 * N);

    // min 초깃값 설정
    min = student[0] + student[2 * N - 1];

    for (int i = 0; i < 2 * N; i++) {
        // 코딩역량이 i번째로 큰 학생, i번째로 작은 학생을 조합
        current = student[i] + student[2 * N - i - 1];
        if (min > current) {	// 최솟값을 찾아나감
            min = current;
        }
    }

    cout << min;

    return 0;
}
