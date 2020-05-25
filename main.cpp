#include <iostream>
#include <cstdint>

#include "BigNumber.h"
#include "MyBigNumber.h"

using namespace std;
//dar ghesmat main faghat tavabeie ke khodam neveshtam check kardam.
//dar soalat manzoor az BigNumber ha ro farz kardam ke az class khodam yani MyBigNumber
//bashe...age manzoor in naboode ye kam tafavot dare ke dar had copy paste lotfan age mishe dar
// nomre dadan hahaz nakonid...
int main() {
    try {
        cout << boolalpha;
        BigNumber big1 = "0", big2 = -17;
        cout<<big2-big1<<endl;
        --big1;
        cout << big1 << endl;
        big1--;
        cout << big1 << endl;
        big1++;
        cout << big1 << endl;
        ++big1;
        cout << big1 << endl;
        MyBigNumber mybig1="17263947",mybig2=-138;
        cout << mybig2.multByOneDigit(2) << endl;
        cout << (mybig2 << 2) << endl;
        cout << mybig1 * mybig2 << endl;
        cout << mybig1(5, 2) << endl;
    }
    catch (invalid_argument e) {
    cout<<e.what();
    }
    return 0;
}
