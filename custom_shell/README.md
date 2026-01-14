# 🐚 Mini Shell - Simple UNIX Shell

A minimal shell written in C for learning how command-line interpreters work.

## 🎓 Purpose
This project was built as a student exercise to understand process control, forking, environment handling, and basic shell logic in UNIX systems.

## 🔧 Features
- Supports command execution via `execv`
- Built-in `cd` and `exit` commands
- PATH-based command lookup
- Simple error coloring (red prompt on error)
- Handles `! true` and `! false` as logical shortcuts

## 🗂 Structure
All logic is modularized:
- `print_prompt()` – shows current directory and error status
- `read_input()` – takes user input
- `parse_args()` – tokenizes input
- `handle_cd()` – changes directory
- `handle_exit()` – exits shell
- `exec_command()` – runs command from PATH
- `fork_and_exec()` – forks and waits for child

## 🖥 Usage
```bash
make
./custom_shell

