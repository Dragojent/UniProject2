#ifndef GALUI_H
#define GALUI_H

#include <iostream>
#include <galMenu.h>
#include <conio.h>

namespace gal
{
    template <class T>
    void display(GalMenu<T> &menu)
    {
        unsigned int pos = 0;
        std::cout << menu.name() << std::endl;
        for (auto item : menu.items())
        {
            std::cout << pos + 1 << ")";
            if (pos == menu.selected())
                std::cout << "->";
            std::cout << item->name() << std::endl;
            pos++;
        }
    }

    template <class T>
    int start(GalMenu<T> &menu)
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

                default:
                    break;
            }
        }
        return 1;
    }
}

#endif //GALUI_H