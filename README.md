# Hotel Management System

A simple C++ console application for managing hotel customer records. The program lets a user add, search, modify, delete, and display customers through a text-based menu.

This project is suitable for beginners who are learning C++ structures, vectors, functions, loops, conditionals, string input, and menu-driven console programs.

## Project Overview

The Hotel Management System stores customer information in memory while the program is running. Each customer has a name, address, and phone number. The user interacts with the program from the terminal by selecting numbered menu options.

The current implementation does not use a database or file storage. All customer records are lost when the program exits.

## Features

- Add a new customer record
- Search for a customer by name
- Modify an existing customer record
- Delete a customer record
- Display all saved customers
- Exit the program safely from the menu
- Uses a simple `struct` to represent customer data
- Uses a global `vector<Customer>` to store all customer records during runtime

## Technologies Used

| Technology | Purpose |
| --- | --- |
| C++ | Main programming language |
| Standard Library `iostream` | Console input and output |
| Standard Library `string` | Customer name, address, and phone number handling |
| Standard Library `vector` | Dynamic in-memory customer storage |
| `stdlib.h` | Used for `system("cls")` to clear the console on Windows |

## Project Files

| File | Description |
| --- | --- |
| `hotel_management.cpp` | Main C++ source code for the hotel management system |
| `hotel_management.exe` | Pre-built Windows executable generated from the C++ source file |
| `README.md` | Project documentation |

## Requirements

To build and run the project from source, you need:

- A C++ compiler such as `g++`
- A terminal or command prompt
- Windows is recommended for the current version because the program uses `system("cls")`

The code can still compile on Linux or macOS, but the `cls` command is Windows-specific. On Linux or macOS, replace `system("cls")` with `system("clear")`, or remove the clear-screen calls.

## How to Compile

Open a terminal in the project folder and run:

```bash
g++ hotel_management.cpp -o hotel_management.exe
```

If you want a compiler warning-friendly build, you can use:

```bash
g++ -Wall -Wextra -std=c++17 hotel_management.cpp -o hotel_management.exe
```

## How to Run

After compiling, run the executable:

```bash
./hotel_management.exe
```

On Windows Command Prompt or PowerShell, you can also run:

```powershell
.\hotel_management.exe
```

## Program Menu

When the program starts, it displays this menu:

```text
-------------------------Hotel Management System Menu------------------------------
1. Add Customer
2. Search Customer
3. Modify Customer
4. Delete Customer
5. Show Customers
6. Exit
Enter your choice:
```

## Menu Options

| Option | Action | Description |
| --- | --- | --- |
| `1` | Add Customer | Takes the customer's name, address, and phone number, then stores the record in memory |
| `2` | Search Customer | Searches for a customer by exact name and displays the matching details |
| `3` | Modify Customer | Searches for a customer by exact name and updates that customer's name, address, and phone number |
| `4` | Delete Customer | Searches for a customer by exact name and removes that customer from memory |
| `5` | Show Customers | Displays every customer currently stored in memory |
| `6` | Exit | Ends the program |

## Customer Data Model

Each customer is represented by the following C++ structure:

```cpp
struct Customer
{
    string name;
    string address;
    string phoneNumber;
};
```

### Fields

| Field | Type | Description |
| --- | --- | --- |
| `name` | `string` | Customer's full name |
| `address` | `string` | Customer's address |
| `phoneNumber` | `string` | Customer's phone number |

The phone number is stored as a `string`, which is useful because phone numbers may contain leading zeroes, country codes, or symbols.

## How Data Is Stored

The program stores customers in this global vector:

```cpp
vector<Customer> customers;
```

This means:

- Customers can be added dynamically while the program is running
- The list can grow as more customers are added
- Data is stored only in RAM
- Data disappears after choosing `6. Exit` or closing the program
- There is no permanent file, database, or cloud storage in the current version

## Function Details

### `addCustomer()`

Adds a new customer to the system.

Steps performed:

1. Creates a new `Customer` object.
2. Takes the customer name using `getline`.
3. Takes the customer address using `getline`.
4. Takes the customer phone number using `cin`.
5. Clears the console using `system("cls")`.
6. Adds the customer to the `customers` vector using `push_back`.
7. Prints a success message.

### `searchCustomer()`

Searches for a customer by name.

Steps performed:

1. Takes the customer name to search.
2. Loops through all records in `customers`.
3. Compares each customer's name with the search name.
4. If a match is found, displays the customer's details.
5. If no match is found, prints `Customer not found.`

Important detail: the search uses exact matching. For example, `John` and `john` are treated as different names.

### `modifyCustomer()`

