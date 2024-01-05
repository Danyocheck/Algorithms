#include <iostream>

int gcd(int a, int b){
    while (a > 0 && b > 0) {
        if (a > b) {
            a %= b;
        } else {
            b %= a;
        }
    }
    return a + b; 
}

int
main()
{
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    int numenator = a * d + b * c;
    int denominator = b * d;
    int nod = gcd(numenator, denominator);
    while (nod != 1) {
        numenator /= nod;
        denominator /= nod;
        nod = gcd(numenator, denominator);
    }

    std::cout << numenator << " " << denominator << std::endl;
    return 0;
}