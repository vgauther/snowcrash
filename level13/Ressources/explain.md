On se connect au level13.

On voit un executable.

On l'execute.

```
UID 2013 started us but we we expect 4242
```

On ne comprend pas grands chose.

On utilise `strings`.

On découvre plusieurs choses. On comprends que c'est du C compilé. On voit également qu'il existe une fontion getuid. Et qu'il y a ecrit libc.so

On cherche et on découvre que c'est une lib partagée. On décide de créer nous aussi une lib partagé pour remplacer getuid par un une fonction qui retournerai 4242 mais aprés plusieurs essaies, rien ne marche.

On décide alors de prendre le problème à l'envers et de modifier la variable pendant l'execution. Après des recherches, on découvre gdb. Et on execute le programe avec.

En utilisant `disas main` on voit :

```
0x0804858c <+0>:	push   %ebp
  0x0804858d <+1>:	mov    %esp,%ebp
  0x0804858f <+3>:	and    $0xfffffff0,%esp
  0x08048592 <+6>:	sub    $0x10,%esp
  0x08048595 <+9>:	call   0x8048380 <getuid@plt>
  0x0804859a <+14>:	cmp    $0x1092,%eax
  0x0804859f <+19>:	je     0x80485cb <main+63>
  0x080485a1 <+21>:	call   0x8048380 <getuid@plt>
  0x080485a6 <+26>:	mov    $0x80486c8,%edx
  0x080485ab <+31>:	movl   $0x1092,0x8(%esp)
  0x080485b3 <+39>:	mov    %eax,0x4(%esp)
  0x080485b7 <+43>:	mov    %edx,(%esp)
  0x080485ba <+46>:	call   0x8048360 <printf@plt>
  0x080485bf <+51>:	movl   $0x1,(%esp)
  0x080485c6 <+58>:	call   0x80483a0 <exit@plt>
  0x080485cb <+63>:	movl   $0x80486ef,(%esp)
  0x080485d2 <+70>:	call   0x8048474 <ft_des>
  0x080485d7 <+75>:	mov    $0x8048709,%edx
  0x080485dc <+80>:	mov    %eax,0x4(%esp)
  0x080485e0 <+84>:	mov    %edx,(%esp)
  0x080485e3 <+87>:	call   0x8048360 <printf@plt>
  0x080485e8 <+92>:	leave
  0x080485e9 <+93>:	ret
 ```

On comprend que la fonction getuid est utilisé. On decouvre qu'il est possible de stoppé un executable à un moment précis pour modifier une variable.

 On décide de l'arrêter juste apres getuid :

 ```
	b *main+14
 ```

 puis on regarde la variable eax

```
	p $eax
```

et on voit bien 2013.

On décide de la changer en 4242.

```
set $eax=4242
```

On fait continue

```
c
```

et la your token is 2A31L79asukciNyi8uppkEuSx 
