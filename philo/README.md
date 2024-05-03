
## The specific rules for the mandatory part are:

Your(s) program(s) should take the following arguments:

- number_of_philosophers 
- time_to_die 
- time_to_eat 
- time_to_sleep
- [number_of_times_each_philosopher_must_eat]





- Each philosopher should be a thread.

- There is one fork between each pair of philosophers. Therefore, if there are several
philosophers, each philosopher has a fork on their left side and a fork on their right
side. If there is only one philosopher, there should be only one fork on the table.

- To prevent philosophers from duplicating forks, you should protect the forks state
with a mutex for each of them.



Philosophers with threads and mutexes

ALLOWED FUNCTIONS:
- `<string.h>`: 
	-	memset (Initialize memory block with a specific value)
- `<stdio.h>`: 
	- printf (Print formatted output)
- `<stdlib.h>`: 
	- malloc (Allocate memory dynamically)
	- free (Deallocate memory)
- `<unistd.h>`: 
	- write (Write to a file descriptor) 
	- usleep (Suspend execution for a specified number of microseconds)
- `<sys/time.h>`: 
	- gettimeofday (Get the current time)
- `<pthread.h>`: 
	- pthread_create (Create a new thread)
	- pthread_detach (Detach a thread)
	- pthread_join (Wait for a thread to terminate)
	- pthread_mutex_init (Initialize a mutex)
	- pthread_mutex_destroy (Destroy a mutex)
	- pthread_mutex_lock (Lock a mutex)
	- pthread_mutex_unlock (Unlock a mutex)
