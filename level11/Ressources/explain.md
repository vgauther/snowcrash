On se connecte au level11

Avec le ls, on decouvre un fichier .lua

On cherche et pour l'executer on doit entrer

```
lua level11.lua
```

Le Retour :
```
lua: level11.lua:3: address already in use
stack traceback:
	[C]: in function 'assert'
	level11.lua:3: in main chunk
	[C]: ?
```

On comprend que le code est déjà en train de s'executer

`
local server = assert(socket.bind("127.0.0.1", 5151))
`

On comprend qu'il se passe quelque chose en localhost sur le port 5151

On execute
`
nc localhost 5151
`

On nous demande un mot de passe, nous comprennons donc qu'un server tourne à cette adresse.

On regarde sur le navigateur mais il n'y a rien.

On essaye de rentrer un mot de passe

`f05d1d066fb246efe0c6f7d095f909a7a0cf34a0`

à savoir un code présent dans le fichier. Cela ne marche pas non plus.

On essaye donc de comprendre le code.

En commencent par io.popen.

En faisant une recherche on trouve que le flag 'r' va simplement executer la commande qu'on lui passe.

C'est bon nous avons compris, il n'y a qu'à injecter la commande `getflag`

On met donc en mot de passe

`getflag`

mais rien ne se passe.

Nous avons fini par comprendre que l'output du programme ne se ferrait pas sur notre terminal mais sur celui du serveur.

Nous avons donc chercher un moyen de broadcast un message. Nous avons trouvé wall.

En utilisant :

```
wall "test"
```

On a compris que ça ne marchait pas comme ça.

Il fallait faire

```
echo "test" | wall
```

et enfin nous avons un message qui apparait

On a donc decidé de mettre en mot de passe

```
getflag | wall
```
mais ça ne fonctionnait toujours pas.

En relisant le code on a compris qu'il fallait empécher le echo de fonctionner.

O a donc mis en mot de passe

```
; getflag | wall
```

et d'un seul coup nous avons eu un message global de la part de flag11 nous donnant le resultat de la commande

Broadcast Message from flag11@Snow
        (somewhere) at 12:59 ...

Check flag.Here is your token : fa6v5ateaw21peobuub8ipe6s
