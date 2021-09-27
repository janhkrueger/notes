---
created: 2021-09-27T13:10:22+02:00
modified: 2021-09-27T13:10:40+02:00
---

# VeraCrypt Container mit cryptsetup öffnen

Container einem Device zuordnen
		
		○ losetup /dev/loop0 /path/to/truecrypt.file
		
Container öffnen / entschlüsseln
		
		○ cryptsetup --type tcrypt open /dev/loop0 myContainer
		○ 
	• 
	• 
	• mount the container
		• mount /dev/mapper/myContainer /media/tmp
			• change /media/tmp with your desired mountpoint
Your truecrypt contain's contents should now be available in the /media/tmp (or your desired mountpoint) directory!
To unmount/cleanup you will need to do the following:
	• umount /media/tmp #substitute your mountpoint
	• cryptsetup --type tcrypt close myContainer #substitute your chosen container name
	• losetup -d /dev/loop0 #release the loopback device
