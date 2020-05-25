#ifndef TA14_MYBIGNUMBER_H
#define TA14_MYBIGNUMBER_H

#include "BigNumber.h"

class MyBigNumber : public BigNumber {
private:
    MyBigNumber();


public:
    //
    MyBigNumber multByOneDigit(int a);
    //
    MyBigNumber( const std::string & str );
    MyBigNumber( const char * myCharArray );
    MyBigNumber(const long & intNum );
    MyBigNumber & operator=(const MyBigNumber & myBigNumber);
    MyBigNumber operator<<( unsigned shift );

};


#endif //TA14_MYBIGNUMBER_H
