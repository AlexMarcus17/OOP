#include <iostream>
using namespace std;
int main(){
    int num;
    cin>>num;
    int binarynum = 0;
    while(num!=0){
        if(num%2==1)
            binarynum+=1;
        num/=2;
    }
    cout<<binarynum;
}
