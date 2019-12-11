#ifndef DEFTOOLS_GOLBAL_H
#define DEFTOOLS_GOLBAL_H

#include <QtCore/QtGlobal>

#if defined(DFTOOLS_DLL)
#   if defined(DEFTOOLS_LIBRARY)
#       define DEFTOOLS_EXPORT Q_DECL_EXPORT
#   else
#       define DEFTOOLS_EXPORT Q_DECL_IMPORT
#   endif
#else
#   define DEFTOOLS_EXPORT
#endif

#endif // DEFTOOLS_GOLBAL_H
