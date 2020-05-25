#include "MyBigNumber.h"
#include "iostream"

using namespace std;


MyBigNumber::MyBigNumber(){}

MyBigNumber::MyBigNumber(const std::string &str) : BigNumber(str) {}

MyBigNumber::MyBigNumber(const char *myCharArray) : BigNumber(myCharArray) {}

MyBigNumber::MyBigNumber(const long &intNum) : BigNumber(intNum) {}

MyBigNumber &MyBigNumber::operator=(const MyBigNumber & myBigNumber) {
    if(&myBigNumber != this){
      sign = myBigNumber.sign;
      numOfDigits = myBigNumber.numOfDigits;
      delete [] numArray ;
      numArray = new int8_t (myBigNumber.numOfDigits);
      for(size_t i= 0; i<numOfDigits;i++)
          numArray[i]=myBigNumber[i];
    }
    return *this;
}

MyBigNumber MyBigNumber::multByOneDigit(int a) {
    if(numOfDigits==1 && (*this)[0]==0 || a==0) {
        MyBigNumber temp;
        temp.sign = true;
        temp.numOfDigits=1;
        temp.numArray=new int8_t{0};
        return temp;
    }
    else {
        MyBigNumber mul;
        int8_t carry = 0, s;
        mul.numOfDigits = numOfDigits + 1;
        if((a>0 && sign==true) || (a<0 && sign ==false) )
            mul.sign =true;
        else if( (a>0 && sign ==false) || (a<0 && sign ==true) )
            mul.sign = false;
        if(a<0)
            a=a*(-1);
        mul.numArray = new int8_t(mul.numOfDigits);
        size_t i = 0;
        for (; i < numOfDigits; ++i) {
            s = a * (*this)[i] + carry;
            mul[i] = s % 10;
            carry = s / 10;
        }
        if (carry != 0)
            mul[i] = carry;
        else
            --(mul.numOfDigits);
        return mul;
    }
}

MyBigNumber MyBigNumber::operator<<(unsigned int shift) {
    if(numOfDigits==1 && (*this)[0]==0)
        return *this;
    else {
        MyBigNumber temp;

        temp.sign = sign;
        temp.numOfDigits = numOfDigits + shift;
        temp.numArray = new int8_t(temp.numOfDigits);
        size_t i = 0;
        for (; i < shift; ++i) {
            temp[i] = 0;
        }
        for (; i < temp.numOfDigits; ++i) {
            temp[i] = (*this)[i - shift];
        }
        return temp;
    }
}

MyBigNumber operator*(const MyBigNumber &mybig1, const MyBigNumber &mybig2) {
    MyBigNumber temp="0",tempmin,tempmax;
    tempmin=MyBigNumber::MyunsignedMin(mybig1,mybig2);
    tempmax=MyBigNumber::MyunsignedMax(mybig1,mybig2);
    size_t i=0;
    for(;i<tempmin.numOfDigits;++i){
        temp = temp+(tempmax<<i).multByOneDigit(tempmin[i]);
    }
    if((mybig1.sign==true && mybig2.sign==true) || (mybig1.sign==false && mybig2.sign==false) )
        temp.sign =true;
    else if((mybig1.sign==true && mybig2.sign==false) || (mybig1.sign==false && mybig2.sign==true) )
        temp.sign = false;
    return temp;
}

MyBigNumber MyBigNumber::MyunsignedMin(const MyBigNumber &num1, const MyBigNumber &num2) {
    if( num1.numOfDigits > num2.numOfDigits){
        return num2;
    }

    if( num1.numOfDigits < num2.numOfDigits){
        return num1;
    }

    size_t index = num1.numOfDigits - 1;
    while( (num1[index] == num2[index]) && (index > 0) ){
        --index;
    }
    if( num1[index] >= num2[index]){
        return num2;
    }
    if( num1[index] < num2[index]){
        return num1;
    }
}

