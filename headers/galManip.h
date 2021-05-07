#ifndef GALMANIP_H
#define GALMANIP_H

#include <galMenu.h>
#include <galPhoto.h>

namespace gal
{
    template <class T>
    int sort(GalMenu<T>& menu)
    {
        int size = menu.size();
        for (int i = 0; i < size - 1; i++)
            for (int j = 0; j < size - i - 1; j++)
                if (menu.nameOf(j) > menu.nameOf(j + 1))
                    menu.swap(j, j + 1);
        return 0;
    }

    template <class T>
    int add(GalMenu<T> &menu)
    {
        std::cout << "Enter a name for a new ";
        if (typeid(T) == typeid(photo))
            std::cout << "photo" << std::endl;
        else if (typeid(T) == typeid(GalMenu<photo>))
            std::cout << "album" << std::endl;
        else 
            std::cout << "item" << std::endl;
        std::cout << ":";
        std::cin >> menu;
        start(menu);

        return 0;
    }

    template <class T>
    int add(GalMenu<T> &menu, MenuItem<T> &item)
    {
        menu.add(item);

        return 0;
    }

    template <class T>
    int remove(GalMenu<T> &menu)
    {
        display(menu);
        std::cout << "Delete which item?\n:";
        unsigned int pos;
        std::cin >> pos;

        menu.remove(pos - 1);

        return 0;
    }

    template <class T>
    int remove(GalMenu<T> &menu, unsigned int pos)
    {
        menu.remove(pos);
        return 0;
    }

    template <class T>
    int filter(GalMenu<T> &menu)
    {
        std::cout << "Enter filter key\n:";
        std::string key{};
        std::cin >> key;
        int shift = 0;
        GalMenu<T> tmpMenu(menu);
        for (int i = 0; i <= tmpMenu.size(); i++)
            if (menu[i]->name() != key)
            {
                remove(tmpMenu, i - shift);
                shift++;
            }
        start(tmpMenu);
        return 0;
    }
}

#endif //GALMAINP_H