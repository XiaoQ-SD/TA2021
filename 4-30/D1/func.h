#include "exp6.h"


int mcomd(const int a,const int b)
{
    int tmpb,tmps,car;
    a > b ? (tmpb=a,tmps=b) : (tmpb=b,tmps=a);
    if (tmpb < 0)
        tmpb = -tmpb;
    if (tmps < 0)
        tmps = -tmps;
    for (;tmps!=tmpb;)
    {
        car = tmpb - tmps;
        car > tmps ? (tmpb = car): (tmpb = tmps, tmps = car);
    }
    return tmps;
}