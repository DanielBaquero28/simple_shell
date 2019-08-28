SIMPLE-SHELL
---------------

<img src = "https://d2z6c3c3r6k4bx.cloudfront.net/uploads/event/logo/1061432/a991d937097e8176adf1ea7196beb80f.png">

----------------
Description
-------------
Simple shell is a command-line interpreter or shell that provides a command line user interface for unix-like operating systems, in the tradition of the first Unix shell written by Ken Thompson in 1971.

--------------
Learning Objectives
--------------
-How does a shell work.<br>
-What is a pid and a ppid.<br>
-How to manipulate the environment of the current process.<br>
-What is the difference between a function and a system call.<br>
-How to create processes.<br>
-What are the three prototypes of main.<br>
-How does the shell use the``` PATH``` to find the programs.<br>
-How to execute another program with the``` execve``` system call.<br>
-How to suspend the execution of a process until one of its children terminates.<br>

--------------
Description
-------------
The objectives of this project is to creat shell is intentionally minimalistic, yet includes the basic functionality of a traditional Unix-like command line user interface. 

-------------
Requirements
--------------------------------
The project is designed to run in the Ubuntu 14.04 LTS linux environment and to be compiled using the GNU (Compiler Colletion) version 4.8.4 or never.

---------------
Installation
---------------------

-Clone this repository:``` git@github.com:DanielBaquero28/simple_shell.git.```<br>
-Change directories into the repository: cd simple_shell<br>
-Compile: ```gcc -Wall -Werror -Wextra -pedantic *.c -o hsh```<br>
-Run the shell in interactive mode: ```./hsh```<br>
-Clone this repository: git@github.com:DanielBaquero28/simple_shell.git.<br>
-Change directories into the repository: cd simple_shell<br>
-Compile: gcc -Wall -Werror -Wextra -pedantic *.c -o hsh<br>
-Run the shell in interactive mode: ./hsh<br>

----------------
Usage
---------------
Enter the executable in your terminal after compiling.
```
$cisfun# /bin/ls
README.md  _atoi.c  hsh  launch_pid.c  parse_line.c  shell.c  shell.h  shell_builtins.c  strings.c  test_simple_shell
$cisfun# /bin/ls	-l
total 56
-rw-r--r-- 1 jay jay    15 Aug 28 01:59 README.md
-rw-r--r-- 1 jay jay   571 Aug 28 01:59 _atoi.c
-rwxr-xr-x 1 jay jay 20288 Aug 28 02:01 hsh
-rw-r--r-- 1 jay jay   693 Aug 28 01:59 launch_pid.c
-rw-r--r-- 1 jay jay  1520 Aug 28 01:59 parse_line.c
-rw-r--r-- 1 jay jay   797 Aug 28 01:59 shell.c
-rw-r--r-- 1 jay jay   997 Aug 28 01:59 shell.h
-rw-r--r-- 1 jay jay  1723 Aug 28 01:59 shell_builtins.c
-rw-r--r-- 1 jay jay  1331 Aug 28 01:59 strings.c
drwxr-xr-x 2 jay jay  4096 Aug 28 01:59 test_simple_shell
```

----------------
Authors
---------------

* **Vivian Ortiz** - [vivianlorenaortiz](https://github.com/vivianlorenaortiz)
* **Daniel Baquero** - [DanielBquero28](https://github.com/DanielBaquero28)

--------------
License
-------------
simple_shell is open source and therefore free to download and use without permission.