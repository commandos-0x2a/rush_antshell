# rush_antshell

## Task1 (11/6)
- make program to run simple command each args
- write `Makefile`


#### Example:
```sh
> ./runner "ls -la" "sleep 10" "ls -l"
```

## Task2 (14/6)
- make program to run complex command each args
- program apply redirection
### Example:
```sh
> ./runner "< data.txt cat -e > out" "> out2 echo Test" "< in1 grep A" "echo test_append >> out2"
```

-------
# References
[ Executable and Linkable Format ](https://en.wikipedia.org/wiki/Executable_and_Linkable_Format)

[ wait and waitpid ](https://notes.shichao.io/apue/ch8/#wait-and-waitpid-functions)

[ Figma white board ](https://www.figma.com/board/qXASHVJWQx1EQgIfmpti86/rush_antshell?node-id=0-1&t=9wm6slCwnOnrGfqL-1)

[ Files Tables image from APUE ](https://notes.shichao.io/apue/figure_8.2.png)