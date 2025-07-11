PORTNAME=	gtk
PORTVERSION=	2.24.33		# sync with graphics/gtk-update-icon-cache
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	2
DISTNAME=	gtk+-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Gimp Toolkit for X11 GUI (previous stable version)
WWW=		https://www.gtk.org/

LICENSE=	LGPL20

USES=		cpe tar:xz

PORTSCOUT=	limitw:0,even

CPE_VENDOR=	gnome

RUN_DEPENDS+=	update-mime-database:misc/shared-mime-info \
		${LOCALBASE}/share/icons/hicolor/index.theme:misc/hicolor-icon-theme

USES+=		gettext gmake gnome libtool localbase:ldflags pathfix perl5 \
		pkgconfig python:run shebangfix xorg
SHEBANG_FILES=	gtk/gtk-builder-convert
GNU_CONFIGURE=	yes
USE_GNOME=	atk pango gdkpixbuf introspection:build \
		gtk-update-icon-cache
USE_LDCONFIG=	yes
USE_PERL5=	build
USE_XORG=	xext xrender x11 xinerama xi xrandr xcursor xfixes xdamage \
		xcomposite
CONFIGURE_ARGS=	--with-xinput=yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	CUPS DEBUG
OPTIONS_DEFAULT=CUPS
OPTIONS_SUB=	yes

CUPS_LIB_DEPENDS=	libcups.so:print/cups
CUPS_CONFIGURE_ON=	--enable-cups=auto
CUPS_CONFIGURE_OFF=	--disable-cups
DEBUG_CONFIGURE_ON=	--enable-debug=yes

PLIST_SUB+=	LIBGAILVER=18.0.1 LIBGVER=0.2400.33

post-patch:
	@${REINPLACE_CMD} -e 's|[{]libdir[}]/locale|{datadir}/locale|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|file,cups|file,cups,lpr|' \
		${WRKSRC}/gtk/Makefile.in

pre-configure:
# .if !exists() evaluates too early before cairo has a chance to be installed
	@if ! pkg-config --exists cairo-xlib; then \
		${ECHO_MSG} "${PKGNAME}: Needs cairo with X11 support enabled."; \
		${FALSE}; \
	fi

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/gtk-2.0/modules
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/gtk-2.0/${GTK2_VERSION}/engines
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/gtk-2.0/${GTK2_VERSION}/loaders
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/gtk-2.0/${GTK2_VERSION}/modules

.include <bsd.port.mk>
