On as un nouveau mail !
On regarde le mail 
```
*/2 * * * * su -c "sh /usr/sbin/openarenaserver" - flag05
```
Une crontab qui s'execute toutes les 30s 

On regarde le scipt

```bash
#!/bin/sh

for i in /opt/openarenaserver/* ; do
	(ulimit -t 5; bash -x "$i")
	rm -f "$i"
done
```

Il va parcourir tout le dossier `/opt/openarenaserver/`, executez les scipts et ls supprimer

On test un premier scripts 
`script1.sh`
Sans résultat.
On test autre choses:
`script2.sh`
Ne marche pas non plus.

Après quelques minutes, je regarde les persmissions de /tmp j'ai le droit d'ecrire et d'executer
je fait donc :
`script3.sh`
Je fait le chmod 777 pour y avoir acces depuis `level05`

Je cat le fichier et on a le token !
