# Expense Tracker (Console-Based Application)

A fully interactive Expense Tracker built using **C++**, utilizing **STL containers**, **modular object-oriented design**, and **stack-based undo functionality**. The user can manage expenses directly from the terminal, with features like categorized search, date-wise filtering, sorting, and undo.

## Features

- **Console-based interactive application**: Track and manage expenses directly in your terminal.
- **Add Expense**: Input name, category, date, and amount for a new expense.
- **Delete Expense**: Remove an expense by its unique ID.
- **View All**: Display all added expenses in a structured format.
- **Search by Category**: Filter and display expenses for a specific category.
- **Search by Date**: Retrieve expenses for a particular date (`YYYY-MM-DD` format).
- **Sort by Amount**: View expenses sorted from highest to lowest amount.
- **Undo Functionality**: Revert the last change using the `undo` feature.
- **Unique ID System**: Each expense is automatically assigned a unique identifier.

## Technologies Used

- **C++**  
- **Standard Template Library (STL)**:  
  - `vector` – To store expenses  
  - `map` – For category-wise search  
  - `unordered_map` – For date-wise filtering  
  - `set` – To manage unique IDs  
  - `stack` – For implementing undo functionality  
- **DSA Concepts**:  
  - Stack-based state saving (for undo operations)  
  - Sorting using custom comparators  
  - Efficient lookup and grouping using associative containers  
- **Modular Design**:  
  - Clean separation of logic using classes  
  - Easy-to-maintain and extendable code structure
