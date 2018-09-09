/***
 * The interface of the disposable class
 */
#ifndef CBASE_INTERFACES_DISPOSABLE_H
#define CBASE_INTERFACES_DISPOSABLE_H

namespace cbase
{
    namespace interfaces
    {
        class Disposable
        {
        public:
            virtual ~Disposable()
            {
            }

            virtual void dispose() = 0;
        };
    }
}

#endif
