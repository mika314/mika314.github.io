#!/bin/bash
root=`dirname "$0"`
cd $root
datetime=`date +'%Y-%m-%d %H:%m:%S'`
filename=`date +'%Y-%m-%d-%s'`.md
echo $filename
echo "---
Layout: post
title: $datetime
date: $datetime +0700
---" > "_posts/$filename"
emacs "_posts/$filename"
git add .
git commit -m "autoupdate"
git pull
git push
