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

## 🧠 Key Concepts

### Unix System Calls

- `fork()`
- `pipe()`
- `dup2()`
- `execve()`

### Process Management

### Descriptor Redirection

The descriptors in the pipe ends ought to be new descriptors distinct from stdin and stdout. For this, `dup2()` can be used to assign one file descriptor to another, allowing them to point to the same file table entry in the kernel. 

### Command Parsing and Execution


## 🚀 Usage

### 1. Build

- Mandatory: `make`
- Bonus: `make bonus`

### 2. Execute

- Mandatory: `./pipex infile cmd1 cmd2 outfile`
- Bonus: `./pipex infile cmd1 cmd2 cmd3 ... cmdn outfile`
	- For heredoc: `./pipex here_doc LIMITER cmd1 cmd2 ... cmdn outfile`
