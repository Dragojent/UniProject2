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
        for (int i = 5; i < size - 1; i++)
            for (int j = 5; j < size - 1; j++)
                if (menu.nameOf(j) > menu.nameOf(j + 1))
                    menu.swap(j, j + 1);
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

        menu.remove(pos + 4);

        return 0;
    }

    int remove(GalMenu &menu, unsigned int pos)
    {
        menu.remove(pos);
        return 0;
    }

    int filter(GalMenu &menu)
    {
        display(menu);
        std::cout << "Enter filter key\n:";
        std::string key{};
        std::cin >> key;
        int shift = 0;
        GalMenu *tmpMenu = new GalMenu(menu);
        tmpMenu->setType(GalMenu::MenuType::noActions);
        int size = tmpMenu->size();
        for (int i = 0; i < size; i++)
        {
            if (i < 5 || (tmpMenu->nameOf(i - shift).compare(0, key.length(), key)))
            {
                tmpMenu->remove(i - shift);
                shift++;
            }
        }
        if (tmpMenu->size() != 0)
            start(*tmpMenu);
        else
        {
            system("cls");
            std::cout << "Pattern not found" << std::endl;
            system("pause");
        }
        return 0;
    }

    int edit(GalMenu &menu)
    {
        gal::display(menu);
        std::cout << "Edit which ";
        if (menu.type() == GalMenu::MenuType::album)
            std::cout << "photo\n:" << std::endl;
        if (menu.type() == GalMenu::MenuType::gallery)
            std::cout << "album\n:" << std::endl;
        unsigned int pos;
        std::cin >> pos;
        menu.edit(pos + 4);
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
            Photo *ph = new Photo{name, "", {1}};
            PointerItem<Photo> *MItem = new PointerItem{ph->name(), view, ph};
            menu.add(*MItem);
        }
        else if (menu.type() == GalMenu::MenuType::gallery)
        {
            Photo *ph = new Photo{name, "", {1}};
            PointerItem<Photo> *MItem = new PointerItem{name, view, ph};
            myArray<MenuItem*> items{MItem};
            GalMenu *newmenu = new GalMenu{name, items, GalMenu::MenuType::album};
            newmenu->remove(0);
            PointerItem<GalMenu> *MMItem = new PointerItem{name, start, newmenu};
            PointerItem<GalMenu> *additem = new PointerItem{"Add Photo", add, newmenu};
            PointerItem<GalMenu> *removeitem = new PointerItem{"Delete Photo", remove, newmenu};
            PointerItem<GalMenu> *sortitem = new PointerItem{"Sort Album", sort, newmenu};
            PointerItem<GalMenu> *filteritem = new PointerItem{"Filter Album", filter, newmenu};
            PointerItem<GalMenu> *edititem = new PointerItem{"Edit Photo", edit, newmenu};

            newmenu->add(*additem);
            newmenu->add(*removeitem);
            newmenu->add(*sortitem);
            newmenu->add(*filteritem);
            newmenu->add(*edititem);
            menu.add(*MMItem);
        }

        return 0;
    }
}


#endif //GALMAINP_H