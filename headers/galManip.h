#ifndef GALMANIP_H
#define GALMANIP_H

#include <galMenu.h>
#include <galPhoto.h>

namespace gal
{
    int sort(GalMenu& menu)
    {
        int size = menu.size();
        for (int i = 4; i < size - 1; i++)
            for (int j = 4; j < size - i - 1; j++)
                if (menu.nameOf(j) > menu.nameOf(j + 1))
                    menu.swap(j, j + 1);
        return 0;
    }

    int add(GalMenu &menu)
    {
        std::cout << "Enter a name for a new ";
        // if (typeid(T) == typeid(photo))
        //     std::cout << "photo" << std::endl;
        // else if (typeid(T) == typeid(GalMenu))
        //     std::cout << "album" << std::endl;
        // else 
        std::cout << "item" << std::endl;
        std::cout << ":";
        std::cin >> menu;
        // start(menu);

        return 0;
    }

    int add(GalMenu &menu, MenuItem &item)
    {
        menu.add(item);

        return 0;
    }

    int remove(GalMenu &menu)
    {
        display(menu);
        std::cout << "Delete which item?\n:";
        unsigned int pos;
        std::cin >> pos;

        menu.remove(pos + 3);

        return 0;
    }

    int remove(GalMenu &menu, unsigned int pos)
    {
        menu.remove(pos);
        return 0;
    }

    int filter(GalMenu &menu)
    {
        std::cout << "Enter filter key\n:";
        std::string key{};
        std::cin >> key;
        int shift = 0;
        GalMenu *tmpMenu = new GalMenu(menu);
        for (int i = 4; i <= tmpMenu->size(); i++)
            if (menu.nameOf(i).compare(0, key.length(), key))
            {
                remove(*tmpMenu, i - shift);
                shift++;
            }
        start(*tmpMenu);
        return 0;
    }
}

#endif //GALMAINP_H