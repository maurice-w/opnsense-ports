--- src/3rdparty/chromium/components/password_manager/core/browser/stub_password_manager_client.cc.orig	2024-10-22 08:31:56 UTC
+++ src/3rdparty/chromium/components/password_manager/core/browser/stub_password_manager_client.cc
@@ -187,7 +187,7 @@ version_info::Channel StubPasswordManagerClient::GetCh
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 void StubPasswordManagerClient::OpenPasswordDetailsBubble(
     const password_manager::PasswordForm& form) {}
 
