Ici on as un fichier perl qui s'aparente a un serveur web

Nous allons donc sur <ip>:4747 page blanche, rien de cacher dans le html ni console js

En lisant le code on vois qu'il prend un argument get x et l'affiche sur la page

On test <ip>:4747?x=toto

Toto est afficher ! 

il n'y as pas de protection dans le code, on peut execter du subshell dans le get 

on test On test <ip>:4747?x=$(getflag)


Ca marche !