/***
 * The interface of the comparable class
 */
#ifndef CBASE_INTERFACES_COMPARABLE_H
#define CBASE_INTERFACES_COMPARABLE_H

#include "equatable.h"

namespace cbase
{
    namespace interfaces
    {
        template <class T>
        class Comparable : public Equatable<T>
        {
        public:
            virtual ~Comparable()
            {
            }

            /**
             * Returns 0 if they are equal, -1 if < other and 1 if > other.
             */
            virtual int compare(const T &other) const = 0;

            virtual bool operator<(const T &other) const
            {
                return this->compare(other) < 0;
            }

            virtual bool operator>(const T &other) const
            {
                return this->compare(other) > 0;
            }

            virtual bool operator<=(const T &other) const
            {
                return this->compare(other) <= 0;
            }

            virtual bool operator>=(const T &other) const
            {
                return this->compare(other) >= 0;
            }

            virtual bool equals(const T &other) const override
            {
                return this->compare(other) == 0;
            }

            virtual bool operator !=(const T &other) const
            {
                return !equals(other);
            }
        };
    }
}

#endif
