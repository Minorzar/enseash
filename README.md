# enseash
Shell created during the System Programming labs

## TP 1

### Question 1:
	The welcome message is functioning. Currently, everything works like a simple "hello world."

### Question 2:
	The execution of commands works. At the moment, no exit cases are handled, and the only way to exit the loop is with a ctrl+c.

	The errors currently handled include:

		- Read error
		- Child process creation error
		- Command execution error

### Question 3:
	The exit and ctrl+d exit codes are functioning correctly, as is the exit message.

	The errors handled have not changed from the previous question.

### Question 4:
	Signals and codes are properly accounted for in the display. A function has been created to handle the new prompt message format.

	The errors handled have not changed.

### Question 5:
	Time is taken into account. The function from question 4 has been modified to consider time.

	The errors handled have not changed.

### Question 6:
	Commands with arguments are now functional. A function to separate the input string based on spaces has been implemented, and the execution mode has been modified to vectorized.

	The errors handled have not changed.

### Question 7:
	Redirections < and > are properly handled. A function has been implemented to retrieve the redirection and check if either of the characters is < or > and act accordingly.

	The errors handled have not changed.

### Question 8:
	The | redirection is now functional. All other redirections are still functional as well. Commands linked by a pipe are executed in another function, requiring a return indicating this execution, here, a NULL return.

	The errors handled have not changed, and those related to pipe execution are similar and also addressed.