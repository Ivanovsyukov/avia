#ifndef MY_UTILS_FOR_HEXVIEW_16122023_Parteyeye_
#define MY_UTILS_FOR_HEXVIEW_16122023_Parteyeye_

template <typename T>
T* push_element(T const* str, size_t* len_str, T sym){
    T* tmp=new T [*len_str+1];
    for(size_t i=0; i<*len_str; ++i){
        tmp[i]=str[i];
    }
    delete[] str;
    tmp[*len_str]=sym;
    (*len_str)++;
    return tmp;
}

bool srav_str(const char* one,  const char* two);//сравнение строк

int str_num_to_int_num(const char* number);//перевод строки в число
#endif