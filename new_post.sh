#!/bin/bash
root=`dirname "$0"`
cd $root
datetime=`date +'%Y-%m-%d %H:%M:%S'`
filename=`date +'%Y-%m-%d-%s'`.md
echo $filename
echo "---
Layout: post
title: Untitled
date: $datetime +0700
---" > "_posts/$filename"
emacs "_posts/$filename"
git add .
git commit -m "new post"
git pull
git push
