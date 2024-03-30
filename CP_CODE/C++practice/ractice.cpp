#include<bits/stdc++.h>
using namespace std;

void f(vector<int>& vec, list<int>& lst)
{

    sort(vec.begin(),vec.end());
    unique_copy(vec.begin(),vec.end(),back_inserter(lst)); // append to res

}

bool has_c(vector<int>& v,int c)
{
    return find(v.begin(),v.end(),c) != v.end();
}

vector<string::iterator> occer(vector<string>& v,string c)
{
    vector<string::iterator> res;

    for(auto p = v.begin(); p != v.end(); ++p)
    {
        if(*p == c)
        {

            cerr<<"fornd" << endl;
        }
    }

    return res;
}

ostream_iterator<string> oo{cout};
int main()
{
     #ifdef PARTHO
       freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
       freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
       int start_time = clock();
    #endif
    string from, to;
    cin >> from >> to; // get source and target file names
    
    ifstream is {from}; // input stream for file "from"
    istream_iterator<string> ii {is}; // input iterator for stream
    istream_iterator<string> eos {}; // input sentinel
    
    ofstream os{to}; // output stream for file "to"
    ostream_iterator<string> oo {os,"\n"}; // output iterator for stream
    
    vector<string> b {ii,eos}; // b is a vector initialized from input [ii:eos)
    sort(b.begin(),b.end()); // sor t the buffer
    
    unique_copy(b.begin(),b.end(),oo); // copy buffer to output, discard replicated values
    
    

    return !is.eof() || !os;


}
