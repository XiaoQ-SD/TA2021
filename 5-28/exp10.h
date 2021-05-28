#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>

using namespace std;

class C {
public:
    int m_int = 3;

    void func(void) {
        cout << "呱！" << endl;
    }
};

typedef int (C::* mpi);

typedef void (C::* fpv)(void);
