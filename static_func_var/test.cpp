#include <iostream>
#include <string>

using namespace std;

class test
{
public:
        test(const char *name)
                : _name(name)
        {
                cout << _name << " created" << endl;
        }

        ~test()
        {
                cout << _name << " destroyed" << endl;
        }

        string _name;
};

test t("global variable");

void f()
{
        static test t("static variable");

        test t2("Local variable");

        cout << "Function executed" << endl;
}


int main()
{
        test t("local to main");

        cout << "Program start" << endl;

        f();

        f();

        cout << "Program end" << endl;
        return 0;
}
