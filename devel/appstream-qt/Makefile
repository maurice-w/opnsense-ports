PORTREVISION=	0
PKGNAMESUFFIX=	Qt${FLAVOR:S/qt//}

COMMENT?=	Qt bindings to AppStream

LIB_DEPENDS=	libappstream.so:devel/appstream

FLAVORS=	qt6 qt5
FLAVOR?=	qt6

USES=		qt:${FLAVOR:S/qt//}

_USE_QT_qt5=	core buildtools:build qmake:build testlib:build
_USE_QT_qt6=	base
USE_QT=		${_USE_QT_${FLAVOR}}

_MESON_ARGS_qt5=	-Dqt-versions='5'
_MESON_ARGS_qt6=	-Dqt-versions='6'
MESON_ARGS=		-Dqt=true ${_MESON_ARGS_${FLAVOR}}

_QT_VER_SUFFIX_qt5=	5
_QT_VER_SUFFIX_qt6=	#
PLIST_SUB=	QT_VER_SUFFIX=${_QT_VER_SUFFIX_${FLAVOR}}

MASTERDIR=	${.CURDIR}/../appstream
PLIST=		${.CURDIR}/pkg-plist

post-install:
	# remove files belonging to the master port
	${XARGS} -L 1 -I % ${RM} -rf ${STAGEDIR}${PREFIX}/% < ${MASTERDIR}/pkg-plist
	${FIND} ${STAGEDIR}${PREFIX} -empty -delete
	${RM} -rf ${STAGEDIR}${PREFIX}/etc ${STAGEDIR}${PREFIX}/share/man

.include	"${MASTERDIR}/Makefile"
