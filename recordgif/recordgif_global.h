#ifndef RECORDGIF_GLOBAL_H
#define RECORDGIF_GLOBAL_H
#include <QtCore/QtGlobal>

#if defined(RECORDGIF_DLL)
#   if defined(RECORDGIF_LIBRARY)
#       define RECORDGIF_EXPORT Q_DECL_EXPORT
#   else
#       define RECORDGIF_EXPORT Q_DECL_IMPORT
#   endif
#else
#   define RECORDGIF_EXPORT
#endif

#endif // RECORDGIF_GLOBAL_H
