#include "exp10.h"

int main() {
    //测试static_cast
    {
        float a = 3.14;
        int b = static_cast<int>(a);
        cout << a << ' ' << b << endl;
    }
    //测试const_cast
    {
        const int a = 0;
        const int *b = &a;
        int *c = const_cast<int *>(b);
        *c = 1;
        cout << a << ' ' << *b << ' ' << *c << endl;
    }
    //测试reinterpret_cast
    {
        float a = 3.14;
        int &b = reinterpret_cast<int &>(a);
        cout << a << ' ' << b << endl;
        b = 4;
        cout << "执行命令“b=4”" << '\n' << a << ' ' << b << endl;
    }
    {
        C a;
        int(C::* mp) = &C::m_int;
        fpv fp = &C::func;
        printf("%d\n", fp);
        cout << mp << ' ' << fp << endl;
    }
    return 0;
}
