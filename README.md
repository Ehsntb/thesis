===========================================
LightIoT Secure Communication Simulation
===========================================

Author: [Your Name]
Project: Master's Thesis - Secure & Scalable Medical IoT Communication
Simulator: OMNeT++ 6.1
Last Updated: May 2025

-------------------------------------------
Overview
-------------------------------------------
This simulation implements the "LightIoT" protocol, a lightweight and secure authentication mechanism for energy-constrained IoT networks in medical environments. The system evaluates secure communication under different scenarios including secure mode, no-security baseline, and replay attack.

-------------------------------------------
Project Structure
-------------------------------------------
.
├── src/                      # All C++ source files (SensorNode, GatewayNode, etc.)
├── ned/                      # Network topology file (LightIoTNetwork.ned)
├── configs/                  # .ini configuration files for each scenario
├── results/                  # CSV and scalar output files
├── logs/                     # Simulation logs for each scenario
├── plots/                    # PNG/PDF graphs generated from analysis
├── omnetpp.ini               # Default configuration file (redirects to configs/)
├── Makefile / run.sh         # Build & run automation (optional)
└── README.txt                # This file

-------------------------------------------
Key Simulation Files
-------------------------------------------
- SensorNode.cc         : Simulates secure data transmission with HMAC
- GatewayNode.cc        : Verifies HMAC, detects replay/MITM, forwards data
- CloudServer.cc        : Measures end-to-end delay
- FakeNode.cc           : Simulates replay attack for evaluation
- LightIoTMessage_m.h   : Custom packet format for LightIoT
- LightIoTNetwork.ned   : Defines topology of Sensor → Gateway → Cloud

-------------------------------------------
How to Run
-------------------------------------------
1. Make sure OMNeT++ 6.1 is properly installed and configured.

2. Build the project:
   $ opp_makemake -f --deep
   $ make

3. Run simulation (choose one of the configs):
   $ ./LightIoTSimulation -u Cmdenv -c SecureMode
   $ ./LightIoTSimulation -u Cmdenv -c NoSecurityMode
   $ ./LightIoTSimulation -u Cmdenv -c ReplayAttackMode

4. To visualize:
   $ NetAnim lightiot.xml

5. To analyze results:
   Open CSV/LOG files in `results/` and `logs/` folders.
   Use `energy_delay.csv` and `stats_summary.csv` to plot charts.

-------------------------------------------
Scenarios Included
-------------------------------------------
- Secure Communication
- No-Security Baseline
- Replay Attack (FakeNode)
- Scalability with 5, 20, 50 Sensor Nodes

-------------------------------------------
Credits
-------------------------------------------
Based on the paper: "LightIoT: Lightweight and Secure Communication for Energy-Efficient IoT in Health Informatics"  
Extended with scalability analysis, dynamic attack simulation, and delay-energy performance metrics.

-------------------------------------------
Contact
-------------------------------------------
[Your Full Name]  
MSc Software Engineering, [Your University]  
[Your Email]





===========================================
شبیه‌سازی پروتکل LightIoT در محیط OMNeT++
===========================================

نام پروژه: پایان‌نامه کارشناسی ارشد - مکانیزم امن و مقیاس‌پذیر ارتباطی در IoT پزشکی  
پدیدآورنده: [نام شما]  
شبیه‌ساز: OMNeT++ نسخه 6.1  
تاریخ آخرین بروزرسانی: اردیبهشت 1404 / می 2025

-------------------------------------------
معرفی پروژه
-------------------------------------------
پروژه حاضر پیاده‌سازی دقیق پروتکل LightIoT است که یک الگوریتم سبک و امن برای تأیید هویت در شبکه‌های اینترنت اشیای پزشکی می‌باشد. هدف آن کاهش مصرف انرژی، مقابله با حملات امنیتی، و حفظ کارایی در شرایط مقیاس‌پذیر است. این سیستم تحت سه سناریو اصلی شبیه‌سازی شده: ارتباط امن، بدون امنیت پایه، و حمله بازپخش.

-------------------------------------------
ساختار پروژه
-------------------------------------------
.
├── src/                 # فایل‌های کدنویسی به زبان ++C (نودها، پیام، حمله و ...)
├── ned/                 # تعریف توپولوژی شبکه (LightIoTNetwork.ned)
├── configs/             # فایل‌های تنظیمات (.ini) برای سناریوهای مختلف
├── results/             # خروجی‌های عددی، CSV و فایل‌های .sca/.vec
├── logs/                # لاگ‌های دقیق از اجرای سناریوها
├── plots/               # نمودارهای تحلیلی از انرژی، تأخیر و امنیت
├── omnetpp.ini          # فایل پیکربندی اصلی (ارجاع به configs/)
├── README.txt           # فایل راهنما (همین فایل)

-------------------------------------------
فایل‌های کلیدی
-------------------------------------------
- SensorNode.cc         : ارسال داده امن با HMAC و ثبت انرژی
- GatewayNode.cc        : اعتبارسنجی، شناسایی حمله و فوروارد داده
- CloudServer.cc        : اندازه‌گیری تأخیر End-to-End
- FakeNode.cc           : تولید حمله بازپخش (Replay) یا MITM
- LightIoTMessage_m.h   : فرمت پیام سفارشی‌شده
- LightIoTNetwork.ned   : توپولوژی شامل سنسورها، گیت‌وی و سرور

-------------------------------------------
نحوه اجرا
-------------------------------------------
1. اطمینان از نصب صحیح OMNeT++ نسخه 6.1

2. ساخت پروژه:
   $ opp_makemake -f --deep
   $ make

3. اجرای شبیه‌سازی (برای هر سناریو):
   $ ./LightIoTSimulation -u Cmdenv -c SecureMode
   $ ./LightIoTSimulation -u Cmdenv -c NoSecurityMode
   $ ./LightIoTSimulation -u Cmdenv -c ReplayAttackMode

4. مشاهده گرافیکی با NetAnim:
   $ NetAnim lightiot.xml

5. مشاهده نتایج:
   فایل‌های CSV و LOG داخل پوشه‌های `results/` و `logs/` قابل بررسی هستند.

-------------------------------------------
سناریوهای پیاده‌سازی‌شده
-------------------------------------------
- ارتباط امن با رمزنگاری HMAC
- حالت بدون امنیت برای مقایسه
- شبیه‌سازی حمله Replay توسط نود جعلی
- بررسی مقیاس‌پذیری در 5، 20 و 50 نود

-------------------------------------------
مراجع
-------------------------------------------
بر اساس مقاله:  
"LightIoT: Lightweight and Secure Communication for Energy-Efficient IoT in Health Informatics"  
به همراه توسعه اختصاصی در زمینه مقیاس‌پذیری، تحلیل مصرف انرژی، و مقاومت در برابر حملات امنیتی

-------------------------------------------
اطلاعات تماس
-------------------------------------------
[نام کامل شما]  
دانشجوی کارشناسی ارشد مهندسی نرم‌افزار، [نام دانشگاه]  
ایمیل: [آدرس ایمیل شما]