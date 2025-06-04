> Tags: embedded systems, git, github, version control, shell commands

# Reading for section 00

## Concept 1: What is an embedded system?

An embedded system is a specialized computer system—a combination of a computer processor, computer memory, and input/output peripheral devices—that has a dedicated function within a larger mechanical or electronic system.

In our case within Dallas Formula Racing, this can be anything, from the dashboard display, data acquistition system, battery management system (EV) and many other smaller projects that support our development.

## Concept 2: Introducing the shell.

Before writing code, we need to understand how to interact with our own computer. One of the most fundamental tools is the shell. Normally, we open an application to use the application software. In this case, the shell allows the user to access and use operating system's services. It's called "shell" because it's the outermost layer around the operating system.

To be clear, a shell is a command interpreter and a terminal is the application we type the command into. If I were to run `echo hello`, the program I type it in is the terminal, and the program that interprets the command and returns `hello` is the shell.

Understanding the shell is critical because many of the tools we’ll use in embedded development, like Git, compilers, and debugging utilities, are run from the command line.

The most basic shell commands involve navigating your directory. The root directory is the top-level folder in a computer's file system, denoted as `~`. `pwd` for print working directory, `cd` for change directory, `mkdir` to make directory. `rm` for removing files or directories.

All shell commands follow a similar structure: `<utility> <flags> <arguments>`. For example, if I wanted to switch to my root directory and create a text file named `bat.txt`, I would run `cd ~` and then `touch bat.txt`.

We can also download software using the shell.

> Open a terminal window and enter `~` then `pwd`.

This will navigate you to your home directory.

> Now enter `cd ..` to move one level up.

You are now in the parent directory of `~`.

> Run `ls -a` (list all) and you should see the name of your home directory.
