# OS-Project-1
Project 1 for my Operating Systems course

Countdown.c

The countdown.c program simply prints a message n times, once per second, then quits with a final goodbye message and a random exit code. It should take two command line parameters: name and n. The output should look like so:

radius$ ./countdown Alice 3
Alice (process 16712, parent 16105) will quit in 3 seconds.
Alice (process 16712, parent 16105) will quit in 2 seconds.
Alice (process 16712, parent 16105) will quit in 1 seconds.
Alice (process 16712, parent 16105) quits with exit code 17.

The message includes the process ID and the process's parent ID.

