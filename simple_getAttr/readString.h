#include <fstream>
#include <string>

using namespace std;

string readString_fromPy(string fileName)
{
    string pyString;
    ifstream istr(fileName.c_str());
    if (istr.is_open())
    {
        string oneLine;
        while (getline(istr, oneLine))
        {
            pyString += oneLine + "\n";
        }
    }
    else
    {
        cout<<"File " << fileName << " does not exists"<<endl;
    }
    pyString +="\n";

    return pyString;
}
