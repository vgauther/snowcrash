Vu qu'il n'y avait aucun fichier nous indiquant une faille et sachant qu'il s'agissait du dernier niveau.
Nous avons décidé de strings getflag. (Nous avions surtout essayé plein de choses pendant des heures pour rien)

Nous avons donc regardé avec `strings` et nous avons remarqué plusieurs choses.

Tout d'abord, il semble que ce soit un fichier compilé en C.

Nous avons remarqué getuid. Nous avons donc compris que getflag recupère le uid de l'utilisateur et affiche le token dans le cas où c'est un flagXX qui fait la demande.

Après avoir découvert gdb à l'etage précédent nous avons décidé de le lancer.

```
disas main
```

nous montre que après le getuid, une comparaison est faite.


On a décidé de chercher le uid de flag14

```
cat /etc/passwd
```

c'est donc 3014.

Avec gdb, on essaye de breakpoint sur la comparaison en ajoutant

```
b *main+452
```

mais ca ne break pas.

Après avoir chercher comment forcer un breakpoint, nous avons vu que le programme utilise ptrace pour faire une verification.

Il faut donc passer cette étape pour pouvoir break la suite

```
b *main+72
```

en affichant le eax

```
p $eax
```

Nous avons vu qu'il était à -1 nous avons essayé de le passer à 0 et la notre breakpoint suivant à fonctionné


Nous avons donc pu changer la variable après le getuid et en continuant le programme, le token est affiché.

Check flag.Here is your token : 7QiHafiNa3HVozsaXkawuYrTstxbpABHD8CPnHJ
