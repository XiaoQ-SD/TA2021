#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int mcomd(const int, const int);

class Rational {

    int m_num = 0;
    int m_don = 1;
public:
    static int objCount;

    Rational()
            : m_num(0) {
        printf("对象已创建\n");
        printf("现存类个数：%d\n", ++objCount);
    }

    Rational(Rational &a)
            : m_num(0) {
        m_num = a.num();
        m_don = a.don();
        printf("对象已创建\n");
        printf("现存类个数：%d\n", ++objCount);
    }

    Rational(int num)
            : m_num(num) {
        printf("对象已创建\n");
        printf("现存类个数：%d\n", ++objCount);
    }

    Rational(const char *str)
            : m_num(0) {
        char *tmp = (char *) malloc(sizeof(char) * strlen(str) + 1);
        for (int i = 0; i <= strlen(str); i++)
            tmp[i] = str[i];
        tmp[strlen(str)] = '\0';
        char *p = tmp;
        for (int i = 0; p[0] != '/'; i++) {
            p = tmp + i;
        }
        int lennum = p - tmp;
        int lendon = strlen(str) - lennum - 1;
        char *num = (char *) malloc(sizeof(char) * lennum + 1);
        if (num) {
            num = strncpy(num, str, lennum);
            num[lennum] = '\0';
            m_num = atoi(num);
        }
        char *don = (char *) malloc(sizeof(char) * lendon + 1);
        if (don) {
            don = strcpy(don, p + 1);
            don[lendon] = '\0';
            m_don = atoi(don);
            if (m_don == 0)
                printf("输入有误，分母不能为0,请重新对本对象用四则运算进行操作\n");
        }
        free(num);
        free(don);
        printf("对象已创建\n");
        printf("现存类个数：%d\n", ++objCount);
    }

    ~Rational() {
        printf("现存类个数：%d\n", --objCount);
    }

    void show() {
        if (m_don == 1.0) {
            printf("%d\n", m_num);
        } else {
            printf("%d/%d\n", m_num, m_don);
        }
    }

    int num() {
        return m_num;
    }

    int don() {
        return m_don;
    }

    void sumof(Rational &a, Rational &b) {
        int md = mcomd(a.don(), b.don());
        m_don = a.don() * b.don() / md;
        m_num = a.num() * m_don / a.don() + b.num() * m_don / b.don();
        md = mcomd(m_num, m_don);
        m_num = m_num / md;
        m_don = m_don / md;
    }

    void difof(Rational &a, Rational &b) {
        int md = mcomd(a.don(), b.don());
        m_don = a.don() * b.don() / md;
        m_num = a.num() * m_don / a.don() - b.num() * m_don / b.don();
        md = mcomd(m_num, m_don);
        m_num = m_num / md;
        m_don = m_don / md;
    }

    void prodof(Rational &a, Rational &b) {
        int md = mcomd(a.don(), b.don());
        m_don = a.don() * b.don();
        m_num = a.num() * b.num();
        md = mcomd(m_num, m_don);
        m_num = m_num / md;
        m_don = m_don / md;
    }

    void quotof(Rational &a, Rational &b) {
        int md = mcomd(a.don(), b.num());
        m_don = a.don() * b.num();
        m_num = a.num() * b.don();
        md = mcomd(m_num, m_don);
        m_num = m_num / md;
        m_don = m_don / md;
    }
};

int Rational::objCount = 0;

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