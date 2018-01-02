
#include <iostream>
#include <iomanip>

#include <Python.h>

using namespace std;

int main (int argc, char* argv[])
{
    int a;

    Py_Initialize();    // 初始化

    PyRun_SimpleString("print('hello python3!!!')");

    PyRun_SimpleString("a = 10");
    PyRun_SimpleString("print('a = ', a)");

    Py_Finalize();      // 释放资源

}
