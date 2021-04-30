#include "exp6.h"


int main()
{
    Rational a("1/2");
    Rational b("3/4");
    Rational c(2);
    Rational d;
    printf("a为");
    a.show();
    printf("b为");
    b.show();
    printf("c为");
    c.show();
    printf("d为");
    d.show();
    d.sumof(a, b);
    printf("d更改为ab的和，为");
    d.show();
    d.difof(a, b);
    printf("d更改为a-b,为");
    d.show();
    d.prodof(a, b);
    printf("d更改为a*b,为");
    d.show();
    d.quotof(a, b);
    printf("d更改为a/b,为");
    d.show();
    Rational e(c);
    printf("e为c的复制,为");
    e.show();
    return 0;
}