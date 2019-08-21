---
Layout: page
title: Mika's Game
permalink: /mika-game/
---

This page is work in progress.

## Little bit of philosophy

## Overview

Mika's Game is a mass multiplayer online game with player generated content. Players can craft terrain, buildings, items, avatars, NPC, program quests and create mini games.

The game universe is a series of parallel infinite worlds. Player can spawn as many as he/she wants. New world may be cloned from current one if player has clone permissions or it can me procedurally generated from the random or specifies seed. Player becomes the owner of the world. World has permission flags: permission to visit, permission to clone, build permit.

Player has list of friends and friends can be categorized by groups.

Visit, build permit can be for everyone, for friends, for some particular group or it can be given to some particular player. Permit can have expiration date.

The world is a voxel world, like Minecraft (open question).

Crafting can be done by using blueprints and crafting table.

New player has basic blueprints: crafting table and basic tools.

Other blueprints has to be crafted or traded with other  players.

To be able to mine and build in the world player has to apply build permit first.

Trading in the game by dropping on the ground and picking up from the ground.

Later on you may craft trading machine for safe trading.



## This game was inspired

- VRChat
- Minecraft
- Roblox
- Dreams for PS4
- YouTube
- Apple Store
- Steam

## Items

### Miniaturizer

### Teleport

Builder can put teleports in the world and make in public, unlisted or private. Teleport will have descriptions and thumbnail.

Recommending system will use this data for recommendations.

### Teleport stone

### Circuitry

It is more like visual programming, like scratch. All values are analog values with analog dial.

Machine needs energy balls to run. Looks like experience balls from Minecraft

Energy balls spawn around player and have expiration. Player can buy energy ball this ball do not expire.

Vars can be connected via red-stone or via radio.

### Blueprint

### Avatars

### Sky machine

## NPC

### Quests

## Tools

### Custom tools

### World cloning

All data saved in no-sql database. Reddis. Each server control some part of the universe, everything saved in memory and periodically get offloaded to database. To offload in memory data to database, sever process get forked and data getting saved to DB in parallel.

Each chunk of Universe points to serving server or to nullptr.

Parallel universes doing copy of write. So it is cheap to make a copy.

On DB we have list of universes, each one has list of chunks. Universe also point to universe from which one one it was copied.

Every time then player makes copy of universe new readonly copy getting created and old one and new ope start pointing to it.

### Recommending system

Happy button. 😀

### Open questions

- How yo build healthy community without toxicity?
- Voxel or polygon based or mixed?







