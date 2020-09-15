---
layout: page
title: Notes
permalink: /notes/
---


### Common Chord progressions

```
I – iV – V7
I – V – vi – IV
I – vi – IV – V
I – V – vi – iii – IV – I – IV – V
I – IV – V – I
I – I – I – I – IV – IV – I – I – V – V – I – I
I – IV – V – IV

ii – IV – V
V – IV – I
vi – IV – I – V
vi – V – IV – III
vi – V – VI – V
ii – I – V6 – bVII
```

### TIL

```
// clang-format on
// clang-format off
```

### My dream job at 2007 (10 years ago)

#### In office:

- [x] salary $3 000 or more
- [ ] big bright office
- [ ] at winter warm and at summer cool
- [x] clean restroom
- [x] no cigarette smoke
- [x] hot water in the sink
- [x] mirror in the restroom
- [ ] sofa
- [x] tea
- [x] trash-bin near by the desktop
- [x] free classes
- [ ] ability to pick your own specification for the computer
- [x] licensed software
- [ ] floating hours

#### WFH

- [x] salary $3,000 or more
- [x] big bright office
- [ ] at winter warm and at summer cool
- [ ] clean restroom
- [x] no cigarette smoke
- [x] hot water in the sink
- [x] mirror in the restroom
- [x] sofa
- [x] tea
- [ ] trash-bin near by the desktop
- [x] free classes
- [x] ability to pick your own specification for the computer
- [x] licensed software
- [ ] floating hours

### My current dream job
- [ ] work on my own ideas
- [ ] be able to drop the project at any time
- [ ] be able to start any project at any time
- [ ] travel (carry with me in the luggage my PC setup with 2 big
      screens and VR setup), have high speed internet while I am traveling
- [x] work from home
- [x] big bright office
- [ ] at winter warm and at summer cool
- [ ] floating hours
- [ ] no planning
- [ ] make technical decisions
- [ ] I want to have a team, and they will do exactly what I asked
      them to do without any questions and complaining
- [x] program in C++
- [x] working on making games
- [ ] be able to stream on Twitch my work

### Play video using VDPAU decoder

```
mplayer -vo vdpau and -vc ffh264vdpau,ffmpeg12vdpau,ffwmv3vdpau,ffvc1vdpau -ao alsa file.mp4
```



### Ideal game engine

- C++ (including scripting on C++)
- Multiplatform (Linux, Mac, iOS, Android)
- Licence (free and I can use the engine for publishing
games on AppStore and Google Play)
- Good tutorials


### How to upload file using linux command tool ftp
```
$ ftp host
Connected to host (10.139.88.123).
220 (vsFTPd 3.0.2)
Name (host:user): user
331 Please specify the password.
Password: password
ftp> cd path
ftp> put localfile remotepath
```

### How to make SSH tunnel

```

      local   ssh connection   remote1       remote2
             o--------------->o
              +------------->+
              ^              v
TCP port [L]o-+              +------------->o TCP port [R]

$ ssh -L L:remote2:R remote1

     local2   local1 ssh connection  remote
                    o------------->o
                     +------------+
                     v            ^
TCP port [L] o<------+            +<-o TCP port [R]
$ ssh -R R:local2:L remote
```

### How to get absolute path
```
$ man realpath
```

```C++
    char *relativePath = "relativePath/file.txt"
    char *absolutePath = realpath(relativePath, NULL);
    if (!absolutePath)
    {
      stc::cerr << "Cannot access " << relativePath << ": No such file or directory";
      return -1;
    }
    // use it
    free(absolutePath);
```

### How to make screenshot in MacOS X

<http://www.imore.com/how-take-screenshot-mac-os-x>
```
Command + Shift + 3 whole screen
Command + Shift + 4 area
```

### How to find current executable's path

```C++
#include <unistd.h>
#ifdef __APPLE__
#include <mach-o/dyld.h>
#endif

#ifndef __APPLE__
std::string getExecutableName()
{
    char buf[MAXPATHLEN];
    ssize_t len;
    if ((len = readlink("/proc/self/exe", buf, sizeof(buf) - 1)) != -1)
        buf[len] = '\0';
    return buf;
}
#else
std::string getExecutableName()
{
    char exe[MAXPATHLEN];
    uint32_t bufSize = sizeof(exe);
    _NSGetExecutablePath(exe, &bufSize);
    char buf[MAXPATHLEN];
    ssize_t len;
    if ((len = readlink(exe, buf, sizeof(buf) - 1)) != -1)
        buf[len] = '\0';
    return buf;
}
#endif
```



