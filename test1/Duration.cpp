//
// Created by User on 27.03.2024.
//
#include "duration.h"
#include <iostream>

Duration::Duration() : amount(0), unit('s') {

}

Duration::Duration(int amount, char unit) {
    if (!(unit=='s'||unit=='m'||unit=='h')) {
        printf("Unit is not valid");
    } else {
        this->amount = amount;
        this->unit = unit;
    }
}

int Duration::compare(Duration other) {
    int sec1 = this->getSeconds();
    int sec2 = other.getSeconds();
    if(sec1<sec2)
        return sec2-sec1;
    if(sec1==sec2)
        return 0;
    if(sec1>sec2)
        return sec1-sec2;
}

int Duration::getSeconds() {
    int sec = 0;
    if(this->unit=='h')
        sec = this->amount*3600;
    if(this->unit=='m')
        sec = this->amount*60;
    if(this->unit=='s')
        sec = this->amount;
    return sec;

}

int Duration::get(char unit) {
    if (!(unit=='s'||unit=='m'||unit=='h')) {
        printf("Unit is not valid");
    } else {
        if(unit=='s') return this->getSeconds();
        if(unit=='m') return this->getSeconds()/60;
        if(unit=='h') return this->getSeconds()/3600;
    }
}

void Duration::plus(Duration other) {
    if(this->unit=='s')
        this->amount+=other.get('s');
    if(this->unit=='m')
        this->amount+=other.get('m');
    if(this->unit=='h')
        this->amount+=other.get('h');
}

void Duration::print() {
    int h = this->getSeconds()/3600;
    int m = (this->getSeconds()%3600)/60;
    int s = (this->getSeconds()%60);
    std::cout<<"PT";
    if(h!=0)
        std::cout<<h<<"H";
    if(m!=0)
        std::cout<<m<<"M";
    if(s!=0)
        std::cout<<s<<"S";
    std::cout<<std::endl;
}