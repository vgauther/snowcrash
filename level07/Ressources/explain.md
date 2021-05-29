ici on as un executable on l'execute cela affiche `levvel07`

On test de le renomer cela affiche toujours `level07`

On fait un `nm`  rien d'interessant

On utilise `stings`, le binaire utilise `getenv` et `LOGNAME`

On tet de redefinir `LOGNAME` en `test` cela fonctione

on test avec 

```bash
export LOGNAME=\`getflag\`
```
On met des back cote pour rendre `getflag` executale

Ca marche !