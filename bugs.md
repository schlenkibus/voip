#Bugs
This programm causes unexpectet behavior when:
- Audio is still being played 
AND
- new Audio is being recieved

Where to look:
When a message is being played, the recieving method is not being restartet.
The AudioPlayer.cpp causes to stop the continuation of the programm while the audio is being played.