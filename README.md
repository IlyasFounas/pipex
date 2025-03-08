# Pipex 🚀

## Introduction 🛠️

**Pipex** is meant to reproduce a real shell pipe.

## Features 🔹

- Executes a command like `ls | wc -l` using pipes.
- Uses a structured approach to store important variables, making modifications easier.
- Basic error handling (e.g., file not found, invalid command).

## Limitations & Possible Improvements ⚠️

🔍 **Known bug:** If a command is given with an absolute path (`/usr/bin/cat`) and is invalid, the error message displays:
> `command not found: /usr/bin/cat`
Instead of:
> `command not found: cat`

🎯 **Possible improvements:** Of course, this project can be optimized, but my goal is to share my code and hopefully inspire you!

## Compilation & Execution 🚀

```bash
make
./pipex file1 "cmd1" "cmd2" file2
```

## Conclusion 🎉

I coded Pipex **in my own way**. It may not be perfect, but it reflects my approach to development. If my code can help or inspire you, then mission accomplished! 😉

🚀 **Happy coding!**

