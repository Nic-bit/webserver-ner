#include<iostream>
#include<fstream>
#include <unistd.h>  // write
#include "buffer.h"
using namespace std;
int main(){
    ifstream in("mypoem.txt");
    if(!in.is_open()){
        cout << "打开文件错误！" << endl;
        return -1;
    }
    string s;
    in >> s;
    cout << s << endl;
    Buffer mybuffer;
    mybuffer.Append(s.data(), size_t(s.size()));
    const string p = "你是一个小天使！";
    mybuffer.Append(p);
    mybuffer.content();
    return 0;
}