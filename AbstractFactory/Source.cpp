#include <iostream>
using namespace std;

class StampingEquipment
{
public:
    virtual void stampWheel() = 0;
    virtual void stampHood() = 0;
    virtual void stampDoor() = 0;
    virtual ~StampingEquipment() {}
};

class Model1StampingEquipment : public StampingEquipment
{
public:
    void stampWheel() override {
        cout << "Stamping a wheel for Model 1" << endl;
    }
    void stampHood() override {
        cout << "Stamping a hood for Model 1" << endl;
    }
    void stampDoor() override {
        cout << "Stamping a door for Model 1" << endl;
    }
};

class Model2StampingEquipment : public StampingEquipment
{
public:
    void stampWheel() override {
        cout << "Stamping a wheel for Model 2" << endl;
    }
    void stampHood() override {
        cout << "Stamping a hood for Model 2" << endl;
    }
    void stampDoor() override {
        cout << "Stamping a door for Model 2" << endl;
    }
};

class Model3StampingEquipment : public StampingEquipment
{
public:
    void stampWheel() override {
        cout << "Stamping a wheel for Model 3" << endl;
    }
    void stampHood() override {
        cout << "Stamping a hood for Model 3" << endl;
    }
    void stampDoor() override {
        cout << "Stamping a door for Model 3" << endl;
    }
};

void assembleCar(StampingEquipment* factory)
{
    factory->stampWheel();
    factory->stampHood();
    factory->stampDoor();
}

int main()
{
    StampingEquipment* model1Factory = new Model1StampingEquipment();
    StampingEquipment* model2Factory = new Model2StampingEquipment();
    StampingEquipment* model3Factory = new Model3StampingEquipment();

    assembleCar(model1Factory);
    assembleCar(model2Factory);
    assembleCar(model3Factory);

    delete model1Factory;
    delete model2Factory;
    delete model3Factory;

	system("pause");
	
	return 0;
}