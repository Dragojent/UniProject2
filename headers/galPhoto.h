#ifndef GALPHOTO_H
#define GALPHOTO_H

#include <string>
#include <myArray.h>

namespace gal
{
    class Photo
    {
    public:
        typedef std::string pic;
        typedef unsigned long userID;

        Photo();
        Photo(std::string name, pic content, myArray<userID> users);
        Photo(Photo& photo);

        std::string name() const;
        pic picture() const;
        myArray<userID> users() const;

        void setName(std::string name);
        void setPicture(pic picture);
        void setUsers(myArray<userID> users);
        int edit();

    private:
        std::string m_name;
        pic m_content;
        myArray<userID> m_users;
    };

    Photo::Photo() :
        m_name("N/A"), m_content("N/A"), m_users({}) {}

    Photo::Photo(std::string name, pic content, myArray<userID> users) :
        m_name(name), m_content(content), m_users(users) {}

    Photo::Photo(Photo& photo) :
        m_name(photo.name()), m_content(photo.picture()), m_users(photo.users()) {}

    std::string Photo::name() const
    { return m_name; }

    Photo::pic Photo::picture() const
    { return m_content; }

    myArray<Photo::userID> Photo::users() const
    { return m_users; }

    void Photo::setName(std::string name)
    { m_name = name; }

    void Photo::setPicture(pic picture)
    { m_content = picture; }

    void Photo::setUsers(myArray<userID> users)
    { m_users = users; }

    int Photo::edit()
    {
        std::cout << m_name << std::endl;
        std::cout << m_content << std::endl;
        for (auto user : m_users)
            std::cout << user;
        std::cout << std::endl;
        std::cout << "Enter new photo" << std::endl;
        std::string input{};
        std::cout << "Name: ";
        std::cin >> input;
        setName(input);
        std::cout << "Image: ";
        std::cin >> input;
        setPicture(input);
    }
}

#endif //GALPHOTO_H