---
created: 2021-09-27T12:45:05+02:00
modified: 2021-09-27T12:45:45+02:00
---

# Raspberry DNS Server

    sudo apt install dnsmasq


## Configuring the DNS Server

    sudo nano /etc/dnsmasq.conf

Replace 
    domain-needed with domain-needed

    bogus-priv with bogus-priv

    no-resolv with no-resolv

    server=/localnet/192.168.0.1

#Docker