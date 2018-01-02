
#include <iostream>
#include <iomanip>
#include <string>
#include <Python.h>

#include "readString.h"

using namespace std;

int main (int argc, char* argv[])
{
    int a;

    Py_Initialize();    // 初始化

    string pyFileName = "input.py";
    string pyString = readString_fromPy(pyFileName);
    PyRun_SimpleString(pyString.c_str());

    Py_Finalize();      // 释放资源

}
