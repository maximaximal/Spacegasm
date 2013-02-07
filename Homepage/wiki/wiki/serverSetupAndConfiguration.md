Server Configuration & Game Setup
================================= 

Simple Steps
------------

1. 	The Client sends a `PTYPE_FULLCONNECTION` package to the 
	server and logs himself in.

2. 	The server initializes the player in the internal array.

3. 	The player sends his messages and commands to the server, 
	the server interprets them.

4. 	The game is running - server and client are exchainging 
	packets with each other.

Server-Configuration (Detailed)
-------------------------------

The Server-Config is done through a GUI-Window, which automaticly sends
packets to the server to execute the set configuration.

In addition, the client is also able to issue console-commands through
a simple input-line with the syntax `/command option1 option2 ...`. 

When the server is fully configurated, the game can start. This part 
could be a little bit of a fun-braker, because people usually want to play
and not to config servers. The standard-config has to fit very good, 
and every extremely customized configuration-feature should be hidden
into an additional window or under a notebook-tab. 

Every configuration-option which is not really important could also be
configured through the commandline interface, which doesn't require coding
on the client side (server-only). The benefit is clear, but the downsides 
are: Less access to the functions, less information, uglier interface, 
and the complete bloat of the thing at the end.

