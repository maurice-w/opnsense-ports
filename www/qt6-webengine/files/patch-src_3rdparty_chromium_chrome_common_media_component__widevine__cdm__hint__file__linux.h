--- src/3rdparty/chromium/chrome/common/media/component_widevine_cdm_hint_file_linux.h.orig	2024-06-17 12:56:06 UTC
+++ src/3rdparty/chromium/chrome/common/media/component_widevine_cdm_hint_file_linux.h
@@ -17,7 +17,7 @@
 
 // TODO(crbug.com/40118868): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if !(BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
+#if !(BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD))
 #error "This file only applies to desktop Linux and ChromeOS."
 #endif
 
