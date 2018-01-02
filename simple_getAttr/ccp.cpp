
#include <iostream>
#include <iomanip>
#include <string>
#include <Python.h>

#include "readString.h"

using namespace std;

int main (int argc, char* argv[])
{
    int a;
    double b;
    string c;
    PyObject *py_namelist, *py_attr;

    Py_Initialize();    // 初始化

    py_namelist = PyImport_AddModule("__main__");

    string pyFileName = "input.py";
    string pyString = readString_fromPy(pyFileName);
    PyRun_SimpleString(pyString.c_str());

    py_attr = PyObject_GetAttrString(py_namelist, "a");
    if (py_attr && PyLong_Check(py_attr))
    {
        a = (int) PyLong_AsLong(py_attr);
    }
    cout<<"a = "<<a<<endl;



    py_attr = PyObject_GetAttrString(py_namelist, "b");
    if (py_attr && PyFloat_Check(py_attr))
    {
        b = PyFloat_AsDouble(py_attr);
    }
    cout<<"b = "<<b<<endl;


    py_attr = PyObject_GetAttrString(py_namelist, "c");
    if (py_attr && PyUnicode_Check(py_attr))
    {
        c = string(PyUnicode_AsUTF8(py_attr));
    }
    cout<<"c = "<<c<<endl;

    Py_Finalize();      // 释放资源

}
