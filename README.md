<h1>ls Auditing Program</h1>


<h2>Description</h2>
This program audits the ls command in Linux using C. The program will take the ls command as input from the user and if the user attempts to access directories outside of the home directory, their attempt will be recorded and added to a log file. This is done by using a list of blacklisted directories and comparing if the provided path begins with one of these blacklisted directories (ex. /etc, /var, /root…). As mentioned before, if one of the blacklisted directories is found, the program will save the current time and date and print out the path the user provided to the log file. However, if none of the members of the blacklist are found, the program will call the opendir() function and list the contents of the given directory. This program was compiled and tested in a Linux Environment. 
<br />


<h2>Languages and Utilities Used</h2>

- <b>C</b> 
- <b>string.h</b>
  - String comparison and manipulation
- <b>dirent.h</b>
  - Directory manipulation
- <b>time.h</b>
  - Getting current date and time

<h2>Environments Used </h2>

- <b> Kali Linux</b>

<h2>Project walk-through:</h2>
<p align="center">
  Compilation and Execution: <br/>
  <img src="https://imgur.com/cuv1jwO.png" height="90%" width="90%" alt=""/>
  <br />
  <br />
</p>
