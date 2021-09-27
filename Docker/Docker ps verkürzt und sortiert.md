---
created: 2021-09-27T12:49:23+02:00
modified: 2021-09-27T12:49:40+02:00
---

# Docker ps verkürzt und sortiert

docker ps --format "table {{.ID}}\t{{.Names}}\t{{.Status}}\t{{.Ports}}\t{{.Image}}" | (read -r; printf "%s\n" "$REPLY"; sort -k 2 )
