#!/bin/bash
for file in ./Markdowns/*.MD; do
    pandoc -f markdown -t html  Markdowns/Basics.MD --self-contained --css=backstyle.css > HTMLs/$(basename $file .MD).html
done