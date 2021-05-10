#if !defined(GALMENUMANAGER_H)
#define GALMENUMANAGER_H

#include <galPhoto.h>
#include <galUser.h>
#include <galMenu.h>
#include <PointerItem.h>
#include <galUI.h>
#include <galPhotoManip.h>

using gal::photo;
using gal::MenuItem;
using gal::GalMenu;
using gal::PointerItem;
using gal::User;

namespace gal
{
    GalMenu* NewMenu(std::string name, GalMenu &item)
    {
        PointerItem<GalMenu> *photoItem = new PointerItem{item.name(), gal::start, &item};

        myArray<MenuItem*> items{
            photoItem,
        };

        GalMenu *menu = new GalMenu{name, items, GalMenu::MenuType::gallery};
        PointerItem<GalMenu> *additem = new PointerItem{"Add Album", add, menu};
        PointerItem<GalMenu> *removeitem = new PointerItem{"Delete Album", gal::remove, menu};
        PointerItem<GalMenu> *sortitem = new PointerItem{"Sort Gallery", gal::sort, menu};
        PointerItem<GalMenu> *filteritem = new PointerItem{"Filter Gallery", gal::filter, menu};

        menu->addOption(*additem);
        menu->addOption(*removeitem);
        menu->addOption(*sortitem);
        menu->addOption(*filteritem);

        return menu;
    }

    GalMenu* NewMenu(std::string name, photo &item)
    {
        PointerItem<photo> *photoItem = new PointerItem{item.name, gal::view, &item};

        myArray<MenuItem*> items{
            photoItem,
        };

        GalMenu *menu = new GalMenu{name, items, GalMenu::MenuType::album};
        PointerItem<GalMenu> *additem = new PointerItem{"Add Photo", gal::add, menu};
        PointerItem<GalMenu> *removeitem = new PointerItem{"Delete Photo", gal::remove, menu};
        PointerItem<GalMenu> *sortitem = new PointerItem{"Sort Album", gal::sort, menu};
        PointerItem<GalMenu> *filteritem = new PointerItem{"Filter Album", gal::filter, menu};

        menu->addOption(*additem);
        menu->addOption(*removeitem);
        menu->addOption(*sortitem);
        menu->addOption(*filteritem);

        return menu;
    }

    void AddItem(GalMenu &item, GalMenu &menu)
    {
        PointerItem<GalMenu> *MItem = new PointerItem{item.name(), gal::start, &item};
        menu.add(*MItem);
    }

    void AddItem(photo &item, GalMenu &menu)
    {
        PointerItem<photo> *MItem = new PointerItem{item.name, gal::view, &item};
        menu.add(*MItem);
    }
}

#endif // GALMENUMANAGER_H
