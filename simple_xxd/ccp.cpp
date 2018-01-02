
#include <iostream>
#include <iomanip>
#include <string>
#include <Python.h>

#include "input.pyh"

using namespace std;

int main (int argc, char* argv[])
{
    int a;

    Py_Initialize();    // 初始化

    string pyString(reinterpret_cast<const char*>(Python_input_py), Python_input_py_len);
    PyRun_SimpleString(pyString.c_str());

    Py_Finalize();      // 释放资源

}
