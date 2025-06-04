> Tags: embedded systems, git, github, version control, shell commands

# Reading for section 00

## Concept 1: What is an embedded system?

An embedded system is a specialized computer system—a combination of a computer processor, computer memory, and input/output peripheral devices—that has a dedicated function within a larger mechanical or electronic system.

In our case within Dallas Formula Racing, this can be anything, from the dashboard display, data acquistition system, battery management system (EV) and many other smaller projects that support our development.

## Concept 2: Introducing the shell.

Before writing code, we need to understand how to interact with our own computer. One of the most fundamental tools is the [shell](<https://en.wikipedia.org/wiki/Shell_(computing)>). Normally, we open an application to use the application software. In this case, the shell allows the user to access and use operating system's services. It's called "shell" because it's the outermost layer around the operating system.

To be clear, a shell is a command interpreter and a terminal is the application we type the command into. If I were to run `echo hello`, the program I type it in is the [terminal](https://en.wikipedia.org/wiki/Terminal_emulator), and the program that interprets the command and returns `hello` is the shell.

Understanding the shell is critical because many of the tools we’ll use in embedded development, like Git, compilers, and debugging utilities, are run from the command line.

The most basic shell commands involve navigating your directory. The root directory is the top-level folder in a computer's file system, denoted as `~`. `pwd` for print working directory, `cd` for change directory, `mkdir` to make directory. `rm` for removing files or directories.

All shell commands follow a similar structure: `<utility> <flags> <arguments>`. For example, if I wanted to switch to my root directory and create a text file named `bat.txt`, I would run `cd ~` and then `touch bat.txt`.

We can also download software using the shell.

> Try: Open a terminal window and enter `~` then `pwd`.

This will navigate you to your home directory.

> Try: Now enter `cd ..` to move one level up.

You are now in the parent directory of `~`.

> Try: Run `ls -a` (list all) and you should see the name of your home directory.

These are just some (very common) examples of commands you may have to execute in the future. Here are some other ones.

| Command           | Purpose                                     |
| ----------------- | ------------------------------------------- |
| `grep`            | Search for text patterns in files or output |
| `ps aux`          | List all running processes                  |
| `kill`, `killall` | Stop a process by PID or name               |
| `top` / `htop`    | Live system performance monitor             |
| `find`            | Search for files by name/type/attributes    |
| `chmod`           | Change file permissions                     |
| `diff`            | Compare two files line-by-line              |

Before ending this section, there's one very important function of the command line that is extremely useful:

### Piping

Piping lets you take the output of one command and pass it as input to another.

It looks like this: `command1 | command2`.

An common example of piping is looking for for error logs in system logs:

`cat system.log | grep "error"`.

For embedded, another example for piping is looking through a live serial monitor, reads live serial output from `/dev/ttyUSB0` and filters only lines containing “ADC”:

`cat /dev/ttyUSB0 | grep "ADC"`.

This is very useful for reading outputs to comb through errors and messages.

## Concept 3: Git, Github and Version Control

As developers, we often collaborate on giant, complex projects that involve all kinds of firmware, configurations and documentation. To manage changes efficiently, we use a version control software. The most popular one out there is called **Git**.

To avoid the common misconception: the **[Git](https://git-scm.com/)** software is _hosted_ on [GitHub](https://github.com/). The same way videos are hosted on YouTube.

Git, and version control software (VCS) in general, allows developers to:

- revert to earlier versions of your projects in case your project blows up
- see who made what changes and when
- work on new, experimental features outside of the main codebase
- collaborate without writing over others' work
- check if things work before [pushing to production](https://en.wikipedia.org/wiki/2024_CrowdStrike-related_IT_outages)
- and other quality of life features that makes developing not unbearable

In a way, git gives us embedded developers a safety net, where one bad line of code can (actually and literally) [blow something up](https://en.wikipedia.org/wiki/Ariane_flight_V88). Bad firmware has been responsible [for a lot](https://en.wikipedia.org/wiki/Therac-25#Root_causes).

---

Git ensures that every change is tracked, reversible, and reviewable. With that in mind, let's look at some of the most basic git commands.

| Command                   | What It Does                                                                 |
| ------------------------- | ---------------------------------------------------------------------------- |
| `git init`                | Starts a new Git repository in your current directory                        |
| `git clone <repo>`        | Copies a remote repository (e.g., from GitHub) to your local machine         |
| `git status`              | Shows the current state of your working directory and staged files           |
| `git add <file>`          | Stages a file (or `.` for all files) for commit                              |
| `git commit -m "message"` | Saves a snapshot of your staged changes with a message describing the change |
| `git log`                 | Displays commit history                                                      |
| `git diff`                | Shows the difference between your files and the last commit                  |
| `git branch`              | Lists branches or creates a new one                                          |
| `git checkout <branch>`   | Switches to a different branch                                               |
| `git merge <branch>`      | Merges another branch into your current one                                  |
| `git pull`                | Fetches and merges changes from the remote repository                        |
| `git push`                | Uploads your commits to the remote repository                                |

---

### Navigate to WORK.md in this folder.
