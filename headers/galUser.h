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
                user = 0,
                admin = 1
            };

            User();
            User(std::string name, AccessLevel aL);

            std::string name() const;
            AccessLevel accessLevel() const;
            ID_type ID() const;

        private:
            std::string m_name;
            AccessLevel m_aL;
            ID_type m_ID;
    };
} 


#endif // GALUSER_H
