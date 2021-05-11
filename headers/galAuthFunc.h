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

        for (User &user : UserBase)
            if (login == user.login() && password == user.password())
            {
                currentUser = &user;
                gal::start(menu);
                currentUser = &Unauthorized;
            }
        return 0;
    }

}