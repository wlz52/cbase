/***
 * The interface of the cloneable class
 */
#ifndef CBASE_INTERFACES_CLONEABLE_H
#define CBASE_INTERFACES_CLONEABLE_H

namespace cbase
{
    namespace interfaces
    {
        template<class T>
        class Cloneable
        {
        public:
            virtual T clone() = 0;
            virtual ~Cloneable()
            {
            }
        };
    }
}

#endif
