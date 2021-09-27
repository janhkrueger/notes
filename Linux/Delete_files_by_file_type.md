---
created: 2021-09-27T13:15:42+02:00
modified: 2021-09-27T13:15:59+02:00
---

# Delete files by file type

```
find . "-name" "*.html" -exec rm {} \;
find . "-name" "*.txt" -exec rm {} \;
find . "-name" "*.css" -exec rm {} \;
find . "-name" "cv.pdf" -exec rm {} \;
find . "-name" "*.php" -exec rm {} \;
find . "-name" "*.jpg" -exec rm {} \;
find . "-name" "*.gif" -exec rm {} \;
find . "-name" ".DS_Store" -exec rm {} \;
find . "-name" "*.htm" -exec rm {} \;
find . -type d -empty -delete
```

