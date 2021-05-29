Ici on as un fichier perl qui s'apparente à un serveur web.

Nous allons donc sur <ip>:4747 page blanche, rien de cacher dans le HTML ni dans la console JS.

En lisant le code, on voit qu'il prend un argument get x et l'affiche sur la page

On test <ip>:4747?x=toto

Toto est affiché ! 

Il n'y a pas de protection dans le code, on peut executer du subshell dans le get 

On test : <ip>:4747?x=$(getflag)

Ca marche !
