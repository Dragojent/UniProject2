#include <globals.h>
#include <list>
#include <iostream>
#include <galUser.h>
#include <galUI.h>
#include <galMenu.h>
#include <menuItem.h>
#include <galPhoto.h>
#include <PointerItem.h>
#include <galPhotoManip.h>
#include <galManip.h>
#include <galMenuManager.h>

using namespace gal;

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

GalMenu* CreateAuthScreen(GalMenu &menu)
{
    PointerItem<GalMenu> *log = new PointerItem{"Login", login, &menu};
    MenuItem *pas = new MenuItem{"Register", reg};

    myArray<MenuItem*> MItems{
        log,
        pas
    };

    GalMenu *authScreen = new GalMenu{"Auth Screen", MItems, GalMenu::MenuType::auth};
    return authScreen;
}

int main()
{
    photo ph{"photo1", "__~+~__", {1, 2, 3}};
    photo pha{"abPhoto", "__~+~__", {1, 2, 3}};
    photo phb{"babPhoto", "__~+~__", {1, 2, 3}};

    GalMenu *album = NewMenu("Album_1", ph);
    AddItem(phb, *album);
    AddItem(pha, *album);
    GalMenu *gallery = NewMenu("Gallery", *album);
    GalMenu *authScreen = CreateAuthScreen(*gallery);

    gal::start(*authScreen);

    return 0;
}