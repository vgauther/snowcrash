vu qu'il n'y avait aucun fichier nous indiquant une faille et sachant qu'il s'agissait du dernier niveau.
Nous avons decide de strings getflag. (Nous avions surtout essaye plein de choses pendant des heures pour rien)

Nous avons donc regardé avec strings et nous avons remarque plusieurs choses

Tout d'abord il semble que ce soit un fichier compilé en C

Nous avons remarqué getuid. Nous avons donc compris que getflag recupere le uid de l'utilisateur et affiche le token dans le cas ou c'est un flagXX qui fait a demande.

Après avoir découvert gdb a l'etage precedent nous avons decide de le lancer

```
disas main
```

nous montre que apres le getuid, une comparaison est faite


on a decide de chercher le uid de flag14

```
cat /etc/passwd
```

c'est donc 3014

avec gdb on essaye de breakpoint sur la comparaison en ajoutant

```
b *main+452
```

mais ca ne break pas

apres avoir chercher comment forcer un breakpoint

nous avons vu que le programme utilise p trace pour faire une verification

il faut donc passer cette etape pour pouvoir break la suite

```
b *main+72
```

en affichant le eax

```
p $eax
```

nous avons vu qu'il etait à -1 nous avons essayé de le passer à 0 et la notre breakpoint suivant à fonctionné


nous avons donc pu changer la variable apres le getuid

et en continuant le programme

le token est affiché

Check flag.Here is your token : 7QiHafiNa3HVozsaXkawuYrTstxbpABHD8CPnHJ
