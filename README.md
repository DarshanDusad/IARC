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
Decided we'll be using gyroscope foe angle turning. <br />
Built and tested the colour sensing module. <br />
Built a chassis for basic LSA08 Testing, as it's delicate and needs precision. <br />
## (9 Feb-16 Feb)
Read the manual of LSA, all three modes, Serial, analog, digital. <br />
We are using analog for basic line following. (For now)(PD too) <br />
Line following was done. Code & Video for the same are uploaded. <br />
For the detection of turns we previously used junction pulse of the lsa08
which automatically tells us if the bot detects a node. In order to find 
the condition of turning we used a range of values for which
the bot stays on the line. We used it as a boundary condition to determine
till when we wanna turn. Also used the range of values to determine
the particular cases of the special turn we gonna take.



