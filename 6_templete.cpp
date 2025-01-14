/* Create a class template to represent a generic vector. Include following member functions:
To create the vector.
To modify the value of a given element
To multiply by a scalar value
To display the vector in the form (10,20,30,...) */

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class GenericVector
{
private:
    vector<T> elements;

public:
    GenericVector(size_t size, T defaultValue = T())
    {
        elements.resize(size, defaultValue);
    }
    void modifyElement(size_t index, T value)
    {
        if (index < elements.size())
        {
            elements[index] = value;
        }
        else
        {
            cout << "Index out of bounds." << endl;
        }
    }
    void multiplyByScalar(T scalar)
    {
        for (size_t i = 0; i < elements.size(); ++i)
        {
            elements[i] *= scalar;
        }
    }
    void display() const
    {
        cout << "(";
        for (size_t i = 0; i < elements.size(); ++i)
        {
            cout << elements[i];
            if (i < elements.size() - 1)
            {
                cout << ",";
            }
        }
        cout << ")" << endl;
    }
};

int main()
{
    GenericVector<int> intVector(5, 0);
    intVector.modifyElement(0, 10);
    intVector.modifyElement(1, 20);
    intVector.modifyElement(2, 30);

    cout << "Original vector: ";
    intVector.display();

    intVector.multiplyByScalar(2);
    cout << "After multiplying by scalar 2: ";
    intVector.display();

    GenericVector<double> doubleVector(3, 1.1);

    doubleVector.modifyElement(0, 2.2);
    doubleVector.modifyElement(1, 3.3);

    cout << "Double vector: ";
    doubleVector.display();

    return 0;
}
