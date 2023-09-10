#include <iostream>
using namespace std;

class InjectionMold
{
public:
    virtual void inject() = 0;
};

class ToyDuckMold : public InjectionMold
{
public:
    void inject() override
    {
        cout << "Injecting plastic to create a Toy Duck." << endl;
    }
};

class ToyCarMold : public InjectionMold
{
public:
    void inject() override
    {
        cout << "Injecting plastic to create a Toy Car." << endl;
    }
};

class MoldFactory
{
public:
    virtual InjectionMold* createMold() = 0;
};

class ToyDuckMoldFactory : public MoldFactory
{
public:
    InjectionMold* createMold() override
    {
        return new ToyDuckMold();
    }
};

class ToyCarMoldFactory : public MoldFactory
{
public:
    InjectionMold* createMold() override
    {
        return new ToyCarMold();
    }
};

int main()
{
    MoldFactory* toyDuckFactory = new ToyDuckMoldFactory();
    InjectionMold* toyDuckMold = toyDuckFactory->createMold();
    toyDuckMold->inject();

    MoldFactory* toyCarFactory = new ToyCarMoldFactory();
    InjectionMold* toyCarMold = toyCarFactory->createMold();
    toyCarMold->inject();

    delete toyDuckFactory;
    delete toyDuckMold;
    delete toyCarFactory;
    delete toyCarMold; 

	system("pause");

	return 0;
}