#include <iostream>
using namespace std;
void triplet(int *a, int len, int *a1, int *a2, int *a3) {
    if(len<3) {
        cout<<"The array has less than 3 elements."<<endl;
        *a1 = 0;
        *a2 = 0;
        *a3 = 0;
        return;
    }
    int biggest = a[0]*a[1]*a[2];

    for(int i=0;i<len;i++)
        for(int j=0;j<len;j++)
            for(int k=0;k<len;k++) {
                if(a[i]*a[j]*a[k]>biggest&&i!=j&&i!=k&&j!=k) {
                    biggest = a[i]*a[j]*a[k];
                    *a1 = a[i];
                    *a2 = a[j];
                    *a3 = a[k];
                }
            }

}
int main() {
//    int n[]= {1,-5,3,15,-25,90};
//    int *p = n;
    int* arr = (int*) malloc(6*sizeof(int));
    for(int i=0;i<6;i++) {
        scanf("%d", arr+i);
    }
    int len = 6;
    int a,b,c;
    triplet(arr,len,&a,&b,&c);
    cout<<"The maximum triplet is ("<<a<<", "<<b<<", "<<c<<") with a product of "<<a*b*c<<endl;

    return 0;
}
