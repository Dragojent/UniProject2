#ifndef GALUI_H
#define GALUI_H

#include <globals.h>
#include <iostream>
#include <galMenu.h>
#include <conio.h>


namespace gal
{
    class User;
    void display(GalMenu &menu)
    {
        int shift{};
        if (menu.type() == GalMenu::MenuType::album)
            shift = 5;
        if (menu.type() == GalMenu::MenuType::gallery)
            shift = 5;
        if (menu.type() == GalMenu::MenuType::noActions)
            shift = 0;

        std::cout << "Use 'w' and 's' to move up and down" << std::endl;
        std::cout << "Press ESC to move up a menu" << std::endl;
        std::cout << "Press SPACE to choose an option" << std::endl;
        std::cout << "Press 'q' to exit the program\n" << std::endl;
        std::cout << menu.name() << "    Logged in as: " << currentUser->name() << "\n" << std::endl;
        for (int pos = 0; pos < menu.size(); pos++)
        {
            if (pos == shift)
                std::cout << std::endl;
            if (pos >= shift)
                std::cout << pos - (shift - 1) << ")";
            if (pos == menu.selected())
                std::cout << "->";
            std::cout << menu.nameOf(pos) << std::endl;
        }
    }

    int start(GalMenu &menu)
    {
        menu = 0;
        system("cls");
        gal::display(menu);
        bool running = true;
        char input{};

        while (running)
        {
            system("cls");
            gal::display(menu);
            input = getch();
            switch (input)
            {
                case 'w':
                    menu--;
                    break;
                
                case 's':
                    menu++;
                    break;
                
                case ' ':
                    system("cls");
                    menu.run();
                    break;

                case 27 /*ESC*/:
                    running = false;
                    break;

                case 'q':
                    exit(0);
                    break;

                default:
                    break;
            }
        }
        return 1;
    }
}

#endif //GALUI_H