```
            o8o
            `"'
oo.ooooo.  oooo  oo.ooooo.   .ooooo.  oooo    ooo
 888' `88b `888   888' `88b d88' `88b  `88b..8P'
 888   888  888   888   888 888ooo888    Y888'
 888   888  888   888   888 888    .o  .o8"'88b
 888bod8P' o888o  888bod8P' `Y8bod8P' o88'   888o
 888              888
o888o            o888o

```

## 🗺️  Overview

`pipex` is a project aimed at understanding pipes and shell redirection by implementing a simplified version of the **shell pipe** command - which allows users to chain multiple commands together using pipes (`|`).

The program takes an input file, performs a command on it, pipes the result to the next command, then writes the output to an output file. The final behaviour should replicate this shell command:

```
< infile cmd1 | cmd2 > outfile
```

The corresponding syntax for `pipex` would be:

```
./pipex infile cmd1 cmd2 outfile
```

## 🎯 Features

- **Piping**: The main functionality of `pipex` revolves connecting the output of a former command directly into the input of the latter command (like in Unix pipes, `|`, which is a common feature in shells like `bash`)
- **Process Creation**: New processes are created via `fork()` to manage the tasks for each command independently
- **Shell Redirection**: Redirecting input and output to and from files, and between processes are handled using `dup2()` and `pipe` commands
- **Error Handling**: Error-handling for file operations, pipe creation, and process forking
- **Command Execution**: `pipex` parses command arguments and environment variables, and uses `execve` to implement command execution

## 📁 Project Structure

```
ft_pipex
├─ Makefile
├─ README.md
├─ include
│  ├─ error_msg.h
│  ├─ log.h
│  ├─ pipex.h
│  └─ struct.h
├─ infile
├─ libft
└─ src
   ├─ heredoc_bonus.c
   ├─ main.c
   ├─ main_bonus.c
   ├─ pipe.c
   ├─ pipe_bonus.c
   └─ shared
      ├─ cleanup.c
      ├─ cmd.c
      ├─ error.c
      ├─ log.c
      ├─ parse.c
      └─ tokenize.c
```

## 🧠 Key Concepts

### Interprocess Communication (IPC): Pipes

IPC refers to mechanisms allowing independent processes to interact and synchronize. By default, each process has an isolated memory space - which prevents one process from accessing the data of another process. While this is ideal when running single processes, this prevents the construction of more complex, multi-process functionalities - hence the need for mechanisms to allow processes to exchange information, share resources, and coordinate their actions when needed.

Pipes are one of the simplest forms of an IPC mechanism. They are unidirectional, kernel-managed queues with two file descriptors - read and write, for reading from and writing to the pipe respectively. There are two types of pipes - anonymous and named. This project focuses on anonymous pipes - which enable communication between processes on the same machine, and is destroyed when these processes terminate.

### Unix System Calls

- `fork()`: Allows a process to create an almost exact copy of itself - called a "child process". When called, the process's entire state at the current point in the program is duplicated - which includes the parent process ID, memory space, and open file descriptors. In the child process, `fork()` returns 0 whereas in the parent process, it returns some positive integer representing the PID of the newly-created child.

- `pipe()`:  Creates an anonymous pipe from an array of two file descriptors. The former file descriptor is initialized as the read end and the latter as the write end. The pipe created acts like a buffer, storing data written to it until it is emptied through the read end.

- `dup2()`: Duplicates the meaning of one file descriptor to another. This can be done because file descriptors do not point directly to the files they describe but rather to a file table entry in the Linux kernel - which in turn points to the actual file. Therefore, the end result is having both file descriptors point to the same file table entry in the kernel, enabling the current read/write position to be maintained.

- `execve()`: Executes a new program referred to by the given path name within the context of the calling process. When called, the code, data, stack, and heap of the calling process are replaced by the new program. Upon success, this function does not return - meaning that if any commands written under `execve` are run, an error has occurred.

### File Descriptor Redirection

The descriptors in the pipe ends ought to be new descriptors distinct from stdin and stdout. For this, `dup2()` can be used to assign one file descriptor to another, allowing them to point to the same file table entry in the kernel.

## 🚀 Usage

### 1. Build

- Mandatory: `make`
- Bonus: `make bonus`

### 2. Execute

- Mandatory: `./pipex infile cmd1 cmd2 outfile`
- Bonus: `./pipex infile cmd1 cmd2 cmd3 ... cmdn outfile`
	- For heredoc: `./pipex here_doc LIMITER cmd1 cmd2 ... cmdn outfile`


## 🔍 Checking Memory Leaks

Run the following valgrind command to check for memory leaks:

```
valgrind --trace-children=yes --leak-check=full --show-leak-kinds=all -s ./pipex infile <cmd1> <cmd2> outfile
```