### Remove duplicates from container without sorting the container

```C++
#include <algorithm>
#include <vector>
struct target_less
{
    template<class It>
    bool operator()(It const &a, It const &b) const { return *a < *b; }
};
struct target_equal
{
    template<class It>
    bool operator()(It const &a, It const &b) const { return *a == *b; }
};
template<class It> It uniquify(It begin, It const end)
{
    std::vector<It> v;
    v.reserve(static_cast<size_t>(std::distance(begin, end)));
    for (It i = begin; i != end; ++i)
    { v.push_back(i); }
    std::sort(v.begin(), v.end(), target_less());
    v.erase(std::unique(v.begin(), v.end(), target_equal()), v.end());
    std::sort(v.begin(), v.end());
    size_t j = 0;
    for (It i = begin; i != end && j != v.size(); ++i)
    {
        if (i == v[j])
        {
            using std::iter_swap; iter_swap(i, begin);
            ++j;
            ++begin;
        }
    }
    return begin;
}
```

### Remove duplicates from container

```C++
sort( vec.begin(), vec.end() );
vec.erase( unique( vec.begin(), vec.end() ), vec.end() );
```

### Load file into string

```C++
std::ifstream t("file.txt");
std::stringstream buffer;
buffer << t.rdbuf();
```



### copy file

```C++
std::ifstream  src("from.ogv", std::ios::binary);
std::ofstream  dst("to.ogv",   std::ios::binary);
dst << src.rdbuf();
```

### string low case

```C++
#include <algorithm>
#include <string> 

std::string data = "Abc"; 
std::transform(data.begin(), data.end(), data.begin(), ::tolower);
```

### list of files in a directory

```C++
DIR *dir;
struct dirent *ent;
if ((dir = opendir ("c:\\src\\")) != NULL) {
  /* print all the files and directories within directory */
  while ((ent = readdir (dir)) != NULL) {
    printf ("%s\n", ent->d_name);
  }
  closedir (dir);
} else {
  /* could not open directory */
  perror ("");
  return EXIT_FAILURE;
}
```

<http://stackoverflow.com/questions/612097/how-can-i-get-a-list-of-files-in-a-directory-using-c-or-c>

### C++ Erase vector element by value rather than by position?

```C++
vec.erase(std::remove(vec.begin(), vec.end(), 8), vec.end());
```

### How to get my ip address in c Linux -…

```C++
getifaddrs(&addrs);
tmp = addrs;

while (tmp) 
{
    if (tmp->ifa_addr && tmp->ifa_addr->sa_family == AF_INET)
    {
        struct sockaddr_in *pAddr = (struct sockaddr_in *)tmp->ifa_addr;
        printf("%s: %s\n", tmp->ifa_name, inet_ntoa(pAddr->sin_addr));
    }

    tmp = tmp->ifa_next;
}

freeifaddrs(addrs);
```

### How do I get the directory that a program is running from?

```C++
#include <stdio.h>  /* defines FILENAME_MAX */
#ifdef WINDOWS
    #include <direct.h>
    #define GetCurrentDir _getcwd
#else
    #include <unistd.h>
    #define GetCurrentDir getcwd
 #endif

 char cCurrentPath[FILENAME_MAX];

 if (!GetCurrentDir(cCurrentPath, sizeof(cCurrentPath)))
     {
     return errno;
     }

cCurrentPath[sizeof(cCurrentPath) - 1] = '\0'; /* not really required */

printf ("The current working directory is %s", cCurrentPath);
```

Windows:
```C++
int bytes = GetModuleFileName(NULL, pBuf, len);
if(bytes == 0)
	return -1;
else
	return bytes;
```
Linux:
```
char szTmp[32];
sprintf(szTmp, "/proc/%d/exe", getpid());
int bytes = MIN(readlink(szTmp, pBuf, len), len - 1);
if(bytes >= 0)
	pBuf[bytes] = '\0';
return bytes;
```



### Converting YUV into BGR or RGB

