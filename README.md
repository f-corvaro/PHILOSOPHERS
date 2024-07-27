<h1 align="center"><a href="https://github.com/f-corvaro/PHILOSOPHERS">
	<img src="https://github.com/f-corvaro/PHILOSOPHERS/blob/main/.extra/philosophers.png" alt="PHILOSOPHERS">
  </a></h1>
  
<p align="center">
	<b><i>"Dive into the world of concurrency with Philosophers, a project that explores the dining philosophers problem."</i></b><br>
</p>
<p align="center" style="text-decoration: none;">
    <a href="https://github.com/f-corvaro/PHILOSOPHERS/blob/main/.extra/en.subject.pdf"><img alt="subject" src="https://img.shields.io/badge/subject-PHILOSOPHERS-yellow" /></a>
    <a href="https://github.com/f-corvaro/PHILOSOPHERS"><img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/f-corvaro/PHILOSOPHERS?color=blueviolet" /></a>
    <a href="https://github.com/f-corvaro/PHILOSOPHERS"><img alt="Code language count" src="https://img.shields.io/github/languages/count/f-corvaro/PHILOSOPHERS?color=yellow" /></a>
    <a href="https://github.com/f-corvaro/PHILOSOPHERS"><img alt="GitHub top language" src="https://img.shields.io/github/languages/top/f-corvaro/PHILOSOPHERS?color=blueviolet" /></a>
    <a href="https://github.com/f-corvaro/PHILOSOPHERS"><img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/f-corvaro/PHILOSOPHERS?color=yellow" /></a>
</p>

<h3 align="center">Index</h3>
<p align="center">


