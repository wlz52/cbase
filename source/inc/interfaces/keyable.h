/***
 * The class need to be used as keys MUST inherit this interface.
 */
#ifndef CBASE_INTERFACES_KEYABLE_H
#define CBASE_INTERFACES_KEYABLE_H

#include <algorithm>
#include "equatable.h"

namespace cbase
{
    namespace interfaces
    {
        template <class T>
        class Keyable : public Comparable<T>
        {
        public:
            virtual ~Keyable()
            {
            }

            /**
             *  Calculates and Gets the hash code.
             */
            virtual std::size_t hash() const = 0;
        };
    }
}

#endif
