#include<bits/stdc++.h>

using namespace std;

template<class T, const int maxn> class Deque {
    T arr[maxn*2+10];
    int _start,_end;

public:
    Deque(){
        _start = _end = maxn;
    }

    inline void push_front(T value){
        if(_start > 0) arr[_start--] = value;
        else puts("MLE _start");
    }
    inline void pop_front(){
        if(!size()) return;
        _start++;
    }
    inline void push_back(T value){
        if(_end <= 2*maxn) arr[++_end] = value;
        else puts("MLE _end");
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

string randString(){
    int ln = rand()%5+1;
    string str;
    for(int i = 0;i<ln;i++) str.push_back(rand()%6 + 'a');
    return str;
}
int main()
{
    #ifdef PARTHO
        freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
        freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
        int start_time = clock();
    #endif

    srand(time(NULL));
    Deque<int,10000000> dq;

    for(int i = 0; i < 20000000; i++){
        int cmd = rand()%6;
        if(cmd <= 1){
            dq.push_back(rand());
        }
        else if(cmd <= 2){
            dq.pop_back();
        }
        else if(cmd <= 4){
            dq.push_front(rand());
        }
        else if(cmd <= 5){
            dq.pop_front();
        }
        // cout << "CMD = " << cmd << endl;
        //for(int j = 0; j < dq.size(); j++) cout << dq[j] << " "; cout << endl;
    }
    puts("done");
    return 0;
}
