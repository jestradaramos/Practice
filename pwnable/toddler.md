# Pwnable: Toddler Bottle

## fd
This pwnable requires learning about linux IO file descriptors. The code
provided by the pwnable requires you to run the code with a number as an 
input. This number then gets subtracted by 0x1234. That number is then used
as a file descriptor for the read function. This code then takes which ever
file you give it and read it. It will then compare it with the string 
"LETMEWIN\n". So an easy way to get this to give us the flag is to make the 
file descriptor equal to 0, so that we can get access to the stdin. This will
allow us to input any string and that string is what gets used in  the program.

So the number we have to input is 4661. And the string we write is "LETMEWIN"
followed by an enter. Then we should get the flag which is:
"mommy! I think I know what a file descriptor is!!"

## collision
In this problem we had to 

Set of bytes read as characters 


Then converted to array of int

Then we had to make sure that the ints that would be read would add up to a 
specific number

Rewrite this later

## bof
This one was annoying, just because it required a little more knowledge
with linux, rather than just the buffer overflow. But, nonetheless it is 
was still do-able. So you had to go into gdb and look for how many bytes
there was between the key and the area of memory that was being compared.
There was one assembly line in the func function that compared 0xcafebabe 
with 0x32 bytes from the base pointer of the stack. This then told be there 
was 52 bytes I was dealing with. So my input had to have 52 arbitiary values
and 0xcafebabe following it. I did it with the following line: 
``` (python -c "print 'A' * 52 + '\xbe\xba\xfe\xca\n'"; cat -)  | nc pwnable.kr 9000 ```

## flag
Turned file into an executable using ```chmod```

Ran the executable

Because there was a malloc I ran strings on it because strings

Found a line about upx, so did research on that

Downloaded upx and decompressed flag with it

Ran strings again

Looked for that malloc message again and above it was the answer


