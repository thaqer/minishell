# minishell

## Overview
`minishell` is a simple shell implementation written in C. It provides a basic command-line interface for users to interact with the operating system. The shell supports executing built-in commands as well as external programs.

## Features
- **Built-in Commands**: Supports `cd`, `pwd`, `echo`, `history`, and `exit`.
- **Signal Handling**: Gracefully handles `SIGINT` (Ctrl+C) to interrupt commands.
- **Environment Variables**: Manages and prints environment variables.
- **Command Execution**: Executes external programs using `execvp`.

## Built-in Commands
- `cd [directory]`: Changes the current directory to the specified directory.
- `pwd`: Prints the current working directory.
- `echo [text]`: Prints the specified text to the terminal.
- `history`: Displays the command history.
- `exit`: Exits the shell.

## Usage
1. **Compile the project**:
    ```sh
    make
    ```

2. **Run the shell**:
    ```sh
    ./minishell
    ```

3. **Use the shell**:
    - Type commands and press Enter to execute.
    - Use `Ctrl+C` to interrupt a running command.
    - Type `exit` to quit the shell.

## Example
```sh
$ ./minishell
minishell> pwd
/home/user/minishell
minishell> cd ..
minishell> pwd
/home/user
minishell> echo Hello, World!
Hello, World!
minishell> history
pwd
cd ..
pwd
echo Hello, World!
history
minishell> exit
$
```

## License
This project is licensed under the MIT License.