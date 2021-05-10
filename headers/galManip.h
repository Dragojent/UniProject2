#ifndef GALMANIP_H
#define GALMANIP_H

#include <galPhoto.h>
#include <galManip.h>
#include <galUI.h>
#include <PointerItem.h>
#include <galPhotoManip.h>
#include <menuItem.h>

namespace gal
{
    int sort(GalMenu& menu)
    {
        int size = menu.size();
        for (int i = 4; i < size - 1; i++)
            for (int j = 4; j < size - 1; j++)
                if (menu.nameOf(j) > menu.nameOf(j + 1))
                    menu.swap(j, j + 1);
        return 0;
    }

    int add(GalMenu &menu)
    {
        display(menu);
        std::cout << "Enter a name for a new ";
        if (menu.type() == GalMenu::MenuType::album)
            std::cout << "photo";
        if (menu.type() == GalMenu::MenuType::gallery)
            std::cout << "album";
        else
            std::cout << "item";
        std::cout << "\n:";

        std::string name;
        std::cin >> name;
        if (menu.type() == GalMenu::MenuType::album)
        {
            photo *ph = new photo{name, "", {1}};
            PointerItem<photo> *MItem = new PointerItem{ph->name, view, ph};
            menu.add(*MItem);
        }
        else if (menu.type() == GalMenu::MenuType::gallery)
        {
            photo *ph = new photo{name, "", {1}};
            PointerItem<photo> *MItem = new PointerItem{name, view, ph};
            myArray<MenuItem*> items{MItem};
            GalMenu *newmenu = new GalMenu{name, items, GalMenu::MenuType::album};
            PointerItem<GalMenu> *MMItem = new PointerItem{name, start, newmenu};
            menu.add(*MItem);
        }
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
                gal::remove(*tmpMenu, i - shift);
                shift++;
            }
        start(*tmpMenu);
        return 0;
    }
}


#endif //GALMAINP_H