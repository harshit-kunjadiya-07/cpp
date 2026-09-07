#include <iostream>
using namespace std;

// Abstract Base Class
class LibraryItem
{
private:
    string title;
    string author;
    string dueDate;

protected:
    bool available;

public:
    LibraryItem(string t, string a)
    {
        title = t;
        author = a;
        dueDate = "Not Set";
        available = true;
    }

    string getTitle()
    {
        return title;
    }

    string getAuthor()
    {
        return author;
    }

    string getDueDate()
    {
        return dueDate;
    }

    void setDueDate(string date)
    {
        dueDate = date;
    }

    virtual void checkOut() = 0;

    virtual void returnItem() = 0;

    virtual void displayDetails() = 0;

    virtual ~LibraryItem()
    {
    }
};

// Book Class
class Book : public LibraryItem
{
public:
    Book(string title, string author)
        : LibraryItem(title, author)
    {
    }

    void checkOut() override
    {
        if (available == true)
        {
            available = false;
            cout << "Book checked out successfully.\n";
        }
        else
        {
            cout << "Book is already checked out.\n";
        }
    }

    void returnItem() override
    {
        if (available == false)
        {
            available = true;
            cout << "Book returned successfully.\n";
        }
        else
        {
            cout << "Book is already available.\n";
        }
    }

    void displayDetails() override
    {
        cout << "\n--- Book ---\n";
        cout << "Title    : " << getTitle() << endl;
        cout << "Author   : " << getAuthor() << endl;
        cout << "Due Date : " << getDueDate() << endl;

        if (available == true)
            cout << "Status   : Available\n";
        else
            cout << "Status   : Checked Out\n";
    }
};

// DVD Class
class DVD : public LibraryItem
{
public:
    DVD(string title, string author)
        : LibraryItem(title, author)
    {
    }

    void checkOut() override
    {
        if (available == true)
        {
            available = false;
            cout << "DVD checked out successfully.\n";
        }
        else
        {
            cout << "DVD is already checked out.\n";
        }
    }

    void returnItem() override
    {
        if (available == false)
        {
            available = true;
            cout << "DVD returned successfully.\n";
        }
        else
        {
            cout << "DVD is already available.\n";
        }
    }

    void displayDetails() override
    {
        cout << "\n--- DVD ---\n";
        cout << "Title    : " << getTitle() << endl;
        cout << "Author   : " << getAuthor() << endl;
        cout << "Due Date : " << getDueDate() << endl;

        if (available == true)
            cout << "Status   : Available\n";
        else
            cout << "Status   : Checked Out\n";
    }
};

// Magazine Class

class Magazine : public LibraryItem
{
public:
    Magazine(string title, string author)
        : LibraryItem(title, author)
    {
    }

    void checkOut() override
    {
        if (available == true)
        {
            available = false;
            cout << "Magazine checked out successfully.\n";
        }
        else
        {
            cout << "Magazine is already checked out.\n";
        }
    }

    void returnItem() override
    {
        if (available == false)
        {
            available = true;
            cout << "Magazine returned successfully.\n";
        }
        else
        {
            cout << "Magazine is already available.\n";
        }
    }

    void displayDetails() override
    {
        cout << "\n--- Magazine ---\n";
        cout << "Title    : " << getTitle() << endl;
        cout << "Author   : " << getAuthor() << endl;
        cout << "Due Date : " << getDueDate() << endl;

        if (available == true)
            cout << "Status   : Available\n";
        else
            cout << "Status   : Checked Out\n";
    }
};

// Main Function
int main()
{
    const int MAX_ITEMS = 10;

    LibraryItem *items[MAX_ITEMS];

    int itemCount = 0;
    int choice;

    cout << "====================================\n";
    cout << "     LIBRARY MANAGEMENT SYSTEM\n";
    cout << "====================================\n";

    do
    {
        cout << "\n----------- MENU -----------\n";
        cout << "1. Add Book\n";
        cout << "2. Add DVD\n";
        cout << "3. Add Magazine\n";
        cout << "4. Display All Items\n";
        cout << "5. Check Out Item\n";
        cout << "6. Return Item\n";
        cout << "7. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        try
        {
            if (choice == 1)
            {
                string title;
                string author;

                if (itemCount >= MAX_ITEMS)
                {
                    throw "Library is full!";
                }

                cout << "Enter Book Title: ";
                cin >> title;

                cout << "Enter Author Name: ";
                cin >> author;

                items[itemCount] = new Book(title, author);

                itemCount++;

                cout << "Book added successfully.\n";
            }

            else if (choice == 2)
            {
                string title;
                string author;

                if (itemCount >= MAX_ITEMS)
                {
                    throw "Library is full!";
                }

                cout << "Enter DVD Title: ";
                cin >> title;

                cout << "Enter Author Name: ";
                cin >> author;

                items[itemCount] = new DVD(title, author);

                itemCount++;

                cout << "DVD added successfully.\n";
            }

            else if (choice == 3)
            {
                string title;
                string author;

                if (itemCount >= MAX_ITEMS)
                {
                    throw "Library is full!";
                }

                cout << "Enter Magazine Title: ";
                cin >> title;

                cout << "Enter Author Name: ";
                cin >> author;

                items[itemCount] =
                    new Magazine(title, author);

                itemCount++;

                cout << "Magazine added successfully.\n";
            }

            else if (choice == 4)
            {
                int i;

                if (itemCount == 0)
                {
                    cout << "No items available.\n";
                }
                else
                {
                    for (i = 0; i < itemCount; i++)
                    {
                        cout << "\nItem Number: "
                             << i + 1 << endl;

                        items[i]->displayDetails();
                    }
                }
            }

            else if (choice == 5)
            {
                int number;

                cout << "Enter Item Number: ";
                cin >> number;

                if (number < 1 || number > itemCount)
                {
                    throw "Invalid item number!";
                }

                items[number - 1]->checkOut();
            }

            else if (choice == 6)
            {
                int number;

                cout << "Enter Item Number: ";
                cin >> number;

                if (number < 1 || number > itemCount)
                {
                    throw "Invalid item number!";
                }

                items[number - 1]->returnItem();
            }

            else if (choice == 7)
            {
                cout << "\nThank you for using "
                     << "Library Management System.\n";
            }

            else
            {
                cout << "Invalid choice!\n";
            }
        }

        catch (const char *error)
        {
            cout << "Error: " << error << endl;
        }

    } while (choice != 7);

    // Free Dynamic Memory
    int i;

    for (i = 0; i < itemCount; i++)
    {
        delete items[i];
    }

    return 0;
}