//
// Class for the global definitions.
//
#ifndef CBASE_GLOBAL_H
#define CBASE_GLOBAL_H

// Platform support.
#define CB_WINDOWS // CB_LINUX

// Tags make the code more clearer.
#if (defined CB_IN) || (defined CB_OUT) || (defined CB_INOUT)
static_assert(false,
    "the parameter store attribute tags 'CB_IN/CB_OUT/CB_INOUT' have been used by the other lib");
#endif

#define CB_IN
#define CB_OUT
#define CB_INOUT

#if (defined CB_INTERNAL)
static_assert(false, "the tag 'CB_INTERNAL' has been used by the other lib");
#endif

#define CB_INTERNAL

// Memory helpers.
#ifndef CB_DEL
#define CB_DEL(p) { if (p){delete(p);  (p)=nullptr;} }
#endif

#ifndef CB_FREE
#define CB_FREE(p) { if (p){free(p);  (p)=nullptr;} }
#endif

#ifndef CB_DEL_ARRAY
#define CB_DEL_ARRAY(p) { if (p){delete[] (p);  (p)=nullptr;} }
#endif

// Class helpers.
#ifndef CB_DISABLE_COPY_ASSIGN
#define CB_DISABLE_COPY_ASSIGN(Type) \
Type(const Type&) = delete;  \
Type& operator=(const Type&) = delete
#endif

#ifndef CB_DISABLE_COPY_ASSIGN_MOVE
#define CB_DISABLE_COPY_ASSIGN_MOVE(Type) \
  Type(const Type&) = delete; \
  void operator=(const Type&) = delete; \
  Type(Type&&) = delete; \
  void operator=(Type&&) = delete
#endif

#endif
