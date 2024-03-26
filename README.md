<h1 align="center">PHILOSOPHERS</h1>

<p align="center">
  <a href="https://github.com/f-corvaro/PHILOSOPHERS">
	<img src="https://github.com/f-corvaro/PHILOSOPHERS/blob/main/.extra/philosophers.png" alt="PHILOSOPHERS">
  </a>
</p>

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

## Specific Rules for the Mandatory Part

- Each philosopher should be a thread.
- There is one fork between each pair of philosophers. Therefore, if there are several philosophers, each philosopher has a fork on their left side and a fork on their right side. If there is only one philosopher, there should be only one fork on the table.
- To prevent philosophers from duplicating forks, you should protect the forks state with a mutex for each of them.

## Program Parameters

Your program should accept the following arguments:

1. `number_of_philosophers`: This represents both the number of philosophers and the number of forks.
2. `time_to_die` (in milliseconds): This is the maximum time a philosopher can go without eating before they die. It is measured from the start of their last meal or the beginning of the simulation.
3. `time_to_eat` (in milliseconds): This is the time it takes for a philosopher to eat. During this time, they must hold two forks.
4. `time_to_sleep` (in milliseconds): This is the time a philosopher will spend sleeping.
5. `number_of_times_each_philosopher_must_eat` (optional): If all philosophers have eaten at least this many times, the simulation stops. If not specified, the simulation stops when a philosopher dies.

## Philosopher Seating Arrangement

Each philosopher is assigned a number from 1 to `number_of_philosophers`. Philosopher number 1 sits next to philosopher number `number_of_philosophers`. Any other philosopher number N sits between philosopher number N - 1 and philosopher number N + 1.

## Log Format

The program should output logs in the following format:

- `timestamp_in_ms X has taken a fork`
- `timestamp_in_ms X is eating`
- `timestamp_in_ms X is sleeping`
- `timestamp_in_ms X is thinking`
- `timestamp_in_ms X died`

Replace `timestamp_in_ms` with the current timestamp in milliseconds and `X` with the philosopher number.

## Output Requirements

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

## Specific Rules for the Bonus Part

- All the forks are put in the middle of the table.
- They have no states in memory but the number of available forks is represented by a semaphore.
- Each philosopher should be a process. But the main process should not be a philosopher.

**Note:** The bonus part will only be assessed if the mandatory part is PERFECT. Perfect means the mandatory part has been integrally done and works without malfunctioning. If you have not passed ALL the mandatory requirements, your bonus part will not be evaluated at all.

## Background Knowledge

<p align="justify">



</p>

## Tester


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

- 

<br>

## Author

<p align="center"><a href="https://profile.intra.42.fr/users/fcorvaro"><img style="height:auto;" src="https://avatars.githubusercontent.com/u/102758065?v=4" width="100" height="100"alt=""></a>
<p align="center">
<a href="mailto:fcorvaro@student.42roma.it"><kbd>Email</kbd><alt=""></a>
<a href="https://github.com/f-corvaro"><kbd>Github</kbd><alt=""></a>
<a href="https://www.linkedin.com/in/f-corvaro/"><kbd>Linkedin</kbd><alt=""></a>
<a href="https://42born2code.slack.com/team/U050L8XAFLK"><kbd>Slack</kbd><alt=""></a>

<hr/>