
Today's mission
==
You will need to write simple file transfer client and server in language `C`.  
Please modify to the [sample code](https://github.com/HSNL-TAs/lab3-file-transfer-client-server/tree/master/sample) to achieve this goal.  
Fill in your own code by following the hint in the code.
```
/**
  TODO:
  print something here.
**/
```

Requirements
==
[Requirement of Server](#server)  
[Requirement of Client](#client)

Compile with makefile
==
Makefile
```
all: server.c client.c
	gcc server.c -o server
	gcc client.c -o client

clean:
	rm -rf server
	rm -rf client
```
compile  
```sh
$ make
```

Server
==
You should implement following functions in your server.
- The server should uses port `8888`  
- Returns files list to client when the client connects immediately to the server.  (We have provided this function which scans all the file under the same directory.)

**For example:**

```sh
# Client side
$ ./client 127.0.0.1
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
- User can assign ip address to connect the server with command line argument.
- Support user inputs the `file name` to download file from server, per file per input.  
- Create a `/download` folder to store downloaded files.
- Input `.exit` to disconnect from server. 

**Note:**    
Server and client should keep connected unless user inputs `.exit`

Hint
==
- Use `read/write` to send and receive informations.
- Understand how to use `argv`.

Deadline
==
If your team don't finish the lab in the class, you can still demonstrate this lab when TA time (14:00 ~ 17:00 on Wed)  
- Deadline: 100%, before 2015/11/27
- Deadline: 80%, before 2015/12/4
- Deadline: 60%, before 2015/12/11
- After 2015/12/11, your submission is not accepted.

Problems
==
Filing any problem in [issues](https://github.com/HSNL-TAs/lab3-file-transfer-client-server/issues) or nthu ilms is welcome.


