#include <iostream.h>
class ClxBase
{
    public:
            ClxBase() {};
             ~ClxBase() { cout <<"delete the object in ClxBase"<< endl;};

             void DoSomething() { cout << "Do something in class ClxBase!" << endl; };
};

class ClxDerived : public ClxBase
{
    public:
            ClxDerived() {};
            ~ClxDerived() { cout << "Output from the destructor of class ClxDerived!" << endl; }; 

             void DoSomething() { cout << "Do something in class ClxDerived!" << endl; };
};
int main()
{
    ClxBase *pTest = new ClxDerived;
    pTest->DoSomething();
    delete pTest;
}