```C++
for(int i = 0, j=0; i < 1280 * 720 * 3; i+=6, j+=4)
{
    m_RGB->imageData[i] = pData[j] + pData[j+3]*((1 - 0.299)/0.615);
    m_RGB->imageData[i+1] = pData[j] - pData[j+1]*((0.114*(1-0.114))/(0.436*0.587)) - pData[j+3]*((0.299*(1 - 0.299))/(0.615*0.587));
    m_RGB->imageData[i+2] = pData[j] + pData[j+1]*((1 - 0.114)/0.436);
    m_RGB->imageData[i+3] = pData[j+2] + pData[j+3]*((1 - 0.299)/0.615);
    m_RGB->imageData[i+4] = pData[j+2] - pData[j+1]*((0.114*(1-0.114))/(0.436*0.587)) - pData[j+3]*((0.299*(1 - 0.299))/(0.615*0.587));
    m_RGB->imageData[i+5] = pData[j+2] + pData[j+1]*((1 - 0.114)/0.436);
}
```

### Convert time_t to string with format YYYY-MM-DD HH:MM:SS

```C++
char buff[20];
time_t now = time(NULL);
strftime(buff, 20, "%Y-%m-%d %H:%M:%S", localtime(&now));
```


### How to convert a string variable containing time to time_t type in c++?

```C++
const char *time_details = "16:35:12";
struct tm tm;
strptime(time_details, "%H:%M:%S", &tm);
time_t t = mktime(&tm);  // t is now your desired time_t
```

### Path to binary in C

```C++
#include <stdio.h>
#include <unistd.h>

int main()
{
  char buffer[BUFSIZ];
  readlink("/proc/self/exe", buffer, BUFSIZ);
  printf("%s\n", buffer);
}
```

```C++
WCHAR path[MAX_PATH];
GetModuleFileName(NULL, path, ARRAYSIZE(path));
```

### Rotate screen
```
xrandr --output HDMI-0 --rotate left
```
### Set wacom pen on one screeen
```bash
xsetwacom set "Wacom Bamboo 16FG 4x5 Pen stylus" MapToOutput HEAD-0
```

### Run Minecraft
```bash
java -Xmx1024M -Xms512M -cp minecraft.jar net.minecraft.LauncherFrame
```

### Set keyboard repeat rate
```
xset r rate 210 120
```
### NATO phonetic alphabet
```
A .......... 	ALPHA		N .......... 	NOVEMBER
B .......... 	BRAVO 	  	O .......... 	OSCAR
C .......... 	CHARLIE 	P .......... 	PAPA
D .......... 	DELTA 		Q .......... 	QUEBEC
E .......... 	ECHO 		R .......... 	ROMEO
F .......... 	FOXTROT 	S .......... 	SIERRA
G .......... 	GOLF 		T .......... 	TANGO
H .......... 	HOTEL 		U .......... 	UNIFORM
I .......... 	INDIA 		V .......... 	VICTOR
J .......... 	JULIET 		W .......... 	WHISKY
K .......... 	KILO 		X .......... 	X-RAY
L .......... 	LIMA 		Y .......... 	YANKEE
M .......... 	MIKE 		Z .......... 	ZULU
```


### Generate etags for emacs

```bash
find . -name "*.cpp" -print0 -or -name "*.c" -print0 -or -name "*.h" -print0 -or -name "*.c" -print0 | xargs -0 etags --append
```

### valgrind

```bash
$ /usr/bin/valgrind --tool=memcheck --leak-check=yes --leak-check=full -v --show-reachable=yes [command line]
```
### unixtime conversions

```bash
$ date -d @1193144433
Tue Oct 23 15:00:33 CEST 2007
```
```bash
$ date -d @1193144433 "+%Y-%m-%d %T"
2007-10-23 15:00:33

$date --date="Sun Oct 21 9:00:00 PDT 2012" +%s
1350835200
```
= generate news from lenta.ru

```bash
wget http://lenta.ru/rss/ -O- 2> /dev/null | grep http://.*news | sed 's/<link>//g' | sed 's/<.link>/_Printed.htm/g' | wget -i- -O- | grep -v -E '<.?html>' | grep -v -E '<.?title>' | grep -v -E '<!DOCTYPE' | htmldoc - -f "news`date +%Y-%m-%d`.pdf" -t pdf14 --webpage --right 1in --fontsize 10 
```
### Run Minecraft

```bash
$ java -Xmx1024M -Xms512M -cp minecraft.jar net.minecraft.LauncherFrame
```

Gentoo related
==============

### emacs startup is slow

add line to /etc/hosts
```
127.0.0.1 cassiopeia
```

### kernel select

