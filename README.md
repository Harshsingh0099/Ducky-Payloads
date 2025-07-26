🔐 Digispark Rubber Ducky – USB HID Attack Toolkit
This project demonstrates how to convert a Digispark ATtiny85 microcontroller into a USB Rubber Ducky capable of automating keyboard payloads on Windows machines. The payloads are written in Arduino-compatible code and mimic keystrokes to perform information gathering, privilege escalation, and stealthy data exfiltration.

⚠️ Educational Use Only
This tool is designed for ethical hacking, security awareness, and learning purposes only. Do not deploy on devices you do not own or have explicit permission to test.

📦 Features
Executes PowerShell commands on plugin
Bypasses UAC for privilege escalation
Extracts:
Wi-Fi passwords
System information

Saves results to:
Victim’s Desktop (default)
OR to plugged-in pendrive (stealth mode)
Fully automated – just plug and attack

🧰 Requirements
✅ Digispark ATtiny85 board (USB-A)
✅ Arduino IDE with Digispark board support
✅ Windows machine for testing
✅ Optional: USB pendrive (for stealth mode)
✅ Optional: Raspberry Pi Pico (for future upgrades)

🛠️ Setup Guide
1. 🔌 Install Digispark Support in Arduino IDE
Go to:
Arduino IDE
File → Preferences → Additional Board Manager URLs:
Paste:
https://raw.githubusercontent.com/digistump/arduino-boards-index/master/package_digistump_index.json
Then go to:
Tools → Board → Boards Manager → Search for "Digistump AVR Boards" → Install

2. 🧠 Clone This Repo
git clone https://github.com/yourusername/rubberducky-digispark.git
cd rubberducky-digispark

3. 📁 Code Overview
🔹 payload_wifi and sysinfo.ino
Saves WiFi + system info to the Desktop of the victim
Simulates pressing Ctrl + Esc, searches for powershell, right-clicks → "Run as Administrator", and hits Alt+Y to approve UAC
🔹 payload_Phone carck.ino
helps crack android phone pin type password upto length 5


4. 🧪 Upload to Digispark
In Arduino IDE:
Open one of the .ino payloads
Set Board to: Digispark (Default - 16.5mhz)
Click Upload → Now plug in your Digispark when prompted

🧪 How It Works
Digispark emulates a keyboard
Launches PowerShell silently
Executes custom script:
Gets all stored WiFi passwords using netsh wlan show profiles
Gets system info using systeminfo
Saves or exfiltrates data

Optionally, you can modify payloads to:
Download a backdoor
Setup persistence
Upload via webhook

📂 Sample PowerShell Dump

SSID: CollegeWiFi
Key: mysecurepassword123

Hostname: VICTIM-PC
OS Name: Microsoft Windows 11 Pro
BIOS Version: American Megatrends Inc.
...

💡 Ideas for Expansion
Add Invoke-WebRequest to upload to webhook or Discord bot
Log keystrokes using PowerShell (careful: detection risk!)
Use Start-Process with encoded payloads
Switch to Raspberry Pi Pico for more control

🚨 Disclaimer
This tool is meant for educational and authorized penetration testing ONLY.
Do not use this on systems you do not own or have explicit permission to test.

🤝 Contribution
Pull requests are welcome!
If you have ideas like persistence modules or cross-platform support, feel free to contribute.

🔥 Built By
Harsh Singh
🛡️ Cybersecurity Enthusiast | Bug Bounty Hunter | InfoSec Student
