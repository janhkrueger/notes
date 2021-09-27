---
created: 2021-09-27T12:59:51+02:00
modified: 2021-09-27T12:59:55+02:00
---

# Block IP Adresses with iptables

# install it

apt-get install ipset



# create a blacklist

ipset create blacklist hash:ip hashsize 4096



# add the blacklist to your iptables rules

iptables -I INPUT -m set --match-set blacklist src -j DROP

iptables -I FORWARD -m set --match-set blacklist src -j DROP



# check that rule is set in 
iptables
iptables -L



# now add the offending ip address

ipset add blacklist ip.address



# check that the ip address is in your blacklist

ipset list blacklist


39.98.247.230

139.59.56.65

85.93.20.22

136.243.201.37

136.243.22.153

222.186.15.23

185.220.101.31

118.139.177.119

23.129.64.188

185.220.101.33

139.199.209.89