```bash
eselect kernel list
eselect kernel set 3
```
### grub updating

```bash
edit /boot/grub/grub.conf
mount /boot
```


### kernel build

```bash
# cd /usr/src/linux
# make menuconfig
##copy .config file if needed from previus kernel
# cp ../linux.../.config .
# make && make modules_install
## if needed mount /boot partition
# mount /boot
# cp arch/x86_64/boot/bzImage /boot/kernel-2.6.36-gentoo-r5 
# module-rebuild rebuild
```
### mount dvd

```bash
# mount -t iso9660 /dev/cdrom /dev/cdrom
```
### play dvd

```bash
$ mplayer dvd://1
```
### how to create tab.bz2


compress:
```bash
$ tar -jcvf archive_name.tar.bz2 directory_to_compress
```
extract:
```bash
$ tar -jxvf archive_name.tar.bz2 -C /tmp/extract_here/
```
### update your system

```bash
# emerge --sync
# emerge --update --deep --ask world
```
### update etc files

```bash
# etc-update
```
```bash
sleep 1; xset s activate
```

### Удаление ненужных зависимостей

```bash
emerge --update --deep --newuse world && emerge --depclean && revdep-rebuild
```

### Удаление пакета

```bash
sudo emerge -av --depclean transcode
```

```bash
ffmpeg -i c++_lessons38_speedup.ogv  -i audio.wav  -map 0:0 -map 1:0 -vcodec copy -av 320k c++_lessons38_audio.ogv 
```
```bash
mplayer dvd://1
```

```
sda5 boot
sda6 root

linux-2.6.36-gentoo-r5

GeForce GT420
```
### rip dvd

```bash
mplayer dvd://1 -dumpstream -dumpfile rippeddvd.vob
```

### Printing howto


<http://www.gentoo.org/doc/en/printing-howto.xml>


### Add a existing user to existing group

```bash
usermod -a -G ftp tony
```

qfile codegen.py - найти файл

python-updater - обновить пакеты зависящие от питона

portageq owners / /usr/lib64/libeggdbus-1.so - найти пакет владельца файла

### Синхронизировать время

```bash
sudo rdate -s ptbtime1.ptb.de
```

### SSH login without password

Your aim

You want to use Linux and OpenSSH to automize your tasks. Therefore you need an automatic login from host A / user a to Host B / user b. You don't want to enter any passwords, because you want to call ssh from a within a shell script.

How to do it

First log in on A as user a and generate a pair of authentication keys. Do not enter a passphrase:
```bash
a@A:~> ssh-keygen -t rsa
Generating public/private rsa key pair.
Enter file in which to save the key (/home/a/.ssh/id_rsa): 
Created directory '/home/a/.ssh'.
Enter passphrase (empty for no passphrase): 
Enter same passphrase again: 
Your identification has been saved in /home/a/.ssh/id_rsa.
Your public key has been saved in /home/a/.ssh/id_rsa.pub.
The key fingerprint is:
3e:4f:05:79:3a:9f:96:7c:3b:ad:e9:58:37:bc:37:e4 a@A
```
Now use ssh to create a directory ~/.ssh as user b on B. (The directory may already exist, which is fine):
```bash
a@A:~> ssh b@B mkdir -p .ssh
b@B's password: 
```
Finally append a's new public key to b@B:.ssh/authorized_keys and enter b's password one last time:
```bash
a@A:~> cat .ssh/id_rsa.pub | ssh b@B 'cat >> .ssh/authorized_keys'
b@B's password: 
```
From now on you can log into B as b from A as a without password:
```bash
a@A:~> ssh b@B hostname
```
B
A note from one of our readers: Depending on your version of SSH you might also have to do the following changes:

Put the public key in .ssh/authorized_keys2
Change the permissions of .ssh to 700
Change the permissions of .ssh/authorized_keys2 to 640

