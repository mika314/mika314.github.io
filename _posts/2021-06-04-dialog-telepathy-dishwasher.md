---
Layout: post
title: Dialog System, Telepathy Quest, Dishwasher Quest
date: 2021-06-04 00:00:00 +0700
---

# Dialog System, Telepathy Quest, Dishwasher Quest

For dialog system I added `UDialogItem` class to store the dialog line
in it. It has to be derived from UObject. I implemented the dialog
line extraction in `UDialogLineUi` and put it in the UTextBlock. I do
not know why it is so complicated, but I guess UE4 engineers are
obsessed with model view pattern. Anyways I have some working dialog
system, can show the dialog, and hide it. Can click on dialog line and
have some reaction on the click. And on clicking on the cancel dialog
is getting closed.

I made Jane to populate the dialog and show it on interaction event. Also,
I added some preparation for the future. If player have got a
telepathy ability Jane populates the dialog with other abilities:
levitation, telekinesis and pyrokinesis.

I made a dishwasher quest. In this quest the hero goes to Philip the
owner of the restaurant and he/she needs to wash dishes, for doing
this quest the hero will get $7.80.

And bicycle quest, but I am to lazy to describe what did I do for the
bicycle quest.
