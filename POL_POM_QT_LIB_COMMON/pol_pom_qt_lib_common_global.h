#ifndef POL_POM_QT_LIB_COMMON_GLOBAL_H
#define POL_POM_QT_LIB_COMMON_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(POL_POM_QT_LIB_COMMON_LIBRARY)
#  define POL_POM_QT_LIB_COMMONSHARED_EXPORT Q_DECL_EXPORT
#else
#  define POL_POM_QT_LIB_COMMONSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // POL_POM_QT_LIB_COMMON_GLOBAL_H