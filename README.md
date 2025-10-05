# pipex (mandatory) + libft

Usa tu **libft** (rutas y build estándar de 42) en `lib/libft`.

## Preparación
Coloca tu libft así:
```
pipex_with_libft/
├─ lib/
│  └─ libft/        # tu repo de libft con su Makefile
│     ├─ libft.h
│     ├─ Makefile
│     └─ (srcs...)
```
El Makefile llamará `make -C lib/libft` y enlazará `libft.a` automáticamente.

## Build
```sh
make
```
## Run
```sh
./pipex infile "cmd1 args" "cmd2 args" outfile
```

## Notas
- Se usan `ft_strlen`, `ft_strncmp`, `ft_strdup`, `ft_memcpy` de tu libft.
- Parser propio `px_split_cmd` para manejar comillas `'` y `"` (libft `ft_split` no sirve para esto).