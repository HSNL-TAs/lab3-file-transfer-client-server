
Today's mission
==
You will need to write simple file transfer client and server in language `C`.  
Please modify to the [sample code](#) to achieve this goal.

Requirements
==
[Requirement of Server](#server)  
[Requirement of Client](#client)

Server
==
You should implement following functions in your server.
- User can assign port number which the server bind.  
- Returns files list to client when the client connects immediately to the server.  

**For example:**

```sh
# Client side
$ ./client
[✓] Connect to server.
[✓] Server reply!
Files on server
yesterday.mp3
homework.pdf
network.jpg
```
- Returns files which client wants to download.


**For example:**

```sh
# Client side
yesterday.mp3 # user input
[-] Downloading `yesterday.mp3`
[✓] Download successfully!
_ # user can continue to send download request.
```

Client
==
- User can assign port number and ip address to connect the server.
- Support user inputs the `file name` to download file from server, per file per input.  
- Create a `/download` folder to store downloaded files.
- Input `.exit` to disconnect from server. 

**Note:**    
Server and client should keep connected unless user inputs `.exit`

Hint
==
Use `read/write` to send and receive informations.

Deadline
==
If your team don't finish the lab in the class, you can still demonstrate this lab when TA time.
