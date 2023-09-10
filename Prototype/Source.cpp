#include <iostream>
using namespace std;

class SingleCellOrganism;
class Cell;

class Clones
{
public:
    virtual Clones* clone() = 0;
    virtual void print() = 0;
};

class SingleCellOrganism : public Clones 
{
public:
    SingleCellOrganism* clone() override
    {
        return new SingleCellOrganism(*this);
    }
    void print() override
    {
        cout << "SingleCellOrganism" << endl;
    }
    SingleCellOrganism split() 
    {
        return SingleCellOrganism();
    }
};

class Cell : public SingleCellOrganism 
{
public:
    Cell* clone() override 
    {
        return new Cell(*this);
    }
    void print() override 
    {
        cout << "Cell" << endl;
    }
    Cell split()
    {
        return Cell();
    }
};

int main()
{
    Clones* obj1 = new SingleCellOrganism();
    Clones* obj2 = new Cell();

    Clones* clone1 = obj1->clone();
    Clones* clone2 = obj2->clone();

    obj1->print();
    clone1->print();
    obj2->print();
    clone2->print();

    delete obj1;
    delete obj2;
    delete clone1;
    delete clone2;

	system("pause");

	return 0;
}