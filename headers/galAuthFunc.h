#include <string>
#include <iostream>
#include <globals.h>
#include <galUser.h>

namespace gal
{
    int reg()
    {
        std::string login{}, password{}, name{};
        std::cout << "Name: ";
        std::cin >> name;
        std::cout << "Login: ";
        std::cin >> login;
        std::cout << "Password: ";
        std::cin >> password;

        for (const auto &user : UserBase)
            if (user.login() == login)
                throw galException("User already exists");

        User newUser{name, password, login, User::AccessLevel::user};
        UserBase.push_back(newUser);

        return 0;
    }

    int login(GalMenu &menu)
    {
        std::string login{}, password{};
        std::cout << "Login: ";
        std::cin >> login;
        std::cout << "Password: ";
        std::cin >> password;

        bool loggedIn = false;
        for (User &user : UserBase)
            if (login == user.login() && password == user.password())
            {
                currentUser = &user;
                loggedIn = true;
                gal::start(menu);
                currentUser = &Unauthorized;
            }
        
        if (loggedIn == false)
            throw galException("Wrong login or password");

        return 0;
    }

}