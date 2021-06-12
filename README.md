# Project2_ thread-safe-counter_20183382 seojeongyeon
+ semaphore instead of mutex
+ semaphore : Synchronization techniques that send control signals to each process to perform operations in order
+ There are many technologies in semaphore, I used binary semaphore technology.(semaphore.c) 
+ I made three executable files and compared them. (lock -> a.out , refer_semaphore -> refer_semaphore.out, (semaphore -> semaphore.out))
+ **I made two semaphores. Please use reference_semaphore.c for grading!!!!! (refer_semaphore.c : refer to professor's code, semaphore.c : made using built-in function)**

<hr>

## Code Description
Semaphore was implemented in two ways.
1. `refer_semaphore.c(refer to professor's code)`
+ semget(key_t key, int nsems, int semflg) : create semaphore
+ semctl(int semid, int semnum, int cmd, ...): Semaphore Operations
+ semop(int semid, struct sembuf *sops, size_t nsops): Semaphore Control

2. `semaphore.c(made using built-in function)`
+ sem_init : Initializes semaphore objects, sets sharing options, and sets initial integer values
+ sem_wait : If the semaphore value received by lock_t *c is greater than 1, decrease it and immediately exit the function. However, if the value is zero, this value is greater than 1 and causes the operation to wait at the current point unless there is an interrupt call.
+ sem_post : increases the value of semaphores received by lock_t *c. If the semaphore value is greater than 1, wake up the process or thread waiting by another sem_wait().

## Compare lock and semaphore
![Screenshot from 2021-06-12 21-23-59](https://user-images.githubusercontent.com/43339377/121776261-d7d5ac80-cbc6-11eb-855f-eff88a0bd63e.png)
<hr>
Run semaphore made with built-in function = results similar

![Screenshot from 2021-06-12 21-24-23](https://user-images.githubusercontent.com/43339377/121776323-2be09100-cbc7-11eb-8934-075cee9966a3.png)




## Result
Performance comparisons show that locking is faster than semaphore. A lock is waiting for the lock's owning process to unlock it. Semaphore, on the other hand, performs wait() operations when all resources are in use, and wakes up by other processes when the semaphore value is greater than 1.
Therefore, lock does not require context switching, and semaphore must store running process statistics and reload other processes into cpu, which is time consuming.
