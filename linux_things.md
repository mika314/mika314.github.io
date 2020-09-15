---
layout: page
title: Linux Things
permalink: /linux-things/
---

# Linux Things

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


http://www.gentoo.org/doc/en/printing-howto.xml


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
