# Minitalk
The purpose of this project is to code a small data exchange program using UNIX signals

The communication occurs between the client and server programs. The server is launched first, showing its PID as it starts. The client then takes that PID and a string as an argument, and transmits the string to the server exclusively through UNIX signals(SIGUSR1 and SIGUSR2).

The message is sent bit by bit, and is then reconstructed by the server. Once the server is launched, it can receive strings from several different clients without resetting.

It supports Unicode characters.
