#include <iostream>
#include <string> 
#include <stdlib.h> 
#include <vector>
using namespace std;
struct Customer 
{
    string name;
    string address;
    string phoneNumber;
};

vector<Customer> customers;

void addCustomer() 
{
    Customer customer;
    cout << "Enter customer name: ";
    cin.ignore();
    getline(cin, customer.name);
    cout << "Enter customer address: ";
    getline(cin, customer.address);
    cout << "Enter customer phone number: ";
    cin >> customer.phoneNumber;
    system("cls"); 
    customers.push_back(customer);
    cout << "Customer added successfully.\n";
    
}

void searchCustomer() 
{
    string searchName;
    cout << "Enter customer name to search: ";
    cin.ignore();
    getline(cin, searchName);
    bool found = false;

    for (const Customer& customer : customers) 
    {
        if (customer.name == searchName) 
        {
            cout << "Customer Found:\n";
            cout << "Name: " << customer.name << "\n";
            cout << "Address: " << customer.address << "\n";
            cout << "Phone Number: " << customer.phoneNumber << "\n";
            found = true;
        }
    }

    if (!found) 
    {
        cout << "Customer not found.\n";
    }
}

void modifyCustomer() 
{
    string modifyName;
    cout << "Enter customer name to modify: ";
    cin.ignore();
    getline(cin, modifyName);
    bool found = false;

    for (Customer& customer : customers) 
    {
        if (customer.name == modifyName)
        {
            cout << "Enter new customer name: ";
            getline(cin, customer.name);
            cout << "Enter new customer address: ";
            getline(cin, customer.address);
            cout << "Enter new customer phone number: ";
            cin >> customer.phoneNumber;
            cout << "Customer information modified successfully.\n";
            found = true;
            break;
        }
    }

    if (!found) 
    {
        cout << "Customer not found.\n";
    }
}

void deleteCustomer() 
{
    string deleteName;
    cout << "Enter customer name to delete: ";
    cin.ignore();
    getline(cin, deleteName);

    for (auto it = customers.begin(); it != customers.end(); ++it) 
    {
        if (it->name == deleteName) 
        {
            customers.erase(it);
            cout << "Customer deleted successfully.\n";
            return;
        }
    }

    cout << "Customer not found.\n";
}

void showCustomers() 
{
    if (customers.empty()) 
    {
        cout << "No customers in the system.\n";
    } else 
    {
        cout << "List of Customers:\n";
        for (const Customer& customer : customers) 
        {
            cout << "Name: " << customer.name << "\n";
            cout << "Address: " << customer.address << "\n";
            cout << "Phone Number: " << customer.phoneNumber << "\n";
            cout << "------------------------\n";
        }
    }
}

int main() 
{
    int choice;
    system("cls"); 

    do 
    {
        cout << "\n-------------------------Hotel Management System Menu------------------------------\n";
        cout << "1. Add Customer\n";
        cout << "2. Search Customer\n";
        cout << "3. Modify Customer\n";
        cout << "4. Delete Customer\n";
        cout << "5. Show Customers\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                addCustomer();
                break;
            case 2:
                searchCustomer();
                break;
            case 3:
                modifyCustomer();
                break;
            case 4:
                deleteCustomer();
                break;
            case 5:
                showCustomers();
                break;
            case 6:
                cout << "------------------------Exiting the program. Goodbye!-----------------------------\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 6);

    return 0;
}
