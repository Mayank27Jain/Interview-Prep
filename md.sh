#!/bin/bash
for file in ./Markdowns/*.MD; do
    pandoc -f markdown -t html  Markdowns/Basics.MD --self-contained --css=backstyle.css > HTMLs/$(basename $file .MD).html
    pandoc -f markdown -t latex  Markdowns/Basics.MD --self-contained -o PDFs/$(basename $file .MD).pdf
done