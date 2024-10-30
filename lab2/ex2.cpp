#include <iostream>
using namespace std;
int main(){
    int* arr = (int*) malloc(10*sizeof(int));
    for(int i=0;i<10;i++)
        cout<<arr[i]<<endl;
    return 0;
}
