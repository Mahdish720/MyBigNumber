#include <iostream>
#include <cstdint>

#include "BigNumber.h"
#include "MyBigNumber.h"

using namespace std;

int main() {
    cout << boolalpha;

//    for(unsigned char i{0}; i <= 127; ++i){
//        std::cout << (int) i << '\t' << i << std::endl;
//    }
    //std::cout << x << std::endl;
//    BigNumber x{-37};
//    string str = "-0000";
//    BigNumber y{str};
//    cout << y << endl;
//    cout << "Enter a number: ";
//    cin >> x;
//    x = -y;
//    BigNumber z = -y;
//    cout << (x != y) << endl;
    MyBigNumber mybig1 = "5", mybig2 = -17;
    cout<<MyBigNumber::power(mybig1,2)<<endl;
    cout<<mybig1*mybig2<<endl;
    BigNumber myBig1 = 344;
    cout<<mybig1.multByOneDigit(4)<<endl;
    cout<<(mybig1<<4);
    BigNumber myBig2 = "0000173";
    //cout << myBig1-myBig2<<endl;
   // cout<<--myBig1<<endl;
   // cout<<myBig1--;
    //cout<< (++myBig1)<<endl;
    //cout << BigNumber::unsignedLessOrEqual(myBig1, myBig2) << endl;
    //BigNumber a = BigNumber::unsignedSubtract(myBig1, myBig2);
    try{

    }
    catch( out_of_range e){
      cout << e.what() << endl;
    }
    return 0;
}