```
13:50 03.02.03
### Удаление писем из почтовой очереди sendmail

В каталоге /var/spool/mqueue/ удалить файлы этого письма. Для того чтобы узнать, 
что в почтовой области  надо воспользоваться коммандой mqilq.
Источник: http://penguin.photon.ru/doc/mail/index.html

17:24 04.02.03
### Разрешить отправку писем по IP

1) В файл /etc/mail/access включить строку:
 xxx.xxx.xxx.xxx RELAY
где xxx.xxx.xxx.xxx требуемый IP адрес.

2) Дать команду:
makemap hash /etc/mail/access.db < /etc/mail/access

Информацию по sendmail можно найти по адресу http://gyro.hotbox.ru/sendmail/index.html .

16:25 17.04.03
### Процедура добавление нового пользователя

- получить права root
- добавить пользователя
/usr/sbin/adduser -g ec -G ecsoft -d /home/public/upload/user user
- ввести пароль 
  passwd user
- запретить доступ к серверу через терминал, поправив файл /etc/passwd
- добавить пользователя в SMB
smbadduser user:user
- поменять права папки нового пользователя
chmod 750 /home/public/upload/user

13:48 29.04.03
### Перезапустить SMB сервер

1) получить права ROOT
2) /etc/rc.d/init.d/smb restart 

20:29 17.06.03
### Включить NAT

1) получить права root
echo 1 > /proc/sys/net/ipv4/ip_forward
/sbin/iptables -t nat -A POSTROUTING -s 192.168.0.0/16 --out-interface eth0 -j SNAT --to-source 194.67.66.38
/sbin/iptables-save > /etc/sysconfig/iptables
echo 1 > /proc/sys/net/ipv4/ip_forward 


вставить в файл /etc/rc.d/rc.local

### Sendmail задумывается

/etc/hosts прописали 
127.0.0.1 localhost
194.67.66.38 ecsoft ecsoft.mephi.ru
192.168.0.1 ecsoft

16:27 18.06.03
### Запустить ftp

ln --symbolic /etc/init.d/vsftpd S50vsftpd



В vsftpd.conf редактируем следующие строки:

anonymous_enable=NO - если не хотим разрешать доступ для анонимных пользователей.
local_enable=YES - чтобы разрешить доступ локальным пользователям системы.
write_enable=YES - чтобы разрешить им запись.
local_umask=022 - ставим более либеральную маску.
chroot_list_enable=YES
chroot_local_user=YES
chroot_list_file=/usr/local/etc/vsftpd.chroot_list

последние три строки означают изменить корневую директорию на домашнюю для всех пользователей, кроме перечисленных (в столбик) в файле vsftpd.chroot_list . Например, если в файле vsftpd.chroot_list будут перечислены пользователи john и boris, то им будет доступна вся корневая дирректория (насколько им позволяют права, конечно), а остальные пользователи не смогут выйти за рамки своих домашних каталогов.

Это лишь один из примеров настройки этого сервера. Конфигурационный файл хорошо документирован, поэтому легко понять что к чему.




### Добавили пользователя skib

#/usr/sbin/groupadd ec
#/usr/sbin/groupadd ecsoft
#/usr/sbin/adduser -g ec -d /home/skib skib
#passwd skib
#chmod 750 /home/skib

### Изменяем владельца группу у домашних папок

# chown :ec alex
# chown :ecsoft anton
# chown :ec borya
# chown :ecsoft dima
# chown :ec fva
# chown :ecsoft hunter
# chown :ec lgau
# chown :ec mav
# chown :ec plugged
# chown :ec rpt
# chown :ec sasa
# chown :ecsoft serge
# chown :ecsoft sna

# chmod 770 alex
# chmod 770 anton
# chmod 770 borya
# chmod 770 dima
# chmod 770 fva
# chmod 770 hunter
# chmod 770 lgau
# chmod 770 mav
# chmod 770 plugged
# chmod 770 rpt
# chmod 770 sasa
# chmod 770 skib
# chmod 770 sna

# /usr/sbin/usermod -g ec -G ecsoft anton
# /usr/sbin/usermod -g ec -G ecsoft dima
# /usr/sbin/usermod -g ec -G ecsoft hunter
# /usr/sbin/usermod -g ec -G ecsoft serge
# /usr/sbin/usermod -g ec -G ecsoft sna
# /usr/sbin/usermod -g ec alex
# /usr/sbin/usermod -g ec borya
# /usr/sbin/usermod -g ec fva
# /usr/sbin/usermod -g ec lgau
# /usr/sbin/usermod -g ec mav
# /usr/sbin/usermod -g ec plugged
# /usr/sbin/usermod -g ec rpt
# /usr/sbin/usermod -g ec sasa
# /usr/sbin/usermod -g ec skib

### Настройка Самбы


Файл /etc/samba/smb.conf

workgroup = ECSOFTNET

server string = Powered ASP Linux 9

hosts allow = 192.168.0.

domain master = yes

domain logon = yes

interfaces = 192.168.0.1/24

character set = 1251
client code page = 866

[homes]
   comment = Home Directories
   browseable = no
   writable = yes
   valid users = %S
   create mode = 0660
   directory mode = 0770
# If you want users samba doesn't recognize to be mapped to a guest user
; map to guest = bad user

[public]
   comment = Public Stuff
   path = /home/skib/
   public = yes
   writable = yes
   printable = no
   write list = @ec
   create mode = 0661
   directory mode = 2775

[lp0]
   security = server
   path = /var/spool/lpd/lp
   printer name = lj1200
   writable = yes
   public = yes
   printable = yes
   print command = lpr -r -h -P %p %s

Добавить в автозагрузку Самбу
ln --symbolic /etc/rc.d/init.d/smb /etc/rc.d/rc3.d/S35smb

21:00 18.06.03
Добавили папку SOFT
# /usr/sbin/usermod -G ec,softman anton
# /usr/sbin/usermod -G ec,softman hunter
# chown :softman SOFT
# chmod 775 SOFT


13:58 19.06.03
### Редирект на другой IP и на другой порт

# /sbin/iptables -t nat -A PREROUTING -p TCP -d 194.67.66.38 --dport 4665 -j DNAT --to-destination 192.168.0.9

15:26 20.06.03
### Настройка принтера через Samba

* Установить пакет redhat-config-printer и все зависимые от него пакеты.
* # printconf
* и дабавляется принтер с такими параметрами
    Имя: lj1200
    Доп. имена:
      Тип: Устройство локального принтера:
      Устройство принтера: /dev/lp0
      Драйвер: HP LaserJet 1200 using Postscript driver  

17:50 24.06.03
### Настройка dhcpd

* Создать файл /etc/dhcpd.conf

ddns-update-style interim;
subnet 192.168.0.0 netmask 255.255.255.0 {

# --- default gateway
        option routers                  192.168.0.1;
        option subnet-mask              255.255.255.0;

        option domain-name      "ecsoft.mephi.ru";
        option domain-name-servers      194.67.67.34, 194.67.67.130;

        range 192.168.0.2 192.168.0.100;
        default-lease-time 21600;
        max-lease-time 43200;

}

* Запустить демона
# /etc/rc.d/init.d/dhcpd start
* Записать в автозагрузку
ln --symbolic /etc/rc.d/init.d/dhcpd /etc/rc.d/rc3.d/S35dhcpd
15:44 30.06.03
### Добавили ползователя

# /usr/sbin/adduser -g ec -G ecsoft -d /home/alexakov alexakov
# passwd alexakov
; подправили группу
# /usr/sbin/usermod -g ec alexakov

16:36 09.07.03
### Добавить новый алиас

- Поправить файл /etc/aliases
- дать команду newaliases

15:05 19.04.04
### Поменять местами сетевухи

- исправить файлы
/etc/sysconfig/network-scripts/ifcfg-eth0
/etc/sysconfig/network-scripts/ifcfg-eth1

18:21 19.04.04
### Прописать шлюз по умолчанию

в файле /etc/sysconfig/network-scripts/ifcfg-eth1 должно быть написано:
DEVICE=eth1
ONBOOT=yes
IPADDR=194.67.66.38
NETMASK=255.255.255.0
NETWORK=194.67.66.0
BROADCAST=194.67.66.255
GATEWAY=194.67.66.130
19:26 18.08.04
### Инициализация SWAP

/sbin/mkswap /dev/hda5
14:20 19.12.2005
### Кодировка в SAMBA

в файле /etc/samba/smb.conf в разделе [global] добавить две строчки

unix charset = windows-1251
dos charset = cp866

14:51 17.07.2006
### После перезагрузки сервера выполнить

#mount /dev/hda6 /home
 cd /home/hunter/Templates/
./firewall1.sh
/etc/init.d/vsftpd start
/etc/init.d/dovecot start
/etc/init.d/httpd start

Для emule
/sbin/iptables -t nat -A PREROUTING -p TCP -i eth0 -d 194.67.66.38 --dport 4665 -j DNAT --to-destination 192.168.0.9

wrUL30pq
18:23 02.11.2006
antivir -s -z --heur-macro --heur-level=4 -v /
18:19 08.12.2006
### очистка почтового ящика

* Запустить mail -u user
* набрать s * old_mail.txt
* q выход

```
