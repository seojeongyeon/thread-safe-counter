# Project2_ thread-safe-counter_20183382 seojeongyeon
+ semaphore instead of mutex
+ semaphore : Synchronization techniques that send control signals to each process to perform operations in order
+ There are many technologies in semaphore, I used binary semaphore technology.
+ I made two executable files and compared them. (lock -> a.out , semaphore -> semaphore.out)

<hr>

## Code Description
+ sem_init : Initializes semaphore objects, sets sharing options, and sets initial integer values
+ sem_wait : If the semaphore value received by lock_t *c is greater than 1, decrease it and immediately exit the function. However, if the value is zero, this value is greater than 1 and causes the operation to wait at the current point unless there is an interrupt call.
+ sem_post : increases the value of semaphores received by lock_t *c. If the semaphore value is greater than 1, wake up the process or thread waiting by another sem_wait().

## Compare lock and semaphore
![Screenshot from 2021-06-12 02-51-36](https://user-images.githubusercontent.com/43339377/121731651-326dfa80-cb2c-11eb-963e-4aa59a0bc604.png)


## Result
Performance comparisons show that locking is faster than semaphore. A lock is waiting for the lock's owning process to unlock it. Semaphore, on the other hand, performs wait() operations when all resources are in use, and wakes up by other processes when the semaphore value is greater than 1.
Therefore, lock does not require context switching, and semaphore must store running process statistics and reload other processes into cpu, which is time consuming.
