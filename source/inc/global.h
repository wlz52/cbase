//
// Class for the global definitions.
//
#ifndef CBASE_GLOBAL_H
#define CBASE_GLOBAL_H

#include "consts.h"

// Platform support.
#define WINDOWS // LINUX

// User-defined types.
#ifndef byte
#define byte uint8_t
#endif

// Tags make the code more clearer.
#if (defined IN) || (defined OUT) || (defined INOUT)
static_assert(false,
    "the parameter store attribute tags 'IN/OUT/INOUT' have been used by the other lib");
#endif

#define IN
#define OUT
#define INOUT

#if (defined INTERNAL)
static_assert(false, "the tag 'INTERNAL' has been used by the other lib");
#endif

#define INTERNAL

// Basic functions.
INTERNAL class GlobalUtils
{
    static void Rtrim(INOUT std::string &s, IN const char *chs, IN int n)
    {
        int len = s.length();
        int end = len - 1;
        int start = 0;

        for (end = len - 1; end >= start; end--)
        {
            int i = 0;
            char ch = s[end];
            for (i = 0; i < n; i++)
            {
                if (chs[i] == ch)
                {
                    break;
                }
            }
            if (i == n)
            {
                break;
            }
        }

        int len_after_trim = end - start + 1;
        if (len_after_trim == len)
        {
            return;
        }

        if (len_after_trim == 0)
        {
            s.resize(0);
            return;
        }

        s.resize(len_after_trim);
    }

public:

    // For files name of the file is returned,
    // for directories the last directory in hierarchy is returned if possible,
    // otherwise the fully qualified name s returned.
    static std::string GetPathName(IN const std::string &path)
    {
        std::string mutable_path = path;

        static constexpr char kSeps[] = { cbase::Consts::kPathSeparator ,' ','\t','\r','\n' };
        static constexpr int kSepSize = 5;

        Rtrim(mutable_path, kSeps, kSepSize);

        auto pos = mutable_path.rfind(cbase::Consts::kPathSeparator);
        if (pos == mutable_path.npos)
        {
            return path;
        }

        return mutable_path.substr(pos + 1);
    }
};

// Memory helpers.
#ifndef DEL_S
#define DEL_S(p) { if (p){delete(p);  (p)=nullptr;} }
#endif

#ifndef FREE_S
#define FREE_S(p) { if (p){free(p);  (p)=nullptr;} }
#endif

#ifndef DEL_ARRAY_S
#define DEL_ARRAY_S(p) { if (p){delete[] (p);  (p)=nullptr;} }
#endif

// Class helpers.
#ifndef DISABLE_COPY_ASSIGN
#define DISABLE_COPY_ASSIGN(Type) \
Type(const Type&) = delete;  \
Type& operator=(const Type&) = delete
#endif

#ifndef DISABLE_COPY_ASSIGN_MOVE
#define DISABLE_COPY_ASSIGN_MOVE(Type) \
  Type(const Type&) = delete; \
  void operator=(const Type&) = delete; \
  Type(Type&&) = delete; \
  void operator=(Type&&) = delete
#endif

// Log helpers.
#define MSG_WITH_CODE_POS(file,line,msg) "[" file","#line"]" msg

#define MSG_WITH_SHORT_CODE_POS(file,line,msg)\
    MSG_WITH_CODE_POS(GlobalUtils::GetPathName(file),line,msg);

#endif
