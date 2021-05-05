#include <iostream>
#include <galMenu.h>
#include <galUI.h>
#include <menuItem.h>

int test1()
{
    std::cout << "1" << std::endl;
    return 1;
}

int test2()
{
    std::cout << "2" << std::endl;
    return 2;
}

int test3()
{
    std::cout << "3" << std::endl;
    return 3;
}

int main()
{
    gal::menuItem
        item1{"one", test1},
        item2{"two", test2},
        item3{"two", test2},
        item4{"two", test2},
        item5{"two", test2},
        item6{"two", test2},
        item7{"two", test2},
        item8{"two", test2},
        item9{"two", test2},
        item10{"three", test3};

    myArray<gal::menuItem*> arr{
        &item1,
        &item2,
        &item3,
        &item4,
        &item5,
        &item6,
        &item7,
        &item8,
        &item9,
        &item10
    };
    gal::SubMenu subMenu("menu", arr);
    // gal::Menu menu("menu", {subMenu, subMenu, subMenu}, {"subMenu1", "subMenu2", "subMenu3"});

    gal::start(subMenu);
    
    return 0;
}