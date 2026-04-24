#include <bits/stdc++.h>
using namespace std;

class PhoneBook {
    map<string, string> mp;
    vector<pair<string, string>> arr;

    void rebuild() {
        arr.clear();
        for (auto &p : mp)
            arr.push_back(p);

        sort(arr.begin(), arr.end());
    }

    int binarySearch(string name) {
        int l = 0, r = arr.size() - 1;

        while (l <= r) {
            int mid = (l + r) / 2;

            if (arr[mid].first == name)
                return mid;
            else if (arr[mid].first < name)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return -1;
    }

public:
    void addContact() {
        string name, number;

        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter Number: ";
        cin >> number;

        mp[name] = number;
        rebuild();

        cout << "Contact Added/Updated Successfully\n";
    }

    void searchMap() {
        string name;

        cout << "Enter Name: ";
        cin >> name;

        if (mp.find(name) != mp.end())
            cout << name << " -> " << mp[name] << endl;
        else
            cout << "Contact Not Found\n";
    }

    void searchBinary() {
        string name;

        cout << "Enter Name: ";
        cin >> name;

        int idx = binarySearch(name);

        if (idx != -1)
            cout << arr[idx].first << " -> " << arr[idx].second << endl;
        else
            cout << "Contact Not Found\n";
    }

    void deleteContact() {
        string name;

        cout << "Enter Name: ";
        cin >> name;

        if (mp.erase(name)) {
            rebuild();
            cout << "Contact Deleted Successfully\n";
        } else {
            cout << "Contact Not Found\n";
        }
    }

    void display() {
        if (mp.empty()) {
            cout << "Phonebook Empty\n";
            return;
        }

        for (auto &p : mp)
            cout << p.first << " -> " << p.second << endl;
    }
};

int main() {
    PhoneBook pb;
    int choice;

    while (true) {
        cout << "\n===== PHONEBOOK MENU =====\n";
        cout << "1. Add Contact\n";
        cout << "2. Search (Map)\n";
        cout << "3. Search (Binary Search)\n";
        cout << "4. Delete Contact\n";
        cout << "5. Display All\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";

        cin >> choice;

        if (choice == 1)
            pb.addContact();
        else if (choice == 2)
            pb.searchMap();
        else if (choice == 3)
            pb.searchBinary();
        else if (choice == 4)
            pb.deleteContact();
        else if (choice == 5)
            pb.display();
        else if (choice == 6)
            break;
        else
            cout << "Invalid Choice\n";
    }

    return 0;
}