MyBigNumber MyBigNumber::MyunsignedMax(const MyBigNumber &num1, const MyBigNumber &num2) {
    if( num1.numOfDigits > num2.numOfDigits){
        return num1;
    }

    if( num1.numOfDigits < num2.numOfDigits){
        return num2;
    }

    size_t index = num1.numOfDigits - 1;
    while( (num1[index] == num2[index]) && (index > 0) ){
        --index;
    }
    if( num1[index] >= num2[index]){
        return num1;
    }
    if( num1[index] < num2[index]){
        return num2;
    }
}

MyBigNumber operator+( const MyBigNumber & num1, const MyBigNumber & num2){
    MyBigNumber sum;
    if(num1.sign == num2.sign){   // -5 + 5
        sum = MyBigNumber:: unsignedAdd(num1, num2);
        sum.sign = num1.sign;
    }
    else{
        sum = MyBigNumber::unsignedSubtract(num1, num2);
        sum.sign = MyBigNumber::unsignedMax(num1, num2).getSign();
    }
    if( sum.numOfDigits == 1 && sum[0] == 0 ){
        sum.sign = true;
    }
    return sum;
}

MyBigNumber MyBigNumber::unsignedAdd(const MyBigNumber &num1, const MyBigNumber &num2) {
    MyBigNumber bMax = MyunsignedMax(num1, num2);
    MyBigNumber bMin = MyunsignedMin(num1, num2);

    MyBigNumber sum;

    sum.sign = true;
    sum.numOfDigits = bMax.numOfDigits + 1;
    sum.numArray = new int8_t[sum.numOfDigits];
    size_t i{0};
    int8_t carry = 0;
    int8_t s;

    for (; i < bMin.numOfDigits; ++i) {
        s = bMax[i] + bMin[i] + carry;
        sum[i] = s % 10;
        carry = s / 10;
    }

    for (; i < bMax.numOfDigits; ++i) {
        s = bMax[i] + carry;
        sum[i] = s % 10;
        carry = s / 10;
    }

    if (carry == 1) {
        sum[i] = 1;
    }
    else if (carry == 0) {
        //sum[i] = 0;
        sum.numOfDigits -= 1;
    }

    return sum;
}

MyBigNumber MyBigNumber::unsignedSubtract(const MyBigNumber &num1, const MyBigNumber &num2) {
    MyBigNumber bMax = MyunsignedMax(num1, num2);
    MyBigNumber bMin = MyunsignedMin(num1, num2);
    int8_t * nArray = new int8_t[bMax.numOfDigits]{};
    size_t i{0};

    ;   for(; i < bMin.numOfDigits; ++i){
        if(bMax[i] >= bMin[i]){
            nArray[i] = bMax[i] - bMin[i];
        }
        else if( bMax[i] < bMin[i] && bMax[i+1] != 0 ){
            nArray[i] = 10 + bMax[i] - bMin[i];
            bMax[i+1] -= 1;
        }
        else if(bMax[i] < bMin[i] && bMax[i+1] == 0){
            size_t j = i;
            while( bMax[j+1] == 0 ){
                bMax[j+1] = 9;
                ++j;
            }
            bMax[j+1] -= 1;
            nArray[i] = 10 + bMax[i] - bMin[i];
        }
    }

    for(; i < bMax.numOfDigits; ++ i){
        nArray[i] = bMax[i];
    }

    int numOfZerosOnTheLeft = 0;
    size_t index{bMax.numOfDigits - 1};
    while( nArray[index] == 0 && index > 0){
        ++numOfZerosOnTheLeft;
        --index;
    }

    MyBigNumber sub;
    sub.sign = true;
    sub.numOfDigits = bMax.numOfDigits - numOfZerosOnTheLeft;
    sub.numArray = new int8_t[sub.numOfDigits];

    for( size_t i{0}; i < sub.numOfDigits; ++i ){
        sub[i] = nArray[i];
    }
    return sub;
}




