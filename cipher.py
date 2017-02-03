#!/usr/bin/python
import sys
file=sys.argv[1]
shift=int(sys.argv[2])
encode=sys.argv[3]
f=open(file,'r')
mess=f.readlines()

def cipher(message,shift):
	sm=open('output.txt','w+')
	for lines in message:
		new_msg=""
		num=0
		for ch in lines:
			if ch == ' ':
				new_msg=new_msg+" "
			elif ch >= 'A' and ch <= 'Z':
				num=ord(ch)+shift
				num=num-65
				num=num%26
				num=num+65
				new_msg=new_msg+chr(num)
			elif ch >= 'a' and ch <='z':
				num=ord(ch)+shift
				num=num-97
				num=num%26
				num=num+95
				new_msg=new_msg+chr(num)
		sm.write(new_msg+'\n')
def decipher(message,shift):
	dc=open('output.txt','w+')
	for lines in message:
		new_msg=""
		num=0
		for ch in lines:
			if ch == ' ':
				new_msg=new_msg+" "
			elif ch >= 'A' and ch <='Z':
				num=ord(ch)-shift
				num=num-65
				num=num%26
				num=num+65
				new_msg=new_msg+chr(num)
			elif ch >= 'a' and ch <='z':
				num=ord(ch)-shift
				num=num-97
				num=num%26
				num=num+97
				new_msg=new_msg+chr(num)
		dc.write(new_msg)
if encode == 'cipher':
	cipher(mess,shift)
if encode == 'decipher':
	decipher(mess,shift)
