# OS-Project-1
Project 1 for my Operating Systems course
All original code

Countdown.c

The countdown.c program simply prints a message n times, once per second, then quits with a final goodbye message and a random exit code. It should take two command line parameters: name and n. The output should look like so:

radius$ ./countdown Alice 3
Alice (process 16712, parent 16105) will quit in 3 seconds.
Alice (process 16712, parent 16105) will quit in 2 seconds.
Alice (process 16712, parent 16105) will quit in 1 seconds.
Alice (process 16712, parent 16105) quits with exit code 17.

The message includes the process ID and the process's parent ID.


Spawn.c

The spawn.c program takes 5 command line parameters, ta, tb, tc, td, and te. The first must be converted to an integer, the others can be left as strings. When you run your spawn program, it should fork several child processes, as follows. The original spawn process (let's call it A) should fork two processes (let's call them B and C). Process C should immediately fork two more process (D and E). There should now be five processes, all executing the spawn program: the original process you ran from the command line, plus four decendents of that process.

Processes B, C, D, and E should each exec() your countdown program, passing an appropriate name ( "Bev", "Cal", "Dot", or "Eve") and the corresponding argument from the original command-line (tb, tc, td, or te). 

Meanwhile, the original parent process should:

print a message: "Ada (process p , parent q ) will sleep for ta seconds.",
then pause for ta seconds,
then print a message: "Ada (process" p , parent q ) now waits.",
then invoke the wait() system call,
then print the results of that system call: "Ada (process p , parent q ) got pid x and status y from wait.",
then finally exit with status 0.
