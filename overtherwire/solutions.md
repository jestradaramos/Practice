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
