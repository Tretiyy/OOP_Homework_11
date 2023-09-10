#include <iostream>
using namespace std;

class Government
{
public:
    static Government* getInstance()
    {
        if (instance == nullptr)
            instance = new Government();
        return instance;
    }

    void election()
    {
        cout << "A new President has been elected!" << endl;
    }
private:
    Government() {}
    static Government* instance;
};

Government* Government::instance = nullptr;

int main()
{
    Government* president = Government::getInstance();
    president->election();

	system("pause");

	return 0;
}