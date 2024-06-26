#include <random>
#include <sstream>
#include <qstring>
#include <qdebug>

#include <iostream>

#ifndef UUID_H
#define UUID_H 1
/* Classe permettant de générer des UUID v4 */
namespace uuid
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dis(0, 15);
    static std::uniform_int_distribution<> dis2(8, 11);

    inline QString generate_uuid_v4()
    {
        std::stringstream ss;
        int i;
        ss << std::hex;
        for (i = 0; i < 8; i++)
        {
            ss << dis(gen);
        };

        return  QString::fromStdString(ss.str());
    }
}
#endif
