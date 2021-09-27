---
created: 2021-09-27T12:58:30+02:00
modified: 2021-09-27T12:58:35+02:00
---

# How to List Installed Packages by Date on Linux

grep -i "install" /var/log/dpkg.log

$ zcat /var/log/dpkg.log.* | grep -i "installed"
