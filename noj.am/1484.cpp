#include<iostream>
using namespace std;

int getg(int s, int e) {
    return e * e - s * s;
}

int main(void) {
    int G, s = 0, e = 1, arr, sv[1000000] = {}, svi = 0;
    cin >> G;
    while ((!(getg(s, e) > G && e - s == 1)) && e > s)
    {
        if (getg(s, e) < G) {       
            e++;
        }
        if (getg(s, e) > G) {
            s++;
        }
        if (getg(s, e) == G) {
            sv[svi] = e;
            svi++;
            e++;
            s++;
        }
    }
    for (int i = 0; i < svi; i++) {
        cout << sv[i]<<"\n";
    }
    if(svi==0){
        cout<<-1;
    }
    return 0;
}