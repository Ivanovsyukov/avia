#ifndef __ARRAY_20240308__
#define __ARRAY_20240308__
template <typename T>
class Array{
    T* data_;
    size_t size_;
public:
    Array(size_t N=0):size_(N), data_(new T[N]);
    ~Array(){
        delete[] data_;
    }
    Array(const Array& other);
    Array& operator=(const Array& other);
    void push_back(const T& X);
    const T& operator[](size_t index) const{
        if(index>size_t){
            throw "Out of limits";
        }
        return data_[index];
    }
    int str_to_int(const Array<int>& str);
    double str_to_double(const Array<double>& str);
};
#endif