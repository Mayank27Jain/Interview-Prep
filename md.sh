#!/bin/bash
for file in ./Markdowns/*.MD; do
    pandoc -f markdown -t html  "$file" --self-contained --css=backstyle.css > HTMLs/$(basename $file .MD).html
    pandoc -f markdown -t latex  "$file" --self-contained -o PDFs/$(basename $file .MD).pdf
done