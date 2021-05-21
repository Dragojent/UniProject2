#if !defined(GALMENUMANAGER_H)
#define GALMENUMANAGER_H

#include <galPhoto.h>
#include <galUser.h>
#include <galMenu.h>
#include <PointerItem.h>
#include <galUI.h>
#include <galPhotoManip.h>
#include <galAuthFunc.h>

using gal::Photo;
using gal::MenuItem;
using gal::GalMenu;
using gal::PointerItem;
using gal::User;

namespace gal
{
    int placeholder() {}

    GalMenu* NewMenu(std::string name)
    {
        MenuItem *photoItem = new MenuItem{" ", placeholder};

        myArray<MenuItem*> items{
            photoItem,
        };

        GalMenu *menu = new GalMenu{name, items, GalMenu::MenuType::gallery};
        menu->remove(0);
        PointerItem<GalMenu> *additem = new PointerItem{"Add Album", add, menu};
        PointerItem<GalMenu> *removeitem = new PointerItem{"Delete Album", gal::remove, menu};
        PointerItem<GalMenu> *sortitem = new PointerItem{"Sort Gallery", gal::sort, menu};
        PointerItem<GalMenu> *filteritem = new PointerItem{"Filter Gallery", gal::filter, menu};
        PointerItem<GalMenu> *edititem = new PointerItem{"Edit Album", gal::edit, menu};

        menu->add(*additem);
        menu->add(*removeitem);
        menu->add(*sortitem);
        menu->add(*filteritem);
        menu->add(*edititem);

        return menu;
    }

    GalMenu* NewMenu(std::string name, Photo &item)
    {
        PointerItem<Photo> *photoItem = new PointerItem{item.name(), gal::view, &item};

        myArray<MenuItem*> items{
            photoItem,
        };

        GalMenu *menu = new GalMenu{name, items, GalMenu::MenuType::album};
        PointerItem<GalMenu> *additem = new PointerItem{"Add Photo", gal::add, menu};
        PointerItem<GalMenu> *removeitem = new PointerItem{"Delete Photo", gal::remove, menu};
        PointerItem<GalMenu> *sortitem = new PointerItem{"Sort Album", gal::sort, menu};
        PointerItem<GalMenu> *filteritem = new PointerItem{"Filter Album", gal::filter, menu};
        PointerItem<GalMenu> *edititem = new PointerItem{"Edit Photo", gal::edit, menu};

        menu->addOption(*additem);
        menu->addOption(*removeitem);
        menu->addOption(*sortitem);
        menu->addOption(*filteritem);
        menu->addOption(*edititem);

        return menu;
    }

    void AddItem(GalMenu &item, GalMenu &menu)
    {
        PointerItem<GalMenu> *MItem = new PointerItem{item.name(), gal::start, &item};
        menu.add(*MItem);
    }

    void AddItem(Photo &item, GalMenu &menu)
    {
        PointerItem<Photo> *MItem = new PointerItem{item.name(), gal::view, &item};
        menu.add(*MItem);
    }

    GalMenu* CreateAuthScreen(GalMenu &menu)
    {
        PointerItem<GalMenu> *log = new PointerItem{"Login", login, &menu};
        MenuItem *pas = new MenuItem{"Register", reg};

        myArray<MenuItem*> MItems{
            log,
            pas
        };

        GalMenu *authScreen = new GalMenu{"Authentification", MItems, GalMenu::MenuType::auth};
        return authScreen;
    }
}

#endif // GALMENUMANAGER_H
