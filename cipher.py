def cipher(message,shift):
	new_msg=""
	num=0
	for ch in message:
		if ch == ' ':
			new_msg=new_msg+' '
		else:
			if ch >= 'A' and ch <= 'Z':
				num=ord(ch)+shift
				num=num-65
				num=num%26
				num=num+65
				new_msg=new_msg+chr(num)
	print new_msg
def decipher(message,shift):
	new_msg=''
	num=0
	for ch in message:
		if ch == ' ':
			new_msg=new_msg+' '
		else:
			if ch >= 'A' and ch <='Z':
				num=ord(ch)-shift
				num=num-65
				num=num%26
				num=num+65
				new_msg+new_msg+chr(num)
	print new_msg