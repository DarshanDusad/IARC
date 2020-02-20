# IARC
This is for the autonomous event of IIT Kanpur Techfest, Techkriti<br />
USP: <br />
1. Line following <br />
2. Wall Following <br />
3. Matrix (6x6 cm2) reading <br />
4. Precise angle Turning <br />
5. Colour sensing. <br />
Whole PS: https://drive.google.com/file/d/1yI86vfG8Xzwl_OsT4mJUZHZfF5TjE_xW/view?usp=sharing <br />
### Progress and Workflow: <br />

## (28 Jan-29 Jan) <br />
Discussed the PS. <br />
Possible sensors etc. <br />
We'll be making a color sensor ourselves instead of purchasing one. With/Without filter wasn't sure at that time. <br />
For line following LSA08. <br />
Problems faced: <br />
How we would turn precise angle in that bot.? <br />
How to detect that 2x2 matrix with the already positioned sensor array. <br /> 

## (1 Feb-5 Feb)
Decided we'll be using gyroscope for angle turning. <br />
Built and tested the colour sensing module without filter as the red and green led's we have significant difference in their intensities. It was able to differentiate between green and red led accurately. We are planning to use colour filter with it, so that colour filter works for led's with same intensity also.  <br />
Built mount for lsa08 and made changes in chassis for the mount and lcd display. <br />
## (9 Feb-16 Feb)
Read the manual of LSA, all three modes- Serial, analog, digital. <br />
A lot of time was spent in understanding the library of lsa08 but we realised that functions explained in library were not required for line following.  
We are using analog mode of LSA for basic line following and  P and D of PID line following system. <br />
Line following was done. Code & Video for the same are uploaded. <br />
For the detection of turns we previously used junction pulse of the lsa08
which automatically tells us if the bot detects a node. In order to find 
the condition of turning we used a range of values for which
the bot stays on the line. We used it as a boundary condition to determine
till when we wanna turn. We also used the range of values to determine
the particular cases of the special turn we gonna take. For now lfr was hard coded
in order to complete the track.

TARGET FOR THIS WEEK :
We will be caliberating array properly as jxnpulse was giving random values for some cases and speed of bot was also slow. we are looking forward to do line following accurately at high speed without hard coding aas in our PS also we will be having dead ends in path annd we have to find the right path.



