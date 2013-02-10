#!/bin/bash

echo "YOU HAVE TO REMEMBER THE PASSWORD! THIS HAS TO BE TYPED INTO THE SERVER-CONFIG FILE!";
echo "After finishing this script, you have to type in the information to the serverConf.xml! ";
echo "The file will be created at startup. All options are set in the example Server/serverConf.xml file with the test-password testpass.";

#Login to Database
sudo -u postgres psql template1;

#Setup Password
\password postgres

create database spacegasm_db;

\q

#Echo success message
echo "Finished setting up the database! \nPlease fill in the config in the serverConf.xml file created at startup.";
echo "DatabaseName: spacegasm_db";
echo "PostgreSQLUser: postgres";
echo "PostgreSQLPass: The one you've typed in before";

