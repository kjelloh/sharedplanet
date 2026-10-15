# sharedplanet

This is me 'chiming in' as in seeding thoughts and needs to our shared planet. As a human. In the discussion about human navigation of whatever reality is.

See 'chimes' for all writings sorted alphabetically.

* [chimes](../chime/index.md)
* [thinking](./thinking.md)
* [Github Pages](https://kjelloh.github.io/sharedplanet/)

## from_mail.py

Vibe coded seed for a script that reads an IMAP mailbox and filters out mails that are 'chimes'.

It requires the local shell environment to be populated with the environment variables to identify the IMAP host, the user and the credentials (password) för SSH access

```sh
> export IMAP_HOST="imap.example.com"
> export IMAP_USER="me@example.com"
> export IMAP_PASSWORD="secret"
> python3 from_mail.py
```

Replaced by [eml_to_domain/README.md](../eml_to_domain/README.md) mechanism actually used to process selected mails into chimes.