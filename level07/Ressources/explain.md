Ici, on a un executable. On l'execute cela affiche `level07`

On test de le renomer cela affiche toujours `level07`

On fait un `nm`  rien d'interessant

On utilise `strings`, le binaire utilise `getenv` et `LOGNAME`

On test de redefinir `LOGNAME` en `test` cela fonctione

on test avec 

```bash
export LOGNAME=\`getflag\`
```
On met des back cote pour rendre `getflag` executale

Ca marche !
