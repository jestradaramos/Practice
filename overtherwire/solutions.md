# OverTheWire: Bandit

## Level 0  
``` ssh bandit0@bandit.labs.overthewire.org -p 2220   ```  
password: bandit0  
``` cat  readme ```  
password: boJ9jbbUNNfktd78OOpsqOltutMc3MY1

## Level 1 -> 2
``` cat ./-  ```  
password: CV1DtqXWVFXTvM2F0k09SHz0YwRINYA9

## Level 2 -> 3  
``` cat spaces\ in\ this\ filename```  
password: UmHadQclWmgdLOKQ3YNgjWxGoRMb5luK

## Level 3 -> 4

```
cd inhere
ls -a
cat .hidden
```
password: pIwrPrtPN36QITSp3EQaw936yaFoFgAB  

## Level 4 -> 5
```
file ./*
cat ./file07
```
password: koReBOKuIDDepwhWk7jZC0RTdopnAYKh

## Level 5->6
```
find ./* -size 1033c
cat ./maybehere07/.file2
```
password: DXjZPULLxYr17uwoI01bNLQbtFemEgo7

## Level 6->7
This one is when bandit starts going in deep to linux commands.(For me at least)  
 ``` find / ``` makes it so that we search the entire filesystem  

 ``` 2>/dev/null ``` makes it so that our stderr (standard error, described w/ a
     fd of 2) go into a "black hole". We want this in order to not have all the
     errors appear on our terminal. You can test without it if you want to see.
```
find / -user bandit7 -group bandit6 -size 33c 2>/dev/null
cat /var/lib/dpkg/info/bandit7.password
```
password: HKBPTKQnIay4Fw76bEy8PVxKEDQRKTzs

## Level 7->8
Here we learn about the grep command. This is like the ctrl-f option in chrome.It
looks for a word in a file. So to solve this level we run the command
``` grep millionth data.txt ```  

password: cvX2JJa4CFALtqS87jk27qwqGhBM9plV

## Level 8->9
In this level we learn about two new commands: ```uniq``` and ```sort``` .
uniq is used to find uniq lines in a file. However, it only looks at adjacent
lines. So to use it properly we would have to sort the file we are going through.
This is when we would use the sort command, which does what its called. It sorts
a file alphabetically. So to find this password we run the command:
``` sort data.txt | uniq -u```  

password: UsvVyFSfZZWbi6wgC7dAFyFuR6jQQUhR

## Level 9->10
In this level we learn about the ```string``` command. What this does is produce
all the human readable characters in a file. So to solve this level we use this
new command as well as the ```grep``` command from level 7->8. So we run:  
``` strings data.txt | grep === ```

password: truKLdjsbJ5g7yyJ2X2R0o3a5HQJFuLk

## Level 10->11
Here we learn about the ```base64``` command. By itself it encodes any data
using base64. Here is an explanation of base64 encoding:
```
It's basically a way of encoding arbitrary binary data in ASCII text. It takes 4
characters per 3 bytes of data, plus potentially a bit of padding at the end.

Essentially each 6 bits of the input is encoded in a 64-character alphabet. The
"standard" alphabet uses A-Z, a-z, 0-9 and + and /, with = as a padding
character.
```

So what we want to do is decode the encoding. To do that we use the -d option.
So we run:
``` base64 -d data.txt ```

password: IFukwKGsFW8MOq3IRFqrxE1hxTNEbUPR

## Level 11 -> 12
In this level we learn about the ROT13 substitution cipher. This cipher simply
rotates each character by 13 positions. For example 'a' becomes an 'n' in this
cipher. So the command that we will need is the ``` tr ``` command. This command
simply does translations that we specify. So we run:  
``` cat data.txt | tr [a-zA-Z] [n-za-mN-ZA-M] ```  
In this scenario, we are translating a-z to letters from n to z, then a to m.
This rotates all the characters by 13 positions. And the same is applicable to
the uppercase letters.

password: 5Te8Y4drgCRfCx8ugdwuEX8KFC6k2EUu

## Level 12->13
Lol this level. In this level I thought I was going through too many steps, but
then I finally got what I needed. So in this level you learn about compression
and decompression tools such as ``` gzip ``` , ``` tar ```,  and ``` bzip2```.  
You also learn about the ``` hexdump ``` ,``` xxd ``` and ``` file ``` command.

So to start this we need to create a directory in the tmp directory. Then move
the data file given into that directory. To do that we run:  
``` mkdir /tmp/new && cp data.txt /tmp/new/mine.txt ```   

After this we look at the file. We know this file has been compressed, but we
don't know what with. This then required some research. After digging through
stackoverflow I learned that each form of compression leaves a header on the
file. And with that you can determine what tool was used to compress the file,
and use that to decompress it.

|filetype | header |   
|:---------:|:--------:|
|.zip      | 0x50 0x4b 0x03 0x04 |
|.gz       | 0x1f 0x8b 0x08|
|.bz2      | 0x42 0x5a 0x68|

So now we look at the hexdumped file and at the begginning of the file we see
the numbers: 1f8b08. So clearly this file has been compressed using gzip. Now we
can decompress it. First we must rename the file without the .txt extension, but
the .gz extension.  
``` mv mine.txt mine.gz ```  

Then we decompress it:  
``` gzip -d mine.gz ```  

This should produce a file called "mine". We then run the ``` file ``` command on
it. What this does is give us information regarding this new file. After running
that command we see that this file is a bzip2 compressed file. So we now use
that  to decompress this new file.  
``` bzip2 -d mine ```  

This then produces a "mine.out" file. We then repeat the process again, and use
the ```file``` command to find out what is going on with this file. In this case
we learn that it is another compressed file, compressed with gzip. So we repeat
the process with gzip. Rename the file and the then decompress it.   
``` mv mine.out mine.gz && gzip -d mine.gz ```  

This will then produe the "mine" file. And we run the file command on it again.
We see that this file is also a compressed file, compressed with "POSIX tar
archive (GNU)". So we want to decompress this with the ``` tar ``` command:  
``` tar -xvf mine```  

This then produces the "data5.bin" file. We run the ```file``` command again. We
keep repeating this process until our file command tells us that our file is not
compressed and of type ASCII. We end up getting a file called "data8"

password: 8ZjyCRiBWFYkneahHwxCv3wb2a1ORpYL
