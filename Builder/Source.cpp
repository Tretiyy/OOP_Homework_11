#include <iostream>
#include <string>
using namespace std;

class ChildrensMeal
{
public:
    void setMainItem(const string& item)
    {
        mainItem_ = item;
    }
    void setSurplusItem(const string& item) 
    {
        surplusItem_ = item;
    }
    void setToy(const string& toy) 
    {
        toy_ = toy;
    }
    void setBeverage(const string& beverage)
    {
        beverage_ = beverage;
    }
    void display() 
    {
        cout << "Kid's Meal: " << mainItem_ << ", " << surplusItem_ << ", " << beverage_ << ", " << toy_ << endl;
    }
private:
    string mainItem_;
    string surplusItem_;
    string beverage_;
    string toy_;
};

class MealBuilder 
{
public:
    virtual void buildMainItem() = 0;
    virtual void buildSurplusItem() = 0;
    virtual void buildBeverage() = 0;
    virtual void buildToy() = 0;
    virtual ChildrensMeal getResult() = 0;
};

class HamburgerMealBuilder : public MealBuilder
{
public:
    void buildMainItem() override
    {
        meal_.setMainItem("Hamburger");
    }
    void buildSurplusItem() override 
    {
        meal_.setSurplusItem("Fries");
    }
    void buildBeverage() override
    {
        meal_.setBeverage("Coca-Cola");
    }
    void buildToy() override 
    {
        meal_.setToy("Toy Dinosaur");
    }
    ChildrensMeal getResult() override 
    {
        return meal_;
    }
private:
    ChildrensMeal meal_;
};

class Cashier
{
public:
    ChildrensMeal orderKidMeal(MealBuilder& builder)
    {
        builder.buildMainItem();
        builder.buildSurplusItem();
        builder.buildBeverage();
        builder.buildToy();
        return builder.getResult();
    }
};

int main()
{
    Cashier cashier;
    HamburgerMealBuilder hamburgerBuilder;

    ChildrensMeal childMeal = cashier.orderKidMeal(hamburgerBuilder);
    childMeal.display();

	system("pause");

	return 0;
}