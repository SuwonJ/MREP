#include<stdio.h>
#include<iostream>

//#include<windows.h>

using namespace std;
int queue[100000];
int frnt = -1;
int rear = -1;

void push(int x) {
    rear++;
    queue[rear] = x;
}
int empty() {
    if (rear - frnt < 1) return 1;
    else return 0;
}
int pop() {
    if (empty() == 1) return -1;
    else {
        frnt++;
        return queue[frnt];
    }
}
int size() {
    return rear - frnt;
}
int front() {
    if (empty() == 1) return -1;
    else return queue[frnt + 1];
}
int back() {
    if (empty() == 1) return -1;
    else return queue[rear];
}
int main() {
    int br, i, pg, ip, j, tmp, max = 0, k,cnt=0,l;
    cin >> br;
    for (i = 0; i < br; i++) {
        frnt = -1;
        rear = -1;
        cnt = 0;
            cin >> pg >> ip;
            for (j = 0; j < pg; j++) {
                cin >> tmp;
                push(tmp);
            }
            for (l = 0; l < pg; l++) {
                //최대 문서 중요도
                int index = 0; max = 0;
                for (j = frnt + 1; j < rear + 1; j++) {
                    if (max < queue[j]) {
                        max = queue[j];
                        index = j;
                    }
                }
                int c = index - frnt - 1;
                // 위치 변경
                for (j = 0; j < c; j++) {
                    int temp = front();
                    pop();
                    push(temp);
                    if (ip == frnt) {
                        ip = rear;
                    }
                }
                /*for (int a = frnt + 1; a <= rear; a++) {
                    cout <<a << " / "<< queue[a] << " " << endl;
                }*/
                //cout << endl;
                cnt++;
                pop();
                //printf("ip : %d\n", ip);
                //출력 ip 출력할 애랑 같은 앤지 확인
                if (ip == frnt) {
                    cout << cnt << endl;
                    break;
                }
            }
        /*
        cout << "Q{" << endl;
        for (k = 0; k < pg; k++) {
            cout << pop() << endl;
        }
        cout << "}" << endl;
        */
    }
    //system("pause");
    return 0;
}
