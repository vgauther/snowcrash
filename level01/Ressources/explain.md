On se connecte a l'user level01

ls touchours rien 

ls -la toujours 
```
dr-x------ 1 level01 level01  100 Mar  5  2016 .
d--x--x--x 1 root    users    340 Aug 30  2015 ..
-r-x------ 1 level01 level01  220 Apr  3  2012 .bash_logout
-r-x------ 1 level01 level01 3518 Aug 30  2015 .bashrc
-r-x------ 1 level01 level01  675 Apr  3  2012 .profile
```

On regarde dans l'env rien 

on regarde de /etc/passwd, il y a : `42hDRfypTqqnw` avec flag01

On test, ca ne marche pas,

On sais que l'utilitaire `john` sert a exploit les passwd

On copie le /etc/passwd sur le mac

on utilise `john --show passwd`

on trouve `abcdefg`

On test, ca marche !