#include <iostream>
#include <string>
#include <map>

struct User {
    std::string username;
    std::string password;
};

std::map<std::string, User> users;

void Register() {
    User newUser;
    std::cout << "Enter username: ";
    std::cin >> newUser.username;

    if (users.find(newUser.username) != users.end()) {
        std::cout << "Username already taken." << std::endl;
        return;
    }

    std::cout << "Enter password: ";
    std::cin >> newUser.password;

    users[newUser.username] = newUser;
    std::cout << "Registration successful." << std::endl;
}

// Function to perform user login
void Login() {
    std::string username, password;
    std::cout << "Enter username: ";
    std::cin >> username;

    auto userIterator = users.find(username);
    if (userIterator == users.end()) {
        std::cout << "Username not found." << std::endl;
        return;
    }

    std::cout << "Enter password: ";
    std::cin >> password;

    if (userIterator->second.password == password) {
        std::cout << "Login successful. Welcome, " << username << "!" << std::endl;
    } else {
        std::cout << "Incorrect password." << std::endl;
    }
}

int main() {
    int choice;
    
    while (true) {
        std::cout << "1. Register\n2. Login\n3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                Register();
                break;
            case 2:
                Login();
                break;
            case 3:
                std::cout << "Goodbye!" << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please select again." << std::endl;
        }
    }

    return 0;
}


