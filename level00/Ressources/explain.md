On se connecte sur l'utilisateur level00 avec le mot de passe fournis dans le sujet.

ls : on ne vois rien

On regarde de /etc/passwd, rien pour le flag00.

ls -la :

```
dr-xr-x---+ 1 level00 level00  100 Mar  5  2016 .
d--x--x--x  1 root    users    340 Aug 30  2015 ..
-r-xr-x---+ 1 level00 level00  220 Apr  3  2012 .bash_logout
-r-xr-x---+ 1 level00 level00 3518 Aug 30  2015 .bashrc
-r-xr-x---+ 1 level00 level00  675 Apr  3  2012 .profile
```

On recherche dans ces fichier, rien de concluant.

On regarde dans l'env : rien de particuler.

On se dit qu'il faut trouver un fichier cacher sur le système avec la commande find après avoir lu le man, on trouve le -user on fait donc :
```bash
find / -user flag00
```
`flag00` car c'est sur cette utilisateur qu'on cherche a se connecter.

Il y a beaucoup trop d'erreurs, on décide donc de les rediriger dans `/dev/null/` :
```bash
find / -user flag00 2>/dev/null
```

On trouve :
```
/usr/sbin/john
/rofs/usr/sbin/john
```

On utilise `cat` sur les fichiers, il y a cette chaine de charactères dans les fichier.
`cdiiddwpgswtgt`

On test de se connecter, ça ne marche pas.

On utilise le site dcode.fr.
On essaye de detecter l'encodage, on trouve que c'est surrement un code cesar.
Avec le code cesar 15 on obtient `nottoohardhere`.

On test, Ca fonctionne !!!
