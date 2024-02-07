// FSM_BT.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

bool sorting(pair <int, int> p, pair <int, int> p2) { // compare 함수
    if (p.first == p2.first) { // first 같다면
        cout << p.second << "<-p1 ,p2:" << p2.second << endl;
        return p.second < p2.second;
    }
    return p.first > p2.first;
}

int solution(vector<string> babbling) {
    int answer = 0;
    vector<string> speak = { "aya", "ye", "woo", "ma" };
    string word, prev = "";

    for (string s : babbling) {
        for (int i = 0; i < s.size(); i++) {
            word += s[i];
            if (find(speak.begin(), speak.end(), word) != speak.end() && word != prev) {
                prev = word;
                cout << prev << ",";
                word.clear();
            }
        }
        if (word == "") answer++;
        prev.clear();
    }
    return answer;
}


string video[64];

// 재귀함수
void printCompResult(int size, int y, int x)
{
    char curr = video[y][x];

    for (int i = y; i < size+y; i++) {
        for (int j = x; j < size+x; j++) {
            if (curr != video[i][j]) {
                cout << "(";
                printCompResult(size / 2, y, x);
                printCompResult(size / 2, y, x + size / 2);
                printCompResult(size / 2, y + size / 2, x);
                printCompResult(size / 2, y + size / 2, x + size / 2);
                cout << ")";
                return;
            }
        }
    }
    cout << curr;
}


int main()
{ 
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> video[i];

    printCompResult(N, 0, 0);

    //vector<string> arr;
    //arr = { "ayaye", "uuu", "yeye", "yemawoo", "ayaayaa" };
    ////solution(arr);

    //string test = "1a2b13c44d";
    //stringstream ss(test);

    //int num;
    //string s;
    //for (int i = 0; i < 4; i++) {
    //    //ss >> num;
    //    s = ss.get();
    //    cout << +1 << ", " << s << endl;
    //}
    



    cout << "\n";
}



// 각 트리의 첫좌표. 2차원 배열이므로 [y][x] 순서
//char start_point = video[y][x];
//
//// 위에서부터 한줄씩 비교하려면 i에 y부터 대입
//for (int i = y; i < y + size; i++) {
//    for (int j = x; j < x + size; j++) {
//        if (start_point != video[i][j]) // 시작점과 다르면
//        {
//            cout << '(';
//            printCompResult(size / 2, y, x); // 2사분면
//            printCompResult(size / 2, y, x + size / 2);
//            printCompResult(size / 2, y + size / 2, x);
//            printCompResult(size / 2, y + size / 2, x + size / 2);
//            // 하나의 루트배열을 4개의 쿼드트리로 나눔
//            cout << ')'; // 위 재귀함수가 끝났으면 괄호를 닫아줌
//            return; // 재귀함수를 마쳤다는건 모든 쿼드트리가 완성됐다는 것
//        }
//    }
//}
//cout << start_point; // 해당 트리 구역에 같은 값만 존재하면 그 수를 출력