#ifndef GALPHOTOMANIP_H
#define GALPHOTOMANIP_H

#include <galPhoto.h>
#include <galUI.h>

namespace gal
{
    int view(photo &photo)
    {
        std::cout << photo.name << "\n" << std::endl;
        std::cout << photo.content << "\n" << std::endl;
        std::cout << "Tagged users: ";
        for (auto user : photo.users)
            std::cout << user << ", ";
        std::cout << std::endl;
        system("pause");
        return 0;
    }

    int edit(GalMenu &menu)
    {
        gal::display(menu);
        std::cout << "Edit which photo\n:";
        unsigned int pos;
        std::cin >> pos;
        menu.edit(pos);
        return 0;
    }
}

#endif // GALPHOTOMANIP_H
