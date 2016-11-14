This is a project i had to do for school where you had to cable a 7 segment display
to an arduino and figure out if its a common anode or cathode and then
control it with the arduino. I had a common cathode one. That means i have to send
it LOW so that a led lights up. I started by doing the cabling on
<a href="http://fritzing.org/"> Fritzing</a>. <br />
<img src="https://raw.githubusercontent.com/p4p1/Projects/master/7segCathodeArduino/img/mainCircuit.png" /><br />
After cabling it up i then went and started coding, for that i used the <a href="https://www.arduino.cc/en/Main/Software">
arduino ide</a>. I first initialized the pins and made a little diagram so that i dont get lost. <br />
<img src="https://raw.githubusercontent.com/p4p1/Projects/master/7segCathodeArduino/img/smalSketch.png" /><br />
Variables finished i then proceeded to code the setup code. In fighlighted in the code the different parts,
in Green you have the pin initializations in blue i then proced to declare the status of each pin to turned off.
In red i execute some startup code. <br />
<img src="https://raw.githubusercontent.com/p4p1/Projects/master/7segCathodeArduino/img/setupCode.png" /><br />
Proceeding the Setup code i then continued to the main code, nothing really interesting just a for loop that goes through
each number that can be writen by the dispNumber function, i will go in detail of this function later it is really cool ^^.
i also add a delay of 1 second between each on and off. Talking about on and off, look at the second photo under the main code
you cna find all of the function prototypes and all of the main variable and a enum that uses TRUE and FALSE in a strange way
I used this code style because the 7 segment display is a 7 segment <u>cathode</u> that means that it has a central + and 8 -
so using this enum makes the code way more simple when someone reads it :) because you need to send low to a pin. <br />
<img src="https://raw.githubusercontent.com/p4p1/Projects/master/7segCathodeArduino/img/mainCode.png" /> <br />
<img src="https://raw.githubusercontent.com/p4p1/Projects/master/7segCathodeArduino/img/varInit.png" /> <br />
Now lets dive in some code , aka the fun stuff :) . We will dive into each function one by one, to start off with lets go
simple we will look at the startup and reset function. The reset function is only used for debuging, we will covert it after
the startup function. The startup function is constructed of two parts the first one is a for loop that turns on and off each 
led on the segment display(The Yellow Part), the second one is a for loop that maked the dp button blink three times it also
indicates the end of the test. This function is also used if there is any error in the code, i will cover that in the last
function.<br />
<img src="https://raw.githubusercontent.com/p4p1/Projects/master/7segCathodeArduino/img/startupCode.png" /> <br />
As i said earlier we will now go in the reset function, the reset function is a bit wierd because it normaly isnt initialized
nor executed, i surounded the reset code with a #ifndef macro (see in blue) this macro is used to block out the function if
DEBUG is not initialized. I made this by desine because i dont want everyone to access this debug function that prints out
everything each time it is called because i didnt want ot flud peoples screens with random debug code. <br />
<img src="https://raw.githubusercontent.com/p4p1/Projects/master/7segCathodeArduino/img/debugCode.png" /> <br />
I will now go in detail of this function, as i said earlier i have the debug macro then i set all of the pins off
with a for loop (see in purple and red) and i print the data of each pin out (see in green). I admit it this function is
pertty useless for now, but im shure i cna figure out a use case, maybey for exemple an error in the pins declaration.<br />
<img src="https://raw.githubusercontent.com/p4p1/Projects/master/7segCathodeArduino/img/resetDebugCode.png" /> <br />
Ok so to end this program lets cover the final function dispNumber, it has two arguments num(in red) and flag(in green).
num represents the number that it has to output, and flag represents the status of the display on/off. <br />
<img src="https://raw.githubusercontent.com/p4p1/Projects/master/7segCathodeArduino/img/funcDispNumber.png" /> <br />
Now lets finish by looking at the code of the dispNumber function. In this code its just a repitition of a simple code sample
so dont be fooled by its size its really simple :) . In green it checks the number given in the first argument and then it
executes a simple for loop in pink to trun on or off the good pins with an if statement. In the digital write there is a
shorthand notation of an if to put on or off the number. :) to use this function you have to turn on the correct number, and
then turn off the number before turning on an other number. If you try turning on 2 numbers at once it will make the function
crash. To reset correctly with this function do this -> dispNumber(8, FALSE); <br />
<img src="https://raw.githubusercontent.com/p4p1/Projects/master/7segCathodeArduino/img/dispnumCode.png" /> <br />
To Conclude i made a small video showing you how this code works, i used <a href="https://circuits.io/lab">circuit.io</a>.
Happy film :)<br />
<a href="https://www.youtube.com/watch?v=OSqB4xEac_o"><img src="https://i.ytimg.com/vi/OSqB4xEac_o/hqdefault.jpg?custom=true&w=196&h=110&stc=true&jpg444=true&jpgq=90&sp=68&sigh=rKkgrpkUAj7Aq1NXlghVltLaFHg" /></a><br />
Thank you for reading and watching L.S. :penguin:
