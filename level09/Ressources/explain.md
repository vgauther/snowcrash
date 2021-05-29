Ici, on a un binaire et un fichier token.

On test
```bash
./level09 token
```
On a une string mais ça ne marche pas.

On utilise cat sur le fichier `token`.

On a une string mais avec des characteres bizare comme si on avait depassé la memoire.

On fait donc un petit programme pour convertire la chaine de caractères:
`prog1.c`
Cala ne marche pas.

Après avoir testé le binaire `level09` on comprend comment convertir la chaine, le décalage correspond à i += 1 avec i commencant à zero.

On fait donc un petit programme
`prog2.c`

Ca marche ! 
