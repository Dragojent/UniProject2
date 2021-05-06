#include <iostream>
#include <galUI.h>
#include <menuItem.h>
#include <galPhoto.h>
#include <galManip.h>

int dis(gal::Photo &photo)
{
    std::cout << photo.content << std::endl;
    system("pause");
    return 0;
}

int users(gal::Photo &photo)
{
    for (auto user : photo.users)
        std::cout << user << std::endl;
    system("pause");
    return 0;
}

using gal::Photo;
using gal::menuItem;
using gal::SubMenu;
int main()
{
    Photo photo{"photo1", "__~+~__", {1, 2, 3}};
    menuItem<Photo> photoIt{"Photo1", dis, &photo},
              photoIt1{"photo1: users", users, &photo};
    myArray<menuItem<Photo>*> photoItems{
        &photoIt,
        &photoIt,
        &photoIt1,
        &photoIt1,
        &photoIt
    };
    SubMenu<Photo> menu{"menu", photoItems};

    menuItem<SubMenu<Photo>> menuPhotoIt{"sub Menu", gal::start<Photo>, &menu};

    myArray<menuItem<SubMenu<Photo>>*> menuPhotoItems{
        &menuPhotoIt,
        &menuPhotoIt,
        &menuPhotoIt,
        &menuPhotoIt,
        &menuPhotoIt,
        &menuPhotoIt
    };

    SubMenu<SubMenu<Photo>> mainMenu{"Main Menu", menuPhotoItems};

    gal::start(mainMenu);

    return 0;
}