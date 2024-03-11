#include "array.h"
bool equal(const Array<char>& left, const Array<char>& right){
    if (left.size()==right.size()){
        char s1=0;
        char s2=0;
        for(size_t i=0; i<right.size(); ++i){
            s1=left[i];
            if (s1>='A'&& s1<='Z'){
                s1=char(int(s1)+32);
            }
            s2=right[i];
            if (s2>='A'&& s2<='Z'){
                s2=char(int(s2)+32);
            }
            if (s1!=s2){
                return false;
            }
        }
        return true;
    }
    return false;
}