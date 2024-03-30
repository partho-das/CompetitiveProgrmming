#include<bits/stdc++.h>

using namespace std;

template<class T, const int maxn> class Deque {
    T arr[maxn*3+10];
    int _start,_end;

public:
    Deque(){
        _start = _end = maxn;
    }

    inline void push_front(T value){
        arr[_start--] = value;
    }
    inline void pop_front(){
        if(!size()) return;
        _start++;
    }
    inline void push_back(T value){
        arr[++_end] = value;
    }
    inline void pop_back(){
        if(!size()) return;
        _end--;
    }
    inline T operator[](const int &index){
        return arr[_start+1+index];
    }
    inline size_t size(){
        return _end-_start;
    }
};

int main()
{
    #ifdef PARTHO
        freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
        freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
        int start_time = clock();
    #endif

    srand(time(NULL));
    Deque<int,100> dq;

    for(int i = 0; i < 20; i++){
        int cmd = rand()%4;
        if(cmd == 0){
            dq.push_back(rand()%10);
        }
        if(cmd == 1){
            dq.pop_back();
        }
        if(cmd == 2){
            dq.push_front(rand()%10);
        }
        if(cmd == 3){
            dq.pop_front();
        }
        cout << "CMD = " << cmd << endl;
        for(int j = 0; j < dq.size(); j++) cout << dq[j] << " "; cout << endl;
    }

    return 0;
}
