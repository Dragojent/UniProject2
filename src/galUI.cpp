#include <galUI.h>

void gal::display(SubMenu &menu)
{
    unsigned int pos = 0;
    std::cout << menu.name() << std::endl;
    for (auto item : menu.items())
    {
        std::wcout << "-";
        if (pos == menu.selected())
            std::cout << "->";
        std::cout << item->name << std::endl;
        pos++;
    }
}

int gal::start(SubMenu &menu)
{
    system("cls");
    gal::display(menu);
    bool running = true;
    char input = getch();

    while (running)
    {
        switch (input)
        {
            case 'w':
                menu--;
                break;
            
            case 's':
                menu++;
                break;
            
            case ' ':
                system("cls");
                menu.run();
                break;

            case 27:
                running = false;
                break;

            default:
                break;
        }
        system("cls");
        gal::display(menu);
        input = getch();
    }
    return 1;
}
