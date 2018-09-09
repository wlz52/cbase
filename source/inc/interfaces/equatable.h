/***
 * The interface of the equatable class
 */
#ifndef CBASE_INTERFACES_EQUATABLE_H
#define CBASE_INTERFACES_EQUATABLE_H

namespace cbase
{
    namespace interfaces
    {
        template <class T>
        class Equatable
        {
        public:
            virtual ~Equatable()
            {
            }

            virtual bool equals(const T &other) const = 0;

            virtual bool operator==(const T &other) const
            {
                return equals(other);
            }
        };
    }
}

#endif
