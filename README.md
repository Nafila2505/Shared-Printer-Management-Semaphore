
# Shared Printer Management – Semaphore

## Description
This project demonstrates shared printer management
using semaphores in C.

It ensures that only one user can access the printer
at a time while other users wait.

## Features
- Multiple users can request printer access.
- Only one user prints at a time.
- Other users wait until the printer is released.
- Displays printer allocation and release sequence.

## Functions Used
- sem_init()
- sem_wait()
- sem_post()
- sem_destroy()
- pthread_create()
- pthread_join()

## Technology Used
- Programming Language: C
- Concept: Process Synchronization
- Tool: POSIX Semaphore and Threads

## Compilation
gcc shared_printer.c -o shared_printer -pthread

## Execution
./shared_printer
