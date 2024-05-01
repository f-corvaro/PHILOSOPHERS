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

- [Folder Structure](#folder-structure)
- [About](#about)
- [Common Instructions:](#common-instructions)
- [Mandatory Part Details](#mandatory-part-details)
  - [Specific Rules for the Mandatory Part](#specific-rules-for-the-mandatory-part)
  - [Program Parameters](#program-parameters)
  - [Philosopher Seating Arrangement](#philosopher-seating-arrangement)
  - [Log Format](#log-format)
  - [Output Requirements](#output-requirements)
- [Bonus Part](#bonus-part)
  - [Specific Rules for the Bonus Part](#specific-rules-for-the-bonus-part)
- [Background Knowledge](#background-knowledge)
  - [Overview](#overview)
  - [Thread](#thread)
  - [Scheduler](#scheduler)
  - [Process](#process)
  - [Concurrency](#concurrency)
  - [Multithreading and Multiprocessing](#multithreading-and-multiprocessing)
  - [IPC](#ipc)
  - [Common problems in concurrent programming](#common-problems-in-concurrent-programming)
  - [Synchronization - Mutex and Semaphore](#synchronization---mutex-and-semaphore)
- [Tester](#tester)
- [Evaluation](#evaluation)
  - [Correction sheet](#correction-sheet)
- [Support Me](#support-me)
- [Skills developed](#skills-developed)
- [Sources](#sources)
- [Author](#author)


## Folder Structure

<p align="justify">

```
.
├── PHILOSOPHERS

```
</p>

## About

<p align="justify">

The Philosophers project is part of the curriculum at 42 school. It is a classic problem in concurrent programming and synchronization. The goal of the project is to learn the basics of threading a process and how to work with semaphores, mutexes, and shared memory.

The project simulates the behavior of a number of philosophers sitting at a round table, each doing one of three things: eating, thinking, or sleeping. A philosopher cannot eat while sleeping or thinking, and cannot sleep or think while eating. A philosopher can do only one thing. 

On the table, there are as many forks as philosophers. Serving and eating spaghetti with only one fork is very inconvenient, so a philosopher takes their right and left forks to eat, one in each hand. When a philosopher has finished eating, they put their forks back on the table and start sleeping. Once awake, they start thinking again. The simulation stops when a philosopher dies of starvation.

The challenge lies in ensuring that philosophers never starve, i.e., every philosopher must get a chance to eat. This requirement introduces the need for careful synchronization to avoid conditions like deadlock and race conditions, which are common in multi-threading problems. The project is a hands-on implementation of a well-known problem in computer science known as the dining philosophers problem.

Philosophers don’t speak with each other and don’t know if another philosopher is about to die. It goes without saying that philosophers should avoid dying.

The project also includes a bonus part where the same problem has to be solved using processes instead of threads. This part introduces the concept of inter-process communication and the differences between process and thread management.

The Philosophers project is not just about coding, but also about understanding and applying complex concepts in real-world scenarios. Give the chance to think critically about resource allocation and process synchronization, which are crucial in systems programming and concurrent computing.

</p>


## Common Instructions:

<p align="justify">

- The project must be written in C (in accordance with the Norm).

- Your functions should not quit unexpectedly (segmentation fault, bus error, double free, etc) apart from undefined behaviors.

- All heap allocated memory space must be properly freed when necessary.

- You must submit a Makefile which will compile your source files to the required output with the flags -Wall, -Wextra and -Werror, use cc, and your Makefile must not relink. And the Makefile must at least contain the rules $(NAME), all, clean, fclean and re (bonus if you want maximum score).

- Bonuses must be in a different file _bonus.{c/h}

- Global variables are forbidden.

</p>

## Mandatory Part Details

**Program Name:** `philo`

**Files to Turn In:** `Makefile`, `*.h`, `*.c`, located in the `philo/` directory

**Makefile Rules:** `NAME`, `all`, `clean`, `fclean`, `re`

**Program Arguments:** 
- `number_of_philosophers`
- `time_to_die`
- `time_to_eat`
- `time_to_sleep`
- `[number_of_times_each_philosopher_must_eat]` (optional)

**External Functions Allowed:**
- `memset`, `printf`, `malloc`, `free`, `write`
- `usleep`, `gettimeofday`, `pthread_create`
- `pthread_detach`, `pthread_join`, `pthread_mutex_init`
- `pthread_mutex_destroy`, `pthread_mutex_lock`, `pthread_mutex_unlock`

**Libft Authorized:** No

**Description:** Philosophers with threads and mutexes

### Specific Rules for the Mandatory Part

- Each philosopher should be a thread.
- There is one fork between each pair of philosophers. Therefore, if there are several philosophers, each philosopher has a fork on their left side and a fork on their right side. If there is only one philosopher, there should be only one fork on the table.
- To prevent philosophers from duplicating forks, you should protect the forks state with a mutex for each of them.

### Program Parameters

Your program should accept the following arguments:

1. `number_of_philosophers`: This represents both the number of philosophers and the number of forks.
2. `time_to_die` (in milliseconds): This is the maximum time a philosopher can go without eating before they die. It is measured from the start of their last meal or the beginning of the simulation.
3. `time_to_eat` (in milliseconds): This is the time it takes for a philosopher to eat. During this time, they must hold two forks.
4. `time_to_sleep` (in milliseconds): This is the time a philosopher will spend sleeping.
5. `number_of_times_each_philosopher_must_eat` (optional): If all philosophers have eaten at least this many times, the simulation stops. If not specified, the simulation stops when a philosopher dies.

### Philosopher Seating Arrangement

Each philosopher is assigned a number from 1 to `number_of_philosophers`. Philosopher number 1 sits next to philosopher number `number_of_philosophers`. Any other philosopher number N sits between philosopher number N - 1 and philosopher number N + 1.

### Log Format

The program should output logs in the following format:

- `timestamp_in_ms X has taken a fork`
- `timestamp_in_ms X is eating`
- `timestamp_in_ms X is sleeping`
- `timestamp_in_ms X is thinking`
- `timestamp_in_ms X died`

Replace `timestamp_in_ms` with the current timestamp in milliseconds and `X` with the philosopher number.

### Output Requirements

- A displayed state message should not be mixed up with another message.
- A message announcing a philosopher's death should be displayed no more than 10 ms after the actual death of the philosopher.
- Philosophers should strive to avoid dying!

***Your program must not have any data races.***

This requirement emphasizes the importance of proper synchronization in your implementation. Data races can lead to unpredictable behavior and are a common issue in concurrent programming.

## Bonus Part

**Program Name:** `philo_bonus`

**Files to Turn In:** `Makefile`, `*.h`, `*.c`, located in the `philo_bonus/` directory

**Makefile Rules:** `NAME`, `all`, `clean`, `fclean`, `re`

**Program Arguments:** 
- `number_of_philosophers`
- `time_to_die`
- `time_to_eat`
- `time_to_sleep`
- `[number_of_times_each_philosopher_must_eat]` (optional)

**External Functions Allowed:**
- `memset`, `printf`, `malloc`, `free`, `write`, `fork`, `kill`
- `exit`, `pthread_create`, `pthread_detach`, `pthread_join`
- `usleep`, `gettimeofday`, `waitpid`, `sem_open`, `sem_close`
- `sem_post`, `sem_wait`, `sem_unlink`

**Libft Authorized:** No

**Description:** Philosophers with processes and semaphores

The program of the bonus part takes the same arguments as the mandatory program. 

### Specific Rules for the Bonus Part

- All the forks are put in the middle of the table.
- They have no states in memory but the number of available forks is represented by a semaphore.
- Each philosopher should be a process. But the main process should not be a philosopher.

**Note:** The bonus part will only be assessed if the mandatory part is PERFECT. Perfect means the mandatory part has been integrally done and works without malfunctioning. If you have not passed ALL the mandatory requirements, your bonus part will not be evaluated at all.

## Background Knowledge

<p align="justify">

### Overview 

<p align="justify">

To successfully complete the Philosophers project, you should have a good understanding of the following concepts:

- **Multithreading and Multiprocessing:** Understanding the difference between threads and processes, and how to create and manage them, is crucial for this project.

- **Concurrency and Synchronization:** You should be familiar with concepts like race conditions, deadlocks, and starvation. You should also know how to use synchronization primitives like mutexes and semaphores to avoid these issues.

- **Inter-Process Communication (IPC):** Since each philosopher is a separate process in the bonus part, you'll need to know how to communicate between processes.

</p>

### Thread

<p align="justify">

A thread, in the context of computer science, is the smallest sequence of programmed instructions that can be managed independently by a scheduler, which is typically a part of the operating system. 

Threads are a way for a program to divide itself into two or more concurrently running tasks. Threads within the same process share the same data space, which means they can communicate with each other more easily than if they were separate processes. 

An example could be:

A thread is like a worker in a factory. Each worker (thread) is doing a specific job (task) as part of the overall production process. The factory (program) can have multiple workers (threads) all doing different jobs (tasks) at the same time. These workers (threads) can communicate and coordinate with each other because they're all in the same factory (program), sharing the same resources.

In the context of Philosophers project, each philosopher could be thought of as a thread, performing their actions (thinking, eating, sleeping) concurrently with the other philosophers (threads).

</p>

### Scheduler

<p align="justify">

A scheduler, in the context of computer science, is a component of the operating system that manages the execution of processes or threads on the available CPUs.

An example could be:

A scheduler is like a manager in a factory. The manager (scheduler) decides which worker (thread or process) should work on which machine (CPU) at what time. The manager (scheduler) has to make these decisions based on a variety of factors, such as the priority of the task, the need to share resources fairly between workers, and the need to keep all the machines (CPUs) as busy as possible.

In a multitasking operating system, the scheduler ensures that all running processes or threads get a fair share of the available CPU time, and that high-priority tasks are not starved of CPU time by lower-priority tasks. The scheduler is also responsible for switching the CPU from one task to another, a process known as context switching.

</p>

### Process

<p align="justify">

A process, in the context of computer science, is an instance of a computer program that is being executed. It contains the program code and its current activity. Each process has a separate memory space, and one process cannot access the variables and data structures of another.

An example could be:

A process is like a project in a factory. Each project (process) has its own set of resources and a workspace (memory space). Projects (processes) are independent of each other, and one project can't directly access the resources or workspace of another. However, projects can communicate with each other through specific channels, a concept known as inter-process communication (IPC).

In the context of Philosophers project, each philosopher could be thought of as a process, performing their actions (thinking, eating, sleeping) independently of the other philosophers (processes). In the bonus part of the project, each philosopher is indeed a separate process.

</p>

### Concurrency

<p align="justify">

**Concurrency** is a property of systems in which several independent tasks are executing simultaneously. The tasks could be multiple threads within a single program, multiple processes across multiple systems, or a combination of both. Concurrency can help utilize the CPU better and increase the efficiency of the program.

</p>

### Multithreading and Multiprocessing

<p align="justify">

Multithreading and multiprocessing are two ways that a computer program can do multiple things at once, a concept known as concurrency.

In **multithreading**, a single program is divided into two or more threads, which are like mini-programs that run in parallel. These threads share the same memory space, which means they can communicate with each other more quickly and easily. However, because they share memory, they need to carefully coordinate when they read and write to that memory to avoid conflicts, a concept known as **synchronization**.

On the other hand, **multiprocessing** involves running multiple separate programs (processes) at the same time. Each process has its own separate memory space, so they can't accidentally interfere with each other like threads can. But if they need to communicate with each other, they have to use a slower and more complicated method known as **inter-process communication** (**IPC**).

In the context of the Philosophers project, each philosopher could be a thread (in the mandatory part) or a process (in the bonus part). This means you'll need to manage their interactions carefully to avoid problems like **race conditions** (where two threads or processes try to access or change the same data at the same time) and **deadlocks** (where two threads or processes each wait for the other to release a resource, causing both to wait forever).

</p>

### IPC

<p align="justify">

Inter-Process Communication (IPC) is a mechanism that allows processes to communicate with each other and synchronize their actions. IPC is used to share data, signals, or events among multiple processes to achieve coordination or communication.

An example could be:

**Inter-Process Communication (IPC)** is like a mail system for processes. Just as people can send letters to each other to share information, processes can send messages to each other to share data. IPC mechanisms include pipes, message queues, shared memory, and sockets.

</p>

### Common problems in concurrent programming

<p align="justify">

1. **Deadlocks**: This occurs when two or more philosophers are unable to proceed because each is waiting for the other to release a fork. For example, if philosopher A has one fork and needs the other, which is held by philosopher B, who also needs the fork held by philosopher A, neither philosopher can proceed. They are in a deadlock.

2. **Starvation**: This happens when a philosopher is perpetually denied access to the forks and thus cannot eat. This usually happens in a scheduling system where resources are assigned with priority, and a philosopher keeps getting bumped in favor of others.

3. **Race Conditions**: This occurs when the behavior of the philosophers depends on the relative timing of their actions. For example, if two philosophers try to grab the same fork at the same time, the final state could depend on which philosopher gets to the fork first, leading to unpredictable results.

4. **Livelocks**: A livelock is similar to a deadlock, except that the states of the processes involved in the livelock constantly change with regard to one another, none progressing. Livelocks are a special case of resource starvation.

</p>

### Synchronization - Mutex and Semaphore

<p align="justify">

**Synchronization** is the coordination of simultaneous threads or processes to complete a task, with the objective of maximizing speed and efficiency while minimizing overlap and potential conflicts. In a concurrent application, synchronization ensures that only one thread or process can access a shared resource (like a variable, file, etc.) at a time. This is typically achieved using mechanisms like locks, semaphores, or monitors.

Synchronization is needed to ensure that no two philosophers are using the same fork at the same time, which would lead to a race condition.

A **mutex** (short for "mutual exclusion") is a synchronization primitive that prevents simultaneous access to a shared resource. It's like a key to a bathroom — only one person can use the bathroom at a time. When a thread acquires the mutex (takes the key), no other thread can access the protected resource until the first thread releases the mutex (returns the key).

A **semaphore** is a more general synchronization primitive that controls access to a shared resource through the use of a counter. If the counter is greater than zero, the semaphore allows access to the shared resource. If it's zero, the semaphore blocks until the counter becomes greater than zero. A semaphore can be thought of as a nightclub bouncer, who only allows a certain number of people inside. If the club is full, new people have to wait until others leave.

A **monitor** is a synchronization construct that allows threads to have both mutual exclusion and the ability to wait (block) for a certain condition to become true. Monitors also have a mechanism for signaling other threads that their condition has been met. A monitor consists of a mutex (lock) object and condition variables.

A condition variable is basically a container of threads that are waiting for a certain condition. Monitors provide a mechanism for threads to temporarily give up exclusive access in order to wait for some condition to be met, before regaining exclusive access and continuing.

</p>

## Tester

<p align="justify">

## Evaluation

### Correction sheet

</p>
<br>


## Support Me

<p align="justify">
Remember to ⭐ the repository.
If you want to support me:</p>

<p align="center">
<a href="https://ko-fi.com/fcorvaro"><img width="180" img align="center" src="https://github.com/f-corvaro/42.common_core/blob/main/.extra/support-me-ko-fi.svg"><alt=""></a>
<a href="https://github.com/sponsors/f-corvaro"><img width="180" img align="center" src="https://github.com/f-corvaro/42.common_core/blob/main/.extra/support-me-github.svg"><alt=""></a>

<br>

## Skills developed

<p align="center">
  <a href="https://skillicons.dev">
    <img src="https://skillicons.dev/icons?i=git,c,vim,vscode" />
  </a>
</p><br>

## Sources

- [Concurrency](https://en.wikipedia.org/wiki/Concurrency_(computer_science));
- [Philosophers guide 1](https://medium.com/@ruinadd/philosophers-42-guide-the-dining-philosophers-problem-893a24bc0fe2);
- [Code Vault playlist](https://www.youtube.com/playlist?list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2);
- [Thread](https://en.wikipedia.org/wiki/Thread_(computing));
- []();
- []();
- []();
- []();
- []();
- []();
- []();

<br>

## Author

<p align="center"><a href="https://profile.intra.42.fr/users/fcorvaro"><img style="height:auto;" src="https://avatars.githubusercontent.com/u/102758065?v=4" width="100" height="100"alt=""></a>
<p align="center">
<a href="mailto:fcorvaro@student.42roma.it"><kbd>Email</kbd><alt=""></a>
<a href="https://github.com/f-corvaro"><kbd>Github</kbd><alt=""></a>
<a href="https://www.linkedin.com/in/f-corvaro/"><kbd>Linkedin</kbd><alt=""></a>
<a href="https://42born2code.slack.com/team/U050L8XAFLK"><kbd>Slack</kbd><alt=""></a>

<hr/>