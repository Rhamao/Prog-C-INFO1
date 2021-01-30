## TP1
---
### EX1
1. Pour obtenir l’arborescence indiquée dans le sujet :
``` c
aapelbau@pccop1b131-08:~/Documents/ProgrammationC/TP/TP1$ mkdir -p tp1/dir1
aapelbau@pccop1b131-08:~/Documents/ProgrammationC/TP/TP1$ mkdir -p tp1/dir2
aapelbau@pccop1b131-08:~/Documents/ProgrammationC/TP/TP1/tp1/dir1$ touch f11 f12 titi
aapelbau@pccop1b131-08:~/Documents/ProgrammationC/TP/TP1/tp1/dir2$ touch f2
```
2. De base voici les droits de notre arborescence :
``` bash
total 156
-rwxr--r-- 1 aapelbau 6ifo1 86890 oct.   2 09:11 CR_TP1_C_Arnaud_Apelbaum.docx
-rw-r--r-- 1 aapelbau 6ifo1 61995 oct.   2 09:22 CR_TP1_C_Arnaud_Apelbaum_v2.odt
drwxr-xr-x 4 aapelbau 6ifo1  4096 oct.   2 09:06 tp1

./tp1:
total 8
drwxr-xr-x 2 aapelbau 6ifo1 4096 oct.   2 09:06 dir1
drwxr-xr-x 2 aapelbau 6ifo1 4096 oct.   2 09:06 dir2

./tp1/dir1:
total 0
-rw-r--r-- 1 aapelbau 6ifo1 0 oct.   2 09:06 f11
-rw-r--r-- 1 aapelbau 6ifo1 0 oct.   2 09:06 f12
-rw-r--r-- 1 aapelbau 6ifo1 0 oct.   2 09:06 titi

./tp1/dir2:
total 0
-rw-r--r-- 1 aapelbau 6ifo1 0 oct.   2 09:06 f2
```
* Voilà comment nous allons obtenir les droits indiqués dans le sujet :
``` c
aapelbau@pccop1b131-08:~/Documents/ProgrammationC/TP/TP1$ chmod u=rwx,g=rwx,o=rwx tp1/
aapelbau@pccop1b131-08:~/Documents/ProgrammationC/TP/TP1/tp1$ chmod u=rwx,g=rwx,o=--- dir1
aapelbau@pccop1b131-08:~/Documents/ProgrammationC/TP/TP1/tp1$ chmod u=rwx,g=---,o=--- dir2
aapelbau@pccop1b131-08:~/Documents/ProgrammationC/TP/TP1/tp1/dir1$ chmod u=x---,g=x---,o=x-- f11
aapelbau@pccop1b131-08:~/Documents/ProgrammationC/TP/TP1/tp1/dir1$ chmod u=rw-,g=r--,o=r-- f12
aapelbau@pccop1b131-08:~/Documents/ProgrammationC/TP/TP1/tp1/dir1$ chmod u=rw-,g=rw-,o=rw- titi
aapelbau@pccop1b131-08:~/Documents/ProgrammationC/TP/TP1/tp1/dir2$ chmod u=rw-,g=rw-,o=rw- f2 
```
* Les droits sont désormais tels qu'on le souhaite :
``` bash
aapelbau@pccop1b131-08:~/Documents/ProgrammationC/TP/TP1$ ls -Rl
.:
total 156
-rwxr--r-- 1 aapelbau 6ifo1 86890 oct.   2 09:11 CR_TP1_C_Arnaud_Apelbaum.docx
-rw-r--r-- 1 aapelbau 6ifo1 64694 oct.   2 09:28 CR_TP1_C_Arnaud_Apelbaum_v2.odt
drwxrwxrwx 4 aapelbau 6ifo1  4096 oct.   2 09:06 tp1

./tp1:
total 8
drwxrwx--- 2 aapelbau 6ifo1 4096 oct.   2 09:06 dir1
drwx------ 2 aapelbau 6ifo1 4096 oct.   2 09:06 dir2

./tp1/dir1:
total 0
---x--x--x 1 aapelbau 6ifo1 0 oct.   2 09:06 f11
-rw-r--r-- 1 aapelbau 6ifo1 0 oct.   2 09:06 f12
-rw------- 1 aapelbau 6ifo1 0 oct.   2 09:06 titi

./tp1/dir2:
total 0
-rw------- 1 aapelbau 6ifo1 0 oct.   2 09:06 f2
```
3. 
``` bash
aapelbau@pccop1b131-08:~/Documents/ProgrammationC/TP/TP1$ cd tp1/dir1/
aapelbau@pccop1b131-08:~/Documents/ProgrammationC/TP/TP1/tp1/dir1$ cp f11 ../tutu
aapelbau@pccop1b131-08:~/Documents/ProgrammationC/TP/TP1/tp1/dir1$ cd ../dir2
aapelbau@pccop1b131-08:~/Documents/ProgrammationC/TP/TP1/tp1/dir2$ mv ../dir1/f* .
aapelbau@pccop1b131-08:~/Documents/ProgrammationC/TP/TP1/tp1/dir2$ ls
f11  f12  f2
```
### EX2
| Commande | Description |
| ------ | ----------- |
|cd|Retourne au dossier racine (~)|
|mkdir ./tutu|Créer le dossier le dossier tutu dans le dossier courant|
|mkdir tutu/titi|Créer le dossier titi dans le dossier titi|
|cd tutu|Se place dans le fichier tutu|
|chmod u=r ../tutu/titi|Donne à l’utilisateur le droit d’écriture sur ces 2 fichiers|
|mkdir ~/tutu/titi/toto|Créer le fichier toto en dessous du fichier titi|
### EX3
1. 
``` bash
aapelbau@pccop1b131-08:~/Documents/ProgrammationC/TP/TP1$ echo "Bonjour !" > titi
aapelbau@pccop1b131-08:~/Documents/ProgrammationC/TP/TP1$ ls
```
2. 
* méthode 1
``` bash
aapelbau@pccop1b131-08:~/Documents/ProgrammationC/TP/TP1$ cat titi titi > toto
```
* méthode 2
``` bash
méthode 2 (question 2) avec sed au lieu de cat
aapelbau@pccop1b131-08:~/Documents/ProgrammationC/TP/TP1$ sed -n p titi > toto
```
3. La commande ` cat zz >> zz ` permet d'ajouter le contenu du fichier zz au cotenu du fichier zz. Dans ce cas précis, le même fichier ne peut pas se trouver en entrée et en sortie. Donc la commande n'est pas exécuté.       
4. 
``` bash
nino@nino-HP-Pavilion-Notebook:/var/spool$ ls -R 2> /media/nino/DATA/err
nino@nino-HP-Pavilion-Notebook:/var/spool$ tail -10 /media/nino/DATA/err 
ls: cannot open directory './cron/crontabs': Permission denied
ls: cannot open directory './cups': Permission denied
ls: cannot open directory './rsyslog': Permission denieds 
```
5. 
``` bash
nino@nino-HP-Pavilion-Notebook:/media/nino/DATA/etudes/esipe/annee1/progc/tp/1tp$ man mv > buff
nino@nino-HP-Pavilion-Notebook:/media/nino/DATA/etudes/esipe/annee1/progc/tp/1tp$ ls -l buff
-rwxrwxrwx 1 nino nino 3141 janv. 27 17:10 buff
nino@nino-HP-Pavilion-Notebook:/media/nino/DATA/etudes/esipe/annee1/progc/tp/1tp$ ls -lh buff
-rwxrwxrwx 1 nino nino 3,1K janv. 27 17:15 buff
```
### EX4
1. 
``` bash 
ls -l | grep rw
```
3. 
``` bash
nino@nino-HP-Pavilion-Notebook:/media/nino/DATA/etudes/esipe/annee1/progc/tp/1tp$ cat passwd.txt 
alon:x:635:201:Marie-PierreTalon:/home/compta/talon:/bin/bash
alon:x:635:201:Jean-Michel:/home/compta/talon:/bin/bash
alon:x:635:201:Mohamaed-Dupois:/home/compta/talon:/bin/bash
nino@nino-HP-Pavilion-Notebook:/media/nino/DATA/etudes/esipe/annee1/progc/tp/1tp$ sed -n  's/.*:\(\w*\)-\(\w*\):.*/\1 \2/p' passwd.txt > tutu
nino@nino-HP-Pavilion-Notebook:/media/nino/DATA/etudes/esipe/annee1/progc/tp/1tp$ cat tutu 
Marie PierreTalon
Jean Michel
Mohamaed Dupois
```
