# Docker-Container

Folgende Container werden in der [[InsualeInfrastruktur]] genutzt.

Fast alle Anweisungen sind mittlerweile in einer zentralen Compose-Anleitung hinterlegt. Diese ist wie folgt zu starten:
```
CURRENT_UID=$(id -u):$(id -g) docker-compose up -d
```

https://gitlab.com/janhkrueger/insulae-private/raw/master/docker/docker-compose.yml


https://hub.docker.com/r/jenkins/jenkins/
CI and delivery

https://store.docker.com/images/sonarqube
CI Code Quality

https://store.docker.com/images/swarm
Docker Clustering

## Swagger-UI
https://hub.docker.com/r/swaggerapi/swagger-ui/


Damit alles CORS gerecht ist, muss ein neuer Header an die JSON-Datei angehängt werden (an den Response)

Dafür Anpassung in der Konfig des VHosts:
```
<Directory "/var/www/html/insulae.janhkrueger.de/www/">
Options+FollowSymLinks
AllowOverride All
Order allow,deny
Allow from all
</Directory>
```

Der Header selbst wird mit einer .htaccess Datei im Ordner /var/www/html/insulae.janhkrueger.de/www/api angefügt:

```
<Files swagger.json>
Header add Access-Control-Allow-Origin "*"
</Files>
```

## Swagger-Editor
https://hub.docker.com/r/swaggerapi/swagger-editor/


https://hub.docker.com/r/linuxserver/letsencrypt/
Genauer prüfen


## memcached


## Gitlab
```
sudo docker run --detach \ --hostname gitlab.example.com \ --publish 443:443 --publish 80:80 --publish 22:22 \ --name gitlab \ --restart always \ --volume /srv/gitlab/config:/etc/gitlab \ --volume /srv/gitlab/logs:/var/log/gitlab \ --volume /srv/gitlab/data:/var/opt/gitlab \ gitlab/gitlab/gitlab-ce:rc
```

## Bombard

```
docker build -t janhkrueger/insulae-bombard:latest .

docker run -it --rm -v /home/insulae/insulae-apitest:/app janhkrueger/insulae-bombard:latest bombard -t1 -i1 -s1 -f /app/siegeurls.txt
```

## Insulae-API
Wird separat behandelt.


## Pelican

```
docker run -it --rm -v $(pwd):/srv/pelican mjjacko/pelican pelican-quickstart -p my-site

docker run --rm -v $(pwd)/blog:/srv/pelican -v $(pwd)/pelican-themes/pelican-bootstrap3:/home/blog/pelican-themes/pelican-bootstrap3 -v $(pwd)/pelican-plugins:/home/blog/pelican-plugins -d --name jhk-pelican -p 8005:8000 janhkrueger/pelican:v2
```
