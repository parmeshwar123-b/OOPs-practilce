/* Imagine a publishing company which does marketing for book and audiocassette versions. Create a class
publication that stores the title (a string) and price (type float) of a publication. From this class derive two
classes: book, which adds a page count (type int), and tape, which adds a playing time in minutes (type
float).
Write a program that instantiates the book and tape classes, allows user to enter data and displays the
data members. If an exception is caught, replace all the data member values with zero values. */

#include <iostream>
#include <string>
using namespace std;

class Publication
{
protected:
    string title;
    float price;

public:
    Publication()
    {
        title = "";
        price = 0.0f;
    }

    virtual void getData()
    {
        cout << "Enter title: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter price: ";
        cin >> price;
    }

    virtual void putData() const
    {
        cout << "Title: " << title << "\nPrice: " << price << endl;
    }

    virtual ~Publication() {}
};

class Book : public Publication
{
private:
    int pageCount;

public:
    Book() : pageCount(0) {}

    void getData() override
    {
        try
        {
            Publication::getData();
            cout << "Enter page count: ";
            cin >> pageCount;
            if (pageCount < 0)
            {
                throw invalid_argument("Page count cannot be negative.");
            }
        }
        catch (const exception &e)
        {
            cerr << "Error: " << e.what() << endl;
            title = "";
            price = 0.0f;
            pageCount = 0;
        }
    }

    void putData() const override
    {
        Publication::putData();
        cout << "Page Count: " << pageCount << endl;
    }
};

class Tape : public Publication
{
private:
    float playingTime;

public:
    Tape()  {
        playingTime = 0.0f;
    }

    void getData() override
    {
        try
        {
            Publication::getData();
            cout << "Enter playing time (in minutes): ";
            cin >> playingTime;
            if (playingTime < 0)
            {
                throw invalid_argument("Playing time cannot be negative.");
            }
        }
        catch (const exception &e)
        {
            cerr << "Error: " << e.what() << endl;
            title = "";
            price = 0.0f;
            playingTime = 0.0f;
        }
    }

    void putData() const override
    {
        Publication::putData();
        cout << "Playing Time: " << playingTime << " minutes" << endl;
    }
};

int main()
{
    Book book;
    Tape tape;

    cout << "Enter data for book:\n";
    book.getData();

    cout << "\nEnter data for tape:\n";
    tape.getData();

    cout << "\nBook details:\n";
    book.putData();

    cout << "\nTape details:\n";
    tape.putData();

    return 0;
}
