#ifndef TA14_MYBIGNUMBER_H
#define TA14_MYBIGNUMBER_H

#include "BigNumber.h"

class MyBigNumber : public BigNumber {
    friend MyBigNumber operator *(const MyBigNumber& mybig1,const MyBigNumber& mybig2);
    friend MyBigNumber operator+( const MyBigNumber & num1, const MyBigNumber & num2);

private:
    MyBigNumber();



public:
    //
    MyBigNumber multByOneDigit(int a);
    static MyBigNumber MyunsignedMin( const MyBigNumber& num1, const MyBigNumber& num2);
    static MyBigNumber MyunsignedMax( const MyBigNumber& num1, const MyBigNumber& num2);
    static MyBigNumber unsignedAdd( const MyBigNumber& num1, const MyBigNumber& num2 );
    static MyBigNumber unsignedSubtract( const MyBigNumber& num1, const MyBigNumber& num2 );
    //

    MyBigNumber( const std::string & str );
    MyBigNumber( const char * myCharArray );
    MyBigNumber(const long & intNum );


    MyBigNumber & operator=(const MyBigNumber & myBigNumber);
    MyBigNumber operator<<( unsigned shift );


};


#endif //TA14_MYBIGNUMBER_H
