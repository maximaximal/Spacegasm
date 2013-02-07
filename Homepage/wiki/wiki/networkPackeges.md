SFML-Sidescroller: Network-Packages
===================================

Connection & User Management
----------------------------
 * **PTYPE_FULLCONNECT**

	Connect to the server. Parameters: `std::string username, std::string password`. This has to be called before any other packet is sent! 

 * **PTYPE_REGISTERUSER**

	Register the user in the internal server database. Parameters: `std::string username, std::string password, bool gender, std::string nationality`. The gender is 0 for male and 1 for female.

 * **PTYPE_GETUSERDATA**

	Request a `PTYPE_USERDATA` package containing the data of the specified user. Parameters: `std::string username`.

Data
----
 * **PTYPE_PLAYERDATA**
	
	Contains a playerdata-object. This propably was requested by a 
	`PTYPE_GETUSERDATA` packet.

Chat & Chat-Commands
--------------------
 
 * **PTYPE_MSG**

	Send a message to the server or back. This will first be checked for commands (/command) and if no command operator ("/") was set, the message will be given to the output (GUI on the client-side and terminal on the server-side)

 * **PTYPE_CONSOLE_OUTPUT**
	
	Outputs a message to the console and does nothing else (no checking for commands or output in a nice chat-GUI). It will be outputted in the server-configuration and maybe in the chat, but it is deactivatable. 

Game-specific Commands
----------------------	

 * **PTYPE_ACTIVATE_CONTROL**
 
	Activate or deactivate the specified control on the server. (direction: client >> server). Parameters: `int controlID, bool state`
 
	* **controlID = 0**
		UP-Movement.
 	* **controlID = 1**
		RIGHT-Movement.
 	* **controlID = 2**
		DOWN-Movement.
 	* **controlID = 3**
		LEFT-Movement
	* **controlID = 4**
		PRIMARY-SHOOT-State
	* **controlID = 5**
		SECONDARY-SHOOT-State

 * **PTYPE_SPACESHIP_DAMAGE**
	
	Damages the spaceship.

 * **PTYPE_SPACESHIP_POS**
	
	Updates the current position of the ship on the server. This has 
	to split up into the multiple parts of the ship, because they 
	can easily brake away from it.