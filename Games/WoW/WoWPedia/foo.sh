#/bin/bash

# Strip the filenames
for filename in *.md; do
    [ -f "$filename" ] || continue
    mv "$filename" "${filename// - Wowpedia - Your wiki guide to the World of Warcraft/}"
done

# Rename all *.txt to *.text
for file in *.md; do
    mv -- "$file" "${file%.md}.adoc"
done