#ifndef APP_GLOBAL_H
#define APP_GLOBAL_H
#include <QtCore/QtGlobal>

#if defined(APP_DLL)
#   if defined(APP_LIBRARY)
#       define APP_EXPORT Q_DECL_EXPORT
#   else
#       define APP_EXPORT Q_DECL_IMPORT
#   endif
#else
#   define APP_EXPORT
#endif
#endif // APP_GLOBAL_H
