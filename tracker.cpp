

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <set>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Expense {
    int id;
    string name;
    string category;
    string date; // format: YYYY-MM-DD
    int amount;
};

class ExpenseTracker {
    vector<Expense> expenses;
    map<string, vector<Expense>> categoryMap;
    unordered_map<string, vector<Expense>> dateMap;
    set<int> idSet;
    stack<vector<Expense>> history;
    int nextId = 1;

public:
    void addExpense(string name, string category, string date, int amount);
    void deleteExpense(int id);
    void searchByCategory(string category);
    void searchByDate(string date);
    void viewAll();
    void viewSortedByAmount();
    void undo();
};

void ExpenseTracker::addExpense(string name, string category, string date, int amount) {
    Expense exp = {nextId++, name, category, date, amount};
    history.push(expenses); // Save state
    expenses.push_back(exp);
    categoryMap[category].push_back(exp);
    dateMap[date].push_back(exp);
    idSet.insert(exp.id);
    cout << "Expense added. ID: " << exp.id << endl;
}

void ExpenseTracker::deleteExpense(int id) {
    if (!idSet.count(id)) {
        cout << "ID not found.\n";
        return;
    }
    history.push(expenses);
    vector<Expense> updated;
    for (auto &e : expenses) {
        if (e.id != id) {
            updated.push_back(e);
        } else {
            // Update maps
            auto &vec1 = categoryMap[e.category];
            vec1.erase(remove_if(vec1.begin(), vec1.end(), [&](Expense x){ return x.id == id; }), vec1.end());
            auto &vec2 = dateMap[e.date];
            vec2.erase(remove_if(vec2.begin(), vec2.end(), [&](Expense x){ return x.id == id; }), vec2.end());
        }
    }
    expenses = updated;
    idSet.erase(id);
    cout << "Expense deleted.\n";
}

void ExpenseTracker::searchByCategory(string category) {
    if (categoryMap.count(category)) {
        for (auto &e : categoryMap[category]) {
            cout << e.id << " | " << e.name << " | " << e.date << " | ₹" << e.amount << "\n";
        }
    } else {
        cout << "No expenses found in this category."<<endl;
    }
}

void ExpenseTracker::searchByDate(string date) {
    if (dateMap.count(date)) {
        for (auto &e : dateMap[date]) {
            cout << e.id << " | " << e.name << " | " << e.category << " | ₹" << e.amount << "\n";
        }
    } else {
        cout << "No expenses found on this date."<<endl;
    }
}

void ExpenseTracker::viewAll() {
    for (auto &e : expenses) {
        cout << e.id << " | " << e.name << " | " << e.category << " | " << e.date << " | ₹" << e.amount << "\n";
    }
}

void ExpenseTracker::viewSortedByAmount() {
    vector<Expense> temp = expenses;
    sort(temp.begin(), temp.end(), [](Expense a, Expense b) {
        return a.amount > b.amount;
    });
    for (auto &e : temp) {
        cout << e.id << " | " << e.name << " | Rs." << e.amount << endl;
    }
}

void ExpenseTracker::undo() {
    if (!history.empty()) {
        expenses = history.top();
        history.pop();
        cout << "↩️ Undo performed."<< endl;
    } else {
        cout << "Nothing to undo."<< endl;
    }
}

int main() {
    ExpenseTracker tracker;
    int choice;
    while (true) {
        cout << "\n1. Add Expense\n2. Delete Expense\n3. View All\n4. Search by Category\n5. Search by Date\n6. View Sorted by Amount\n7. Undo\n8. Exit\nChoice: ";
        cin >> choice;
        if (choice == 1) {
            string name, category, date;
            int amount;
            cout << "Category: ";
            cin >> category;
            cout << "Enter name: ";
            cin >> name;
            cout << "Date: ";
            cin >> date; 
            cout << "Amount: ";
            cin >> amount;
            tracker.addExpense(name, category, date, amount);
        } else if (choice == 2) {
            int id;
            cout << "Enter ID to delete: ";
            cin >> id;
            tracker.deleteExpense(id);
        } else if (choice == 3) {
            tracker.viewAll();
        } else if (choice == 4) {
            string cat;
            cout << "Enter category: ";
            cin >> cat;
            tracker.searchByCategory(cat);
        } else if (choice == 5) {
            string dt;
            cout << "Enter date: ";
            cin >> dt;
            tracker.searchByDate(dt);
        } else if (choice == 6) {
            tracker.viewSortedByAmount();
        } else if (choice == 7) {
            tracker.undo();
        } else {
            break;
        }
    }
    return 0;
}
