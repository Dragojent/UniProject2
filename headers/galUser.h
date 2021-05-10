#ifndef GALUSER_H
#define GALUSER_H

#include <string>

namespace gal
{
    class User
    {

        public:
            typedef unsigned int ID_type;
            enum AccessLevel{
                unauthorized = 0,
                user = 1,
                admin = 2
            };

            User();
            User(std::string name, std::string password, std::string login, AccessLevel aL);
            User(User& user);

            std::string name() const;
            AccessLevel accessLevel() const;
            ID_type ID() const;
            std::string password() const;
            std::string login() const;

            User& operator=(const User& user);

        private:
            std::string m_name;
            AccessLevel m_aL;
            ID_type m_ID;
            std::string m_password;
            std::string m_login;
    };

} 


#endif // GALUSER_H
