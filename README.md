## Run a sorting algorithm


```
    g++ ./Isertion/insertionsort.cpp
            or
    g++ *.cpp
```
If compiled successfully, creates an executable file called `a.out`.

## Run an executable

```
    ./a.out ./inputs/input.100000.1
```

### Caluclate Running time (real time)

```
    time for f in ./inputs/input.100000.1; do echo $f; ./a.out $f; done
```