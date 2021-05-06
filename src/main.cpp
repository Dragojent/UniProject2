#include <iostream>
#include <galMenu.h>
#include <galUI.h>
#include <menuItem.h>
#include <galPhoto.h>

int dis(gal::Photo photo)
{
    std::cout << photo.content << std::endl;
    system("pause");
    return 0;
}

int users(gal::Photo photo)
{
    for (auto user : photo.users)
        std::cout << user << std::endl;
    system("pause");
    return 0;
}

int main()
{
    gal::Photo photo{"photo1", "__~+~__", {1, 2, 3}};
    gal::menuItem<gal::Photo> it{"Photo1", dis, photo},
                              it1{"photo1: users", users, photo};
    myArray<gal::menuItem<gal::Photo>*> arr{
        &it,
        &it,
        &it1,
        &it1,
        &it
    };
    gal::SubMenu menu{"menu", arr};

    gal::start(menu);

    return 0;
}