- [Introduction](#introduction)
  - [Overview](#overview)
- [Folder Structure](#folder-structure)
- [Project Requirements - Mandatory Part](#project-requirements---mandatory-part)
  - [Important Guidelines](#important-guidelines)
  - [Specific Rules for the Mandatory Part](#specific-rules-for-the-mandatory-part)
  - [Philosopher Seating Arrangement](#philosopher-seating-arrangement)
  - [Program name](#program-name)
    - [Usage](#usage)
    - [Program Parameters](#program-parameters)
  - [Files to Submit](#files-to-submit)
  - [Allowed External Functions](#allowed-external-functions)
  - [Log Format](#log-format)
  - [Output Requirements](#output-requirements)
- [Project Requirements - Bonus Part](#project-requirements---bonus-part)
  - [Specific Rules for the Bonus Part](#specific-rules-for-the-bonus-part)
  - [Program name'](#program-name-1)
    - [Usage](#usage-1)
    - [Program Parameters](#program-parameters-1)
  - [Files to Submit](#files-to-submit-1)
  - [Allowed External Functions](#allowed-external-functions-1)
- [Theoretical Background](#theoretical-background)
  - [Threads](#threads)
  - [Task Scheduler](#task-scheduler)
  - [Process](#process)
  - [Inter-Process Communication (IPC)](#inter-process-communication-ipc)
  - [Differences between Process and Thread](#differences-between-process-and-thread)
  - [Concurrency: Multithreading vs Multiprocessing](#concurrency-multithreading-vs-multiprocessing)
    - [Common Problems in Concurrent Programming](#common-problems-in-concurrent-programming)
    - [Synchronization - Mutex and Semaphore](#synchronization---mutex-and-semaphore)
- [Testing Tools for the Philosophers Project](#testing-tools-for-the-philosophers-project)
- [Evaluation Process](#evaluation-process)
  - [Correction sheet](#correction-sheet)
- [Developed Skills](#developed-skills)
- [References](#references)
- [Support and Contributions](#support-and-contributions)
- [Author](#author)

</p>
<br>

## Introduction

<p align="justify">

The Philosophers project is a classic problem in concurrent programming and synchronization. It aims to explore the dining philosophers problem, which involves simulating the behavior of philosophers sitting at a round table and performing actions such as eating, thinking, and sleeping. The project provides an opportunity to learn about threading, semaphores, mutexes, and shared memory. The challenge lies in ensuring that philosophers never starve and that careful synchronization is implemented to avoid issues like deadlock and race conditions. By working on this project, you can gain hands-on experience in implementing solutions to real-world problems in concurrent computing.

</p>
<br>

### Overview 

<p align="justify">

To successfully complete the Philosophers project, it is important to have a solid understanding of the following concepts:

- **Multithreading and Multiprocessing:** Familiarity with the distinction between threads and processes, as well as their creation and management, is essential for this project.

- **Concurrency and Synchronization:** Understanding concepts such as race conditions, deadlocks, and starvation is crucial. Additionally, knowing how to utilize synchronization primitives like mutexes and semaphores to prevent these issues is important.

- **Inter-Process Communication (IPC):** In the bonus part, where each philosopher is a separate process, knowledge of inter-process communication techniques is necessary.

</p>
<br>

## Folder Structure

<p align="justify">

```
.
├── philosophers
│   └── philo
│       ├── include
│       │   ├── config.h
│       │   ├── error_messages.h
│       │   ├── functions.h
│       │   ├── macro.h
│       │   ├── philo.h
│       │   └── types.h
│       ├── srcs
│       │   ├── input
│       │   │   ├── manipulation.c
│       │   │   └── validation.c
│       │   ├── simulation
│       │   │   ├── cleanup.c
│       │   │   ├── control.c
│       │   │   ├── init.c
│       │   │   ├── philosopher_actions_logger.c
│       │   │   ├── philosopher_behaviour.c
│       │   │   └── state.c
│       │   ├── utils
│       │   │   ├── error_management.c
│       │   │   ├── message_handling.c
│       │   │   └── time_operations.c
│       │   └── main.c
│       └── Makefile
```

<p>

## Project Requirements - Mandatory Part

### Important Guidelines

<p align="justify">

- The project must be written in C, following the Norm guidelines.
- Your functions should handle errors gracefully and avoid unexpected crashes or memory leaks.
- All dynamically allocated memory must be properly freed when no longer needed.
- Include a Makefile that compiles your source files with the flags -Wall, -Wextra, and -Werror. Use the cc compiler, and ensure that your Makefile does not relink. It should include the rules $(NAME), all, clean, fclean, and re. You can earn bonus points for additional rules.
- If you have any bonus features, place them in a separate file named _bonus.{c/h}.
- Do not use global variables.

</p>

### Specific Rules for the Mandatory Part

 - Each philosopher should be represented as a separate thread.
 - There should be one fork between each pair of philosophers. For example, if there are multiple philosophers, each philosopher should have a fork on their left side and a fork on their right side. If there is only one philosopher, there should be only one fork on the table.
 - To ensure that philosophers do not duplicate forks, you should protect the state of each fork using a mutex.

### Philosopher Seating Arrangement

 Each philosopher is assigned a number from 1 to `number_of_philosophers`. Philosopher number 1 sits next to philosopher number `number_of_philosophers`. For any other philosopher number N, they sit between philosopher number N - 1 and philosopher number N + 1.

### Program name
 
 `philo`

 #### Usage

 ```bash
 ./philo 5 800 200 200
 ```

 #### Program Parameters

 Your program should accept the following arguments:

 1. `number_of_philosophers`: This represents both the number of philosophers and the number of forks.
 2. `time_to_die` (in milliseconds): This is the maximum time a philosopher can go without eating before they die. It is measured from the start of their last meal or the beginning of the simulation.
 3. `time_to_eat` (in milliseconds): This is the time it takes for a philosopher to eat. During this time, they must hold two forks.
 4. `time_to_sleep` (in milliseconds): This is the time a philosopher will spend sleeping.
 5. `number_of_times_each_philosopher_must_eat` (optional): If all philosophers have eaten at least this many times, the simulation stops. If not specified, the simulation stops when a philosopher dies.

### Files to Submit

 To complete the project, you need to submit the following files located in the `philo/` directory:

 - `Makefile`: The makefile that compiles the project's source files.
 - `*.h`: Any header files used in the project.
 - `*.c`: All the source code files for the project.

### Allowed External Functions

 - Memory management functions: `memset`, `malloc`, `free`
 - Standard I/O functions: `printf`, `write`
 - Time management functions: `usleep`, `gettimeofday`
 - POSIX thread functions: `pthread_create`, `pthread_detach`, `pthread_join`, `pthread_mutex_init`, `pthread_mutex_destroy`, `pthread_mutex_lock`, `pthread_mutex_unlock`

 Please note that the use of the `ft_printf` or other functions from the Libft library is not authorized. 

### Log Format

The program should generate logs in the following format:

- `timestamp_in_ms X has taken a fork`
- `timestamp_in_ms X is eating`
- `timestamp_in_ms X is sleeping`
- `timestamp_in_ms X is thinking`
- `timestamp_in_ms X died`

Replace `timestamp_in_ms` with the current timestamp in milliseconds and `X` with the philosopher number.

### Output Requirements

- Each displayed state message should be distinct and not mixed up with another message.
- The announcement of a philosopher's death should be displayed within 10 ms after the actual death of the philosopher.
- Philosophers should strive to avoid dying!

***Your program must ensure there are no data races.***

This requirement emphasizes the importance of proper synchronization in your implementation. Data races can lead to unpredictable behavior and are a common issue in concurrent programming.

## Project Requirements - Bonus Part

### Specific Rules for the Bonus Part

In the bonus part of the project, there are specific rules that need to be followed:

- All the forks are placed in the middle of the table.
- Instead of maintaining states in memory, the number of available forks is represented by a semaphore.
- Each philosopher should be implemented as a separate process, while the main process should not act as a philosopher.

Please note that the bonus part will only be evaluated if the mandatory part is completed perfectly. Perfect completion of the mandatory requirements is a prerequisite for the assessment of the bonus part.

### Program name'
 
 `philo_bonus`

  #### Usage

 ```bash
 ./philo_bonus 5 800 200 200
 ```

 #### Program Parameters

 Your program should accept the following arguments:

 1. `number_of_philosophers`: This represents both the number of philosophers and the number of forks.
 2. `time_to_die` (in milliseconds): This is the maximum time a philosopher can go without eating before they die. It is measured from the start of their last meal or the beginning of the simulation.
 3. `time_to_eat` (in milliseconds): This is the time it takes for a philosopher to eat. During this time, they must hold two forks.
 4. `time_to_sleep` (in milliseconds): This is the time a philosopher will spend sleeping.
 5. `number_of_times_each_philosopher_must_eat` (optional): If all philosophers have eaten at least this many times, the simulation stops. If not specified, the simulation stops when a philosopher dies.

### Files to Submit

 To complete the project, you need to submit the following files located in the `philo_bonus/` directory:

 - `Makefile`: The makefile that compiles the project's source files.
 - `*.h`: Any header files used in the project.
 - `*.c`: All the source code files for the project.

### Allowed External Functions

 - Memory management functions: `memset`, `malloc`, `free`
 - Standard I/O functions: `printf`, `write`
 - Process control functions: `fork`, `kill`, `exit`, `waitpid`
 - POSIX thread functions: `pthread_create`, `pthread_detach`, `pthread_join`
 - Time management functions: `usleep`, `gettimeofday`
 - Semaphore functions: `sem_open`, `sem_close`, `sem_post`, `sem_wait`, `sem_unlink`
  
 Please note that the use of the `ft_printf` or other functions from the Libft library is not authorized. 

## Theoretical Background

<p align="justify">

### Threads

<p align="justify">

A thread is the smallest unit of execution within a program, managed independently by a scheduler. It allows a program to perform multiple tasks concurrently. Threads within the same process share the same data space, enabling easier communication and coordination between them.

An analogy could be drawn to a factory, where each thread represents a worker performing a specific task as part of the production process. Multiple threads can work simultaneously, sharing resources and collaborating to achieve the overall goal of the program.

In the context of the Philosophers project, each philosopher can be seen as a thread, engaging in actions such as thinking, eating, and sleeping concurrently with other philosophers.

</p>

### Task Scheduler

<p align="justify">

A task scheduler, in the context of computer science, is a component of the operating system that manages the execution of processes or threads on the available CPUs.

An analogy could be drawn to a factory manager who assigns tasks to workers based on various factors such as task priority, resource allocation, and workload balancing. The task scheduler ensures that all running processes or threads receive a fair share of the available CPU time and prevents high-priority tasks from being starved by lower-priority tasks. It is also responsible for efficiently switching the CPU between different tasks, a process known as context switching.

In a multitasking operating system, the task scheduler plays a crucial role in optimizing resource utilization and maintaining system responsiveness. By efficiently managing the execution of tasks, it helps maximize productivity and ensure smooth operation of the system.

</p>

### Process

<p align="justify">

A process is an instance of a computer program that is being executed. It contains the program code and its current activity. Each process has its own separate memory space, ensuring that one process cannot access the variables and data structures of another.

In the context of computer science, a process can be compared to a project in a factory. Each project (process) has its own set of resources and a dedicated workspace (memory space). Projects (processes) operate independently of each other, with no direct access to each other's resources or workspace. However, they can communicate through specific channels, known as inter-process communication (IPC).

In the Philosophers project, each philosopher can be seen as a separate process, carrying out their actions (thinking, eating, sleeping) independently of the other philosophers (processes). In the bonus part of the project, each philosopher is implemented as a distinct process.

</p>

### Inter-Process Communication (IPC)

<p align="justify">

Inter-Process Communication (IPC) is a crucial mechanism that enables processes to communicate and synchronize their actions. It serves as a mail system for processes, allowing them to exchange messages and share data.

IPC mechanisms include pipes, message queues, shared memory, and sockets. These mechanisms facilitate coordination and communication among multiple processes, enabling them to work together effectively.

In the context of the Philosophers project, IPC plays a vital role in ensuring proper synchronization and data sharing between the philosopher processes. It allows them to coordinate their actions, share information, and avoid conflicts.

</p>

### Differences between Process and Thread

<p align="justify">

Processes and threads are both units of execution within a program, but they have some key differences. 

A **process** is an instance of a program that runs independently and has its own memory space. Processes are isolated from each other and communicate through inter-process communication mechanisms. Each process has its own resources and can execute multiple threads. Processes are heavyweight and have higher overhead due to the need for separate memory space.

On the other hand, a **thread** is a lightweight unit of execution within a process. Threads share the same memory space and resources of the process they belong to. Multiple threads within a process can execute concurrently and communicate through shared memory. Threads are more efficient in terms of memory usage and context switching compared to processes.

In summary, processes are independent entities with separate memory spaces, while threads are lightweight units within a process that share the same memory space. Processes provide better isolation and stability, while threads offer better performance and resource sharing capabilities.

</p>

### Concurrency: Multithreading vs Multiprocessing

Concurrency is a fundamental concept in computer science that involves the execution of multiple independent tasks simultaneously. It allows programs to make better use of the CPU and improve overall efficiency. There are two common approaches to achieve concurrency: multithreading and multiprocessing.

**Multithreading** involves dividing a single program into multiple threads that run in parallel. These threads share the same memory space, enabling fast and efficient communication. However, proper synchronization is crucial to prevent conflicts when accessing shared memory.

**Multiprocessing** entails running multiple separate programs (processes) simultaneously. Each process has its own memory space, eliminating the risk of interference. However, inter-process communication (IPC) is required for processes to exchange data and coordinate their actions.

In the Philosophers project, you have the flexibility to choose between implementing philosophers as threads (mandatory part) or processes (bonus part). Regardless of your choice, careful management of interactions is essential to avoid issues such as race conditions and deadlocks.

</p>


#### Common Problems in Concurrent Programming

<p align="justify">

1. **Deadlocks**: Deadlocks occur when two or more philosophers are unable to proceed because each is waiting for the other to release a fork. For example, if philosopher A has one fork and needs the other, which is held by philosopher B, who also needs the fork held by philosopher A, neither philosopher can proceed. They are in a deadlock.

2. **Starvation**: Starvation happens when a philosopher is perpetually denied access to the forks and thus cannot eat. This usually occurs in a scheduling system where resources are assigned with priority, and a philosopher keeps getting bumped in favor of others.

3. **Race Conditions**: Race conditions occur when the behavior of the philosophers depends on the relative timing of their actions. For example, if two philosophers try to grab the same fork at the same time, the final state could depend on which philosopher gets to the fork first, leading to unpredictable results.

4. **Livelocks**: Livelocks are similar to deadlocks, except that the states of the processes involved in the livelock constantly change with regard to one another, none progressing. Livelocks are a special case of resource starvation.

</p>

#### Synchronization - Mutex and Semaphore

<p align="justify">

**Synchronization** is the coordination of simultaneous threads or processes to complete a task, maximizing speed and efficiency while minimizing overlap and conflicts. It ensures that only one thread or process can access a shared resource at a time. This is achieved using synchronization primitives like locks, semaphores, or monitors.

In the context of the Philosophers project, synchronization is crucial to prevent race conditions when multiple philosophers try to access the same fork simultaneously.

A **mutex** (mutual exclusion) is a synchronization primitive that allows only one thread to access a shared resource at a time. It acts like a key to a bathroom, ensuring exclusive access. When a thread acquires the mutex, no other thread can access the resource until it releases the mutex.

A **semaphore** is a synchronization primitive that controls access to a shared resource using a counter. If the counter is greater than zero, the semaphore allows access. If it's zero, the semaphore blocks until the counter increases. It can be compared to a nightclub bouncer, allowing a certain number of people inside. If the club is full, new people have to wait.

A **monitor** is a synchronization construct that provides mutual exclusion and the ability to wait for a condition to become true. It consists of a mutex and condition variables. Condition variables allow threads to temporarily give up exclusive access and wait for a condition to be met before continuing.

</p>

## Testing Tools for the Philosophers Project

<p align="justify">

- [Philosophers Tester by kichkiro](https://github.com/kichkiro/philosophers_tester): A comprehensive tester for the Philosophers project, providing various test cases to ensure the correctness of your implementation.
- [Philosophers Tester by Aldisti](https://github.com/Aldisti/philosophers-tester): Another useful tester for the Philosophers project, offering a range of scenarios to validate your code.
- [Philosophers Tester by moulin-louis](https://github.com/moulin-louis/philosophers-tester): A detailed tester designed to help you debug and verify your Philosophers project.
- [Philosophers Tester by Yoo0lh](https://github.com/Yoo0lh/philosopher_tester): A robust tester for the Philosophers project, featuring multiple test cases to check the reliability of your solution.

## Evaluation Process

### Correction sheet

<a href="https://github.com/f-corvaro/PHILOSOPHERS/tree/main"><img width="650" src="https://github.com/f-corvaro/PHILOSOPHERS/blob/main/.extra/philo_cs.jpg">

</p>
<br>

## Developed Skills

<p align="center">
  <a href="https://skillicons.dev">
    <img src="https://skillicons.dev/icons?i=git,c,vim,vscode" />
  </a>
</p><br>

## References

- [Concurrency in Computer Science](https://en.wikipedia.org/wiki/Concurrency_(computer_science)): An overview of concurrency concepts in computer science.
- [Dining Philosophers Problem Guide](https://medium.com/@ruinadd/philosophers-42-guide-the-dining-philosophers-problem-893a24bc0fe2): A detailed guide on the Dining Philosophers problem.
- [Code Vault YouTube Playlist](https://www.youtube.com/playlist?list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2): A playlist of videos covering various concurrency topics.
- [Threads in Computing](https://en.wikipedia.org/wiki/Thread_(computing)): An introduction to threads and their use in computing.
- [Understanding Threads](https://philosophers.simple.ink/threads-4cf298dbad9f4c36ba5e01e8a364e102): An in-depth article on threads and their role in concurrent programming.
- [Semaphore in Operating Systems](https://en.wikipedia.org/wiki/Semaphore_(programming)): Explanation of semaphores and their role in process synchronization.
- [POSIX Threads Programming](https://computing.llnl.gov/tutorials/pthreads/): A comprehensive tutorial on POSIX threads (pthreads).
- [Mutexes and Condition Variables](https://www.cs.cmu.edu/afs/cs/academic/class/15492-f07/www/pthreads.html): Detailed information on mutexes and condition variables in pthreads.
- [Dining Philosophers Problem on GeeksforGeeks](https://www.geeksforgeeks.org/dining-philosopher-problem-using-semaphores/): An article explaining the Dining Philosophers problem using semaphores.
- [Concurrency Patterns](https://martinfowler.com/articles/lmax.html): An article discussing various concurrency patterns and their applications.
- [Deadlock in Operating Systems](https://www.geeksforgeeks.org/deadlock-in-operating-system/): An overview of deadlock conditions and how to handle them in operating systems.
- [Understanding Race Conditions](https://en.wikipedia.org/wiki/Race_condition): An explanation of race conditions and their impact on concurrent programming.

<br>

## Support and Contributions

<p align="center">
If you find this repository helpful, please consider starring it to show your support. Your support is greatly appreciated!</p>

<p align="center">
<a href="https://ko-fi.com/fcorvaro"><img width="180" img align="center" src="https://github.com/f-corvaro/42.common_core/blob/main/.extra/support-me-ko-fi.svg"><alt=""></a>
<a href="https://github.com/sponsors/f-corvaro"><img width="180" img align="center" src="https://github.com/f-corvaro/42.common_core/blob/main/.extra/support-me-github.svg"><alt=""></a>

<br>

## Author

<p align="center"><a href="https://profile.intra.42.fr/users/fcorvaro"><img style="height:auto;" src="https://avatars.githubusercontent.com/u/102758065?v=4" width="100" height="100"alt=""></a>
<p align="center">
<a href="mailto:fcorvaro@student.42roma.it"><kbd>Email</kbd><alt=""></a>
<a href="https://github.com/f-corvaro"><kbd>Github</kbd><alt=""></a>
<a href="https://www.linkedin.com/in/f-corvaro/"><kbd>Linkedin</kbd><alt=""></a>
<a href="https://42born2code.slack.com/team/U050L8XAFLK"><kbd>Slack</kbd><alt=""></a>

<hr/>
