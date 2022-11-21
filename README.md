<h1>ls Auditing Program</h1>


<h2>Description</h2>
This program audits the <i>ls</i> command in Linux using C. The program will take the ls command as input from the user and if the user attempts to access directories outside of the home directory, their attempt will be recorded and added to a log file. This is done by using a list of blacklisted directories and comparing if the provided path begins with one of these blacklisted directories ( <i> ex. /etc, /var, /root… </i>). As mentioned before, if one of the blacklisted directories is found, the program will save the current time and date and print out the path the user provided to the log file. However, if none of the members of the blacklist are found, the program will call the <i>opendir()</i> function and list the contents of the given directory. As this program can monitor linux commands, it can be compiled as a shared library and used with <i> LD_PRELOAD </i> to more efficiently monitor ls commands. This program was compiled and tested in a Linux Environment. 
<br />


<h2>Languages and Utilities Used</h2>

- <b>C Programming Language</b> 
- <b>string.h</b>
  - String comparison and manipulation
- <b>dirent.h</b>
  - Directory manipulation
- <b>time.h</b>
  - Getting current date and time

<h2>Environments Used </h2>

- <b> Kali Linux</b>
- <b> VS Code </b>

<h2>Project walk-through:</h2>
<p align="center">
  Compilation and Execution: <br/>
  <img src="https://imgur.com/kpWbank.png" height="90%" width="90%" alt=""/>
  <br />
  <img src="https://imgur.com/6h7f5rB.png" height="90%" width="90%" alt=""/>
  <br />
  <br />
  Log File After Execution: <br/>
  <img src="https://imgur.com/nmJl6xU.png" height="90%" width="90%" alt=""/>
</p>
