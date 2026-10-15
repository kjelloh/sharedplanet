import imaplib, email

user = 'darwinet2@itfied.se'
password = 'darw1n3t2'
imap_url = 'imap01.binero.se'

con = imaplib.IMAP4_SSL(imap_url)
con.login(user,password)

