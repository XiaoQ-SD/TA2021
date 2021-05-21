#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

//写一个n维数组，不限类型，实现1，初始化2，展示数组内容3，赋值4，下标[]5，改变容量
template<class T>
class MyArray {
    T *p;
    int m_cap;//Capacity，总容量
    int m_size;//目前占用容量
    bool pr = 0;//初始化标，防止被二次初始化
public:
    MyArray(int cap)
            : m_cap(cap), m_size(0) {
        p = new T[m_cap];
    }

    MyArray(MyArray &a)
            : m_cap(a.m_cap), m_size(a.m_size) {
        p = new T[m_cap];
        for (int i = 0; i < m_size; i++)
            p[i] = a.p[i];
    }

    ~MyArray() {
        delete[] p;
    }

    //展示数组
    //全部初始化，将数组全部设置为一个初值，并使容量占用满
    void allset(T a, int num) {
        if (pr) {
            cout << "该数组已经初始化过了" << endl;
            return;
        }
        for (int i = 0; i < m_cap; i++)
            p[i] = num;
        m_size = m_cap;
        pr = !pr;
    }

    //逐一初始化,手动输入num个初值
    void set1by1(T a, int num) {
        if (pr) {
            cout << "该数组已经初始化过了" << endl;
            return;
        }
        for (int i = 0; i < num; i++)
            cin >> p[i];
        m_size = num;
        pr = !pr;
    }

    //容量扩容为num
    void realloc(int cap) {
        MyArray tmp = *this;
        delete[] p;
        T *p = new T[cap];
        for (int i = 0; i < m_size; i++)
            p[i] = tmp.p[i];
    }

    //将给的数组a的前num个数写进数组的末尾
    void arrcat(const T &a, int num) {
        //检测容量是否足够，不够则实现扩容
        if (num > (m_cap - m_size)) {
            realloc(m_size + num);
            for (int i = 0; i < num; i++)
                p[m_size + i] = a[i];
        }
            //容量足够
        else {
            for (int i = 0; i < num; i++)
                p[m_size + i] = a[i];
        }
    }

    T &operator[](int i) {
        return p[i];
    }

    int getcap() {
        return m_cap;
    }

    int getsize() {
        return m_size;
    }
};

template<class T>
ostream &operator<<(ostream &os, const MyArray<T> &a) {
    /*cout << "数组容量为：" << a.m_cap << "现占用：" << a.m_size << endl << "内容为：" << endl;
    for (int i = 0; i < a.m_size; i++)
        cout << a.p[i] << ' ';*/
    return os;
}
