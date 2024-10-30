#include <ostream>
#include <iostream>
using namespace std;
class Array
{
public:
    Array(unsigned int capacity = 10):m_data{new
                                                     int[capacity]},m_length{0},m_capacity{capacity}{}
    unsigned int lenght() const {return m_length;}
    unsigned int capacity() const {return m_capacity;}
    bool append(int elem){
        if(m_length < m_capacity){
            m_data[m_length++] = elem;
            return true;
        }
        return false;
    }
    int& at(unsigned int i){
        return m_data[i];
    }
    friend ostream& operator<<(ostream& os, const Array& a){
        for(unsigned int i {0}; i < a.m_length; i++)
            os<<a.m_data[i]<<" ";
        os<<endl;
        return os;
    }

    ~Array(){
        if(m_data){
            delete[] m_data;
            m_data = nullptr;
        }
    }


    Array(const Array& other){
        m_capacity = other.m_capacity;
        m_length = other.m_length;
        m_data = new int[m_capacity]();
        for(int i{0}; i < m_length; i++)
            m_data[i] = other.m_data[i];
    }

    Array& operator=(const Array& other){
        if(this != &other){
            if(m_data)
                delete[] m_data;
            m_capacity = other.m_capacity;
            m_length = other.m_length;
            m_data = new int[m_capacity]();
            for(int i{0}; i < m_length; i++)
                m_data[i] = other.m_data[i];
        }
        return *this;
    }
private:
    int* m_data;
    unsigned int m_length;
    unsigned int m_capacity;
};
