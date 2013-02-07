Console Commands
================

Console commands are issued with the syntax `/command option1 option2 ...`
and are executed if the applied chat-handler has an event attached to 
them.
	
 + **/serverStats**
	
	Gets some statistics from the server (speed, ping, etc) and 
	outputs it into the lokal chat.

 + **/admin <Password>**
 
	Logs in as admin of the game. The password is given at server-startup.
	The server-starter is automatically an admin, but the other
	users have to use this command to get the admin-flag.
	
 + **/downloadLog <filename>**
	
	Downloads the log of the current game. This log contains all the 
	commands issued by the players & the admins. The log is in the 
	format `[DD-MM-YYYY MM:SS] [<USER>] <logged action>`. Because
	the log is too long for the local chat, it is saved to the specified
	filename.
	
 + **/kick <User> <Why>** (admin)
	
	Suddenly disconnects the specified user for the reason specified
	in <Why>. The reason is displayed when the player gets thrown
	to his start-screen in an additional GUI-Window. 
	
 + **/say <What to say>** (admin)

	Broadcast the message to all players (anonymous for them but logged)

 + **/reset** (admin)
 
	Resets the game to the beginning. 
	
