---
created: 2021-09-27T12:48:21+02:00
modified: 2021-09-27T12:49:00+02:00
---

# Docker Security

Here are 6 ways you can secure Docker containers.

Always make sure to start Docker containers with the -u flag so that they run as an ordinary user instead of root. This is a basic first step toward improving security.

Taking the previous point a step further, remove SUID flags from your container images. This makes privilege escalation attacks even harder.

Configure Docker control groups (also known as cgroups), which let you set limits on how many resources each container can use. This will go a long way toward preventing container-based DoS attacks. (Note, however, that cgroups aren’t intended to help provide other security isolations between containers—to do that, you use namespaces.)

Use namespaces in Docker to isolate containers from one another. Namespaces help assure that a user or process running inside one container can’t affect those in other containers.

Don’t use images from repos you don’t trust. In particular, avoid public repos if they’re not from an official source and you don’t know the maintainer. This may sound like a no-brainer, but it’s worth noting because it’s sometimes so tempting to pull an image from a random registry.

Consider using Clair (CoreOS’s container security scanner) to validate containers from your registries. You can use Clair to scan images locally or you can run it directly from public registry services that are supported (which, for now, include CoreOS’s own platform, Quay, as well as Dockyard).
