# Filler_public
This project contains the source code to create an algorithm for playing the game filler. The algorithm plays this game against other algorithms and attempts to beat them by  placing the most randomly generated shapes onto the given board. 

Once compiled the algorithm is called "./wvan-ees.filler".  

In order to play the game VM, opposing players and a map is needed. is needed. This is included as "./filler-vm". The opposing players and maps can be found in the "players" and "maps" directories respectivelu.  

In order to play the game enter the following into the terminal: ./filler-vm -p1 (player1) -p2 (player2) -v -f ./maps/(Map)  Example: ./filler-vm -p1 ./wvan-ees.filler -p2 ./players/carli.filler -v -f maps/map00

In case of "permission denied ./filler_vm" error:
  If this error is encountered use chmod to change the permissions.
  Entering the following into the terminal will fix the error : chmod 777 ./filler_vm
