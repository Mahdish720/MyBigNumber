#include "MyBigNumber.h"


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



