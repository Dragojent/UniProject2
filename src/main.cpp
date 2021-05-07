#include <iostream>
#include <galUI.h>
#include <menuItem.h>
#include <galPhoto.h>
#include <galManip.h>

int dis(gal::photo &photo)
{
    std::cout << photo.content << std::endl;
    system("pause");
    return 0;
}

int users(gal::photo &photo)
{
    for (auto user : photo.users)
        std::cout << user << std::endl;
    system("pause");
    return 0;
}

using gal::photo;
using gal::MenuItem;
using gal::GalMenu;

int main()
{
    photo photo{"photo1", "__~+~__", {1, 2, 3}};
    MenuItem photoIt{"b", dis, &photo},
                    photoIt1{"a", users, &photo},
                    photoIt2{"c", users, &photo};

    myArray photoItems{
        &photoIt,
        &photoIt1,
        &photoIt2
    };
    GalMenu menu{"menu", photoItems};

    MenuItem menuPhotoIt{"sort", gal::sort, &menu};
    MenuItem menuPhotoItStart{"sub Menu", gal::start, &menu};
    MenuItem menuPhotoItAdd{"add", gal::add, &menu};
    MenuItem menuPhotoItDel{"delete", gal::remove, &menu};
    MenuItem menuPhotoItFil{"filter", gal::filter, &menu};

    myArray menuPhotoItems{
        &menuPhotoIt,
        &menuPhotoItStart,
        &menuPhotoItAdd,
        &menuPhotoItDel,
        &menuPhotoItFil
    };

    GalMenu mainMenu{"Main Menu", menuPhotoItems};

    MenuItem MMitemStart{"another menu", gal::start, &mainMenu};
    MenuItem MMitemDel{"delete item", gal::remove, &mainMenu};
    myArray MMitems{
        &MMitemStart,
        &MMitemDel
    };
    GalMenu MM{"MM", MMitems};

    gal::start(MM);

    return 0;
}