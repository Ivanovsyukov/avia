#ifndef __ARRAY_20240308__
#define __ARRAY_20240308__
#include <cstring>
#include <utility>
#include <fstream>
#include <iostream>
#include <cmath>
template <typename T>
class Array{
    T* data_;
    size_t size_;
public:
    Array(size_t N=0):size_(N), data_(new T[N]){}
    ~Array(){
        delete[] data_;
    }
    Array(const Array& other);
    Array& operator=(const Array& other);
    void push_back(const T& X);
    size_t size() const{return size_;}
    int str_to_int() const;
    double str_to_double() const;
    const T& operator[](size_t index) const{
        if(index>size_){
            throw "Out of limits";
        }
        return data_[index];
    }
};

template <typename T>
Array<T>::Array(const Array<T>& other){
	size_ = other.size_;
	data_ = new T[size_];
	for(int i=0; i<size_; ++i){
		data_[i] = other.data_[i];
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other){
	if (this != &other){
		delete[] data_;
		size_ = other.size_;
		data_ = new T[size_];
		for(int i=0; i<size_; ++i){
			data_[i] = other.data_[i];
		}
	}
	return *this;
}

template <typename T>
void Array<T>::push_back(const T& X){
	T* tmp = new T[size_+1];
	for(size_t i=0; i<size_; ++i){
			tmp[i] = std::move(data_[i]);
	}
	delete[] data_;
	data_= tmp; 
	data_[size_] = X;
	++size_;
}

template <typename T>
int Array<T>::str_to_int() const{
    int result=0;
    char s=0;
    for(size_t i=0; i<size_; ++i){
        s=str[i];
        result=result*10+(int)(s-'0');
    }
    return result;
}

template <typename T>
double Array<T>::str_to_double() const{
    double result=0.0;
    size_t i=0;
    char s=str[i];
    while(s!='.' && i<size_){
        result=result*10+(int)(s-'0');
        ++i;
        s=str[i];
    }
    ++i;
    for(size_t j=i; j<size_; ++j){
        s=str[j];
        result=result+(int)(s-'0')*pow(0.1, j-i+1);
    }
    return result;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const Array<T>& X){
    for(size_t i=0; i<X.size(); ++i){
        out<<X[i];
    }
    return out;
}
#endif