#include <iostream>
using namespace std;

const char * my_strchr( const char * str, char character ){
    char f;
    int i = 1;
    f = *str;
    while(f!=NULL){
        if(f==character)
            return &f;
        f = *(str+i);
        i++;
    }
}

int main(){

}