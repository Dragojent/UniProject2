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


int main()
{
    Photo ph{"photo1", "__~+~__", {1, 2, 3}};
    Photo pha{"abPhoto", "__~+~__", {1, 2, 3}};
    Photo phb{"babPhoto", "__~+~__", {1, 2, 3}};

    GalMenu *album = NewMenu("Album_1", ph);
    AddItem(phb, *album);
    AddItem(pha, *album);
    GalMenu *gallery = NewMenu("Gallery");
    AddItem(*album, *gallery);
    GalMenu *authScreen = CreateAuthScreen(*gallery);

    gal::start(*authScreen);

    return 0;
}