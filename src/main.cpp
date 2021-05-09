#include <iostream>
#include <galUI.h>
#include <menuItem.h>
#include <galPhoto.h>
#include <galManip.h>
#include <galMIPhoto.h>
#include <galPhotoManip.h>
#include <galUser.h>

using gal::photo;
using gal::MenuItem;
using gal::GalMenu;
using gal::MIPhoto;
using gal::User;


void AddPhoto(std::string name, std::string content, myArray<User*> users, GalMenu<photo> &menu)
{
    photo *tmp = new photo{name, content, {1, 2, 3}};
    MenuItem<photo> *tmpItem = new MenuItem{name, gal::view, tmp};
    menu.add(*tmpItem);
}

GalMenu<photo> newAlbum(std::string name, photo &ph)
{
    MenuItem<photo> *photoIt = new MenuItem{ph.name, gal::view, &ph};
    myArray<MenuItem<photo>*> *photoItems = new myArray{photoIt};
    GalMenu menu{name, *photoItems};
    return menu;
}

GalMenu<GalMenu<photo>> newGallery(std::string name, GalMenu<photo> &album)
{
    MenuItem<GalMenu<photo>> *galItem = new MenuItem{album.name(), gal::start, &album};
    myArray<MenuItem<GalMenu<photo>>*> *galItems = new myArray{galItem};
    GalMenu gallery{name, *galItems};
    return gallery;
}

void AddAlbum(GalMenu<photo> &album, GalMenu<GalMenu<photo>> &gallery)
{
    MenuItem<GalMenu<photo>> *albItem = new MenuItem{album.name(), gal::start, &album};
    gallery.add(*albItem);
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
    GalMenu album = newAlbum("Album", ph);
    AddPhoto("photo2", "=_=_=", users, album);
    AddPhoto("photo3", "=~+~=", users, album);
    AddPhoto("photo4", "=+-+=", users, album);
    AddPhoto("photo5", "=-=-=", users, album);
    AddPhoto("photo6", "=~=~=", users, album);

    GalMenu albumTwo = newAlbum("Album2", ph);
    AddPhoto("kfd", "=~=~=", users, albumTwo);

    GalMenu gallery = newGallery("gallery", album);

    AddAlbum(albumTwo, gallery);

    gal::start(gallery);

    return 0;
}