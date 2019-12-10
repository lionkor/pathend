# pathend

Minimalist commandline tool to retrieve the "end" of a given path. Same core functionality as `basename`.

Examples: 

```sh
$ pathend "/home/user/Downloads/glfw3.tar.gz"
glfw3.tar.gz
```

```sh
$ pathend ~/src/my-project/
my-project
```

```sh
$ ls /home/user/myfile.txt | pathend -
myfile.txt
```

Of course this is easy to do with a simple bash script, but I can't for the life of me be bothered to remember how to use `cut` every time I need to write a quick & dirty script. 

I felt like this is one job, and I wanted - UNIX style - one tool for it.
