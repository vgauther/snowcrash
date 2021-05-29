On a un binaire `level08` et un fichier `token`.

On test :
```bash
./level08 token
```

Cela nous renvoie :
`You may not access 'token'`

On essaye de copier le token ailleurs, de faire un lien symbolique. Rien ne marche.

On renomme le ficher `token` en `test`

On fait :
```bash
./level08 test
```
Ca marche ! 
