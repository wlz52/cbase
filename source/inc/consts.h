//
// Class for the constants.
//
#ifndef CBASE_CONSTS_H
#define CBASE_CONSTS_H

#include <string>
#include <algorithm>

namespace cbase
{
    class Consts final
    {
    public:

        // Epsilon, used for double comparison.
        constexpr static double kEps = 0.000000001;

        // Path separator.
#ifdef WINDOWS
        constexpr static char kPathSeparator = '\\';
#else
        constexpr static char kPathSeparator = '/';
#endif
    };
}

#endif
