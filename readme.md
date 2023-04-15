
# Philosophers Frenzy
Original dinners problem: 

1) With strict ordering(B) - five threads are created which resemble the philosophers(0..4), further philosopher 0 and 1 starts eating together and then after eating for some time they both start thinking together. They at the same time ask philosophers right of them to eat and so on, cycle continues inifinitely.

2) With use of semaphores(A) - five threads are created which resemble the philosophers(0..4) and five semaphores which resemvle forks, further philosophers know the fork numbers from which they want to eat. All the philosophers before picking fork will need to acquire the semaphore and after eating they will release the semaphore. If two philosophers at same time try to acquire the same semaphore then one of them will wait for the other to release the semaphore.

Modified dinners problem : we have two bowls and philosophers need one bowl to eat.

1) It is same at part B but with the addition of a two new bowls which are represented by two another semaphore where each philospher first check that if first bowl is available then he will eat from it and if not then he will eat from second bowl, if second is also busy then he will wait for second to be free.


## Installation

Download the code and create a file named `makefile` and paste below code into that

```makefile
target o:
	gcc originalA.c -o originalA
	gcc originalB.c -o originalB
	gcc modifiedA.c -o modifiedA
	gcc modifiedB.c -o modifiedB
    mkdir m{1..5}
    mkdir check
    mkdir bowl{1,2}
```
above makefile can be run by just typing `make` by being in same directory as of makefile.

## Usage
For original problem A:
```bash
./originalA
```
For original problem B:
```bash
./originalB
```
For modified problem A:
```bash
./modifiedA
```
For modified problem B:
```bash
./modifiedB
```
## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

## Appendix
If there is any issue in proper execution of the parts using semaphore then please give suffecient permissions to the files using `chmod` command.
