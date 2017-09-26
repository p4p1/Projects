# webDump
A program to dump http request made to you're computer and view them on the terminal. This app can be used for many webexploits
where it is usefull to view http POST and GET content like for xss. or you can use it to send data throught http requests.

##Exemple/How to
To use this command it is verry simple you first have to compile with:<br />
[ $ -> Make all<br />
[ gcc source/*.c -std=c99 -Wall -Wextra -pedantic -o webdump<br />
After compiling you execute it as root with sudo then enter youre ip in a web browser and watch the magic on you're terminal :)
<br />
<img src="https://raw.githubusercontent.com/p4p1/webDump/master/images/output.png" /><br />
If you find this method boaring or redundent you can use bash to script this program to do what you want. Look at this example
i made : <a href="https://raw.githubusercontent.com/p4p1/webDump/master/run.bash">here</a>. This script will accept one
client, one by one and log the info in a file so that it can be inspected late