Updates an existing customer record.

Steps performed:

1. Takes the customer name to modify.
2. Searches the `customers` vector for an exact name match.
3. If found, asks for a new name, address, and phone number.
4. Updates the selected customer record.
5. Prints a success message.
6. If no match is found, prints `Customer not found.`

Only the first matching customer is modified because the function stops after updating one record.

### `deleteCustomer()`

Deletes a customer from the system.

Steps performed:

1. Takes the customer name to delete.
2. Searches the `customers` vector using an iterator.
3. If a matching customer is found, removes it with `erase`.
4. Prints a success message.
5. Stops immediately after deleting the first matching record.
6. If no match is found, prints `Customer not found.`

### `showCustomers()`

Displays all customers currently stored in memory.

Behavior:

- If the vector is empty, it prints `No customers in the system.`
- If records exist, it prints each customer's name, address, and phone number
- Each customer is separated by a divider line

### `main()`

Controls the whole program.

Main responsibilities:

1. Clears the screen at startup.
2. Displays the hotel management menu.
3. Takes the user's menu choice.
4. Calls the correct function using a `switch` statement.
5. Keeps showing the menu using a `do while` loop.
6. Exits when the user enters option `6`.

## Example Usage

### Add a Customer

```text
Enter your choice: 1
Enter customer name: Rahul Sharma
Enter customer address: Delhi, India
Enter customer phone number: 9876543210
Customer added successfully.
```

### Search for a Customer

```text
Enter your choice: 2
Enter customer name to search: Rahul Sharma
Customer Found:
Name: Rahul Sharma
Address: Delhi, India
Phone Number: 9876543210
```

### Modify a Customer

```text
Enter your choice: 3
Enter customer name to modify: Rahul Sharma
Enter new customer name: Rahul S.
Enter new customer address: Mumbai, India
Enter new customer phone number: 9999999999
Customer information modified successfully.
```

### Delete a Customer

```text
Enter your choice: 4
Enter customer name to delete: Rahul S.
Customer deleted successfully.
```

### Show All Customers

```text
Enter your choice: 5
List of Customers:
Name: Rahul S.
Address: Mumbai, India
Phone Number: 9999999999
------------------------
```

## Input Notes

- Customer names and addresses can contain spaces because they are read using `getline`.
- Phone numbers are read using `cin`, so spaces are not supported in the phone number field.
- Searching, modifying, and deleting customers depend on exact name matches.
- The program uses `cin.ignore()` before `getline()` to handle leftover newline characters after numeric menu input.
- Invalid menu numbers display `Invalid choice. Please try again.`

## Current Limitations

- Customer data is not saved permanently.
- All data is erased after the program exits.
- There is no login system or admin authentication.
- There is no room booking module.
- There is no room availability tracking.
- There is no billing or payment system.
- There is no check-in or check-out date handling.
- Search works only by exact customer name.
- Duplicate customer names are allowed.
- Only the first matching customer is modified or deleted.
- The program does not validate phone number format.
- The program does not handle invalid non-numeric input for the menu choice.
- `system("cls")` is Windows-specific.

## Possible Future Improvements

- Save customer records to a file.
- Load customer records from a file when the program starts.
- Add room details such as room number, type, price, and availability.
- Add booking, check-in, and check-out features.
- Add billing and invoice generation.
- Add customer ID numbers to avoid duplicate-name issues.
- Add case-insensitive search.
- Add partial-name search.
- Validate phone numbers.
- Handle invalid menu input more safely.
- Replace `system("cls")` with a cross-platform screen-clearing method.
- Split the code into multiple files, such as headers and implementation files.
- Add comments for beginner-friendly learning.

## Troubleshooting

### `g++` is not recognized

Install a C++ compiler such as MinGW-w64, MSYS2, or another GCC distribution, then make sure the compiler is added to your system `PATH`.

### The program closes immediately

Run it from a terminal instead of double-clicking the executable. This keeps the console window open so you can see the menu and output.

### Search says customer not found

Make sure the name is typed exactly as it was entered. The current search is case-sensitive and space-sensitive.

### Screen clear does not work

The program uses:

```cpp
system("cls");
```

This is intended for Windows. On Linux or macOS, use:

```cpp
system("clear");
```

or remove the screen-clearing line.

## Educational Concepts Covered

This project demonstrates:

- C++ structures
- Vectors
- Global variables
- Functions
- Loops
- `switch` statements
- Iterators
- `getline` input
- Console input and output
- Basic CRUD operations
- Menu-driven program design

## Author

This is a C++ mini project for learning and practicing basic hotel customer management operations.
Harsh
