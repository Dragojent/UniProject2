#include <iostream>
#include <galUI.h>
#include <menuItem.h>
#include <galPhoto.h>
#include <galManip.h>
#include <PointerItem.h>
#include <galPhotoManip.h>
#include <galUser.h>

using gal::photo;
using gal::MenuItem;
using gal::GalMenu;
using gal::PointerItem;
using gal::User;

GalMenu* NewAlbum(photo &ph)
{
    PointerItem<photo> *photoItem = new PointerItem{ph.name, gal::view, &ph};

    myArray<MenuItem*> items{
        photoItem,
    };

    GalMenu *menu = new GalMenu{"menu", items};
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

template <class T>
void AddItem(T &item, GalMenu &menu)
{
    PointerItem<T> *phItem = new PointerItem{item.name, gal::view, &item};
    menu.add(*phItem);
}

int Auth()
{
    return 0;
}

int main()
{
    User user1{"user1", User::AccessLevel::user},
         user2{"user2", User::AccessLevel::user};

    myArray users{
        &user1,
        &user2
    };

    photo ph{"photo1", "__~+~__", {1, 2, 3}};
    photo pha{"abPhoto", "__~+~__", {1, 2, 3}};
    photo phb{"babPhoto", "__~+~__", {1, 2, 3}};

    GalMenu *menu = NewAlbum(ph);
    AddItem(phb, *menu);
    AddItem(pha, *menu);

    gal::start(*menu);

    return 0;
}