On se connecte pour l'utilisateur level00

ls : on ne vois rien

On regarde de /etc/passwd, rien pour le flag00

ls -la :

```
dr-xr-x---+ 1 level00 level00  100 Mar  5  2016 .
d--x--x--x  1 root    users    340 Aug 30  2015 ..
-r-xr-x---+ 1 level00 level00  220 Apr  3  2012 .bash_logout
-r-xr-x---+ 1 level00 level00 3518 Aug 30  2015 .bashrc
-r-xr-x---+ 1 level00 level00  675 Apr  3  2012 .profile
```

On recherche dans ces fichier, rien de concluent

On regarde dans l'env : rien de particuler 

On se dit qu'il faut trouver un fichier cacher sur le systeme
avec la commande find
apres avoir lu le man on trouve le -user on fait donc
```bash
find / -user flag00
```
`flag00` car c'est sur cette utilisateur qu'on cherche a se connecter

Beaucoup trop d'erreur on redirige donc les erreurs dans `/dev/null/` :
```bash
find / -user flag00 2>/dev/null
```

On trouve
```
/usr/sbin/john
/rofs/usr/sbin/john
```

On cat les fichiers il y a cette meme chaine de characteres dans les fichier
`cdiiddwpgswtgt`

On test, ca ne marche pas 

On utilise le site dcode.fr
On regarde avec le code cesar
Avec le code cesar 15 on obtient `nottoohardhere`

On test, Ca fonctionne !!!